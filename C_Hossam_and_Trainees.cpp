#include<bits/stdc++.h>
using ll = long long;
using lli = long long int;
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define nline '\n'
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // *find_by_order, order_of_key

template <typename... T>
void read(T &...args) {
	((cin >> args), ...);
}

void init_code() {
	fast_io;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

vector<int> primes;
std::vector<bool> isPrime(1e5 + 1, true);

void seive() {
	for (ll i = 2; i <= 1e5 + 1; i++) {
		if (isPrime[i]) {
			primes.pb(i);
			for (ll j = i * i; j <= 1e5 + 1; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

void solve() {
	int n; cin >> n;
	vector<int> arr(n);
	fr (0, n) cin >> arr[i];
    cout<<primes.size()<<endl;

	map<int, int> mp;

	for (int i = 0; i < n; i++) {
		for (auto prime : primes) {
			if (arr[i] % prime == 0) {
				mp[prime]++;

				while (arr[i] % prime == 0) {
					arr[i] = arr[i] / prime;
				}

			}
		}
        if (arr[i] > 1) {
			mp[arr[i]]++;
		}

	}

	for (auto e : mp) {
        // cout<<e.first<<" "<<e.second<<endl;
		if (e.second >= 2) {
			cout << "YES" << nline;
			return;
		}
	}

	cout << "NO" << nline;
}

int main() {
	// init_code();

	int t;
	cin >> t;

	seive();

	while (t--) {
		solve();
	}

	return 0;
}
