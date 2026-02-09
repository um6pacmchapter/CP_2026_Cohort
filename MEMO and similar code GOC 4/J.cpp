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
        unordered_map<string,string> ntor,ltor;
        for (int i=0;i<n;i++) {
            string a,b;
            cin>>a>>b;
            ltor[a]=b;
        }
        for (int i=0;i<m;i++) {
            string a,b;
            cin>>a>>b;
            ntor[a]=b;
        }
        unordered_map<string,set<string>> out;
        int k;cin>>k;
        for (int i=0;i<k;i++) {
            char c;
            cin>>c;
            if (c=='L') {
                string name,act;
                cin>>name>>act;
                out[ltor[name]].insert(act);
            }
            else {
                string name,act;
                cin>>name>>act;
                out[ntor[name]].insert(act);
            }
        }
        int q;
        cin>>q;
        for (int i=0;i<q;i++) {
            string s;
            cin>>s;
            cout<<out[s].size()<<" ";
            for (auto elem : out[s]) {
                cout<<elem<<" ";
            }
            cout<<endl;
        }

    }
}