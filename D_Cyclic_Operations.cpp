#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define rep(i,y) for(ll i=0;i<y;i++)


void fun(ll m)
{
  ll n,k;
  cin>>n>>k;
  
  vector<ll>b(n+1);
  rep(i,n) cin>>b[i+1];
  vector<ll>tim(n+1,0);
  vector<ll>vis(n+1,0);

  if (k==1){
    rep(i,n+1){
        if (b[i]!=(i)){
            // cout<<b[i]<<i+1;
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return;
  }
  
  for(int i=1;i<=n;i++)
  {
    if(!vis[i])
    {
      ll tm=1;
      ll curr=i;
    
      while(1)
      {
        if(vis[curr]==i)
        {
          if(abs(tm-tim[curr])!=k)
          {
            cout<<"NO"<<endl;
            return;
          }
          
        //   if(tim[curr]>k)
        //   {
        //     cout<<"NO"<<endl;
        //     // cout<<tim[curr]<<endl;
        //     return;
        //   }
          break;
        }
        else if(vis[curr]==0)
        {
          vis[curr]=i;
          tim[curr]=tm;
          curr=b[curr];
          tm++;
        }
        else break;
        // else
        // {
        //   if(tm>k)
        //   {
        //     cout<<"NO"<<endl;
        //     return;
        //   }
        //   break;
        // }
      }
    
    }
  }
  
  
  cout<<"YES"<<endl;
}


int main() 
{
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


  ll q;
  cin>>q;
  ll m=1;
 
  while(m<=q)
  {

    fun( m);
    m++;
  }

}
