#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
bool visit[1005];
int level[1005];
int parent[1005];
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
                parent[child]=par;
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
    memset(parent,-1,sizeof(parent));
    int src, dis;
    cin >> src >> dis;
    bfs(src);
    int node=dis;
    vector<int>path;
    while(node!=-1)
    {
       path.push_back(node);
       node=parent[node];
    }
    reverse(path.begin(),path.end());
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
