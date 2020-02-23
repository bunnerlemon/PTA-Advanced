#include <bits/stdc++.h>
using namespace std;
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)
vector<int> num;
void to_vector(string &n) {
    for(int i = n.length() - 1; i >= 0; i--) num.push_back((n[i] - '0'));
}
void add() {
    vector<int> temp;
    for(int i = num.size() - 1; i >= 0; i--) temp.push_back(num[i]);
    int carry = 0;
    for(int i = 0; i < num.size(); i++) {
        int cur = carry + num[i] + temp[i];
        num[i] = cur % 10;
        carry = cur / 10;
    }
    if(carry) num.push_back(carry);
}
bool judge() {
    for(int i  = 0, j = num.size() - 1; i < j; i++, j--) {
        if(num[i] != num[j]) return false;
    }
    return true;
}
int main() {
    fin, fout;
    string n;
    int k, countx = 0;
    cin >> n >> k;
    to_vector(n);
    while(k--) {
        if(judge()) break;
        add();
        countx++;
    }
    for(int i = num.size() - 1; i >= 0; i--) cout << num[i];
    cout << endl << countx << endl;
    return 0;
}