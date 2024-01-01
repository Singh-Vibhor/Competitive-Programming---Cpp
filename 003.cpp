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
    vector <int> l;
    for(int i=0; i<5; i++) {
        int a; cin>>a; l.push_back(a);
    }
    sort(l.begin(), l.end());
    int end; cin>>end;
    int prv = 0, ptr = 0;
    int ans = 0;
    while (prv<end && ptr<l.size()){
        ans+=max(l[ptr]-prv-10,0);
        prv = l[ptr];
        ptr+=1;
    }
    ans+=(end-prv-10);
    cout<<ans<<endl;
}


int32_t main()
{
    ioset
    int t=1;
    // cin>>t;
    while(t--)
    {   
        solve();
    }
    return 0;
}