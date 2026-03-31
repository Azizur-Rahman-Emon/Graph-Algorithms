#include<bits/stdc++.h>
using namespace std;
vector<int>adj_list[1008];
bool vis[1008];
void dfs(int src)
{
    cout<<src<<" ";
    vis[src]=true;
    for(int child:adj_list[src])
    {
        if(!vis[child])
        dfs(child);
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    dfs(0);
}
