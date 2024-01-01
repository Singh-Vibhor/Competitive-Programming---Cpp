#include<bits/stdc++.h>
using namespace std;

 
#define pb push_back
#define ppb pop_back
#define int long long
 
//---------------------------------------------------------------------------------------
 
typedef long long ll;
typedef long double lld;
 
 
 
//---------------------------------------------------------------------------------------
 
const ll MOD1=1e9+7;
const ll MOD2=1e9+9;
ll gcd(ll a,ll b){return (b==0)?a:gcd(b,a%b);}
ll mod_add(ll a,ll b,ll m){return ((a%m + b%m)%m + m)%m;}
ll mod_sub(ll a,ll b,ll m){return ((a%m-b%m)%m + m)%m;}
ll mod_mul(ll a,ll b,ll m){return ((a%m * b%m)%m + m)%m;}
ll expo(ll a,ll b,ll m){if (b==0) return 1;ll res=expo(a,b/2,m);res=mod_mul(res,res,m);if (b & 1) res=mod_mul(a,res,m);return res;}
ll inv(ll a,ll m){return expo(a,m-2,m);}
ll mod_div(ll a,ll b,ll m){return (mod_mul(a,inv(b,m),m)+m)%m;}
 
 
void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	int sum=0;
    int mx = 0;
	for (int &i:v){
		cin>>i;
		sum+=i;
        mx = max(mx,i);
	}
	auto check=[&](int maxi){
		int sum1=v[0];
		int count=1;
		for (int i=1;i<n;++i){
			sum1+=v[i];
			if (sum1>maxi){
				sum1=v[i];
				count++;
			}
		}
 
		return (count <= k);
	};
	int l=mx-1;
	int r=sum+1;
	while (l+1<r){
		int mid=(l+r)/2;
		if (check(mid))
			r=mid;
		else
			l=mid;
	}
	cout<<r<<endl;
 
}
 
 
int32_t main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
solve();
}	