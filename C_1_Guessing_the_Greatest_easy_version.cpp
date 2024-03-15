#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mii map<int,int>
#define umii unordered_map<int,int>
#define si set<int>
#define ff first
#define ss second
#define vi vector<int>
#define vpii vector<pii>
#define pb push_back
#define pii pair<int,int>
#define print(x) cout<<x<<"\n";
#define printvector(a) for(auto i : a) cout<<i<<" "; cout<<"\n";
#define takevector(a) for(auto &x:a)cin>>x;
#define take1(a) int a; cin>>a;
#define take2(a,b) int a,b; cin>>a>>b;
#define take3(a,b,c) int a,b,c; cin>>a>>b>>c;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define f(i,a,b) for(int i=a; i<b; i++)
#define rf(i,a,b) for(int i=a; i>=b; i--)
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define yesno(ok) cout<<(ok ? "YES" : "NO")<<"\n";
int MOD = 1e9 + 7;

/* ----------------------------------- GLOBAL'S ------------------------------------------*/
 
 
 
/* ----------------------------------- OTHER FUNC'S --------------------------------------*/
 int askQuery(int l , int r)
 {
   if(l >= r) return -1;
   int s_max = -1;
   cout<<"? "<< l <<" "<< r << endl; 
   cin>>s_max;
   return s_max;
 }
 
/* --------------------------------------- SOLVE -----------------------------------------*/
 
void solve()
{
  take1(n)

  int lo = 1, hi = n;
  while(lo < hi-1)
  {
      int mid = lo + ((hi-lo) >> 1);
      int s_max = askQuery(lo , hi);
      if(s_max < mid)
      {
        if(s_max == askQuery(lo,mid - 1))
        {
          // in range from lo to mid-1
          hi = mid - 1;
        }
        else
        {
          // in range from mid to hi
          lo = mid;
        }
      }
      else
      {
        if(s_max == askQuery(mid , hi))
        {
          // in range from mid to hi
          lo = mid;
        }
        else
        {
          // in range from lo to mid-1
          hi = mid - 1;
        }
      }

  }
  if (askQuery(lo,hi)==hi)
  cout<<"! "<< lo <<endl;
  else cout<<"! "<<hi<<endl;
}

/* ----------------------------------- MAIN -----------------------------------------------*/

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t=1;
  // cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}
