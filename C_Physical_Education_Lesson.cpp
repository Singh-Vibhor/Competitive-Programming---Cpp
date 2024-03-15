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

#define MAXN 100001
 
// stores smallest prime factor for every number

void solve()
{
    ll n,x; cin>>n>>x;
    // x--;
    set<ll> ans;
    
    int a1 = n-x,a2 = n+(x-1)-1;
    
    for(int i=1; i*i<=a1; i++){
        if(a1%i==0){
            ans.insert(i);
            ans.insert(a1/i);
        }
    }
    
    for(int i=1; i*i<=a2; i++){
        if(a2%i==0){
            ans.insert(i);
            ans.insert(a2/i);
        }
    }
    int ans1 = 0;
    for(auto it: ans){
        if(it&1) continue;
        // cout<<it<<" ";
        it = (it+2)/2;
        if(it>=x and it!=1) ans1++;
    }
    cout<<ans1<<endl;

}


int32_t main()
{
    ioset
    int t;
    // sieve();
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}