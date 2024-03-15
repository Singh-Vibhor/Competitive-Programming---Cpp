#define _CRT_SECURE_nO_WaRnInGS
#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define sayed ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define ull unsigned long long
#define sz(d) d.size()
#define ll long long
#define dd double
#define el "\n"
#define sp " "
#define int long long
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve();
signed main()
{
    sayed;
    int T = 1;
    while (T--)
        solve();
    return 0;
}
const int N = 1e5 + 5;
vector<ll> prime;
vector<bool> primes(N, 1);
void sieve()
{
    primes[0] = primes[1] = 0;
    for (ll i = 2; i * i <= N; i++)
    {
        if (primes[i])
        {
            for (ll j = i * i; j <= N; j += i)
            {
                primes[j] = 0;
            }
        }
    }
    prime.push_back(2);
    for (int i = 3; i < N; i += 2)
        if (primes[i])
            prime.push_back(i);
}
void solve()
{
    sieve();
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int sumRow = 0;
        for (int j = 0; j < m; j++)
        {
            if (!primes[arr[i][j]])
            {
                int low = *lower_bound(all(prime), arr[i][j]);
                sumRow += (low - arr[i][j]);
            }
        }
        if (sumRow < mn)
            mn = sumRow;
    }
    int mnn = INT_MAX;
    for (int j = 0; j < m; j++)
    {
        int sumCol = 0;
        for (int i = 0; i < n; i++)
        {
            if (!primes[arr[i][j]])
            {
                int low = *lower_bound(all(prime), arr[i][j]);
                sumCol += (low - arr[i][j]);
            }
        }
        if (sumCol < mnn)
            mnn = sumCol;
    }
    cout << min(mn, mnn);
}

