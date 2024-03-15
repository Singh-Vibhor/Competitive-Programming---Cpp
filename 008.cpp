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

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i  = 0;i < n; i++){
        cin >> arr[i];
    }

    stack<pair<int,int>>st;
    st.push(make_pair(INT_MIN,-1));
    vector<int> leftValue(n,0);
    for(int i=0; i<n; i++){
        pair<int,int> it = st.top();
        while(arr[i]<it.first) {
            st.pop();  it = st.top();
        }
        leftValue[i] = it.second;   st.push( make_pair(arr[i],i) );
    }


    stack<pair<int,int>>st2;
    st2.push( make_pair( INT_MIN,n ));
    vector<int> rightValue(n,0);
    for(int i=n-1; i>=0; i--){
        pair<int,int> it = st2.top();
        
        while(arr[i]<it.first) {
            st2.pop();  it = st2.top();
        }
        rightValue[i] = it.second; st2.push(make_pair(arr[i],i));
    }
    vector<pair<int , int> > vp;
    for(int i = 0; i < n; i++){
        vp.push_back(make_pair(arr[i] , rightValue[i] - leftValue[i] - 1 ) );
    }
    sort(vp.begin() , vp.end() );
    reverse(vp.begin() , vp.end() );
    vector<int> ans(n+1 , -1);
    int pt = 0;
    for(int i=1; i<=n; i++){
        while(vp[pt].second<i) 
            pt++;
        ans[i-1] = vp[pt].first;
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] <<" ";
    }
}



int32_t main()
{
    ioset
    int t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}