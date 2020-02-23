#include <bits/stdc++.h>
#define fin freopen("in.txt", "r", stdin)
using namespace std;
typedef long long ll;
const int maxn = 2005;
const double eps = 1e-2;
struct P {
    double e[maxn];
    P() { 
        for(int i = 0; i < maxn; i++) e[i] = 0;
    }
}a, b, cc;
struct node {
    int e;
    double c;
    node(int x, double y) : e(x), c(y) {}
};
vector<node> _a;
vector<node> _b;
vector<node> _c;
int main() {
    fin;
    int n, x;
    double c;
    cin >> n;
    for(int i = 0; i < n; i++) { cin >> x >> c; _a.push_back(node(x, c)); }
    cin >> n;
    for(int i = 0; i < n; i++) { cin >> x >> c; _b.push_back(node(x, c)); }
    
    for(int i = 0; i < _a.size();  i++) {
        for(int j = 0; j < _b.size(); j++) {
            cc.e[_a[i].e + _b[j].e] += _a[i].c * _b[j].c;
        }
    }
    //cout << n << endl;
    for(int i = maxn - 1; i >= 0; i--) {
        if(fabs(cc.e[i]) < eps) continue;
        _c.push_back(node(i, cc.e[i]));
    }
    cout << _c.size();
    for(int i = 0; i < _c.size(); i++) printf(" %d %.1f", _c[i].e, _c[i].c);
    cout << "\n";
    return 0;
}