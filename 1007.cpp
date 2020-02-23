#include <bits/stdc++.h>
#define fin freopen("in.txt", "r", stdin)
using namespace std;
typedef long long ll;
const int maxn = 10005;
int a[maxn];
int main() {
    fin;
    int n;
    int s = 0, e = 0, ans_s, ans_e, sum = 0, ans_sum = -1;
    cin >> n;
    bool flag = true;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(flag && a[i] >= 0) flag = false;
    }
    if(flag) {
        cout << 0 << " " << a[0] << " " << a[n - 1] << "\n";
        return 0;
    }
    for(int i = 0; i < n; i++) {
        if(sum <= 0) {
            sum = 0;
            s = i, e = i;
            sum += a[i];
        }
        else {
            sum += a[i];
            e = i;
        }
        if(sum > ans_sum) {
            ans_sum = sum;
            ans_s = s, ans_e = e;
        }
    }
    cout << ans_sum << " " << a[ans_s] << " " << a[ans_e] << "\n";
    return 0;
}