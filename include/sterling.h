#pragma once

#ifndef STERL_T
#define STERL_T unsigned long long
#endif

STERL_T sterl2(STERL_T n, STERL_T k) {

    if (n == k) return 1;
    if (n == 0) return 0;
    if (k == 0) return 0;
    if (n < k) return 0;

    STERL_T dp[k + 1];
    dp[0] = 1;
    for (STERL_T x = 1; x <= k; x++) {
        dp[x] = 0;
    }

    for (STERL_T y = 1; y <= n; y++) {
        STERL_T x0 = y < k ? y : k;
        for (STERL_T x = x0; x >= 1; x--) {
            dp[x] = dp[x - 1] + x * dp[x];
        }
        dp[0] = 0;
    }
    
    return dp[k];
}