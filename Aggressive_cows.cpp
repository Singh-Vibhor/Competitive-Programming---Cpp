// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool isPossible(long long minDis,set<long long>&pos ,long long k){
    long long cnt=1;
    auto it=pos.begin();
    long long prev_pos=*it;
    it++;
    for(it;it!=pos.end();it++){
        long long c_pos=*it;
        if((c_pos-prev_pos)>=minDis){
            prev_pos=c_pos;
            cnt++;
        }
    }
    if(cnt>=k)return true;
    return false;
}
void solve(){
    
    long long n,c;cin>>n>>c;
    set<long long>set1;
    for(long long i=0;i<n;i++){
        long long val;cin>>val;
        set1.insert(val);
    }
    long long lo=0,hi=1e18;
    long long ans=lo;
    //binary search on distance
    while(lo < hi - 1){
        long long midDis=lo+(hi-lo)/2;
        if(isPossible(midDis,set1,c)){
            ans=midDis;
            lo=midDis;
        }else{
            hi=midDis;
        }
    }
    cout<<lo;
}
int main() {
    // Write C++ code here
   
    long long t;cin>>t;
    while(t-->0){
        solve();
    }

    return 0;
}