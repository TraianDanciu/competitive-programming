#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("excursie.in");
ofstream fout("excursie.out");

const int NMAX = 2e5;
int nrleft[NMAX+5], nrright[NMAX+5], n, aint[NMAX*4+5];

int getvalue(int node, int left, int right, int start, int finish)
{
    if (start <= left && right <= finish)
        return aint[node]+nrleft[left-1]-nrleft[start-1]+
                          nrright[finish]-nrright[right];
    else {
        int middle = (left+right)/2, ans = n;
        
        if (start <= middle)
            ans = min(ans, getvalue(2*node, left, middle, start, finish));
        if (finish > middle)
            ans = min(ans, getvalue(2*node+1, middle+1, right, start, finish));
        
        return ans;
    }
}

void build(int node, int left, int right)
{
    if (left == right) aint[node] = 0;
    else {
        int middle = (left+right)/2;
        build(2*node, left, middle);
        build(2*node+1, middle+1, right);
        aint[node] = min(aint[2*node]+nrright[right]-nrright[middle],
                         aint[2*node+1]+nrleft[middle]-nrleft[left-1]);

        if (aint[node] < 0) fout<<node<<' ';
    }
}

class query {
    private:
        int john, mary;
        
        void read()
        {
            fin>>john>>mary;
            
            if (john > mary) swap(john, mary);
        }
        
        void solve()
        {
            fout<<getvalue(1, 1, n, john, mary)<<'\n';
        }
    
    public:
        query()
        {
            read();
            solve();
        }
};

int main()
{
    char direction;
    int m;
    fin>>n;

    for (int i = 1; i <= n; i++)
        fin>>direction,
        nrleft[i] = nrleft[i-1]+(direction == 'L'),
        nrright[i] = nrright[i-1]+(direction == 'R');

    build(1, 1, n);
    fin>>m;
    
    while (m--) query q;

    return 0;
}
