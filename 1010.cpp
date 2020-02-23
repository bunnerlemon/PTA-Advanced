#include <bits/stdc++.h>
#define fin freopen("in.txt", "r", stdin)
using namespace std;
typedef long long ll;
const int maxn = 1e3+5;
string s, ss;
ll check(ll mid) {
    ll num = 0;
    for(int i = 0; i < ss.length(); i++) {
        if(ss[i] >= '0' && ss[i] <= '9') num = num * mid + ss[i] - '0';
        else num = num * mid + ss[i] - 'a' + 10;
    }
    return num;
}

int main() {
    fin;
    ll l, r, mid, num = 0, b, tag;
    cin >> s >> ss >> tag >> b;
    if(tag == 2) swap(s, ss);
    for(int i = 0; i < s.length(); i++) { 
        if(s[i] >= '0' && s[i] <= '9') num = num * b + s[i] - '0';
        else num = num * b + s[i] - 'a' + 10;
    }

    ll maxx = 0;
    for(int i = 0; i < ss.length(); i++) {
        if(ss[i] >= '0' && ss[i] <= '9') maxx = max(maxx, (ll) ss[i] - '0');
        else maxx = max(maxx, (ll) ss[i] - 'a' + 10);
    }

    l = maxx + 1;
    r = max(l, num + 1);

    bool flag = false;

    for(int i = 1; i <= 100; i++) {
        mid = (l + r) >> 1;
        ll num2 = check(mid);
        if(num == num2) {
            flag = true;
            break;
        }
        if(num2 >= num || num2 < 0) r = mid - 1;
        else if(num2 < num) l = mid + 1;
    }
    if(flag) cout << mid << "\n";
    else cout << "Impossible\n";
    return 0;
}