#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using namespace chrono;
 
#ifdef prcsh
#include "debug.h"
#else
#define dbg(...) ;
#define debug(...) ;
#define crndl ;
#endif
 
#define int         long long int
#define pb          push_back
#define fst         first
#define sec         second
#define endl        '\n'
#define rep(i,a,b)   for(int i=a;i<b;i++)
#define msb(mask) (63-__builtin_clzll(mask))
#define to_lowercase(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define to_uppercase(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
bool isPrime(int v) {if (v <= 3)return true;if ( v % 2 == 0 || v % 3 == 0)return false;int i = 5;while (i * i <= v) {if (v % i == 0 || v % (i + 2) == 0)return false;i += 6;}return true;}
int power(int a, int b, int mod = LONG_LONG_MAX) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
int mminvprime(int a, int b) {return power(a, b - 2, b);}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
 
 
void fxn(){
   int n; cin>>n;
   vector<int>arr(n);
   rep(i,0,n)cin>>arr[i];
   sort(arr.begin(),arr.end());
   int med=0;
   if(n&1){
      med=arr[n/2];
   }
   else{
      med=arr[n/2];
   }
   int ans=0;
   rep(i,0,n){
      ans+=abs(arr[i]-med);
   }
   cout<<ans<<endl;
}
 
signed main(){
    // #ifdef prcsh
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif
    int t=1;
    rep(i,0,t) fxn();
   return 0;
}