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

bool chk(ll mid,ll k,vector<ll> &v){
    ll sum=0;

    for(int i=0;i<v.size();i++){
        sum += (mid/v[i]);
        if (sum>=k) return true;
    }

    return sum>=k;

}

void solve()
{
    int n,k; cin>>n>>k;
    vector<ll> v(n); rep(i,n) cin>>v[i];
    ll l=1,r=1e18;
    ll ans=r;

    while(l<=r){
        ll mid=(l+r)/2;

        if(chk(mid,k,v)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }

    cout<<ans<<endl;
}


int32_t main()
{
    ioset
    int t;
    // cin>>t;
    t = 1;
    while(t--)
    {
        solve();
    }
    return 0;
}