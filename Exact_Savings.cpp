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
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void solve()
{
    ll n,x,z; cin>>n>>x>>z;
    vl v1(n);
    vl v(n); rep(i,n) {cin>>v[i]; v1[i] = v[i]/x; v[i]%=x;}
    bitset <2100> dp;
    dp.set(0);
    rep (i,n) dp |= dp<<v[i];
    // cout<<dp.test(3)<<endl;
    ll a = z/x;
    if (a*x==z) {cout<<a<<endl; return;}
    a++;
    int a1 = a*x - z;
    
    if (dp.test(a1)) {
        vvl dp1(n, vl(x+1, LONG_MAX));
        rep(i,n) dp1[i][0] = 1;
        rep(i,n){
            rep(j,x+1){
                if(j-v[i]>=0) dp1[i][j] = min(dp1[i][j], dp1[i][j-v[i]] + v1[i]);
                if (i!=0) dp1[i][j] = min(dp1[i][j], dp1[i-1][j]);
            }
        }
        
        rep(i,n){
            rep(j,x+1){
                cout<<dp1[i][j]<<" ";
            }
            cout<<endl;
            // cout<<v1[i]<<endl;
        }
        

        cout<<a + dp1[n-1][a1]-1<<endl; return;
    }
    a++;
    a1 = a*x - z;
        if (dp.test(a1)) {
        vvl dp1(n, vl(x+1, LONG_MAX));
        rep(i,n) dp1[i][0] = 1;
        rep(i,n){
            rep(j,x+1){
                if(j-v[i]>=0) dp1[i][j] = min(dp1[i][j], dp1[i][j-v[i]] + v1[i]);
                if (i!=0) dp1[i][j] = min(dp1[i][j], dp1[i-1][j]);
            }
        }
        // 
        cout<<a + dp1[n-1][a1]<<endl; return;
    }

    cout<<-1<<endl;
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