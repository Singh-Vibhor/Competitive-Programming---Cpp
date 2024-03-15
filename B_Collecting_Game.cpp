#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],fd[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            fd[i]=a[i];
        }
        sort(a,a+n);
        vector<int>b;
        int ui=0;
        for(int i=0;i<n;i++){
            ui+=a[i];
            b.push_back(ui);
        }
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            if(i+1!=n){
                int x,y;
                x=b[i];
                y=a[i+1];
                if(x>=y){
                    v.push_back(make_pair(i,1));
                }else{
                    v.push_back(make_pair(i,0));
                }
            }else{
                v.push_back(make_pair(i,0));
            }
        }
        int op;
        op=v.size();
        for(int i=op-2;i>=0;i--){
            if(v[i].second==1){
                v[i].first=v[i+1].first;
            }
        }
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[fd[i]].push_back(i);
        }
        vector<int>praga(n,0);
        for(int i=0;i<n;i++){
            if(i>0  and a[i] == a[i-1]) continue;
            for(auto jk: mp[a[i]])
            praga[jk]=v[i].first;
        }
        for(auto x:praga){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}