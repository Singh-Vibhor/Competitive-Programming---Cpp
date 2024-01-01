#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <cstdint>
#include <cstddef>
#include <chrono>
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
#define mod 1000000007
#define pb push_back
#define is insert
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rfr(n) for(int i=n-1;i>=0;i--)
#define rep1(i,a,b) for(long long i=a;i<=b;i++)
#define fr(n) for(long long i=0;i<n;i++)
#define nesfr(x,y) for(long long i=0;i<x;i++)for(long long j=0;j<y;j++)
#define rep(i,a,b) for(long long i=a;i<b;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;
#define nl cout << "\n"
const unsigned int M = 1000000007;
const int  N = 2e5 + 5 ;


void solve(){
    ll n,k;cin>>n>>k;
    ll mn = INT64_MAX;
    vi a(n);fr(n){cin>>a[i];mn = min(mn,a[i]);}
    sort(all(a));
    if(k>=3){cout<<0<<endl;}
    else if (k==1){
        ll ans=mn;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                
                if (i!=j){ans=min(ans,abs(a[i]-a[j]));}
            }
        }
        cout<<ans<<endl;
    }
    else{
        ll ans=mn;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (i!=j){
                    ans = min(ans,abs(a[i]-a[j]));
                    ll x_=abs(a[i]-a[j]);
                    int x=upper_bound(a.begin(),a.end(),x_)-a.begin();
                    int y=lower_bound(a.begin(),a.end(),x_)-a.begin();
                    if (y!=0) y--;
                    ans=min3(ans,abs(x_-a[x]),abs(x_-a[y]));
                }
            }
        }
        cout<<ans<<endl;
    }
}
int main(){
   fast;
   ll t=1;
   cin>>t;
   while(t--){
   solve();
   }
return 0;
}