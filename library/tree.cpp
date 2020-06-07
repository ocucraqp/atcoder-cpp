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

using Graph = vector<vector<ll>>;
Graph G;

// vは現在見ている頂点，pはvの親
void dfs(ll v, ll p) {
    for (auto nv:G[v]) {
        if (nv == p) continue;
        dfs(nv, v);
    }
}

//int main() {
//    ll root = 0;
//    dfs(root, -1);
//    return 0;
//}