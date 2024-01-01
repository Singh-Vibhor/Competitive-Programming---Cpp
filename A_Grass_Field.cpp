#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
    int a;
    int cnt=0;
    for (int i=0;i<4;i++){
        cin>>a;
        if (a==1)
        cnt++;
    }   
    if (cnt==0)
    cout<<0<<endl;
    else if(cnt==4)
    cout<<2<<endl;
    else
    cout<<1<<endl;
    }
    return 0;
}