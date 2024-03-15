#include <bits/stdc++.h>
#define ll long long int
#define TxtIO                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
using namespace std;

ll dr[4] = {-1, 0, 1, 0};
ll dc[4] = {0, 1, 0, -1};
ll dp[1001][1001][4][3];

bool dfs(ll si, ll sj, ll ei, ll ej,ll turns, ll n, ll m, ll dir,vector<vector<char>>& a)
{
    // if (dp[si][sj][dir][turns]==1) return false; 
    dp[si][sj][dir][turns] = 1;
    if (si == ei && sj == ej && turns <= 2)
    {
        return true;
    }
    for (ll i = 0; i < 4; i++)
    {

        ll nr = si + dr[i];
        ll nc = sj + dc[i];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m && dp[nr][nc][dir][turns] == -1 && a[nr][nc]!='*')
        {
            
            ll cdir;
            if (i == 0)
            {
                cdir = 1;
            }
            else if (i == 1)
            {
                cdir = 2;
            }
            else if (i == 2)
            {
                cdir = 3;
            }
            else
            {
                cdir = 4;
            }
            if (dir == 0 || dir == cdir)
            {
                if (turns <= 2)
                {

                    if (dfs(nr, nc, ei, ej,turns, n, m, cdir,a))
                    {
                        return true;
                    }

                }
            }
            else
            {
                if (turns < 2)
                {
                    if (dfs(nr, nc, ei, ej,turns + 1, n, m, cdir,a))
                    {
                        return true;
                    }

                }
            }
        }
    }
    //vis[si][sj] = 0;
    return false;
}

int main()
{
    // TxtIO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        memset(dp, -1, sizeof dp);
        vector<vector<char>> a(n, vector<char>(m));
        //vector<vector<ll>> vis(n, vector<ll>(m, 0));

        ll start_i = -1, start_j = -1, end_i = -1, end_j = -1;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> a[i][j];
                
                if (a[i][j] == 'S')
                {
                    start_i = i;
                    start_j = j;
                }
                if (a[i][j] == 'T')
                {
                    end_i = i;
                    end_j = j;
                }
            }
        }

        ll turns = 0;
        ll dir = 0;
        
        if (dfs(start_i, start_j, end_i, end_j,turns, n, m, dir,a))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}