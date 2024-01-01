#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    stack<char> st;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        while (st.size() >= 2)
        {
            int flag=0;
            char b = st.top();
            st.pop();
            char a = st.top();
            st.pop();
            // cout << b << " " << a << endl;
            if (a == 'A' && b == 'B')
            {
                count++;
                flag=1;
                st.push('B');
                st.push('C');
            }
            else if (a == 'B' && b == 'A')
            {
                count++;
                flag=1;
                st.push('C');
                st.push('B');
            }
            else
            {
                st.push(a);
                st.push(b);
            }
            // cout<<flag<<endl;
            if(!flag)
            break;
        }
        st.push(s[i]);
    }
    while (st.size() >= 2)
        {
            int flag=0;
            char b = st.top();
            st.pop();
            char a = st.top();
            st.pop();
            // cout << b << " " << a << endl;
            if (a == 'A' && b == 'B')
            {
                count++;
                flag=1;
                st.push('B');
                st.push('C');
            }
            else if (a == 'B' && b == 'A')
            {
                count++;
                flag=1;
                st.push('C');
                st.push('B');
            }
            else
            {
                st.push(a);
                // st.push(b);
            }
            // cout<<flag<<endl;
            // if(!flag)
            // break;
        }
    reverse(all(s));
    int count1 = 0;
    stack<char> st2;
    for (int i = 0; i < n; i++)
    {
        while (st2.size()>=2)
        {
            int flag=0;
            char b = st2.top();
            st2.pop();
            char a = st2.top();
            st2.pop();
            // cout << b << " " << a << endl;
            if (a == 'A' && b == 'B')
            {
                flag=1;
                count1++;
                st2.push('B');
                st2.push('C');
            }
            else if (a == 'B' && b == 'A')
            {
                flag=1;
                count1++;
                st2.push('C');
                st2.push('B');
            }
            else
            {
                st2.push(a);
                st2.push(b);
            }
            if(!flag)
            break;
        }
        st2.push(s[i]);
    }
    while (st2.size()>=2)
        {
            int flag=0;
            char b = st2.top();
            st2.pop();
            char a = st2.top();
            st2.pop();
            // cout << b << " " << a << endl;
            if (a == 'A' && b == 'B')
            {
                flag=1;
                count1++;
                st2.push('B');
                st2.push('C');
            }
            else if (a == 'B' && b == 'A')
            {
                flag=1;
                count1++;
                st2.push('C');
                st2.push('B');
            }
            else
            {
                st2.push(a);
                // st2.push(b);
            }
            // if(!flag)
            // break;
        }
    cout << max(count, count1) << endl;
}