#include <bits/stdc++.h>
#include <vector>
using namespace std;

const long long mxN = 1e5 + 5;
vector<long long> mnTree;
vector<long long> lzy;
vector<long long>fin;
long long n;
#define ll long long


void pass(long long ind, long long st, long long endd) {
    if (lzy[ind] != 0) 
    {
        long long mid = (st + endd) >> 1;
        if (st != endd) {
            // mnTree[ind] += lzy[ind];
            lzy[(ind << 1)] += lzy[ind];
            lzy[(ind << 1) | 1] += lzy[ind];
            mnTree[(ind << 1)] += lzy[ind];
            mnTree[(ind << 1) | 1] += lzy[ind];
        }
        lzy[ind] = 0;
    }
}

void query(long long val, long long idx= 1, long long st = 0, long long endd = n - 1) 
{
    pass(idx, st, endd);
    
    if(st==endd)
    {
      fin[st]=mnTree[idx];
      return;
    }
    ll mid=(st+endd)/2;
    query(val,idx*2,st,mid);
    query(val,1+idx*2, mid+1,endd);
}

void update(long long ql, long long qr, long long val, long long ind = 1, long long st = 0, long long endd = n - 1) 
{
    if (st > qr or endd < ql) {
        return;
    }
    pass(ind, st, endd);

    if (st >= ql and endd <= qr) {
        lzy[ind]+= val;
        return;
    }
    long long mid = (st + endd) >> 1;
    update(ql, qr, val, ind << 1, st, mid);
    update(ql, qr, val, (ind << 1) | 1, mid + 1, endd);
    mnTree[ind] = min(mnTree[ind << 1], mnTree[(ind << 1) | 1]);
}

int main() 
{
    long long m;
    std::cin >> n >> m;
    vector<ll> v(n);
    lzy.resize(4*n+1,0);
    mnTree.resize(4*n+1,0);
    fin.resize(n,0);
    for(int i=0;i<n;i++)
    {
      cin>>v[i];
    }
    
    for (long long i = 0; i < m; ++i) {
      ll l,r;
      cin>>l>>r;
      l--;
      r--;
      update(l,r,1);
    }
    sort(v.begin(),v.end());
    ll ans=0;
    query(1);
    sort(fin.begin(),fin.end());
    for(int i=0;i<n;i++)
    {
      ans+=fin[i]*v[i];
    }
    for(auto it: fin){
        cout<<it<<" ";
    }
    cout<<endl;
    
    cout<<ans<<endl;
    
    
    return 0;
}