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
    vi a(n),b(n);
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    
    rep(i,n){
        
        if (a[i]>b[i]){
            cout<<"NO"<<endl;
            return;
        }

        if (a[i]==b[i]) continue;

        bool f = false;
        for (int j=i-1; j>=0; j--){
            if (a[j] == b[i]){
                f=true; break;
            }
            if (a[j] > b[i] || b[j] < b[i]) break;
        }

        for (int j=i+1; j<n; j++){
            if (a[j] == b[i]){
                f=true; break;
            }
            if (a[j] > b[i] || b[j] < b[i]) break;
        }

        if (!f){
            cout<<"NO"<<endl;
            return;
        }

    }
    cout<<"YES"<<endl;
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