#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int ans=0;
    int flag=0;
    for(int i=0;i<s.length();i++)
    {
        if (s[i]=='4' || s[i]=='7')
        ans++;
    
    }
    if (ans==0)
    flag=1;
    while(ans>0){
        if(ans%10==4 || ans %10 ==7)
        ans=ans/10;
        else
        {flag=1; break;}
    
    }
    if (flag)
    cout<<"NO";
    else
    cout<<"YES";
    return 0;
}