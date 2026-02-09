#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn = (int) 2 * 1e5 + 7;
const ll mod = (ll) 1e9 + 7;

int main() {
    fast();
    string s;
    cin >> s;
    stack<ll> st;
    int i=0;
    int n = s.size();
    while (i < n) {
        char c = s[i];
        if (c <= '9' && c >= '0') {
            st.push((ll)(c - '0'));
            i++;
            continue;
        }
        if (c == '[') {
            st.push(-1);
            i++;
            continue;
        }
        if (c <= 'z' && c >= 'a') {
            ll a = 0;
            while (c <= 'z' && c >= 'a') {
                i++;
                c = s[i];
                a++;
            }
            st.push(a);
            continue;
        }
        ll num = 0;
        while (st.top() != -1) {
                num =(num+ st.top())%mod;
                st.pop();
        }
        st.pop();
        num = (num * st.top())%mod;
        st.pop();
        while (!st.empty() && st.top() != -1) {
                num = (num +st.top())%mod;
                st.pop();
            }
            st.push(num);
            i++;
        }
    ll ans = 0;
    while (!st.empty()) {
        ans = (ans + st.top())%mod;
        st.pop();
    }
    cout << ans<<endl;
    return 0;
}

