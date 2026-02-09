//
// Created by elghali on 2/8/26.
//
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
typedef vector<int> vi;

void fast() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
}
struct  Point {
    typedef Point P;
    ll x,y;
    explicit Point(ll x = 0 , ll y = 0): x(x) , y(y) {}
    bool operator< (P p )const {return tie(x,y) < tie(p.x,p.y);}
    bool operator == (P p )const {return tie(x,y) == tie(p.x,p.y);}
    P operator+ (P p )const {return P(x +p.x,y+p.y);}
    P operator- (P p )const {return P(x -p.x,y-p.y);}
    P operator* (ll d)const {return P(x *d,y*d);}
    P operator/ (ll d )const {return P(x /d,y/d);}
    ll dot(P p) const {return x*p.x + y*p.y;}
    ll cross(P p) const { return x*p.y - y*p.x;}
    ll cross(P a , P b) const {
        return (a - *this).cross(b - *this);
    }
};

template<class P> bool onSegment(P s, P e, P p) {
    return p.cross(s,e) == 0 && (s - p).dot(e - p) <= 0;
}
template<class P>
bool insidestrict(vector<P> &p,P a,bool strict=true) {
    int cnt = 0,n=p.size();
    for (int i=0;i<n;i++) {
        P q = p[(i+1)%n];
        if (onSegment(p[i],q,a))return !strict;
        cnt ^= ((a.y<p[i].y) - (a.y<q.y)) * a.cross(p[i],q) > 0;

    }
    return cnt;
}
template<class P>

bool insidenot(vector<P> &p,P a,bool strict=false) {
    int cnt = 0,n=p.size();
    for (int i=0;i<n;i++) {
        P q = p[(i+1)%n];
        if (onSegment(p[i],q,a))return !strict;
        cnt ^= ((a.y<p[i].y) - (a.y<q.y)) * a.cross(p[i],q) > 0;

    }
    return cnt;
}



int main() {
    int t=1;
    //cin>>t;
    ll x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Point p1 = Point(x1,y1);
    Point p2 = Point(x2,y2);
    Point p3 = Point(x3,y3);
    vector<Point> arr(3) ;
    arr[0] = p1;
    arr[1] = p2;
    arr[2] = p3;
    int q;
    cin >> q;
    while (q--) {
        ll a,b;
        cin >> a >> b;
        Point p = Point(a,b);
        bool tr = insidenot(arr,p);
        if (!tr) {
            cout << "OUTSIDE" << endl;
            continue;
        }
        tr = insidestrict(arr,p);
        if (tr)
            cout << "INSIDE" << endl;
        else
            cout << "BOUNDARY" << endl;
    }


}