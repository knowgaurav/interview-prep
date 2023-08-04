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

void dfs(int i, vector<int> &order, vector<bool> &visited, vector<vector<int>> &adj)
{
    visited[i] = true;
    order.push_back(i);

    for (auto it : adj[i])
    {
        if (!visited[it])
        {
            dfs(it, order, visited, adj);
        }
    }
}

// void solve()
// {
//     int n = 0;
//     cin >> n;
//     vector<int> a(n, 0);

//     for (int i = 0; i < n; i++)
//     {
//         int ele;
//         cin >> ele;
//         a.push_back(ele);
//     }

//     vector<vector<int>> adjL(n + 2, vector<int>());

//     for (int i = 1; i <= n; i++)
//     {
//         adjL[i].push_back(i + 1);

//         if (a[i - 1] == 0)
//             adjL[i].push_back(n + 1);
//         else if (a[i - 1] == 1)
//             adjL[n + 1].push_back(i);
//     }

//     vector<bool> visited(n + 2, false);
//     vector<int> order;

//     dfs(1, order, visited, adjL);

//     for (int i = 0; i < order.size(); i++)
//         cout << order[i] << " ";
//     cout << endl;
// }

// void solve()
// {
//     int n = 0;
//     cin >> n;
//     int a[n];

//     for (int i = 0; i < n; i++)
//         cin >> a[i];

//     if (a[0] == 0 && a[n - 1] == 0)
//     {
//         int i = 1;
//         for (; i <= n; i++)
//         {
//             if (a[i - 1] == 1)
//                 break;
//             cout << i << " ";
//         }
//         cout << n + 1 << " ";
//         for (; i <= n; i++)
//             cout << i << " ";
//         cout << endl;
//         // int i = 0;
//         // while (a[i] == 0)
//         // {
//         //     i++;
//         //     cout << i << " ";
//         // }
//         // cout << n + 1 << " " << i + 1 << " ";
//         // i++;
//         // while (i < n)
//         // {
//         //     i++;
//         //     cout << i << " ";
//         // }
//         // cout << endl;
//     }
//     else if (a[n - 1] == 0)
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             cout << i << " ";
//         }
//         cout << n + 1 << endl;
//     }
//     else if (a[0] == 1)
//     {
//         cout << n + 1 << " ";
//         for (int i = 1; i <= n; i++)
//         {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
// }

void solve()
{
    int n;
    cin >> n;
    int a[n];

    bool zeroFound = false;
    int zeroIndex = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            zeroFound = true;
            zeroIndex = i;
        }
    }

    if (!zeroFound)
    {
        cout << n + 1 << " ";
        for (int i = 0; i < n; i++)
            cout << i + 1 << " ";
    }
    else
    {
        for (int i = 0; i <= zeroIndex; i++)
            cout << i + 1 << " ";
        cout << n + 1 << " ";
        for (int i = zeroIndex + 1; i < n; i++)
            cout << i + 1 << " ";
    }

    cout << endl;
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