//
// Created by elghali on 2/8/26.
//
#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<ll> vi;

void fast() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
}

vector<vector<pair<ll,ll>>> g(1e5+1);
vector<ll> visited(1e5+1,0);
vector<ll> cost(1e5+1);

vector<ll> parent(1e5+1,0);
vector<ll> cha3l(1e5+1,0);

ll res = 0;
ll find(ll a) {
    if (parent[a] == a)return a;
    parent[a] = find(parent[a]);
    return parent[a];
}
void merge(ll a,ll b) {
    a = find(a);
    b = find(b);
    if (a == b)return;
    parent[a] = b;
    cha3l[b] = max(cha3l[a],cha3l[b]);
}

ll dfs(ll a) {
    ll m = cost[a];
    for (auto c: g[a]) {
        if (visited[c.first])continue;
        visited[c.first] = 1;
        m = min(m,dfs(c.first));
    }
    return m;
}

int main() {
    fast();
    ll n;cin >> n;
    for (ll i=1;i<=n;i++) {
        parent[i] = i;
    }
    vector<vector<ll>> prices;

    for (ll i=0;i<n;i++) {
        cin >> cost[i+1];
        prices.push_back({cost[i+1],i+1,1});
    }
    ll m;cin >> m;

    for (ll i=0;i<m;i++) {
        ll a,b,c;cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
        prices.push_back({c,a,b,0});//0 is edge
    }
    sort(prices.begin(),prices.end());
    for (auto elem : prices) {

        if (*elem.rbegin()==0) {
            //edge
            if (find(elem[1]) != find(elem[2])) {
                if (cha3l[find(elem[1])] && cha3l[find(elem[2])])
                    continue;
                merge(elem[1],elem[2]);
                res += elem[0];
            }
        }
        else {
            if (cha3l[find(elem[1])] == 0) {
                res+=elem[0];
                cha3l[find(elem[1])]=1;
            }
        }

    }

    cout << res << endl;
}