#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<pair<int,int>> g[N];
int dis[N];

void dijkstra(int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,s});
    dis[s]=0;
    while(!pq.empty())
    {
        pair<int,int> parent=pq.top();
        int parentNode=parent.second;
        int parentCost=parent.first;
        pq.pop();
        for(auto v:g[parentNode])
        {
            int childNode=v.first;
            int childCost=v.second;
            if(parentCost+childCost<dis[childNode])
            {
                dis[childNode]=parentCost+childCost;
                pq.push({dis[childNode],childNode});
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});

    }
    for(int i=0;i<=n;i++) dis[i]=INT_MAX;
    dijkstra(1);
    for(int i=1;i<=n;i++)
    {
        cout<<"Node: "<<i<<" dis: "<<dis[i]<<endl;
    }
    return 0;
}
