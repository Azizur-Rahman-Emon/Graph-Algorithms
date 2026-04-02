#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1008];
bool vis[1008];
int parent[1008];
bool cycle;
void dfs(int src)
{
    vis[src] = true;
    for (int child : adj_list[src])
    {
        if(vis[child] && parent[src]!=child)
        {
           cycle = true;
        }
        if (!vis[child])
        {
            dfs(child);
            parent[child]=src;
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
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
    if(cycle)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;;
}
