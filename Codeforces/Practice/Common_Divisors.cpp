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

int gcd_(int a, int b)
{
    while (a)
    {
        int temp = a;
        a = b % a;
        b = temp;
    }

    return b;
}

void solve()
{
    int n = 0;
    cin >> n;

    vector<int> arr(1e6+1, 0);

    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        arr[in]++;
    }

    // int ans = 1;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         ans = max(ans, gcd_(arr[i], arr[j]));
    //     }
    // }

    // cout << ans << endl;

    int ans = 1;

    for(int i=1e6; i>=2; i--){
        int multiples = 0;
        
        for(int g=i; g<=1e6; g+=i){
            multiples += arr[g];
        }

        if(multiples > 1){
            ans = max(ans, i);
            break;
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
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}