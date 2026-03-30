#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
bool visit[1005];
int level[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visit[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : adj[par])
        {
            if (!visit[child])
            {
                q.push(child);
                visit[child] = true;
                level[child] = level[par] + 1;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(visit, false, sizeof(visit));
    memset(level, -1, sizeof(level));
    int src, dis;
    cin >> src >> dis;
    bfs(src);
    cout << level[dis] << endl;
}
