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

void solve(vector<int>&v, int n) {
    ll sum = 0;
    vector<int>ans(n);
    multiset<int>st;
    for (int i = 0; i < n; i++)st.insert(v[i]);

    ans[0] = *st.begin();
    st.erase(st.begin());
    sum = ans[0];
    int k = 1;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        auto it = upper_bound(st.begin(), st.end(), sum);
        if (it == st.end()) {
            for (auto it1 : st){
                ans[k] = it1;
                cnt++;
                k++;
            }
            break;

        } else {
            ans[k] = *it;
            sum += ans[k];
            st.erase(st.find(*it));
        }
        k++;
    }
    cout << cnt << endl;
    for (auto it : ans)cout << it << " ";
    cout << endl;
    
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>v(n);
        for (auto &it : v)cin >> it;
        solve(v, n);
    }
}
