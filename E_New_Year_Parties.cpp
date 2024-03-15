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
    vi v(n); rep(i,n) cin>>v[i];
    vi mx(n+2);
    set<int> s;
    sort(v.begin(), v.end());
    for (auto it: v){
        s.insert(it);
        if (mx[it-1]==0) mx[it-1] = 1;
        else if(mx[it]==0) mx[it] = 1;
        else mx[it+1] = 1;
    }
    int mxans = 0;
    for(auto it: mx) mxans += it;
    int minans = 0;
    int prv = -5, crr = 1;
    for(auto it:s){
        if (it == prv+1 && crr<3){
            crr++;
            // cout<<it<<endl;
        }
        else if (it == prv+2 && crr==1){
            crr = 3;
        }
        else{
            minans++;
            crr = 1;
        }
        prv = it;
    }
    cout<<minans<<" "<<mxans<<endl;

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