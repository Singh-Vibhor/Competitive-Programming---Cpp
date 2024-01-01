#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int c1=0,c2=0,c3=0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]=='1')
        c1++;
        else if(s[i]=='2')
        c2++;
        else
        c3++;
        i++;
    }
    
    if(c1!=0)
    {cout<<1;c1--;}
    else if(c2!=0)
    {cout<<2;c2--;}
    else
    {cout<<3;c3--;}

    for (int i = 1; i <= c1; i++)
    cout<<"+"<<1;
    for (int i = 1; i <= c2; i++)
    cout<<"+"<<2;
    for (int i = 1; i <= c3; i++)
    cout<<"+"<<3;
    return 0;
}