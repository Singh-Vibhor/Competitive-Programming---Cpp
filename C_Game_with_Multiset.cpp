#include <bits/stdc++.h>
#include <string>

#define ll long long
#define pb push_back
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(7) << x
#define triplet pair<ll, pair<ll, ll>>
#define goog(tno) cout << "Case #" << tno << ": "
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define read(x) \
    int x;      \
    cin >> x
#define vi vector<int>
#define vli vector<ll int>
typedef long double lld;
const double PI = 3.14159265359;
using namespace std;

void init_code()
{
    fast_io;
}
multiset<ll int> s;
bool search(multiset<ll int> &s,ll int x){
    while(x>0){
        ll int ok = *s.lower_bound(x);
        if(ok==x)return true;
        auto it = s.lower_bound(x); 
        it--;
        // cout<<x<<" "<<(*it)<<endl;
        x-=(*it);
    }
    return false;
}
void solve()
{
    s.clear();
    read(m);
    while(m--){
        int t;
        cin>>t;
        ll int v;
        cin>>v;
        if(t&1)s.insert(1<<v);
        else{
            if(search(s,v)){
                cout<<"YES"<<endl;
                continue;
            }
            else{
                cout<<"NO"<<endl;
                continue;
            }
        }
    }
    return;
}
// main function
int32_t main()
{
    init_code();
    // ll int tno;
    // cin >> tno;
    // while (tno--)
    // {
    //     solve();
    // }
    solve();

    return 0;
};