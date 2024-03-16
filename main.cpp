#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using vii = vector<pii>;
using vll = vector<pll>;
using vs = vector<string>;

using vvb = vector<vb>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

ll t;
ll n;
vl V;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> t;
  while (0 < (t--)) {
    cin >> n;

    V = vl(n);
    for (auto&& x : V) {
      cin >> x;
    }

    auto r = 1;
    auto is_double = false;
    auto sum = V[0];
    for (auto i = 1; i < n; ++i) {
      sum += V[i];

      if (V[r - 1] < V[i]) {
        r = i + 1;
        is_double = false;
      } else if (V[r - 1] == V[i]) {
        is_double = true;
      }
    }

    if (is_double) {
      cout << "no winner\n";
    } else {
      if (sum / 2 < V[r - 1]) {
        cout << "majority winner " << r << '\n';
      } else {
        cout << "minority winner " << r << '\n';
      }
    }
  }

  return 0;
}
