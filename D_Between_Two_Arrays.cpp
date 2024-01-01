#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
const int mod = 998244353;


void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    int m = b[n - 1];

    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));

    for (int i = a[0]; i <= b[0]; i++)
    {
        dp[1][i] = 1;
    }


    for (int i = 1; i <= m; i++)
    {
        dp[1][i] += dp[1][i-1];
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j <= b[i-1])
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod; 
        }
    }

    int ans = dp[n][m];

    // for (int i = a[n-1]; i <= b[n-1]; i++)
    // {
    //     ans = (ans + dp[n][i]) % mod;
    // }
    // for(int i=0; i<=n; i++){
    //     for (int j = 0; j<=m; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);

    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}