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

// 素数判定
bool is_prime(long long N) {
    if (N == 1) return false;
    if (N == 2) return true;
    for (long long i = 3; i * i <= N; i += 2) {
        if (N % i == 0) return false;
    }
    return true;
}

// 約数列挙
Vec enum_divisors(ll N) {
    Vec res;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N / i != i) res.push_back(N / i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

// 素因数分解
VecP prime_factorize(ll N) {
    VecP res;

    // a=2だけ別処理
    ll a=2;
    if (N % a != 0) continue;
    ll ex = 0;
    // 割れる限り割り続ける
    while (N % a == 0) {
        ++ex;
        N /= a;
    }
    // その結果を push
    res.push_back({a, ex});

    // 3以降の素数に関して素因数分解
    for (a = 3; a * a <= N; a+=2) {
        if (N % a != 0) continue;
        ll ex = 0;
        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}