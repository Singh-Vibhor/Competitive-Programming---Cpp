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

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    fr (0, n) cin >> arr[i];

    int i = 0;
    multiset<int> st;

    vector<int> ans;

    for (int j = 0; j < n; j++) {
        st.insert(arr[j]);
        if (arr[j] == *(st.begin()) or arr[j] == *(st.rbegin())) continue;

        while (i <= j - 2 and (arr[i] == *(st.begin()) or arr[i] == *(st.rbegin()))) {
            st.erase(st.lower_bound(arr[i]));
            i++;
        }

        if (st.empty() == false and arr[i] != *(st.begin()) and arr[i] != *(st.rbegin()) and arr[j] != *(st.begin()) and arr[j] != *(st.rbegin())) {
            ans.pb(i + 1);
            ans.pb(j + 1);
            break;
        }
    }

    if (ans.size() == 0) {
        cout << -1 << nline;
    }
    else {
        cout << ans[0] << ' ' << ans[1] << nline;
    }
}

int main() {
    // init_code();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}