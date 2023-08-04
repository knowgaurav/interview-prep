#include "bits/stdc++.h"
using namespace std;

#define ll long long int 
#define repi(s,e,t) for(ll i=s; i<=e; i+=t)
#define eb emplace_back
#define pb push_back

vector<long long> adj[400005];
bool used[400005];
long long indegree[400005];


int main()
{
    int testcases;
    cin >> testcases;

    while(testcases--){
        ll n, k; cin >> n >> k;
        repi(0, n, 1){
            adj[i].clear();
            used[i] = false;
            indegree[i] = 0;
        }

        repi(1, n-1, 1){
            ll x, y; cin >> x >> y;
            adj[x].eb(y);
            adj[y].eb(x);
            indegree[x]++;
            indegree[y]++;
        }

        if(n==1){
            cout << 0 << endl;
            continue;
        }

        queue<int> q;
        k--;

        repi(1, n, 1){
            if(indegree[i] == 1){
                q.push(i);
                used[i] = true;
                indegree[i] = 0;
            }
        }

        if(k>0){
            while(q.size() > 0){
                --k;
                ll cnt = q.size();

                while(cnt--){
                    ll f = q.front();
                    q.pop();

                    for(auto i : adj[f]){
                        if(!used[i]){
                            indegree[i]--;
                            if(indegree[i]==1){
                                q.push(i);
                                used[i] = true;
                            }
                        }
                    }
                }

                if(k <= 0) break;
            }
        }

        ll ans = 0;
        repi(1, n, 1){
            if(!used[i]){
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}