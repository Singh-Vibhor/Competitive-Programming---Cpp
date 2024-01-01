#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define _test int _TEST; cin >> _TEST; while (_TEST--)
#define endl "\n"

void solve() {
    // cout<<5<<endl;
    ll a, b;
    cin >> a >> b;
    ll c = 0;
    ll d = 1;
    while (true) {
        if (d % a != 0) {
            c++;
        }
        if (c == b) {
            cout << d << endl;
            break;
        }
        d++;
    }
}

int main() {
    _test {
        solve();
    }
    return 0;
}