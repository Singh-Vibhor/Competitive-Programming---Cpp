#include <bits/stdc++.h>

    //Whatever
    //IMSS I am sad scam 

#define pi (3.141592653589)
#define M 1000000007
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define ioset ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ps(x,y) fixed<<setprecision(y)<<x
#define pii pair<int,int>
#define vi vector<int>

using namespace std;

void solve()
{
    string s; cin>>s;
    string a1 = "";
    a1 += s[0];
    int j = -1;
    for(int i=1; i<s.length(); i++){
        if (s[i] == '0') a1+=s[i];
        else {j = i; break;}
    }
    
    if (j==-1){cout<<-1<<endl;return;}
    string a2 = s.substr(j,s.length());
    // cout<<a1<<" "<<a2<<endl;
    if (stoi(a1)<stoi(a2)) cout<<a1<<" "<<a2<<endl;
    else cout<<-1<<endl;
    
}


int32_t main()
{
    ioset
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}