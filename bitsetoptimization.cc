/*
dp[0] = 1;
for(int i = 0; i < n; i++)
    for(int j = maxv - 1; j >= a[i]; j--) 
        dp[j] |= dp[ j - a[i] ];
cout << count(dp, dp + maxv, 1) << '\n';

gets optimized to:
bitset<maxv> dp;
dp.set(0);
for(int i = 0; i < n; i++)
    dp |= dp << a[i];
cout << dp.count() << '\n';
*/