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
vector<int> ans(2*(1e5)+1, 0);

void solve()
{
    int n; cin>>n;
    cout<<ans[n]<<endl;
}


int32_t main()
{
    ioset
    for(int i=1; i<2*(1e5)+1; i++){
        int j = i;
        ans[i] = ans[i-1];
        while(j>0){
            ans[i]+=j%10;
            j/=10;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}