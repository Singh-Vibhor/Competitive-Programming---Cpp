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

// int dfs1(int node, vector<vi> &tree, vi &cntact, vi&mx, vi&act, map<int,int> &m){
// //     int mn1 = act[node];
// //     for(auto it: tree[node]){
// //         mn1 = min(mn1, dfs1(it, tree, mn, mx, act, m));
// //     }
// //     mn[node] = mn1;
// //     return mn1;
//     mx[node] = cntact[node];
//     for(auto it: tree[node]){
//         mx[node] = max(mx[node], dfs1(it, tree, cntact, mx, act, m));
//     }
//     return mx[node];
// }
// void dfs2(int node, vector<vi> &tree, vi &cntact, vi&mx, vi&act, map<int,int> &m){
//     // int mx1 = node;
//     // for(auto it: tree[node]){
//     //     mx1 = max(mx1, dfs2(it, tree, mn, mx, act, m));
//     // }
//     // mx[node] = mx1;
//     // return mx1;
//     for(auto it: tree[node]){
//         m[act[it]]++;
//         if (m[act[it]]==1) cntact[it] = cntact[node]+1;
//         else cntact[it] = cntact[node];
//         dfs2(it, tree, cntact, mx, act, m);
//         m[act[it]]--;
//     }
// }



void solve()
{
    int n; cin>>n;
    vector<vi> tree(n+1);
    vector<int> act(n+1, 0);
    for(int i=2; i<=n; i++){
        int k; cin>>k;
        tree[k].pb(i);
    }
    for(int i=1; i<=n; i++){
        cin>>act[i];
    }
    // vi cntact(n+1, 0), mx(n+1, 1);
    // map<int,int> m;
    // cntact[1] = 1;
    // m[act[1]]++;
    // dfs2(1, tree, cntact, mx, act, m);
    // dfs1(1, tree, cntact, mx, act, m);
    // // rep(i,n+1) cout<<mx[i]<<" ";
    // // cout<<endl;
    // // rep(i,n+1) cout<<cntact[i]<<" ";
    // // cout<<endl;
    
    // ll ans = 0;
    // for(int i=1; i<=n; i++){
    //     int m1 = 1;
    //     for(auto it: tree[i]){
    //         // cout<<cntact[i]<<" "<<mx[it]<<endl;
    //         ans = max(ans, 1ll * (-cntact[i]+mx[it]+1) * m1);
    //         m1 = max(m1, -cntact[i]+mx[it]+1);
    //     }
    // }c:\Vibhor\Python\C_Number_of_Equal.cpp
    // cout<<ans<<endl;

    


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