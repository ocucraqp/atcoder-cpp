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

// ベクトルの最大値取得
ll max = *max_element(A.begin(), A.end());

// 最小公倍数
ll lcm(ll A, ll B) {
    // process
    ll ans = 0;

    ll x = A * B;
    if (A < B) {
        ll tmp = A;
        A = B;
        B = tmp;
    }
    ll r = A % B;
    while (r != 0) {
        A = B;
        B = r;
        r = A % B;
    }
    ans = x / B;

    return ans;
}

//最小公約数
ll gcd(ll p, ll q) {
    while (q != 0) {
        ll r = p % q;
        p = q;
        q = r;
    }
    return p;
}