#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    int n;
    cin >> n;
    ll a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll sum = 0;
    map<ll, ll> m1;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        m1[a[i]]++;
    }

    ll sum_of_2 = (sum * 2) / n;

    if ((sum * 2) % n)
    {
        cout << 0 << endl;
        return;
    }

    ll ans = 0;
    for (auto it : m1)
    {
        if (it.first > sum_of_2)
            break;
        ll rem = sum_of_2 - it.first;
        if (rem < it.first)
            break;
        else if (rem == it.first)
        {
            ans += ((it.second) * (it.second - 1)) / 2;
        }
        else
        {
            ans += (it.second * m1[rem]);
        }
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}