#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void fast() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
}
int main() {
    int t=1;
    //cin>>t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vector<vi> g(n+1);
        vi deg(n+1,0);
        for (int i=0;i<m;i++) {
            int a,b,e;
            cin>>a>>b>>e;
            if (e==0) {
                g[a].push_back(b);
                deg[b]++;
            }
        }
        queue<int> q;
        for (int i=1;i<=n;i++) {
            if (deg[i]==0)
                q.push(i);
        }
        vi visited(n+1);
        bool val = true;

        while (!q.empty()) {
            int h = q.front();
            visited[h]=1;
            q.pop();
            for (auto elem: g[h]) {
                deg[elem]--;
                if (deg[elem]==0)
                    q.push(elem);
            }
        }
        for (int i=1;i<=n;i++) {
            if (visited[i]==0)
                val=false;
        }

        if (val)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}