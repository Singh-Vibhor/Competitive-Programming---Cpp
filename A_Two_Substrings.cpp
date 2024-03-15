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
    string s;
    cin>>s;

    int f1 = 0;
    for(int i=0; i<s.length()-1; i++){
        
        if(f1 == 1 and s[i] == 'B' and s[i+1] == 'A') {
            cout<<"YES"<<endl; return;
        }
        
        if(f1 == 0 and s[i] == 'A' and s[i+1] == 'B') {
            f1 = 1; 
            i++;
        }
    }


    f1 = 0;
    for(int i=0; i<s.length()-1; i++){
        
        if(f1 == 1 and s[i] == 'A' and s[i+1] == 'B') {
            cout<<"YES"<<endl; return;
        }
        
        if(f1 == 0 and s[i] == 'B' and s[i+1] == 'A') {
            f1 = 1;
            i++;
        }
    }
    cout<<"NO"<<endl;
}


int32_t main()
{
    ioset
    solve();
}