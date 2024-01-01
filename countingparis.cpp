#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"

const ll N=200005;
const ll mod=1e9+7;


void solve()
{
   ll m,n;
   cin>>m>>n;
   ll grid[m+1][n+1];
   ll cooperation_degree[m+1][n+1];
   for(ll i=1;i<=m;i++)
   {
      for(ll j=1;j<=n;j++)
      {
        cooperation_degree[i][j]=0;
      }
   }
   for(ll i=1;i<=m;i++)
   {
      for(ll j=1;j<=n;j++)
      {
        cin>>grid[i][j];
      }
   }
   for(ll i=1;i<=m;i++)
   {
      bool val=false;
      for(ll j=1;j<=n;j++)
      {
         if(grid[i][j]==1 && val==true)
         {
            cooperation_degree[i][j]++;
         }
         else if(grid[i][j]==2)
         {
            val=false;
         }
         else if(grid[i][j]==1) val=true;
      }
      val=false;
      for(ll j=n;j>=1;j--)
      {
         if(grid[i][j]==1 && val==true)
         {
            cooperation_degree[i][j]++;
         }
         else if(grid[i][j]==2)
         {
            val=false;
         }
         else if(grid[i][j]==1) val=true;
      }
   }

   for(ll j=1;j<=n;j++)
   {
       bool val=false;
       for(ll i=1;i<=m;i++)
       {
         if(grid[i][j]==1 && val==true)
         {
            cooperation_degree[i][j]++;
         }
         else if(grid[i][j]==2)
         {
            val=false;
         }
         else if(grid[i][j]==1) val=true;
       }
       val=false;
       for(ll i=m;i>=1;i--)
       {
         if(grid[i][j]==1 && val==true)
         {
            cooperation_degree[i][j]++;
         }
         else if(grid[i][j]==2)
         {
            val=false;
         }
         else if(grid[i][j]==1) val=true;
       }
   }

//    for(ll i=1;i<=m;i++)
//    {
//       for(ll j=1;j<=n;j++)
//       {
//         cout<<cooperation_degree[i][j]<<" ";
//       }
//       cout<<"\n";
//    }

   ll ans[10];
   for(ll i=0;i<10;i++)ans[i]=0;

   for(ll i=1;i<=m;i++)
   {
      bool val=false;
      ll ele=0;
      for(ll j=1;j<=n;j++)
      {
         if(cooperation_degree[i][j]>0 && val==true)
         {
            ans[cooperation_degree[i][j]+ele]++;
            ele=cooperation_degree[i][j];
         }
         else if(grid[i][j]==2)
         {
            val=false;
         }
         else if(cooperation_degree[i][j]>0)
         {
            val=true;
            ele=cooperation_degree[i][j];
         } 
      }
    //   val=false;
    //   for(ll j=n;j>=1;j--)
    //   {
    //       ll ele=0;
    //      if(cooperation_degree[i][j]>0 && val==true)
    //      {
    //         ans[cooperation_degree[i][j]+ele]++;
    //         ele=cooperation_degree[i][j];
    //      }
    //      else if(cooperation_degree[i][j]==0&& grid[i][j]==2)
    //      {
    //         val=false;
    //      }
    //      else if(cooperation_degree[i][j]>0)
    //      {
    //         val=true;
    //         ele=cooperation_degree[i][j];
    //      } 
    //   }
   }

   for(ll j=1;j<=n;j++)
   {
       bool val=false;
       ll ele=0;
       for(ll i=1;i<=m;i++)
       {
        
         if(cooperation_degree[i][j]>0 && val==true)
         {
            ans[cooperation_degree[i][j]+ele]++;
            ele=cooperation_degree[i][j];
         }
         else if(cooperation_degree[i][j]==0&& grid[i][j]==2)
         {
            val=false;
            ele=0;
         }
         else if(cooperation_degree[i][j]>0)
         {
            val=true;
            ele=cooperation_degree[i][j];
         } 
       }
    //    val=false;
    //    for(ll i=m;i>=1;i--)
    //    {
    //      ll ele=0;
    //      if(cooperation_degree[i][j]>0 && val==true)
    //      {
    //         ans[cooperation_degree[i][j]+ele]+=1;
    //         ele=cooperation_degree[i][j];
    //      }
    //      else if(cooperation_degree[i][j]==0&& grid[i][j]==2)
    //      {
    //         val=false;
    //      }
    //      else if(cooperation_degree[i][j]>0)
    //      {
    //         val=true;
    //         ele=cooperation_degree[i][j];
    //      } 
    //    }
   }

       for(ll i=2;i<=8;i++)
       {
         cout<<i<<" "<<ans[i]<<"\n";
       }



}


int main() {
    IOS;
    ll T;
    T=1;
    // cin >> T;
    while(T--)
    {
        solve();
    }

    return 0;
}
