#include <bits/stdc++.h>
#define fin freopen("in.txt", "r", stdin)
using namespace std;
typedef long long ll;
const int maxn = 10005;

int up = 6, down = 4, stay = 5;

int main() {
    fin;
    int n, x, cur = 0, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(x > cur) ans += (x - cur) * up + 5;
        else if(x < cur) ans += (cur - x) * down + 5;
        else ans += 5;
        cur = x;
    }
    cout << ans << "\n";
    return 0;
}