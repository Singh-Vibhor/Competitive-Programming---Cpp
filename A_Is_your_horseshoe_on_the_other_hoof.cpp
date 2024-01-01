#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    set<int> st={a,b,c,d};
    cout<<(4-st.size());
    return 0;
}