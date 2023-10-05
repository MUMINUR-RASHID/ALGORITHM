#include<bits/stdc++.h>
using namespace std;



const int N=1e5+5;
vector<int>g[N];
bool vi[N];
void dfs(int n)
{
    int parent=n;
    vi[parent]=true;
        for(auto v:g[parent])
        {
            int child=v;
            if(!vi[child])
            {
                dfs(child);
            
            }
        }
}

int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int c=0;
    
    for(int i=1;i<=n;i++)
    {
        if(!vi[i])
        {
            c++;
            dfs(i);
        }
    }

cout<<c<<endl; //how many disconnected node check;
    
    return 0;
}
