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
    vi v(n); rep(i,n)cin>>v[i];
    vector<ll> prfeve(n,0), prfodd(n,0);
    prfeve[0] = v[0];
    int f = 0;
    map<ll,int> mp;
    mp[prfodd[0]-prfeve[0]]++;
    for(int i=1; i<n; i++){
        prfodd[i]+=prfodd[i-1];
        prfeve[i]+=prfeve[i-1];
        if (i%2) prfodd[i]+=v[i];
        else prfeve[i]+=v[i];
        mp[prfodd[i]-prfeve[i]]++;
        // cout<<prfodd[i]<<" "<<prfeve[i]<<" "<<prfodd[i]-prfeve[i]<<endl;
        if (mp[prfodd[i]-prfeve[i]]==2 || prfodd[i]-prfeve[i]==0){
            f=1;break;
        }
    }
    if(f)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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