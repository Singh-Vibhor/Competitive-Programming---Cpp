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
    int n; cin>>n;
    string s; cin>>s;
    string ans = "";
    reverse(s.begin(),s.end());
    int i = 0;
    while(i<n-1){
        if (i==n-2){
            ans += s.substr(i,2);
            break;
        }
        if(s[i]=='a' || s[i]=='e'){
            ans += s.substr(i,2) + ".";
            i+=2;
        }
        else{
            ans+=s.substr(i,1);
            i++;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
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