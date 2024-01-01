#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    sort(s3.begin(),s3.end());
    int a1=0,a2=0,i=0,flag=1;
    for(i=0;i<s3.length();i++){
        if(a1<s1.length())
        {
            if (s1[a1]==s3[i]){
                a1++;
                //cout<<a1<<" 1"<<endl;
                continue;
            }
        }
        if(a2<s2.length())
        {

            if(s2[a2]==s3[i]){
                a2++;
                //cout<<a2<<" 2"<<endl;
                continue;

            }
        }
        if(a1==s1.length() && a2==s2.length())
        break;
        flag=0;
        break;
        
    }    
    if(a1==s1.length() && a2==s2.length() && i==s3.length() && flag==1)
    cout<<"YES";
    else
    cout<<"NO";

    return 0;
}