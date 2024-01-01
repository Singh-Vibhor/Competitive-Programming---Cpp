#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>a;
            if (a==1)
            {n=i;m=j;break;}
        }
    }
    int ans= abs(2-n) + abs(2-m);
    //cout<<n<<m<<endl;
    cout<<ans<<endl;

    
    return 0;
}