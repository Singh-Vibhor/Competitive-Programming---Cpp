#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define ull unsigned long long
 
const ll INF = INT_MAX;
const ll mod = 1e9 + 7;
 
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;
typedef set<ll> sll;
typedef unordered_set<ll> usll;
 
 
#define pb push_back
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define rrep(i,x,y) for(ll i=x;i>=y;i--)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
 
ll gcd(ll a, ll b) {if (b == 0)return a; return gcd(b, a % b);}
 
bool isPrime(ll n) {if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false; for (int i = 5; i * i <= n; i = i + 6)if (n % i == 0 || n % (i + 2) == 0)return false; return true;}
bool isPowerOfTwo(ll x) {if (x == 0)return false; return (x & (x - 1)) == 0;}
bool isPerfectSquare(ll x) {if (x >= 0) {ll sr = sqrt(x); return (sr * sr == x);} return false;}
bool sortfa(const pair<int, int> &a, const pair<int, int> &b) {return (a.first < b.first);}
bool sortfsa(const pair<int, int> &a, const pair<int, int> &b) {if (a.first == b.first) {return (a.second < b.second);} else {return (a.first < b.first);}}
bool sorta(const pair<int, int> &a, const pair<int, int> &b) {return (a.second < b.second);}
bool sortd(const pair<int, int> &a, const pair<int, int> &b) {return (a.second > b.second);}
 
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v) {for (auto &it : v)cin >> it; return istream;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
template <typename T> // cout << set<T>
ostream& operator<<(ostream& os, const set<T>& v) {for (auto it : v) {os << it; if (it != *v.rbegin())os << " ";} os << "\n"; return os;}
template <typename T, typename S> // cout << map<T,S>
ostream& operator<<(ostream& os, const map<T, S>& v) {for (auto it : v) os << it.first << " " << it.second << "\n"; return os;}
 
const ll N = 30001;
ll n;
void build(ll index, ll start, ll end, vll *segTree, vll &arr) {
    if (start == end) {
        segTree[index].pb(arr[start]);
        return;
    }
    ll mid = (start + end) / 2;
    build(2 * index, start, mid, segTree, arr);
    build(2 * index + 1, mid + 1, end, segTree, arr);
    ll i = 0; ll j = 0;
    while (i < segTree[2 * index].size() && j < segTree[2 * index + 1].size()) {
        if (segTree[2 * index][i] <= segTree[2 * index + 1][j]) {
            segTree[index].pb(segTree[2 * index][i]);
            i++;
        }
        else {
            segTree[index].pb(segTree[2 * index + 1][j]);
            j++;
 
        }
 
    }
    while (i < segTree[2 * index].size()) {
        segTree[index].pb(segTree[2 * index][i]);
        i++;
    }
    while (j < segTree[2 * index + 1].size()) {
        segTree[index].pb(segTree[2 * index + 1][j]);
        j++;
    }
 
}
ll query(ll index, ll start, ll end, ll l, ll r, ll k, vll *segTree, vll &arr) {
 
    if (start > r || end < l) {
        return 0;
    }
    if (start >= l && end <= r) {
        return segTree[index].end() - upper_bound(segTree[index].begin(), segTree[index].end(), k) ;
 
    }
    ll mid = (start + end) / 2;
    ll left = query(2 * index, start, mid, l, r, k, segTree, arr);
    ll right = query(2 * index + 1, mid + 1, end, l, r, k, segTree, arr);
    return left + right;
 
}
 
void solve() {
    ll m;
    cin >> n;
    vll segTree[4 * (n+1)];
    vll arr(n+1);

    rep(i, 1, n + 1) {
        cin >> arr[i];
    }
    build(1, 1, n, segTree, arr);
    cin >> m;
    while (m--) {
        ll p, q, k;
        cin >> p >> q >> k;
        cout << query(1, 1, n, p, q, k, segTree, arr) << endl;
 
    }
 
 
 
 
 
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
