#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j,k,si=0,sj=0,sk=0;
    cin>>n;
    for(int m=0;m<n;m++)
    {
        cin>>i>>j>>k;
        si+=i;
        sj+=j;
        sk+=k;
    }
    if (si==0 && sj==0 && sk==0)
    cout<<"YES";
    else
    cout<<"NO";
    return 0;
}