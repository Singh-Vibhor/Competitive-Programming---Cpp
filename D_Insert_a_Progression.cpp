#include<bits/stdc++.h>
using namespace std;

int main()
{ 
     
     int t;
     cin>>t;

     while(t--)
     {
          int n,m;
          cin>>n>>m;
          
          int ar[n], mi=INT_MAX, ma=0;
          long long int sum=0;

          for(int a=0;a<n;a++) {
               cin>>ar[a];
               mi=min(mi,ar[a]);
               ma=max(ma,ar[a]);
          }
          
          for(int a=1;a<n;a++)
          {
               sum+=abs(ar[a]-ar[a-1]);
          }

          if(mi!=1) 
          {
               long long int sum1 = sum + min(abs(1-ar[0]), abs(1-ar[n-1]));
               for(int i=1; i<n; i++){
                    sum1 = min(sum1, sum - abs(ar[i] - ar[i-1]) + abs(ar[i] - 1) + abs(ar[i-1] - 1));
               }
               sum = sum1;
          }
          if(ma<m) 
          {
               long long int sum1 = sum + min(abs(m-ar[0]), abs(m-ar[n-1]));
               for(int i=1; i<n; i++){
                    sum1 = min(sum1, sum - abs(ar[i] - ar[i-1]) + abs(ar[i] - m) + abs(ar[i-1] - m));
               }
               sum = sum1;
               
          }
          cout<<sum<<"\n";
          
     }
     
}
          