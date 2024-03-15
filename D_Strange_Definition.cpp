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

#define MAXN 1000001
 
int spf[MAXN];
 
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
 
        spf[i] = i;
 
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
 
    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}


void solve()
{
  int n; cin>>n;
  vl v(n); rep(i,n) cin>>v[i];
  int q; cin>>q; 
  map <int,int> ans;
  for(auto it: v){
    map<int,int> mp;
    while (it>1){
      mp[spf[it]]++;
      mp[spf[it]]%=2;
      it/=spf[it];
    }
    int pr = 1;
    for(auto it1: mp){
      if (it1.second==1) pr *= it1.first;
    }
    ans[pr]++;
  }
  int even = 0, mx = 0, one = 0;
  for(auto it: ans){
    if (it.second % 2 == 0 and it.first!=1) even += it.second;
    mx = max(mx,it.second);
    if (it.first == 1) one = it.second;
  }
  int mx1 = max(mx,even+one);
  rep(i,q){
    ll w; cin>>w;
    if (w==0) cout<<mx<<endl;
    else cout<<mx1<<endl;
  }
}


int32_t main()
{
  ioset
  sieve();
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}