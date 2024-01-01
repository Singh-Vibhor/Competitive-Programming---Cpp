#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll mod = 998244353;
int maxN = 300000 + 5;
vector<int>isprime(10000001, 1);
// int spf[1000001];
int spf[10000001];
void spf_sieve() {
    int maxn = 10000000;
    for (int i = 0; i <= maxn; i++)spf[i] = i;
    for (int i = 2; i * i <= maxn; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= maxn; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void sieve() {
    int maxn = 10000000;
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i * i <= maxn; i++) {
        if (isprime[i]) {
            for (int j = i * i; j <= maxn; j += i) {
                isprime[j] = 0;
            }
        }
    }

}
ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)res *= (a);
        b >>= 1;
        a *= (a);
    }
    return res;
}
ll power(ll a, ll b, ll mod) {
    a %= mod;
    ll res = 1;
    while (b) {
        if (b & 1)res = res * a % mod  ;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

ll inverse(ll a) {
    return power(a, mod - 2, mod);
}

vector<ll>fact(maxN, 1);
void fac() {
    fact[0] = 1;
    for (ll i = 1; i < maxN; i++) {
        fact[i] = 1ll * fact[i - 1] * i % mod;
    }
}
ll binomialCoef(ll n, ll r) {
    return fact[n] * inverse(fact[r] * fact[n - r] % mod)  % mod;
}

ll __ceil(ll a, ll b) {
    return (a + b - 1) / b;
}
/************************************************************************/
/* SOLUTION */
/************************************************************************/

void solve(vector<int>&v, int n) {
    for (int i = 0; i < n; i++)v[i] = abs(v[i]);
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll maxi = 1ll * 2 * v[i];
        auto it = upper_bound(v.begin(), v.end(), maxi);
        int idx  = it - v.begin();
        if (idx < n && v[idx] <= maxi) {
            ans += idx - i;
            continue;
        }
        if (it != v.begin()) {
            it--;
        } else {
            continue;
        }
        idx = it - v.begin();
        ans += idx - i;
    }
    cout << ans << endl;
}


int main() {
    int n;
    cin >> n;
    vector<int>v(n);
    for (auto &it : v)cin >> it;
    solve(v, n);
}