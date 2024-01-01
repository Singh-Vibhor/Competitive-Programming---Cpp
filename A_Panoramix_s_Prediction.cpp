#include <bits/stdc++.h>
using namespace std;
bool isprime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
        return false;
    }
    return true;
}

int main()
{
    int n,m;
    cin>>n>>m;
    n++;
    while(true)
    {
        if (isprime(n)){
            if (n==m)
            cout<<"YES";
            else
            cout<<"NO";
            break;
        }
        n++;
    }
    return 0;
}