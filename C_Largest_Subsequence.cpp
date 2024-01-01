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
    vector<char> ch;
    map<int,int> ind;
    ind[n-1] = 1;
    char prv = s[n-1];
    string s1 = "";
    s1 += s[n-1];
    int ans = 0;
    rrep(i,n-1){
        if (s[i]>=prv){
            ans++;
            prv = s[i];
            ind[i] = 1;
            s1+=s[i];
        }
    }
    int cnt = count(s.begin(), s.end(), prv);
    ans -= (cnt-1);
    int p1 = 0;
    rep(i,n){
        if (ind.find(i)==ind.end()){
            ch.push_back(s[i]);
        }
        else{
            ch.push_back(s1[p1]);
            p1++;
        }

        if (ch[max(0,i-1)]>ch[i]){
            cout<<-1<<endl;
            return;
        }
    }
    // for (auto it: ch) cout<<it<<endl;
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