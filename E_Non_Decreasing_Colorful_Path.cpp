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

ll getsuperparent(vl &superparent, ll x){
    if (superparent[x]==x) return x;
    return superparent[x] = getsuperparent(superparent, superparent[x]);
}

void merge(ll u, ll v, vl &superparent){
    ll u1 = getsuperparent(superparent, u);
    ll v1 = getsuperparent(superparent, v);
    if (u1 < v1){
        superparent[u1] = v1;
    }
    else {
        superparent[v1] = u1;
    }
}

void solve()
{
    ll n,m; cin>>n>>m;
    vl val(n+1); rep(i,n) cin>>val[i+1];
    vvl graph(n+1);
    rep(i,m){
        ll a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vl superparent(n+1, 0);
    rep(i,n) superparent[i+1] = i+1;
    rep(i,n){
        for(auto it: graph[i+1]){
            if (val[it] == val[i+1]) 
            {
                // cout<<superparent[it]<<" "<<superparent[i+1]<<endl;
                merge(it, (ll)(i+1), superparent);
            }
        }
    }
    vector<pair<int,int>> nodes;
    vl dp(n+1, -10000000);
    rep(i,n){
        nodes.push_back(make_pair(val[i+1], i+1));
    }
    sort(nodes.begin(), nodes.end());
    dp[getsuperparent(superparent, 1)] = 1;
    ll st = val[1];
    for(auto it: nodes){
        // cout<<it.first<<" "<<it.second<<endl;
        
        if(it.first < st) continue;
        ll node1 = getsuperparent(superparent, it.second);
        for(auto it1: graph[it.second]){
            // if(it.second == 8) cout<<it1<<endl;
            if (val[it1] == val[it.second]){
                dp[node1] = max(dp[node1], dp[getsuperparent(superparent, it1)]);
            }
            else if( val[it1] < val[it.second])
            dp[node1] = max(dp[node1], dp[getsuperparent(superparent, it1)]+1);
        }
    }
    // rep(i,n) cout<<dp[i+1]<<" ";
    // cout<<endl;
    cout<<max(dp[getsuperparent(superparent, n)], 0ll);
    
}


int32_t main()
{
    ioset
    int t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}