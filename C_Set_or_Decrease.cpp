#include <bits/stdc++.h>
using namespace std;
bool checker(long long mid,long long n,long long k,vector<long long>&arr,long long s){
    if(s-k<=mid){
        return true;
    }
    if(n-1<mid){
        long long m=mid-(n-1);
        arr[0]-=m;
        s-=m;
    }
    long long original=s;
    long long f=min(n-1,mid);
    for(int i=0;i<=f;i++){
        s=original;
        arr[0]-=i;
        s-=i;
        s+=arr[0]*(f-i);
        int count=f-i;
        int d=n-1;
        while(count>0){
            count--;
            s-=arr[d];
            d--;
        }
        if(s<=k){
            return true;
        }
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    vector<long long>req;
    for(int j=0;j<t;j++){
        long long n;
        long long k;
        cin>>n>>k;
        vector<long long>arr(n);
        long long s=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            s+=arr[i];
        }
        sort(arr.begin(),arr.end());
        long long l=0;
        long long r=s-k;
        long long ans=0;
        // cout<<checker(6,n,k,arr,s);
        while(l<=r){
            long long mid=(l+r)/2;
            if(checker(mid,n,k,arr,s)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        req.push_back(ans);
    }
    for(int i=0;i<t;i++){
        cout<<req[i]<<endl;
    }
    
}