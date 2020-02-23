#include <bits/stdc++.h>
using namespace std;
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)


vector<int> to_base(int n, int base) {
    vector<int> ans;
    while(n) {
        ans.push_back(n % base);
        n /= base;
    }
    return ans;
}

bool judge(vector<int> x) {
    for(int i = 0, j = (int) x.size() - 1; i < j; i++, j--) {
        if(x[i] != x[j]) return false;
    }
    return true;
}

int main() {
    // fin;
    // fout;
    ios::sync_with_stdio(false);
    int n, base;
    cin >> n >> base;
    vector<int> n_base = to_base(n, base);
    if(judge(n_base)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    for(int i = (int)n_base.size() - 1; i >= 0; i--) {
        if(i) cout << n_base[i] << " ";
        else cout << n_base[i] << endl;
    }
    return 0;
}