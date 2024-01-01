#include <bits/stdc++.h>

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

using namespace std;

long long solve(int* arr, int n, int k)
{
    long long chocolate_distribution = -1;
    chocolate_distribution = INT_MAX;
    if (k == 0 || n == 0)
        return 0;
 
    sort(arr, arr + n);
 
    if (n < k)
        return -1;
 
    for (int i = 0; i + k - 1 < n; i++) {
        int diff = arr[i + k - 1] - arr[i];
        if (diff < chocolate_distribution)
            chocolate_distribution = diff;
    }
    return chocolate_distribution;
}


int32_t main()
{
    ioset
    int t;
    t = 1;
    int arr[] = {1,2,3,4,5,6,7,8,9,18};
    int n = 10, k = 8;
    while(t--)
    {
        cout << solve(arr,n,k);
    }
    return 0;
}