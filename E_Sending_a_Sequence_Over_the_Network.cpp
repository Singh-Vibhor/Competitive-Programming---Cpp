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
    vi v(n); rep(i,n) cin>>v[i];
    vi dp(n+1);
    dp[0] = 1;
    for(int i = 1; i<=n; i++){
        if (dp[i-1]==1 && (i+v[i-1]) <= n) dp[i+v[i-1]] = 1;
        if (i - v[i-1] - 1>=0) dp[i] = max(dp[i - v[i-1] - 1], dp[i]);
    }
    // rep(i,n+1) cout<<dp[i]<<" ";
    if (dp[n]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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