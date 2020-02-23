#include <bits/stdc++.h>
#define fin freopen("in.txt", "r", stdin)
using namespace std;
typedef long long ll;
const int maxn = 1e4+5;
int a[8];
void sovle(int x) {
    bool flag = (x < 0);
    x = abs(x);
    int idx = 0;
    if(x == 0) a[idx++] = x;
    while(x) {
        a[idx++] = x % 10;
        x /= 10;
    }
    if(flag) cout << "-";
    int k = 0;
    for(int i = idx-1; i >= 0; i--) {
        if(i != idx - 1 && (i+1) % 3 == 0 && i) cout << ",";
        cout << a[i];
    }
    cout << "\n";
}

int main() {
    fin;
    int a, b, c;
    cin >> a >> b;
    c = a + b;
    sovle(c);
    return 0;
}