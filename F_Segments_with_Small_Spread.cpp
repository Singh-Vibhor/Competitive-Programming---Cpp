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

void solve(){
	ll n,k; cin>>n>>k;
	vector<ll> v(n);
	for(ll i=0;i<n;i++)
		cin>>v[i];

	ll i=0,j=0;
	ll mx=0,mn=LONG_MAX;
	ll ans=0;
	multiset<ll> ms;

	while(j<n){
		ms.insert(v[j]);
		mx=*(--ms.end());
		mn=*(ms.begin());

		while(i<=j && mx-mn>k){
			ms.erase(ms.find(v[i]));
			mx=*(--ms.end());
			mn=*(ms.begin());
			i++;	
		}
		ans+=(j-i+1);
		j++;
	}
	cout<<ans<<endl;
}


int32_t main()
{
    ioset
    ll t;
    // cin>>t;
    t = 1;
    while(t--)
    {
        solve();
    }
    return 0;
}