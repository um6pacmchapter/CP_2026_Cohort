#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void fast() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
}
int main() {
    fast();
    int t=1;
    //cin>>t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vector<vi> g(2*n+1);
        vector<pair<int,int>> edges(n);
        unordered_map<int,int> to_index;
        for (int i=0;i<n;i++) {
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
            to_index[a]=i;
            to_index[b]=i;
            edges[i] = {a,b};
        }

//we will have all of them right
        vi arr(m,0);
        bool val=true;
        for (int i=0;i<m;i++) {
            int a,b;
            cin>>a>>b;
            a = to_index[a];
            b = to_index[b];

            if (a==b)continue;
            if (arr[b]==0)arr[b]++;
            else arr[a]++;outdegrtee
            if (arr[a]==2)val=false;
        }
        if (!val)
            cout<<-1;
        else {
            for (int i=0;i<n;i++) {
                if (arr[i]==0)
                    cout<<edges[i].first<<" ";
                else
                    cout<<edges[i].second<<" ";
            }
        }

    }
}