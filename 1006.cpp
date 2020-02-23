#include <bits/stdc++.h>
#define fin freopen("in.txt", "r", stdin)
using namespace std;
typedef long long ll;
const int maxn = 1005;

int main() {
    fin;
    string unlock, lock, s;
    int ul = 24 * 3600, l = 0, n, hh, mm, ss;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int t = hh * 3600 + mm * 60 + ss;
        if(t < ul) ul = t, unlock = s;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        t = hh * 3600 + mm * 60 + ss;
        if(t > l) l = t, lock = s;
    }    
    cout << unlock << " " << lock << "\n";
    return 0;
}