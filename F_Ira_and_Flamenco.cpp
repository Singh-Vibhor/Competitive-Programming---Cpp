#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long int
#define all(v) (v).begin(), (v).end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i,i1,n) for(ll i=i1;i<n;i++)
#define repr(i,n,i1) for(ll i=n;i>=i1;i--)
#define di(a) ll a;cin>>a;
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define sz(a) a.size()
#define el '\n'
#define yes cout<<"YES"<<el
#define no cout<<"NO"<<el
#define print(x) cout<<x<<el
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define debug(x,y) cout<<x<<' '<<y<<el
#define vi vector<ll>
#define mpp map<ll,ll>
#define disp(v) for(ll i=0;i<v.size();i++){cout<<v[i]<<' ';} cout<<el
#define SUM(v) accumulate(all(v), 0LL)
#define srt(v) sort(all(v))
#define rsrt(v) sort(rall(v))
#define invec(v,n) vector<ll> v(n); rep(i,0,n) cin>>v[i]
const long long INF = 4e18;
const long long inf = -4e18;
const ll M=1e9+7;

ll gcd(int a,int b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}




void solve(){
    di(n);
    di(k);
    invec(v,n);
    multiset<ll>s;
    // for(auto it:v)s.insert(it);
    ll ans=0,j=0;
    ll mn=0,mx=0;
    for(int i=0;i<n;i++){
        s.insert(v[i]);
        mx=*(--s.end());
        mn=*(s.begin());
        while(j<=i and (mx-mn)>=k){
            s.erase(s.find(v[j]));
            mx=*(--s.end());
            mn=*(s.begin());
            j++;
        }
        if(s.size()==k)ans+=(i+1-j+1);
    }   
    print(ans);
}


signed main()
{
    int tc=1;
    cin>>tc;
    while(tc--){
     solve();
    }
}