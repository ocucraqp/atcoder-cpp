#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <bitset>

using namespace std;

using ll = long long;
using Vec = vector<ll>;
using P = pair<ll, ll>;
using VecP = vector<P>;
#define rep(i, n) for(ll i=0;i<(n);i++)
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

//static const ll MOD = 1000000007;
//static const ll INF = 1000000000000000000;
//#define PI 3.14159265359

static const ll MAX_N = 99;
static const ll MAX_W = 99;

ll dp[MAX_N + 1][MAX_W + 1];

void ex1() {
    memset(dp, 0, sizeof(dp));

    ll n = 4, W = 5;
    ll w[MAX_N] = {2, 1, 3, 2}, v[MAX_N] = {3, 2, 4, 2};

    for (ll i = n - 1; i >= 0; i--) {
        for (ll j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[i][j] = dp[i + 1][j];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[0][W] << endl;
}

void ex2() {
    memset(dp, 0, sizeof(dp));

    ll n = 4, m = 4;
    string s = "abcd", t = "becd";

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j <= m; j++) {
            if (s[i] == t[i]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    cout << dp[n][m] << endl;
}