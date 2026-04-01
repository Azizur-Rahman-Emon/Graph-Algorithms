// shortest distance
#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
bool visit[105][105];
int level[105][105];
vector<pair<int,int>>d={{-1,0},{0,-1},{1,0},{0,1}};
 int n,m;
bool valid(int i ,int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
    return false;
    return true;
}
void bfs(int si,int sj)
{
   queue<pair<int,int>>q;
   q.push({si,sj});
   visit[si][sj]=true;
   level[si][sj]=0;
   while(!q.empty())
   {
      pair<int,int>p=q.front();
      q.pop();
      int par_i=p.first;
      int par_j=p.second;
      for(int i=0;i<4;i++)
      {
        int ci=par_i+d[i].first;
        int cj=par_j+d[i].second;
        if(valid(ci,cj)&& !visit[ci][cj])
        {
            q.push({ci,cj});
            visit[ci][cj]=true;
            level[ci][cj]=level[par_i][par_j]+1;
        }
      }
   }
}
int main()
{
   
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    memset(visit,false,sizeof(visit));
    memset(level,-1,sizeof(level));
    int si,sj,di,dj;
    cin>>si>>sj>>di>>dj;
    bfs(si,sj);
    cout<<level[di][dj]<<endl;
}
