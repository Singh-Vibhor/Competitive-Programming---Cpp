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

//sexy af
//dp of k+1 segment trees

void update(int n, int x, ll val, vvl &dp, int k){
    int node = x + n - 1;
    dp[k][node] = val;
    while (node > 0){
        node = (node - 1)/2;
        int left_child = node * 2 + 1;
        int right_child = node * 2 + 2;
        dp[k][node] = dp[k][left_child];
        if(right_child < 2*n)
        dp[k][node] += dp[k][right_child];
    }
}

ll query (int n, int k, int x, vvl &dp){
    int l = n;
    int r = x + n - 1;

    ll sum = 0;
    
    while (l <= r){
        
        if((l%2) == 0){
            sum += dp[k][l];
            l = (l + 1 - 1) / 2;
        }
        else 
            l = (l-1) /2;
        
        if ((r % 2) == 1){
            sum += dp[k][r];
            r = (r - 1 - 2)/2 ;
        }
        else
            r = (r - 2) / 2;
    }
    return sum;
}


void solve()
{
    int n,k; cin>>n>>k;
    int n1 = n;
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    // cout<<n<<endl;
    vector<vector<ll>> dp(k+2, vector<ll>(n*2,0));

    for(int i=0; i<n1; i++){

        int x; cin>>x;
        update(n, x, 1, dp, 1);
        for(int i=2; i<=k+1; i++){
            ll val = query(n, i-1, x-1, dp);
            update(n, x, val, dp, i);
        }

    }
    cout<<dp[k+1][0]<<endl;

}


int32_t main()
{
    ioset
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}