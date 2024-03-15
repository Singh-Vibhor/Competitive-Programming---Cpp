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
    int n1 = n;
    vi v(n);
    vl v1(n,0);
    map<ll,int> mp;
    rep(i,n) {cin>>v[i]; mp[v[i]] = i;}
    vvl ans;
    int k = 0;
    // int i = 0;
    while (k<n){
        // i++;
        vl a1;
        vl used(n,0);
        int t1 = 0;
        rep(i,n) if(v[i]==i+1) t1++;
        if (t1==n) break;
        t1 = 0;
        rep(i,n){
            // if (v1[i]) continue;
            if (v[i] == i+1) {v1[i] = 1; t1++; continue; }
            int req = mp[i+1];
            if (used[i] or used[req]) continue;
            a1.pb(i+1); a1.pb(req+1);
            t1++;
            v1[i] = 1; int tmp = v[i];
            v[i] = i+1; v[req] = tmp;
            mp[tmp] = req; mp[i+1] = i;
            used[i] = 1; used[req] = 1;
        }
        // k = t1;
        t1 = 0;
        ans.pb(a1);
        
    }
    // rep(i,n) cout<<v[i]<<" ";
    // cout<<endl;
    cout<<ans.size()<<endl;
    for(auto it: ans){
        cout<<it.size()<<" ";
        for(auto it1: it){
            cout<<it1<<" ";
        }
        cout<<endl;
    }
    
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