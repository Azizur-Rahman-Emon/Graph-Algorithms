#include <bits/stdc++.h>
using namespace std;

const int mx = 2e5 + 5;

vector<int> adj[mx];
vector<int> colour(mx);

bool bfs(int src, int &cnt0, int &cnt1)
{
    queue<int> q;
    q.push(src);
    colour[src] = 0;
    cnt0++;

    bool ok = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            if (colour[v] == -1)
            {
                colour[v] = colour[u] ^ 1;

                if (colour[v] == 0) cnt0++;
                else cnt1++;

                q.push(v);
            }
            else if (colour[v] == colour[u])
            {
                ok = false;
            }
        }
    }

    return ok;
}

void dosomethingbig()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        colour[i] = -1;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (colour[i] == -1)
        {
            int cnt0 = 0, cnt1 = 0;

            if (bfs(i, cnt0, cnt1))
            {
                ans += max(cnt0, cnt1);
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        dosomethingbig();
    }

    return 0;
}
