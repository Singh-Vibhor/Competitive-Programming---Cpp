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
    string even = "", odd = "";
    string ans = "";
    for (auto c:s){
        if (c % 2) odd += c;
        else even += c;
    }
    int p1 = 0,p2 = 0;
    while (p1 < even.size() && p2 < odd.size()){
        if (even[p1] - '0' < odd[p2] - '0'){
            ans += even[p1];
            p1++;
        }
        else{
            ans += odd[p2];
            p2++;
        }
    }

    while (p1<even.size()){
        ans += even[p1];
        p1++;
    }

    while (p2<odd.size()){
        ans += odd[p2];
        p2++;
    }
    // cout<<even<<endl<<odd<<endl;
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