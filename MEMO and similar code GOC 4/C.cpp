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
        int n;
        cin>>n;
        vi arr(n);
        unordered_map<int,int> m;
        for (int i=0;i<n;i++) {
            cin>>arr[i];
            m[arr[i]]++;
        }
        bool val=true;
        for (auto elem : m) {
            if (elem.second & 1)
                val=false;
        }
        if (val)
            cout<<"YES";
        else
            cout<<"NO";
    }
}