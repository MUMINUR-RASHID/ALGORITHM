#include<bits/stdc++.h>
using namespace std;
const int INF=1e7;
int main()
{
    int n,e;
    cin>>n>>e;
    int dis[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dis[i][j]=INF;
            if(i==j) dis[i][j]=0;
        }
    }

    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dis[u][v]=w;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    ///negetive cycle check;
    bool flag=true;
    
        for(int j=1;j<=n;j++)
        {
            if(dis[j][j]<0) 
            {
                flag=false;
                break;
            }
        }
    
    if(flag)
    {
        for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dis[i][j]==INF) cout<<"INF ";
            else cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    }
    else cout<<"There is a negetive cycle"<<endl;

    return 0;

}