#include<bits/stdc++.h>
using namespace std;


typedef  long long ll;
typedef  long int lli;
typedef  double dl;
typedef long double ld;
typedef  vector<int> vi;
typedef  vector<ll> vl;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<pii>vpi;
typedef  vector<pll> vpl;
 
#define     pb       push_back
#define     del       pop_back
#define     MP        make_pair
#define     F         first
#define     S         second
#define     sz(x)     (int)x.size()
#define     all(a)    (a).begin(),(a).end()
#define     faster    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define     endl      '\n'
#define     mem(a,b)  memset(a,b,sizeof(a))
#define     mod       1000000007
#define     gcd(a,b)  __gcd(a,b)
#define     pf        printf
#define     YES       cout<<"YES\n"
#define     Yes       cout<<"Yes\n"
#define     NO        cout<<"NO\n"
#define     No        cout<<"No\n"

const char nl='\n';

void merge(int a[],int l,int mi,int r)
{
    int n=mi-l+1;
    int m=r-mi;
    vector<int>s1;
    vector<int>s2;
    for(int k=l;k<=mi;k++)
    {
        s1.push_back(a[k]);
    }
    s1.push_back(INT_MAX);

    for(int k=mi+1;k<=r;k++)
    {
        s2.push_back(a[k]);
    }
    s2.push_back(INT_MAX);
    int i=0;
    int j=0;
    while(l<=r)
    {
        if(s1[i]>s2[j])
        {
            a[l]=s2[j];
            l++;
            j++;
        }
        else
        {
            a[l]=s1[i];
            i++;
            l++;
        }
    }
    
}

void merge_sort(int a[],int l,int r)
{
    if(l==r) return;
     int mid=(l+r)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);
    merge(a,l,mid,r);
    
    

}


int main()
{
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
     merge_sort(a,0,n-1);
     for(int i=0;i<n;i++) cout<<a[i]<<" ";
     cout<<endl;
    return 0;
}
