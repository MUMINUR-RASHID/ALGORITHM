#include<bits/stdc++.h>
using namespace std;

const int N=1e7+5;
int leader[N];
int leadersize[N];
int leaderlevel[N];

void dsu_set(int n)
{
    for(int i=0;i<=n;i++)
    {
        leader[i]=-1;
       leadersize[i]=1;
       leaderlevel[i]=0;
    }
    
}


int dsu_find(int n)
{
    while(leader[n]!=-1)
    {
        n=leader[n];
    }
    return n;
}

void dsu_union(int a,int b)
{
    int leaderA=dsu_find(a);
    int leaderB=dsu_find(b);
    if(leaderA!=leaderB)
    {
        if(leaderlevel[leaderA]==leaderlevel[leaderB]) 
        {
            leaderlevel[leaderA]++; ///find leader maximum level
        }

        if(leadersize[leaderA]>=leadersize[leaderB])
        {
            leader[leaderB]=leaderA;
            leadersize[leaderA]+=leadersize[leaderB];
        }
        else
        {
            leader[leaderA]=leaderB;
            leadersize[leaderB]+=leadersize[leaderA];
        }
    }
}



int main()
{
    int n,e;
    cin>>n>>e;
    dsu_set(n);
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        int leaderA = dsu_find(u);
        int leaderB = dsu_find(v);
       
       
       ///cycle detection
       
        if (leaderA == leaderB)
        {
            cout << "Cycel detected in between: " << u << " " << v << endl;
        }
        else
        {
            dsu_union(u,v);
        }
        
    }
    cout<<dsu_find(7);
    return 0;
}

/* input
7 4
1 2
2 3
4 5
6 5

*/