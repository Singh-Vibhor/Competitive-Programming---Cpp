#include <bits/stdc++.h>
#include <vector>
#include <utility>  // for pair
using namespace std;



#define ll long long 
#define llu long long unsigned
#define pb push_back
#define rep(i,b) for(ll i=0; i<(b);i++)

using namespace std;
const ll lim =1e6;
vector<ll>prime;
vector<ll>sieve(lim+1,1);
ll mod=998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll>  vl;
typedef vector<pii> vpii;
typedef vector<pl>  vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
vector<ll>square;

bool compare(vector<ll>&a,vector<ll>&b)
{
  if(a[0]==b[0])
  {
    return a[1]<b[1];
  }
  
  return a[0]>b[0];
}


// bool compare2(vector<ll>& a, vector<ll>& b)
// {
//   for(int i=0;i<a.size();i++)
//   {
//     if(a[i]!=b[i])
//     {
//       return a[i]<b[i];
//     }
//   }
  
// }

ll get(vl & a, vl &b)
{
  ll res=0;
  for(int i=0;i<a.size();i++)
  {
    if(a[i]==b[i])
    {
      res++;
    }
    else
    {
      return res;
    }
  }
  
  return res;
}

unsigned long long factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    }

    return num * factorial(num - 1);
}

// Function to calculate n choose r (nCr)
unsigned long long nCr(int n, int r) {
    if (r > n) {
        return 0;
    }

    return factorial(n) / (factorial(r) * factorial(n - r));
}


void fun() {
  ll n,m;
  cin>>n>>m;
  
  vvl adj[n+1];
  
  
  for(int i=0;i<m;i++)
  {
    ll a, b, c;
    cin>>a>>b>>c;
    adj[a].pb({b,c});
    adj[b].pb({a,c});
  }
  
  vl slow(n+1);
  ll maxi=0;
  for(int i=1;i<=n;i++)
  {
    cin>>slow[i];
    maxi=max(maxi, slow[i]);
  }
  
  priority_queue<vl,vvl,greater<vl>>pq;
  vvl dist(n+1,vl(maxi+1, -1));
  dist[1][slow[1]]=0;
  pq.push({0,1,slow[1]});

  
  
  while(!pq.empty())
  {
    // cout<<1<<endl;
    ll flag=0;
    ll dis=pq.top()[0];
    ll node=pq.top()[1];
    ll speed=pq.top()[2];
    pq.pop();
    // cout<<node<<endl;
    if(node==n)
    {
      continue;
    }
    for(auto x:adj[node])
    {
      if(dist[x[0]][speed]==-1)
      {
         dist[x[0]][speed]=dis+speed*x[1];
         pq.push({dist[x[0]][speed], x[0],min(slow[x[0]],speed)});
        //  slow[x[0]]=min(speed,slow[x[0]]);
      }
      else
      {
        if(dis+speed*x[1]<dist[x[0]][speed])
        {
          dist[x[0]][speed]=dis+speed*x[1];
          pq.push({dist[x[0]][speed], x[0],min(slow[x[0]],speed)});
        }
      }
     
    }
  }
  ll ans=-1;
  ll flag=0;
  
  for(int i=1;i<=maxi;i++)
  {
    if(dist[n][i]!=-1)
    {
      flag=1;
      if(ans==-1)
      {
        ans=dist[n][i];
      }
      else
      {
        ans=min(ans, dist[n][i]);
      }
    }
  }
  if(flag==0)
  {
    cout<<-1<<endl;
  }
  
  cout<<ans<<endl;
  return;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    ll m = 1;

    while (m <= t) {
        fun();
        m++;
    }

    return 0;
}