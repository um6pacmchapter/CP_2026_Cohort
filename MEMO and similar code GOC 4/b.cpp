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
        int offset = 1e5+10;
        vi arr(2*offset+15,0);

        for (int i=0;i<n;i++) {
            char c;
            cin>>c;
            int a;cin>>a;
            a += offset;
            if (c=='L') {
                arr[a]++;
            }
            else {
                arr[0]++;
                arr[a+1]--;
            }
        }
        int res=arr[0];
        for (int i=1;i<arr.size();i++){
            arr[i] += arr[i-1];
            res = max(res,arr[i]);
        }
        cout<<n-res<<endl;
    }
}
