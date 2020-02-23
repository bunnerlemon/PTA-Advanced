#include<bits/stdc++.h>
using namespace std;
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)
vector<int> origin, now;
int rec[10];
void to_vector(string s) {
    for(int i = s.length() - 1; i >= 0; i--) origin.push_back(s[i] - '0');
}
void multi() {
    int carry = 0;
    for(int i = 0; i < origin.size(); i++) {
        int num = carry + (origin[i] << 1);
        now.push_back(num % 10);
        carry = num / 10;
    }
    if(carry) now.push_back(carry);
}
bool judge() {
    if(origin.size() != now.size()) return false;
    for(int i = 0; i < origin.size(); i++) rec[origin[i]]++;
    for(int i = 0; i < now.size(); i++) {
        rec[now[i]]--;
        if(rec[now[i]] < 0) return false;
    }
    return true;
}
int main() {
    // fin, fout;
    string s;
    cin >> s;
    to_vector(s);
    multi();
    if(judge()) cout << "Yes" << endl;
    else cout << "No" << endl;
    for(int i = now.size() - 1; i >= 0; i--) cout << now[i];
        cout << endl;
    return 0;
}