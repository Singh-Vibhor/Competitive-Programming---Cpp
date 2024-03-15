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
    int n,m; cin>>n>>m;
    map<int,set<int>> graph;
    // vector<set<int>> graph(n+m+1,set<int>());
    // n+colour will represent node to colour
    rep(i,m){
        int u,v,c;
        cin>>u>>v>>c;
        graph[u].insert(c+n);
        graph[v].insert(c+n);
        graph[c+n].insert(u);
        graph[c+n].insert(v);
    }
    // make a graph of colours with nodes
    // every node will have which colour lines it has connected to it
    // then connect the colours according to the nodes.
    // then traverse in colours to get answer
    // GOOD THING 
    
    int start,end;
    cin>>start>>end;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> p;
    map<int,int> vis;
    p.push({0,start});
    vis[start] = 0;
    while(!p.empty()){
        vector<int> cur = p.top();
        p.pop();
        int dis = cur[0];
        if(cur[1]>n) dis++;
        for(auto it: graph[cur[1]]){
            if(vis.find(it)==vis.end()){
                p.push({dis,it});
                vis[it] = dis;
            }
            else if(vis[it]>dis){
                p.push({dis,it});
                vis[it] = dis;
            }
        }
    }

    cout<<vis[end]<<endl;


    // vector<int> vis(n+1,INT_MAX);
    // vis[start] = 0;
    // map<pair<int,int>, int> m1;
    // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> p;
    // p.push({0,start,0});
    // while (!p.empty()){
    //     vector<int> cur = p.top();
    //     p.pop();
    //     for(auto it: graph[cur[1]]){
    //         int node = it.first;
    //         int line = it.second;
    //         int dis = cur[0];
    //         if(line!=cur[2]) dis++;
    //         if(vis[node] > dis){
    //             vis[node] = dis;
    //             p.push({dis,node,line});
    //             m1[{node,line}] = dis;
    //         }
    //         else if(vis[node] == dis and (m1.find({node,line})==m1.end())){
    //             vis[node] = dis;
    //             p.push({dis,node,line});
    //             m1[{node,line}] = dis;
    //         }
    //         else if(vis[node] == dis and m1[{node,line}]>dis){
    //             vis[node] = dis;
    //             p.push({dis,node,line});
    //             m1[{node,line}] = dis;
    //         }
    //     }
    // }
    // cout<<vis[end]<<endl;
    
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