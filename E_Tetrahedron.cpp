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
    int n; cin >>n;
    vector<vector<ll>> dp (2, vector<ll>(4,0));
    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    ll MOD = 1e9+7;
    rep(i,n-1){
        dp[1][0] = (dp[0][1] + dp[0][2] + dp[0][3])%MOD;
        dp[1][1] = (dp[0][0] + dp[0][2] + dp[0][3])%MOD;
        dp[1][2] = (dp[0][1] + dp[0][0] + dp[0][3])%MOD;
        dp[1][3] = (dp[0][1] + dp[0][2] + dp[0][0])%MOD;
        rep(j,4){
            dp[0][j] = dp[1][j];
        }
    }
    cout<<dp[0][3]<<endl;
    
}


int32_t main()
{
    ioset
    int t;
    // cin>>t;
    t = 1;
    while(t--)
    {
        solve();
    }
    return 0;
}