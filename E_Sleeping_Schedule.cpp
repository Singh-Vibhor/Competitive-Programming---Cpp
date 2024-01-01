#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD= 1e9+7;


// ll f(ll i,ll t,vector<ll> v,ll h,ll l, ll r)
// {
//  if(i==v.size()) {
//   if(t>=l && t<=h)
//   return 1;
//   else
//   return 0;
//  }
//  if(dp[i][t]!=-1)
//  return dp[i][t];
 
//   ll t1= (t+v[i]-1)%h;
//   ll t2= (t+v[i])%h;
//   if(t>=l && t<=h)
//   {
//     return dp[i][t]= 1+max(f(i+1,t1,v,h,l,r),f(i+1,t2,v,h,l,r));
//   } 
//   else
//   {
//     return dp[i][t]=max(f(i+1,t1,v,h,l,r),f(i+1,t2,v,h,l,r));
//   }
// }

// dp[i][t]=max(dp[i+1][t1],dp[i+1][t2])

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n,h,l,r;
  cin>>n>>h>>l>>r;
  ll dp[n+1][h+1];
  memset(dp,0,sizeof dp);
  vector<ll> v(n);
  for(ll i=0;i<n;i++) cin>>v[i];
  for(ll i=0;i<=h;i++) dp[n][i] = (i>=l && i<=r)?1:0;

  for(ll i=n-1;i>=0;i--)
  {
    for(ll j=0;j<=h;j++)
    {
        ll t1= (j+v[i]-1+h)%h;
        ll t2= (j+v[i]+h)%h;
        if(j>=l && j<=r)
         dp[i][j]=1+max(dp[i+1][t1],dp[i+1][t2]);
         else
         dp[i][j]=max(dp[i+1][t1],dp[i+1][t2]);

    }
  }
  cout<<dp[0][0];

}