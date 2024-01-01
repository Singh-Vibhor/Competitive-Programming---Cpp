#include <bits/stdc++.h>
using namespace std;
int toggle(int n){
    if (n==0)
    return 1;
    else
    return 0;
}
int main()
{
    int a[3][3];
    int b[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            b[i][j]=1;
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
            
            if ((a[i][j]%2)==1){
                b[i][j]=toggle(b[i][j]);
                if (i!=0)
                b[i-1][j]=toggle(b[i-1][j]);
                if(i!=2)
                b[i+1][j]=toggle(b[i+1][j]);
                if (j!=0)
                b[i][j-1]=toggle(b[i][j-1]);
                if (j!=2)
                b[i][j+1]=toggle(b[i][j+1]);
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<b[i][j];
            
        }
        cout<<endl;
    }

    return 0;
}