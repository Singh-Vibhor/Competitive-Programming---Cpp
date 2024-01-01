#include <bits/stdc++.h>

    //Whatever
    //IMSS I am sad scam 

#define pi (3.141592653589)
#define M 1000000007
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define ioset ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ps(x,y) fixed<<setprecision(y)<<x
#define pii pair<int,int>
#define vi vector<int>

using namespace std;

void solve()
{
    int n; cin>>n;
    vector<vector<int>>graph(n,vector<int>(0,0));
    rep(i,n-1){
        int a,b; cin>>a>>b;
        graph[a-1].push_back(b);
        graph[b-1].push_back(a);
    }
    int ans = 0;
    for (auto it: graph){
        if (it.size()==1) ans++;
    }
    cout<<(ans+1)/2<<endl;
}


int32_t main()
{
    ioset
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}