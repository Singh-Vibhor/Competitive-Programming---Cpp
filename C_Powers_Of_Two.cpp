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
    int n,k;
	cin>>n>>k;
	if (n<k){
		cout<<"NO"<<endl; return;
	}
	vector<int> ans;
	for(int i=0; i<32; i++){
		if(n & 1<<i) ans.push_back(1<<i);
	}
	int size = ans.size();
	if (size>k){
		cout<<"NO"<<endl;
		return;
	}
	int ptr = 0;
	while (size<k){
		while (ans[ptr] == 1) ptr++;
		ans[ptr] /= 2;
		ans.push_back(ans[ptr]);
		size++;
	}
	cout<<"YES"<<endl;
	rep(i,k) cout<<ans[i]<<" ";
	cout<<endl;
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