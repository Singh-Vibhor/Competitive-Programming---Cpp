#include<bits/stdc++.h>
using namespace std;
 
 
  
// ..Optimizations
 // #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 //#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,tune=native")
// #pragma GCC optimize ("O3")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target ("avx2")
// #pragma GCC optimize ("Os")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("fast-math")
// #define _FORTIFY_SOURCE 0 
// #pragma GCC optimize("no-stack-protector")  
#define MOD 1000000007
#define MOD1 998244353
#define INF 10000000000
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#define int long long
#define ll long long
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
//ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b
//ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
//ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
 #define endl "\n"
  const int M=1000000007;
        long long mod(long long x){
            return ((x%M + M)%M);
        }
        long long add(long long a, long long b){
            return mod(mod(a)+mod(b));
        }
        long long mul(long long a, long long b){
            return mod(mod(a)*mod(b));
        }


  
void solve(){
    int n;
	cin>>n;
	vector<int>v;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.pb(x);
	}
	//dp[i][j] max score that the current player can get from subarray i to j
	vector<vector<int>>dp(n+1,vector<int>(n+1,0));
vector<int>pref=v;
vector<int>suff=v;
	for(int i=1;i<n;i++){
		pref[i]+=pref[i-1];
	}
	for(int i=n-2;i>=0;i--){
		suff[i]+=suff[i+1];
	}
	//dp[i][j]= max(v[i]+sum[i+1][j]-d[i+1][j] , v[j]+sum[i][j-1]-dp[i][j-1]);
	for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i==j){
                dp[i][j]=v[i];
                continue;
            }
            int op1=pref[j]-pref[i];
            int op2=pref[j-1];
            if(i>0){
                op2-=pref[i-1];
            }
            int p1=0;
            int p2=0;
            if((i+1)<=j){
                p1+=dp[i+1][j];
            }
            if((i)<=(j-1)){
                p2+=dp[i][j-1];
            }
            dp[i][j]=max(v[i]+op1-p1,v[j]+op2-p2);
        }
    }
    cout<<dp[0][n-1]<<endl;
}
	
	
	
	
		
			
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
int t=1;

//cin>>t;
	while(t--){	
	solve();
}
}
