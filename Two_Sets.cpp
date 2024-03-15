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
    vl a1,a2;
    if(n%4 == 3){
        a1.pb(n);
        a2.pb(n-1);
        a2.pb(1);
        int p1 = n - 2, p2 = 2;
        while (p1>p2){
            a1.pb(p1);
            a1.pb(p2);
            p1--; p2++;
            a2.pb(p1); a2.pb(p2);
            if(p1<=p2) {cout<<"NO"<<endl; return;}
            p1--; p2++;
        }
        int n1 = a1.size(), n2 = a2.size();
        cout<<"YES"<<endl;
        cout<<n1<<endl;
        rep(i,n1) cout<<a1[i]<<" ";
        cout<<endl;
        cout<<n2<<endl;
        rep(i,n2) cout<<a2[i]<<" ";
        cout<<endl;
    }
    else if (n%4 == 0){
        int p1 = n, p2 = 1;
        while (p1>p2){
            a1.pb(p1);
            a1.pb(p2);
            p1--; p2++;
            a2.pb(p1); a2.pb(p2);
            if(p1<=p2) {cout<<"NO"<<endl; return;}
            p1--; p2++;
        }
        int n1 = a1.size(), n2 = a2.size();
        cout<<"YES"<<endl;
        cout<<n1<<endl;
        rep(i,n1) cout<<a1[i]<<" ";
        cout<<endl;
        cout<<n2<<endl;
        rep(i,n2) cout<<a2[i]<<" ";
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
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