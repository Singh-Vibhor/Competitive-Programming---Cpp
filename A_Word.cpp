#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string ans="";
    int u=0,l=0;
    for (int i=0;i<s.length() ;i++){
        char c=s[i];
        if (isupper(c))
        u++;
        else
        l++;
    }
    if (u>l)
    {
        for (int i=0;i<s.length() ;i++){
            ans=ans+char(toupper(s[i]));
        }
    }
    else
    {
        for (int i=0;i<s.length() ;i++){
            ans=ans+char(tolower(s[i]));
        }
    }
    cout<<ans<<endl;
    return 0;
}