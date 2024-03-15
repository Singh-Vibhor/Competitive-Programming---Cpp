#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
#define vl vector<ll>
#define vvl vector<vl>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int check(ll mid, vl v, int n){
    vl dp(n,0);
    multiset<ll> st;
    st.insert(0);
    dp[0] = v[0];
    st.insert(dp[0]);
    int p1=0, p2 = 0;
    int f = 1;
    ll sum = 0;
    while(p2<n-1){
        sum += v[p2];
        p2++;
        if (sum>mid and f) st.erase(0);
        while (sum-v[p1]>mid){
            sum -= v[p1];
            st.erase(dp[p1]);
            p1++;
        }
        auto it = st.begin();
        dp[p2] = *it + v[p2];
        st.insert(dp[p2]);
    }
    sum = 0;
    for(int i=n-1; i>=0; i--){
        if (sum>mid) return 0;
        if (dp[i]<=mid) return 1;
        sum += v[i];
    }
    return 0;
}

void solve()
{
            int n;
        cin >> n;
        int64_t a[n+1];
        for(int i = 0;i < n;++i)
        {
            cin >> a[i];
        }
        int64_t l = 0,r = int64_t(1e9)*n;
        while(l < r)
        {
            int64_t m = (l+r)/2;
            set<pair<int64_t,int>> pos;
            int64_t dp[n+1];
            int p2 = n;
            dp[n] = 0;
            pos.insert({dp[n],n});
            int64_t sum = 0;
            for(int j = n-1;j >= 0;--j)
            {
                while(sum > m)
                {
                    sum -= a[p2-1];
                    pos.erase({dp[p2],p2});
                    p2--;
                }
                dp[j] = pos.begin()->first + a[j];
                pos.insert({dp[j],j});
                sum += a[j];
            }
            sum = 0;
            int yes = 0;
            for(int j =0;j < n;++j)
            {
                if(sum <= m && dp[j] <= m)
                    yes = 1;
                sum += a[j];
            }
            if(yes)
                r = m;
            else
                l = m+1;
        }
        cout << l << "\n";

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