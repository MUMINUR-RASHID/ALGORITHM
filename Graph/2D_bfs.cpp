#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
vector<pi>path={{0,1},{0,-1},{1,0},{-1,0}};
const int N=1e3+5;
int n,m;
bool vi[N][N];
int dis[N][N];
char g[N][N];
bool valid(int i,int j)
{
    return (i>=0&&i<n&&j>=0&&j<m&&g[i][j]=='.');
}


void bfs(int si,int sj)
{
    queue<pi>q;
    q.push({si,sj});
    vi[si][sj]=true;
    dis[si][sj]=0;
    while(!q.empty())
    {
        pi parent=q.front();
        int pI=parent.first;
        int pJ=parent.second;
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            pi p=path[i];
            int cI=p.first+pI;
            int cJ=p.second+pJ;
            if(valid(cI,cJ)&&!vi[cI][cJ])
            {
                dis[cI][cJ]=dis[pI][pJ]+1;
                vi[cI][cJ]=true;
                q.push({cI,cJ});
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
            cin>>g[i][j];
        }
    }
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(g[i][j]=='.'&&!vi[i][j])
            {
                c++;
                bfs(i,j);
            }
        }
    }
    cout<<c<<endl;
    
    return 0;
}



/*

component count in 2D grid

5 8
########
#..#...#
####.#.#
#..#...#
########
*/