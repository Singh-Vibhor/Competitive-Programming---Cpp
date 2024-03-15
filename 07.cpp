#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define agam_gupta

#define endl '\n'
#define ll long long
#define MP make_pair
#define pb push_back
#define ppb pop_back
#define FOR(i, a, n) for(ll i = (a); i <= (n); i++)
#define FORD(i, a, n) for(ll i = (a); i >= (n); i--)
#define all(v) (v).begin(), (v).end()
#define sz(v) (ll)(v).size()
#define MOD 1000000007
#define INF (ll)1e18

#ifdef agam_gupta
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key


void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(float t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned ll t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


/******************************INTERACTOR************************************/
/*struct Interactor{
	ll n;
	vector<ll> v;
	Interactor(ll n, vector<ll> &v){
		this->n = n;
		this->v = v;
	}

	ll make_query(int l, int h){
		return v[l]+v[h];
	}
};
ll make_query(int l, int h){
	cout << "? " << l << " " << h << endl;

	int idx;
	cin>>idx;

	return idx;
}*/
/******************************INTERACTOR************************************/


/******************************UTILITY************************************/
ll mod_mul(ll a, ll b, ll m){ return (a%m * b%m)%m; }
ll mod_sub(ll a, ll b, ll m){ return (((a%m - b%m)%m)+m)%m; }
ll mod_expo(ll a, ll b, ll mod){ ll ans = 1; while(b){ if(b&1) ans = (ans*a)%mod; a = (a*a)%mod; b >>= 1; } return ans%mod; }
ll expo(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b&1) ans = (ans*a);
		a = (a*a);
		b >>= 1;
	}
	return ans;
}
ll gcd(ll a, ll b) { if(b == 0) return a; return gcd(b, a % b); } 
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

vector<ll> Prime;
void sieve(ll n){
	Prime.resize(n+1, 1);

	Prime[0] = Prime[1] = 0;
	// NLog(LogN)
	FOR(i, 2, n){
		if(Prime[i] == 1){
			Prime[i] = i;
			// start from i*i not from 2*i
			for(ll j = i*i; j <= n; j += i){
				Prime[j] = i;
			}
		}
	}
}
/******************************UTILITY************************************/





vector<pair<ll, pair<ll,ll>>> v;
ll dp[201][1001][12][2][2][3][3];

ll solve(ll i, ll b, ll selected, bool wk, bool all, ll bt, ll bw, ll n){
	if(selected > 11LL) return INT_MIN;

	if(i >= n){
		return ((selected==11) && wk && all && bt==2 && bw==2)?0:INT_MIN;
	}

	if(dp[i][b][selected][wk][all][bt][bw] != -1)
		return dp[i][b][selected][wk][all][bt][bw];

	ll op1 = solve(i+1, b, selected, wk, all, bt, bw, n);


	ll t = v[i].first;
	ll p = v[i].second.first;
	ll val = v[i].second.second;
	ll op2 = INT_MIN;

	if(p <= b){
		op2 = val + solve(
				i+1,
				b-p, 
				selected+1, 
				wk|(t==0), 
				all|(t==3),
				(t==1)?min(2LL,bt+1):bt,
				(t==2)?min(2LL,bw+1):bw,
				n
			);
	}

	return dp[i][b][selected][wk][all][bt][bw] = max(op1, op2);
}

void run(){
	ll n;
	cin>>n;

	vector<int> price(n);
	FOR(i, 0, n-1) cin>>price[i];
	ll twenty = ceil(n*2*1.0 / 10.0);
	// cout<<twenty<<endl;
	FOR(i, 0, n-1){
		int value; cin>> value;
		int type;
		if(i <= twenty) type = 0;
		else if (i&1) type = 1;
		else if(i%4 == 0) type = 3;
		else type = 2;

		v.pb(MP(type, MP(price[i], value)));
	}
	ll budget;cin>>budget;


	memset(dp, INT_MIN, sizeof dp);


	dp[n][budget][0][0][0][0][0] = 0;

	// iterative dp
	for(ll i = n; i > 0; i--){
		for(ll b = 0; b <= budget; b++){
			for(ll selected=10; selected >= 0; selected--){

				for(ll bt = 2; bt >= 0; bt--){
					for(ll bw = 2; bw >= 0; bw--){
						for(ll wk = 1; wk >= 0; wk--){
							for(ll all = 1; all >= 0; all--){
								if(dp[i][b][selected][wk][all][bt][bw] == INT_MIN) continue; 

								dp[i-1][b][selected][wk][all][bt][bw] = max(dp[i-1][b][selected][wk][all][bt][bw] , dp[i][b][selected][wk][all][bt][bw]);

								ll t = v[i-1].first;
								ll p = v[i-1].second.first;
								ll val = v[i-1].second.second;

								if(b-p >= 0){
										dp[i-1][b-p][selected+1][wk|(t==0)][all|(t==3)][(t==1)?min(2LL,bt+1):bt][(t==2)?min(2LL,bw+1):bw] = 
									max(dp[i-1][b-p][selected+1][wk|(t==0)][all|(t==3)][(t==1)?min(2LL,bt+1):bt][(t==2)?min(2LL,bw+1):bw], 
									val+dp[i][b][selected][wk][all][bt][bw]);
								}
							}
						}
					}
				}
			}
		}
	}

	ll ans = INT_MIN;
	for(ll b = 0; b <= budget; b++){
        // cout<<dp[0][b][1][1][1][2][2]<<endl;
		ans = max(ans, dp[0][b][11][1][1][2][2]);
	}

	if(ans <= 0) {
		cout << "Insufficient Budget" << endl;
	}
	else{
		cout << ans << endl;
	}
}

int main(){
#ifdef agam_gupta
    freopen("debug.txt", "w", stderr);
#endif
	ios::sync_with_stdio(false); cin.tie(NULL);


	int t = 1;
	// cin >> t;

	while(t--){
		run();
	}


	return 0;
}
