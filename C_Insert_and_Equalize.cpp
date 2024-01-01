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
    vi arr(n); rep(i,n) cin>>arr[i];
    sort(all(arr));

    int gcd = abs(arr[1] - arr[0]);
    for (int i=1; i<n; i++){
        gcd = __gcd(gcd, abs(arr[i] - arr[i - 1]));
    }

    int high  = arr[n-1];
    ll ans = 0;
    for (int i = 0; i < n -1; i++) ans += (high-arr[i])/gcd;
    int ptr = n-2;
    for (int i=1; i<=n; i++){
        if (ptr >= 0 && (high - i*gcd) == arr[ptr]) {
            ptr--;
            continue;
        }
        ans+=i;
        break;
    }

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