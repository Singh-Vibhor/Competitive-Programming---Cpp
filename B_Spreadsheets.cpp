#define ll long long
#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve(){
    string s;
    cin>>s;
    int type_two=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='R'){
            type_two++;
        }
        if(s[i]=='C'){
            type_two++;
        }
    }
    if(type_two==2){
        if(s[0]=='R' and 9>=s[1]-'0' and s[1]-'0'>=0){
            int index_r=0;
            int index_c=0;
            for(int i=0;i<n;i++){
                if(s[i]=='C'){
                    index_c=i;
                    // cout<<index_c<<endl;
                    break;
                }
            }
            int first_no=0;
            int second_no=0;
            for(int i=1;i<index_c;i++){
                first_no+=(s[i] - '0')*(pow(10,index_c-i-1));
            }
            for(int i=index_c+1;i<n;i++){
                second_no+=(s[i] - '0')*(pow(10,n-i-1));
            }
            string num= "";
            while(second_no>0){
                int ascii=second_no%26;
                if (ascii==0){ascii = 26; second_no--;}
                num=char(ascii + 64) + num;
                second_no/=26;
            }
            cout<<num<<first_no<<"\n";
            return;
        }
    }
//bc23 type
    int index_num=0;
    for(int i=0;i<n;i++){
        if(9>=s[i]-'0' and s[i] - '0'>=0){
            index_num=i;
            // cout<<i<<endl;
            break;
        }
    }
    int first_no = 0;
    for(int i=index_num;i<s.size();i++){
        first_no+=(s[i]-'0')*pow(10,s.size()-i-1);
    }
    int second_no=0;
    for(int i=0;i<index_num;i++){
        second_no+=(s[i]-'A'+1)*(pow(26,index_num-i-1));
    }

    cout<<'R'<<first_no<<'C'<<second_no<<"\n";

    
}

int32_t main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}