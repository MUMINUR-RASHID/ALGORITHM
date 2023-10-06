#include<bits/stdc++.h>
using namespace std;



class Edge
{
    public:
    int u;
    int v;
    int w;
    Edge(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

int main()
{
    int n,e;
    cin>>n>>e;
    vector<Edge>ed;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        Edge ev(u,v,w);
        ed.push_back(ev);
    }

    int dis[n+1];
    bool flag=false;
    for(int i=0;i<n;i++) dis[i]=INT_MAX;///(should minus the maximum weight)
    int s=1; ///SOURCE
    //cin>>s;
    dis[s]=0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<ed.size();j++)
        {
            Edge ev=ed[j];
            if(dis[ev.u]+ev.w<dis[ev.v])
            {
                dis[ev.v]=dis[ev.u]+ev.w;
            }

        }
    }

    ///cycle handling
    for(int j=0;j<ed.size();j++)
        {
            Edge ev=ed[j];
            if(dis[ev.u]+ev.w<dis[ev.v])
            {
                flag=true;
                break;
            }

        }


    if(flag) cout<<"Cycle Detected"<<endl;
    else
    {
        for(int i=1;i<=n;i++)
        {
            cout<<"dis "<<i<<"= "<<dis[i]<<endl;
        }
    }
    
    return 0;
}


/*
4 4
1 2 5
2 3 2
3 4 -3
4 1 -1

source 1
*/