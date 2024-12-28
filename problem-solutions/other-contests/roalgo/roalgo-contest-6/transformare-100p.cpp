#include <bits/stdc++.h>

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int task, m, n, p;
    cin >> task >> n >> m >> p;
    struct position
    {
        bool island;
        int k, direction;
    };
    vector<vector<position>> a(n + 1, vector<position>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j].island = false;
            a[i][j].k = 0;
            a[i][j].direction = -4;
        }
    }
    while (p--)
    {
        int x, y, k, d;
        cin >> x >> y >> k >> d;
        a[x][y].island = true;
        a[x][y].k = k;
        a[x][y].direction = d;
    }
    const int dx[] = {0, 1, 0, -1, -1, 1, 1, -1}, dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
    if (task == 1)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j].island)
                {
                    int cnt = 0;
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int newx = i + dx[dir], newy = j + dy[dir];
                        if (1 <= newx && newx <= n && 1 <= newy && newy <= m)
                        {
                            if (a[newx][newy].island == false)
                            {
                                cnt++;
                            }
                        }
                    }
                    int newx = i + dx[3 + a[i][j].direction], newy = j + dy[3 + a[i][j].direction];
                    if (1 <= newx && newx <= n && 1 <= newy && newy <= m)
                    {
                        if (a[newx][newy].island == false)
                        {
                            cnt++;
                        }
                    }
                    if (cnt >= a[i][j].k)
                    {
                        ans++;
                    }
                }
            }
        }
        cout << ans;
    }
    else
    {
        struct qpos
        {
            int x, y, val;
        };
        vector<vector<int>> ans(n + 1, vector<int>(m + 1, n * m + 1));
        queue<qpos> q;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j].island)
                {
                    int cnt = 0;
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int newx = i + dx[dir], newy = j + dy[dir];
                        if (1 <= newx && newx <= n && 1 <= newy && newy <= m)
                        {
                            if (a[newx][newy].island == false)
                            {
                                cnt++;
                            }
                        }
                    }
                    int newx = i + dx[3 + a[i][j].direction], newy = j + dy[3 + a[i][j].direction];
                    if (1 <= newx && newx <= n && 1 <= newy && newy <= m)
                    {
                        if (a[newx][newy].island == false)
                        {
                            cnt++;
                        }
                    }
                    if (cnt >= a[i][j].k)
                    {
                        ans[i][j] = 1;
                        for (int dir = 0; dir < 8; dir++)
                        {
                            int newx = i + dx[dir], newy = j + dy[dir];
                            if (1 <= newx && newx <= n && 1 <= newy && newy <= m)
                            {
                                if (a[newx][newy].island)
                                {
                                    qpos newpos;
                                    newpos.x = newx;
                                    newpos.y = newy;
                                    newpos.val = 2;
                                    q.push(newpos);
                                }
                            }
                        }
                    }
                }
            }
        }
        while (!q.empty())
        {
            qpos current = q.front();
            q.pop();
            int x = current.x, y = current.y, nr = current.val, cnt = 0;
            if (ans[x][y] <= nr)
            {
                continue;
            }
            for (int dir = 0; dir < 4; dir++)
            {
                int newx = x + dx[dir], newy = y + dy[dir];
                if (1 <= newx && newx <= n && 1 <= newy && newy <= m)
                {
                    if (a[newx][newy].island == false || ans[newx][newy] < nr)
                    {
                        cnt++;
                    }
                }
            }
            int newx = x + dx[3 + a[x][y].direction], newy = y + dy[3 + a[x][y].direction];
            if (1 <= newx && newx <= n && 1 <= newy && newy <= m)
            {
                if (a[newx][newy].island == false || ans[newx][newy] < nr)
                {
                    cnt++;
                }
            }
            if (cnt >= a[x][y].k)
            {
                ans[x][y] = nr;
                for (int dir = 0; dir < 8; dir++)
                {
                    int newx = x + dx[dir], newy = y + dy[dir];
                    if (1 <= newx && newx <= n && 1 <= newy && newy <= m)
                    {
                        if (a[newx][newy].island)
                        {
                            qpos newpos;
                            newpos.x = newx;
                            newpos.y = newy;
                            newpos.val = nr + 1;
                            q.push(newpos);
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (ans[i][j] == n * m + 1)
                {
                    ans[i][j] = -1;
                }
            }
        }
        int t;
        cin >> t;
        while (t--)
        {
            int x, y;
            cin >> x >> y;
            cout << ans[x][y] << '\n';
        }
    }
    return 0;
}
