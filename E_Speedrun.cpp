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


ll max(ll a, ll b){
    return a>b?a:b;
}

vector<ll> topologicalSort(vector<vector<ll>> &graph, ll V, map<int,int> &mp1)
{
    vector<ll> in_degree(V, 0);
 
    for (int u = 0; u < V; u++) {
        for (auto itr:graph[u])
            in_degree[itr]++;
    }
 
    queue<ll> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            {q.push(i); mp1[i] = 1;}
 
    vector<ll> top_order;
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        top_order.push_back(u);
 
        for (auto itr : graph[u])
 
            if (--in_degree[itr] == 0)
                q.push(itr);
 
    }
    return top_order;
}


ll dfs(vector<vector<ll>> &graph, ll crr, vector<pair<ll,ll>> &dp, vector<ll> &h, ll k){
    if (dp[crr].first!=0 || dp[crr].second!=0) return dp[crr].second;
    dp[crr].first = h[crr];
    if(graph[crr].size()==0) return 0ll;
    for(auto it: graph[crr]){
        if (h[it]>=h[crr])
        dp[crr].second = max(dp[crr].second, h[it]-h[crr]+dfs(graph,it,dp,h,k));
        else
        dp[crr].second = max(dp[crr].second, k - h[crr] + h[it]+dfs(graph,it,dp,h,k));
    }
    return dp[crr].second;
}

void solve()
{
    // mp1.clear();
    map <int,int> mp1;

    ll n,m,k; cin>>n>>m>>k;
    vector<ll> h(n,0);
    rep(i,n){
        cin>>h[i];
    }
    vector<vector<ll>> graph(n);
    rep(i,m){
        ll a,b; cin>>a>>b;
        graph[a-1].push_back(b-1);
    }
     
    vector <ll> tp = topologicalSort(graph,n,mp1);


    vector <pair<ll,ll>> dp(n, {0,0});
    for(ll it = 0; it<n; it++){
        if (dp[it].first!=0 || dp[it].second!=0) continue;
        ll x = dfs(graph, it, dp, h, k);
    }


    vector<vector<ll>> check;
    ll mxend = 0;
    rep(i,n){

        mxend = max(mxend, dp[i].first+dp[i].second);
        if (mp1.find(i)!=mp1.end()){
            check.push_back({dp[i].first, dp[i].first + dp[i].second});
        }
    }
    
    
    
    sort(check.begin(), check.end());


    ll ans = 1e18;
    rep(i,check.size()){
        ans = min(ans,mxend - check[i][0]);
        mxend = max(mxend,check[i][1]+k);
    }

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