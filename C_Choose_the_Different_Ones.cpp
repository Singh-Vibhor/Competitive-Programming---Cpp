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
    int n,m,k; cin>>n>>m>>k;
    vl a(n), b(m);
    set<int> a1,b1;
    rep(i,n) {
        cin>>a[i];
        a1.insert(a[i]);
    }
    rep(i,m) {
        cin>>b[i];
        b1.insert(b[i]);
    }
    int a2=0,b2=0,c2=0;
    rep(i,k){
        if (a1.find(i+1)!=a1.end()) a2++;
        if (b1.find(i+1)!=b1.end()) b2++;
        if (a1.find(i+1)!=a1.end() and b1.find(i+1)!=b1.end()) c2++;
    }
    // cout<<a2<<" "<<b2<<" "<<c2<<endl;
    if (a2+b2-c2>=k and b2>=k/2 and a2>=k/2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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