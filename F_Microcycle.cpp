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

int f = 0;

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
    void bridgeUtil(int u, vector<bool>& visited, vector<int>& disc, 
                                  vector<int>& low, int parent);
public:
    map<pair<int,int>,int> mp;

    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    void bridge();    // prints all bridges
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}
 
// A recursive function that finds and prints bridges using
// DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree
void Graph::bridgeUtil(int u, vector<bool>& visited, vector<int>& disc, 
                                  vector<int>& low, int parent)
{
    // A static variable is used for simplicity, we can 
    // avoid use of static variable by passing a pointer.
    static int time = 0;
 
    // Mark the current node as visited
    visited[u] = true;
 
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
 
    // Go through all vertices adjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u
           
          // 1. If v is parent 
          if(v==parent)
            continue;
       
          //2. If v is visited
          if(visited[v]){
          low[u]  = min(low[u], disc[v]);
        }
       
          //3. If v is not visited
          else{
          parent = u;
          bridgeUtil(v, visited, disc, low, parent);
   
          // update the low of u as it's quite possible 
          // a connection exists from v's descendants to u
          low[u]  = min(low[u], low[v]);
           
          // if the lowest possible time to reach vertex v
          // is greater than discovery time of u it means 
          // that v can be only be reached by vertex above v
          // so if that edge is removed v can't be reached so it's a bridge
          if (low[v] > disc[u])
              {
                mp[{v,u}]=1;
                mp[{u,v}]=1;
              }
           
        }
    }
}
 
// DFS based function to find all bridges. It uses recursive 
// function bridgeUtil()
void Graph::bridge()
{
    // Mark all the vertices as not visited disc and low as -1
    vector<bool> visited (V,false);
    vector<int> disc (V,-1);
      vector<int> low (V,-1);
     
      // Initially there is no parent so let it be -1
      int parent = -1;
 
    // Call the recursive helper function to find Bridges
    // in DFS tree rooted with vertex 'i'
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);
}
 

int getparent(int a, vl &dsu){
    if(dsu[a]==a) return a;
    return dsu[a] = getparent(dsu[a], dsu); 
}


void merge(int a, int b, vl &dsu){
    int a1 = getparent(a, dsu);
    int b1 = getparent(b, dsu);

    if (a1>b1) dsu[a] = b1;
    else dsu[b] = a1;
}

void dfs(int a, vector<vector<pair<int,int>>> &graph, vl &par, int b){
    if(a==b) {f = 1; return;}
    if (f) return;
    for(auto it: graph[a]){
        int node = it.first;
        // cout<<par[node]<<endl;
        if(par[node]==-1 and par[a]!=node){
            par[node] = a;
            dfs(node, graph, par, b);
        }
    }
}


void solve()
{
    // int n,m; 
    // cin>>n>>m;
    // vector<vector<pair<int,int>>> adj(n+1,vector<pair<int,int>>());
    // int mw = INT_MAX;
    // int aa = -1;
    // int bb = -1;
    // Graph g(n+1);
    // rep(i,m)
    // {
    //     int a,b,w;
    //     cin>>a>>b>>w;
    //     g.addEdge(a,b);
    //     adj[a].push_back({b,w});
    //     adj[b].push_back({a,w});
    // }
    // g.bridge();
    // for(int i=1;i<=n;i++)
    // {
    //     for(auto it:adj[i])
    //     {
    //         if(g.mp.find({i,it.first})!=g.mp.end()) continue;
    //         if(it.second<mw)
    //         {
    //             mw=it.second;
    //             aa=it.first;
    //             bb=i;
    //         }
    //     }
    // }
    // queue<int> q;
    // q.push(bb);
    // vector<int> vis(n+1,0);
    // vis[aa]=1;
    // vis[bb]=1;
    // vector<int> parent(n+1,-1);
    // parent[bb] = aa;
    // while(!q.empty())
    // {
    //     auto node = q.front();
    //     q.pop();
    //     for(auto child:adj[node])
    //     {
    //         if(g.mp.find({child.first,node})!=g.mp.end()) continue;
    //         if(child.first == aa and parent[node]!=aa) {parent[aa] = node; break;}
    //         if(vis[child.first]) continue;
    //         parent[child.first]=node;
    //         vis[child.first]=1;
    //         q.push(child.first);
    //     }
    //     if (parent[aa]!=-1) break;
    // }
    // vector<int> ans;
    // ans.push_back(aa);
    // int node = parent[aa];
    // while(node!=aa and node!=-1)
    // {
    //     ans.push_back(node);
    //     node = parent[node];
    // }
    // cout<<mw<<" "<<ans.size()<<endl;
    // for(auto it:ans) cout<<it<<" ";
    // cout<<endl;
    int n,m; cin>>n>>m;
    f = 0;
    vector<vl> v1;
    vector<vector<pair<int,int>>> graph(n+1, vector<pair<int,int>>(0));
    vl dsu(n+1,0);
    rep(i,n) dsu[i+1] = i+1;
    ll a,b,mn;
    rep(i,m){
        int u,v,w; cin>>u>>v>>w;
        v1.push_back({-w,u,v});
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
        
    }
    sort(v1.begin(), v1.end());
    rep(i,m){
        int u,v,w;
        u = v1[i][1]; 
        v = v1[i][2];  
        w = -v1[i][0];
        if (getparent(u,dsu) == getparent(v,dsu)){
            a = u; b = v; mn = w;
        }
        else merge(u,v,dsu);
    }
    // cout<<a<<" "<<b<<" "<<mn<<endl;

    vl par(n+1,-1);
    par[a] = b;

    dfs(a, graph, par, b);

    vl ans;
    ans.push_back(a);
    int node = par[a];
    while(node != a and node != -1){
        ans.push_back(node);
        node = par[node];
    }
    cout<<mn<<" "<<ans.size()<<endl;
    for(auto it: ans) cout<<it<<" ";
    cout<<endl; 
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