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
vector<int> endstate = {0,0,3,3};
map<vector<int>,int> visited;
void print(vector<int> state){
    cout<<state[0]<<" "<<state[1]<<" "<<state[2]<<" "<<state[3]<<endl;
}

int dfs(vector<int> state, int boat){
    // print(state);cout<<1<<endl;
    if(state[0]<0 or state[1]<0 or state[2]<0 or state[3]<0) return 0;
    if((state[1]>state[0] and state[0]>0) or (state[3]>state[2] and state[2]>0)) return 0;
    vector<int> state1 = {state[0], state[2], state[2], state[3], boat};
    if(visited.find(state1) != visited.end()) return 0;
    visited[state1] = 1;
    if (state==endstate){
        print(state);
        return 1;
    }
    int a=0, b=0, c=0, d=0, e=0,f=0;
    int g=0,h=0,i=0,j=0;
    boat = 1-boat;
    if (boat==1){

        a = dfs({state[0]-2, state[1], state[2]+2, state[3]}, boat);
        g = dfs({state[0]-1, state[1], state[2]+1, state[3]}, boat);
        b = dfs({state[0], state[1]-2, state[2], state[3]+2}, boat);
        h = dfs({state[0], state[1]-1, state[2], state[3]+1}, boat);
        c = dfs({state[0]-1, state[1]-1, state[2]+1, state[3]+1}, boat);

    }
    else{

        d = dfs({state[0]+2, state[1], state[2]-2, state[3]}, boat);
        i = dfs({state[0]+1, state[1], state[2]-1, state[3]}, boat);
        e = dfs({state[0], state[1]+2, state[2], state[3]-2}, boat);
        j = dfs({state[0], state[1]+1, state[2], state[3]-1}, boat);
        f = dfs({state[0]+1, state[1]+1, state[2]-1, state[3]-1}, boat);

    }
    // print(state);
    if(a==1 or b==1 or c==1 or d==1 or e==1 or f==1 or g==1 or h==1 or i==1 or j==1) 
    {print(state); return 1;}
    return 0;
}

void solve()
{
    vector<int> startstate = {3,3,0,0};
    dfs(startstate, 0);
}


int32_t main()
{
    ioset
    int t;
    // cin>>t;
    t = 1;
    while(t--)
    {
        solve();
    }
    return 0;
}