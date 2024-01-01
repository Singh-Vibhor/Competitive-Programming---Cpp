#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string ans="";
    ans+=char(toupper(s[0]));
    ans=ans+s.substr(1,s.length());
    cout<<ans;
    return 0;
}