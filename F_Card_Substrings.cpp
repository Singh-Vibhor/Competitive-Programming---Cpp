#include <bits/stdc++.h>
using namespace std ;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n, m;
    cin >> n >> m ;
    string s, t ;
    cin >> s >> t ;

    map<char, int> mpp ;
    for(auto it: t){
        mpp[it]++ ;
    }

    int i = 0, j = 0 ;
    //int n = s.size() ;
    long long int cnt = 0 ;

    while(j < n){
        mpp[s[j]]-- ;

        while(mpp[s[j]] < 0){
            mpp[s[i]]++ ;
            i++ ;
        }

        cnt += (j-i+1); 
        j++ ;

    }

    cout << cnt ;

    return 0 ;
}