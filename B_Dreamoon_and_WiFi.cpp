#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using i64 = long long;
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

long long int nCr(int n, int r) {
    if (r > n) return 0;
    if (r * 2 > n) r = n - r;
    if (r == 0) return 1;

    long long int result = n;
    for (int i = 2; i <= r; ++i) {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int count = 0, count1 = 0, c = 0;

    for (char ch : s1) {
        if (ch == '+') count++;
    }
    for (char ch : s2) {
        if (ch == '+') count1++;
        else if(ch=='?') c++;
    }
    // cout<<s1.size()-count<<" "<<s1.size()-count1+c<<endl;
    if((count > count1+c) || ((s1.size()-count)> (s1.size()-count1))){
        cout << fixed << setprecision(15) << 0.0 << endl;
        return 0;
    }

    if (count - count1 == 0 && c == 0) {
        cout << fixed << setprecision(15) << 1.0 << endl;
    } else if (count - count1 == 0 && c != 0 and count!=0) {
        // if (c % 2 == 0) {
            cout << fixed << setprecision(15) << nCr(c, c / 2) / pow(2, c) << endl;
        // } else {
        //     cout << fixed << setprecision(15) << 0.0 << endl;
        // }
    } else {
        if (c != 0 && abs(count - count1) <= c) {
            cout << fixed << setprecision(15) << nCr(c, abs(count - count1)) / pow(2, c) << endl;
        } else {
            cout << fixed << setprecision(15) << 0.0 << endl;
        }
    }

    return 0;
}