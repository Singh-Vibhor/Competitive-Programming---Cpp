#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl '\n'

#define ld long double
#define ull unsigned long long
 
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX >> 1;

void print(int a){ cerr << a;}
void print(ll a ){cerr <<  a;}
void print(ld a ){cerr << a;}
void print(string a){ cerr << a;}
void pirnt(bool a ){ cerr << a;}
void print(float a){cerr << a;}
void print( double a){ cerr << a;}
void print( char a) { cerr << a; }
void print(ull a){cerr << a;}

template<class t,class v> void print( pair<t,v> p);
template<class t> void print( vector<t> v1);
template<class t> void print( set<t> s);
template<class t,class v> void print( map<t,v> mp);
template<class t> void print( multiset<t> ms);
template<class t,class v>void print(pair<t,v> p){ cerr << "{" << p.first << "," << p.second << "}"; }
template<class t>void print( vector<t> v1){ cerr << "["; for(auto i:v1){ print(i); cerr << " ";} cerr << "]";}
template<class t> void print(set<t> s){ cerr << "["; for(auto i:s){print(i); cerr << " ";} cerr << "]";}
template<class t,class v> void print(map<t,v> mp){ cerr << "["; for(auto i:mp){ print(i); cerr << " ";} cerr << "]";}
template<class t> void print(multiset<t> ms){ cerr << "["; for(auto i:ms) { print(i); cerr << " "; } cerr << "]";}


void solve()
{
   ll n;cin >> n;

   ll g2[n];
   ll g1[n];

   for(ll i=0;i<n;i++)cin >> g2[i];
   for(ll i=0;i<n;i++)cin >> g1[i];

   ll l =0;
   ll r = 0;

   ll al = 0;
   ll ar = 0;

   for(ll i=0;i<n-1;i++){
       if( g1[i] > g1[i+1]){
		   l = i+1;
	   }

	   r = i+1;

	   if(r-l > ar - al){
		   al = l;
		   ar = r;
	   }

   }

   cout << (al+1) << " " << (ar+1);
   cout << endl;


}
 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
 
    ll tc;
    cin >> tc ;
 
    while(tc--){
    
        solve();
 
    }
 
 
}
