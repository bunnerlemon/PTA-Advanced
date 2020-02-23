#include <bits/stdc++.h>
#define fin freopen("in.txt", "r", stdin)
using namespace std;
typedef long long ll;
const int maxn = 1e3+5;
const double eps = 1e-3;
struct node {
    double e[maxn];
    node() {
        for(int i = 0; i < maxn; i++) e[i] = 0;
    }
};
node a, b, c;
int main() {
    fin;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++) { cin >> x; cin >> a.e[x]; }
    cin >> n;
    for(int i = 0; i < n; i++) { cin >> x; cin >> b.e[x]; }
    int ans = 0;
    for(int i = maxn - 1; i >= 0; i--) {
        c.e[i] = a.e[i] + b.e[i];
        if(fabs(c.e[i]) < eps) continue;
        ans++;
    }
    cout << ans;
    for(int i = maxn - 1; i >= 0; i--) {
        if(fabs(c.e[i]) < eps) continue;
        printf(" %d %.1f", i, c.e[i]);
    }
    puts("");
    return 0;
}