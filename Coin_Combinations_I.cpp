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
    ll n,k; cin>>n>>k;
    vi a(n);
    rep(i,n) cin>>a[i];
    sort(a.begin(), a.end());
    vi dp(k+1,0);
    dp[0] = 1;
    for(int i=1; i<=k; i++){
        for (auto it:a){
            if (it>i) break;
            dp[i] = (dp[i]+dp[i-it])%(int)(1e9+7);
        }
    }
    cout<<dp[k]<<endl;
}


int32_t main()
{
    ioset
    int t;
    t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}