// Template 1

#include <bits/stdc++.h>
using namespace std;

void solve() {
  // enter code here
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }
}

// Template 2

#include <bits/stdc++.h>
using namespace std;

long double PI = acos(-1.0);

#define int long long
#define endl "\n"
#define MOD 1000000007

void solve() {
  // enter code here
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }

  return 0;
}

// Template 3

#include <bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using ordered_set = tree<T, null_type, less<T>,
// rb_tree_tag, tree_order_statistics_node_update>; template <typename T,
// typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag,
// tree_order_statistics_node_update>;
/*
    *s.find_by_order(k)     // kth element;
    s.order_of_key(k)       // number of elements less than k (first elements in
   case of map)
*/

long double PI = acos(-1.0);
const long double EPS = 1e-9;
const long long INF = 1e18;
const int MAXN = 1e6 + 1;

// clang-format off
#define int long long
#define endl '\n'
#define MOD 1'000'000'007
#define F first
#define S second
#define B begin()
#define E end()
#define pb push_back
#define all(v) v.B, v.E
#define sz(v) (int)((v).size())
#define rep(i, s, f) for (i = s; i < f; i++)
#define print(v) for(auto &z:v){cout<<z<<' ';cout<<'\n'}
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sortall(x) sort(all(x))
//<<fixed << setprecision(9)
// clang-format on

// Operator overloads
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) {
  return (istream >> p.first >> p.second);
}
template <typename T> istream &operator>>(istream &istream, vector<T> &v) {
  for (auto &it : v)
    cin >> it;
  return istream;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) {
  return (ostream << p.first << " " << p.second);
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
  for (auto &it : c)
    cout << it << " ";
  return ostream;
}

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

typedef vector<int> vi;
typedef vector<vi> vvi;

/** --- Add Global Variables & Functions --- **/
string yes = "YES\n", no = "NO\n";
/** ---------------------------------------- **/

void precompute() {}

inline void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

void solve() {
  // enter code here
}

int32_t main() {
  init();
  int t = 1;
  // cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }

  return 0;
}
