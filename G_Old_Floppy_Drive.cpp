#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int tc;
    cin>>tc;
    while( tc-- )
    {
        int n,q,m;
        cin>>n>>q;
        
        vector<int>v(n),mx,ind;
        
        for( int i = 0 ; i < n ; i++ )
        {
         cin>>v[i];
         
         if(i)
         v[i] += v[i-1];
         
         if( i == 0  || v[i] > mx.back() )
         {
            mx.push_back(v[i]);
         }
         else{
            mx.push_back(mx.back());
         }
         
        }
        
        while( q-- )
        {
            int k,ans=0,m=mx.size();
            cin>>k;
            
            if( k > mx[m-1] )   
            {
                if( v[n-1] <= 0 )
                {
                    cout<<-1<<" ";
                    continue;
                }
                
                ans = (k-mx[m-1])/v[n-1] + 1; 
                k = k - (v[n-1]*ans);
                
                if( k == 0 )
                {
                    k += v[n-1];
                    ans-=1;
                }
                
                ans = ans * n; 
            }
            
            auto it = upper_bound(mx.begin(),mx.end(),k-1);
            int index = it - mx.begin();
            if (index>0) index--;
            ans += index;
            
            cout<<ans<<" ";
        }
        
        cout<<endl;
    }
}