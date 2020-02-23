#include <bits/stdc++.h>
#define fin freopen("in.txt", "r", stdin)
using namespace std;
typedef long long ll;
const int maxn = 1005;
string s[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<int> ans;
void con(int x) {
    if(!x) ans.push_back(x);
    while(x) {
        ans.push_back(x % 10);
        x /= 10;
    }
}
int main() {
    fin;
    string x;
    int t = 0;
    cin >> x;
    for(int i = 0; i < x.length(); i++) { t = t + x[i] - '0'; }
    con(t);
    for(int i = ans.size() - 1; i >= 0; i--) if(i) cout << s[ans[i]] << " "; else cout << s[ans[i]] << "\n";
    return 0;
}