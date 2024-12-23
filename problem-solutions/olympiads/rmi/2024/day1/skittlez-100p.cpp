// Folosesc faptul ca elementul majoritar e asociativ si comutativ

#include <stdio.h>
#include <vector>

const int MAXQ = 500'000;
const int MAXN = 1'000;
const int AINTN = 1'024;

struct Query {
    int l1, c1, l2, c2, num;
};
std::vector<Query> queries[MAXQ + 1];
std::vector<std::pair<int, int>> poz[MAXQ + 1];
long long mars[MAXN + 2][MAXN + 2];
int answer[MAXN + 2][MAXN + 2];

int nextp2(int n) {
    while(n & (n - 1)) {
        n += n & -n;
    }
    return n;
}

struct SegmentTree1D {
    struct Node {
        int val;
        long long freq;
        
        void operator +=(Node other) {
            if(val == other.val) {
                freq += other.freq;
            } else if(freq >= other.freq) {
                freq -= other.freq;
            } else {
                val = other.val;
                freq = other.freq - freq;
            }
        }
    } tree[AINTN << 1];
    int n;
    
    void init(int n) {
        this->n = nextp2(n);
        for(int i = 1; i < 2 * this->n; i++) {
            tree[i] = {0, 0};
        }
    }
    
    void update(int st, int dr, Node val) {
        st += n - 1;
        dr += n - 1;
        while(st <= dr) {
            if(st & 1) {
                tree[st++] += val;
            }
            st >>= 1;
            
            if(!(dr & 1)) {
                tree[dr--] += val;
            }
            dr >>= 1;
        }
    }
    
    void dfs(std::vector<Node> &col_answer, Node ancestors, int nodec) {
        ancestors += tree[nodec];
        if(nodec >= n) {
            col_answer[nodec - n] += ancestors;
        } else {
            dfs(col_answer, ancestors, 2 * nodec);
            dfs(col_answer, ancestors, 2 * nodec + 1);
        }
    }
    
    // Practic calculez pentru toate coloanele pe care le tin eu
    // si dupa compar totul cu ce aveam din aintul 2d
    void computeAll(std::vector<Node> &col_answer) {
        dfs(col_answer, {0, 0}, 1);
    }
};

struct SegmentTree2D {
    SegmentTree1D tree[AINTN << 1];
    int n;
    SegmentTree1D::Node answer[AINTN][AINTN];
    
    void init(int n) {
        this->n = nextp2(n);
        for(int i = 1; i < 2 * this->n; i++) {
            tree[i].init(n);
        }
    }
    
    void update(int st1, int st2, int dr1, int dr2, SegmentTree1D::Node val) {
        st1 += n - 1;
        dr1 += n - 1;
        while(st1 <= dr1) {
            if(st1 & 1) {
                tree[st1++].update(st2, dr2, val);
            }
            st1 >>= 1;
            
            if(!(dr1 & 1)) {
                tree[dr1--].update(st2, dr2, val);
            }
            dr1 >>= 1;
        }
    }
    
    void dfs(std::vector<SegmentTree1D::Node> col_answer, int nodel) {
        tree[nodel].computeAll(col_answer);
        if(nodel >= n) {
            for(int c = 0; c < n; c++) {
                answer[nodel - n + 1][c + 1] = col_answer[c];
            }
        } else {
            dfs(col_answer, 2 * nodel);
            dfs(col_answer, 2 * nodel + 1);
        }
    }
    
    void computeAll() {
        dfs(std::vector<SegmentTree1D::Node>(n, {0, 0}), 1);
    }
} aint2d;

struct AIB2D {
    int n;
    long long aib[MAXN + 1][MAXN + 1];
    
    void init(int n) {
        this->n = n;
        for(int l = 1; l <= n; l++) {
            for(int c = 1; c <= n; c++) {
                aib[l][c] = 0;
            }
        }
    }
    
    void update(int i, int j, long long val) {
        for(int l = i; l <= n; l += l & -l) {
            for(int c = j; c <= n; c += c & -c) {
                aib[l][c] += val;
            }
        }
    }
    
    void update(int l1, int c1, int l2, int c2, long long val) {
        update(l1, c1, +val);
        update(l1, c2 + 1, -val);
        update(l2 + 1, c1, -val);
        update(l2 + 1, c2 + 1, +val);
    }
    
    long long query(int i, int j) {
        long long answer = 0;
        for(int l = i; l > 0; l &= l - 1) {
            for(int c = j; c > 0; c &= c - 1) {
                answer += aib[l][c];
            }
        }
        return answer;
    }
} aib2d;

int main() {
    int n, q, l1, c1, l2, c2, val, i, l, c, num;
    
    scanf("%d%d", &n, &q);
    aint2d.init(n);
    for(i = 0; i < q; i++) {
        scanf("%d%d%d%d%d%d", &l1, &c1, &l2, &c2, &val, &num);
        queries[val].push_back({l1, c1, l2, c2, num});
        aint2d.update(l1, c1, l2, c2, {val, num});
        mars[l1][c1] += num;
        mars[l2 + 1][c1] -= num;
        mars[l1][c2 + 1] -= num;
        mars[l2 + 1][c2 + 1] += num;
    }
    
    aint2d.computeAll();
    for(l = 1; l <= n; l++) {
        for(c = 1; c <= n; c++) {
            poz[aint2d.answer[l][c].val].push_back({l, c});
            mars[l][c] += mars[l - 1][c] + mars[l][c - 1] - mars[l - 1][c - 1];
            answer[l][c] = -1;
        }
    }
    
    aib2d.init(n);
    for(val = 1; val <= q; val++) {
        for(Query it : queries[val]) {
            aib2d.update(it.l1, it.c1, it.l2, it.c2, +it.num);
        }
        
        for(auto it : poz[val]) {
            if(aib2d.query(it.first, it.second) > mars[it.first][it.second] / 2) {
                answer[it.first][it.second] = val;
            }
        }
        
        for(Query it : queries[val]) {
            aib2d.update(it.l1, it.c1, it.l2, it.c2, -it.num);
        }
    }
    
    for(l = 1; l <= n; l++) {
        for(c = 1; c <= n; c++) {
            printf("%d ", answer[l][c]);
        }
        fputc('\n', stdout);
    }
    
    return 0;
}
