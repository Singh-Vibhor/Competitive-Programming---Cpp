#include <bits/stdc++.h>
using namespace std;
using ip = pair<int, int>;

void solve() {
    priority_queue <ip, vector<ip>, greater<ip>> pq;

    int n, m;
    cin >> n >> m;

    int tempfirst = 0, tempsecond = 0;
    for (int i = 1; i <= m; i++)
        pq.push(make_pair(0, i));

    for (int i = 1; i <= n; i++) {
        vector<pair<int, int>> ts;
        auto cp = pq.top();
        // cout<<"hi"<<cp.first<<" "<<cp.second<<endl;
        // cout<<"HI"<<pq.size()<<endl;
        ts.push_back(cp);
        pq.pop();

        int cf = cp.first;
        tempfirst = cp.first+1;
        tempsecond = cp.second;
        int flag = 0;
        int chks = abs(((m + 1) / 2) - cp.second);
        int j = 1;
        while (!pq.empty()) {
            j++;
            if (j>10) break;
            auto fp = pq.top();
            // cout<<i<<" "<<fp.first<<" "<<fp.second<<" "<<pq.size()<<endl;
            pq.pop();
            ts.push_back(fp);

            if (fp.first == cf) {
                if (abs(((m + 1) / 2) - fp.second) < chks) {
                    chks = abs(((m + 1) / 2) - fp.second);
                    tempfirst = fp.first + 1;
                    tempsecond = fp.second;
                }
                else {
                    pair<int,int> p1 = make_pair(tempfirst,tempsecond);
                    pq.push(p1);
                    // cout<<pq.size()<<endl;
                    break;
                }  
            } else {
                pair<int,int> p1 = make_pair(tempfirst,tempsecond);
                pq.push(p1);
                // cout<<pq.size()<<endl;
                break;
            }
        }
        for (auto x : ts) {
            if (x.second != tempsecond)
                pq.push(x);
            // cout<<"jo"<<pq.size()<<endl;
        }

        ts.clear();
        cout << tempsecond << " "<<endl;
    }
}

int main() {
    int t = 1;
    while (t--) {
        solve();
        cout << "\n";
    }

    return 0;
}