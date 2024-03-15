#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
#define vl vector<ll>
#define vvl vector<vl>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void solve()
{
    int n; cin>>n;
    string s1,s2; cin>>s1>>s2;
    int ans = 0, f=0;
    vector<vector<int>> dp(n, vector<int>(2,0));
    dp[0][0] = 1;
    string path;
    path = s1[0];
    ans = 1;
    for(int i=1; i<n; i++){
        if(s1[i]==s2[i-1]) ans++;
        else if(s1[i] =='0' and s2[i-1]=='1') ans = 1;
        else break;
    }
    for(int i=1; i<n; i++){
        string a;
        if(f==1){
            a = s2[i-1];
            path += a;
            dp[i][1] = dp[i-1][1];
            continue;
        }
        if(s1[i] == '0' and s2[i-1] == '1') {
            dp[i][0] = dp[i-1][0];
            a = s1[i];
            path += a;
        }
        if(s1[i]=='1' and s2[i-1]=='0'){
            dp[i-1][1] += dp[i-1][0];
            if(i>=2) dp[i-1][1] += dp[i-2][1];
            dp[i][1] = dp[i-1][1];
            a = s2[i-1];
            path += a;
            f = 1;
        }
        if(s1[i] == s2[i-1]){
            a = s1[i];
            dp[i-1][1] = dp[i-1][0];
            if(i>=2) dp[i-1][1] += dp[i-2][1];
            dp[i][0] = dp[i-1][0];
            path += a;
        }
    }
    path+=s2[n-1];
    // rep(i,n){
    //     cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    // }
    cout<<path<<endl;
    cout<<(dp[n-1][0] + dp[n-2][1])<<endl;
    cout<<ans<<endl;
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