#include <bits/stdc++.h>
using namespace std;
bool poss(long long mid, vector<pair<long long,long long>> wf, long long x2, long long y2,long long x1,long long y1){
    long long n=wf.size();
    long long xf= x1 + (mid/n)*wf[n-1].first;
    long long yf= y1 + (mid/n)*wf[n-1].second;
    if(mid%n!=0){
        xf+=(wf[mid%n-1].first);
        yf+=(wf[mid%n-1].second);
    }
    long long dis=(abs(x2-xf)+abs(y2-yf));
    return dis<=mid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long x1,y1;
    cin>>x1>>y1;
    long long x2,y2;
    cin>>x2>>y2;
    long long n;
    cin>>n;
    string wind;
    cin>>wind;
    long long xf=0,yf=0;
    vector<pair<long long,long long>> wf(n);
    for(long long i=0;i<n;i++){
        if(wind[i]=='L') xf--;
        else if(wind[i]=='R') xf++;
        else if(wind[i]=='D') yf--;
        else yf++;
        wf[i]={xf,yf};
        // cout<<wf[i].first<<" "<<wf[i].second<<endl;
    }
    long long l=1;
    long long r=1e15;
    long long ans=-1;
    while(l<=r){
        long long mid=(l+r)/2;
        if(poss(mid,wf,x2,y2,x1,y1)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;

    return 0;
}
