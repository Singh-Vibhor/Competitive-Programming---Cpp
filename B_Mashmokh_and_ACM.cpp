#include <bits/stdc++.h>
using namespace std;
void _pri(int t) {cout << t;}
// #define int long long
#define it(v) v.begin(),v.end()
#define ll long long
#define vl vector<long long> 
#define vvl vector<vector<long long>> 
 
#define lld long  double
#define ull unsigned long long  
#define nl '\n'
 
 
#define iinp(n) long long n; cin>>n;
#define sinp(s) string s; cin >> s ;cin.ignore();
#define vinp(name,size) vector<ll>name (size); for(int i=0;i<size;i++) {cin>>name[i];}
template<typename... T> void pri(T&&... args){((cout << args <<" "), ...);cout<<'\n';}
template<typename... T> void inp(T&... args){((cin >> args and cin.ignore()), ...);}
void priv(vector<ll> &v){for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<'\n';}
void _pri(ll t) {cout << t<<" ";}
void _pri(string t) {cout << t;}
void _pri(char t) {cout << t;}
void _pri(lld t) {cout << t;}
void _pri(double t) {cout << t;}
void _pri(ull t) {cout << t;}  
 
template <class T, class V> void _pri(pair <T, V> p);
template <class T> void _pri(vector <T> v);
template <class T> void _pri(set <T> v);
template <class T, class V> void _pri(map <T, V> v);
template <class T> void _pri(multiset <T> v);
template <class T, class V> void _pri(pair <T, V> p) {_pri(p.first); cout << " "; _pri(p.second); cout << '\n';}
template <class T> void _pri(vector <T> v) {for (T i : v){_pri(i);}cout <<'\n';}    
template <class T> void _pri(set <T> v) {for (T i : v) {_pri(i); } cout << '\n';}
template <class T> void _pri(multiset <T> v) {for (T i : v) {_pri(i);} cout << '\n';}
template <class T, class V> void _pri(map <T, V> v) {for (auto i : v) {_pri(i);} cout <<'\n';}
//
#define mod 1000000007  
ll moda(ll a, ll b, ll cm=mod) {a = a % cm; b = b % cm; return (((a + b) % cm) + cm) % cm;}
ll modm(ll a, ll b, ll cm=mod) {a = a % cm; b = b % cm; return (((a * b) % cm) + cm) % cm;}
ll mods(ll a, ll b, ll cm=mod) {a = a % cm; b = b % cm; return (((a - b) % cm) + cm) % cm;}
int mpow(int base, int exp, long long cmod=mod){base %= cmod;long long result = 1;while (exp > 0) {if (exp & 1) result = ((long long)result * base) % cmod;base = ((long long)base * base) % cmod;exp >>= 1;}return result;}    
ll mminvprime(ll a, ll b) {return mpow(a, b - 2, b);}
ll modd(ll a, ll b, ll cm=mod) {a = a % cm; b = b % cm; return (modm(a, mminvprime(b, cm), cm) + cm) % cm;}  //only for prime cm
#define moda3(a,b,c) moda(a,moda(b,c))  
#define modm3(p,q,r) ((((p%mod)*(q%mod))%mod)*(r%mod))%mod   
 
// cout<<fixed<<setprecision(6)<<ans<<nl;
#define deb(x) cout << #x << " " << x <<'\n';
#define middle l+(h-l)/2; 
#define countsetbit(i) __builtin_popcountll(i) 
 

 
 
void solve(){   
    ll n,kk;
    ll m = 1e9+7;
    inp(n,kk);
    vvl dp(kk+1,vl(n+1,0));
    vvl dp1(kk+1,vl(n+1,0));

    //dp[1][1 to n]=1
    for(ll i=1;i<=n;i++){
        dp[1][i]=1;
        dp1[1][i]=1;
    }
    // for(ll i=2;i<=kk;i++){
    //     for(ll j=1;j<=n;j++){
    //         for(ll k=j;k<=n;k+=j){
    //             dp[i][k]=(dp[i][k] + dp[i-1][j]) % m;
    //         }
    //     } 
        // for(ll j=1;j<=n;j++){
        //     for(ll k=1;k<=j;k++){
        //         if(j%k==0){
        //           dp1[i][j]+=dp1[i-1][k];
        //         }
        //     }
        // } 

    // }
    for(ll i=2;i<=kk;i++){
        for(ll j=1;j<=n;j++){
            // for(ll k=1;k<j;k++){
            //     if(j%k==0){
            //         dp[i][j]+=dp[i-1][k];
            //     }
            // }
            for(ll k=1;k<sqrt(j);k++){
                if(j%k==0){
                    dp[i][j]=(dp[i][j] + dp[i-1][k])%m;
                    dp[i][j]=(dp[i][j] + dp[i-1][j/k])%m;
                }
            }
            if(ceil(sqrt(j))==floor(sqrt(j))) (dp[i][j]=dp[i][j]+dp[i-1][sqrt(j)])%m;
        } 
    }

    ll sum=0;
    ll sum1=0;
    for(ll i=1;i<=n;i++){
        sum=(sum + dp[kk][i])%m;
        // sum1+=dp1[kk][i];
    }
    pri(sum);
    // pri(sum1);
    
    
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
 
    int ttt;
    ttt=1;
    // cin>>ttt;
    int ccc=ttt;
    while(ttt--){
        // cout<<"Case "<<(ccc-ttt)<<":"<<" ";
        solve();
    } 
 
}