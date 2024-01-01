#include <bits/stdc++.h>
using namespace std;
bool fun(int n){
    int a1=n%10;
    n=n/10;
    int a2=n%10;
    n=n/10;
    int a3=n%10;
    int a4=n/10;
    if(a1!=a2 && a2!=a3 && a3!=a4 && a4!=a1 && a1!=a3 && a2!=a4)
        return true;
    else
        return false;
}
int main()
{
    int n;
    cin>>n;
    n++;
    while(true)
    {
        if(fun(n)){
            cout<<n;
            break;
        }
        n++;
    }
    return 0;
}