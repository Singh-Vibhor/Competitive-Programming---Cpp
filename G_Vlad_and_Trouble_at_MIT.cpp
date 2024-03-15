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
int ans = 0;

char dfs(int node, string &s, vector<vector<int>> &connected, int p){
    if(connected[node].size() == 1) return s[node];
    int c1=0, c2 = 0;
    if(s[node] == 'P') c1++;
    if(s[node] == 'S') c2++;
    for(auto it: connected[node]){
        if(it == p) continue;
        char c = dfs(it, s, connected, node);
        if(c == 'P') c1++;
        else if (c=='S') c2++;
    }
    if(c1>0 and c2>0) {
        ans++;
        return s[node];
    }
    if(s[node] == 'C'){
        if (c1>0) return 'P';
        if (c2>0) return 'S';
    }
    return s[node];

}

void solve()
{
    int n; cin>>n;
    vector<vector<int>> par(n+1,vector<int>());
    for(int i = 2; i<=n; i++){
        int a; cin>>a;
        par[i].push_back(a);
        par[a].push_back(i);
    }
    // maintain dp ig 
    // and then solve using it 
    ans = 0;
    string s; cin>>s;
    dfs(1, s, par, -1);
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