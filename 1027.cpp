#include <bits/stdc++.h>
using namespace std;
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)

vector<char> to_13(int x) {
    vector<char> ans;
    int countx = 0;
    while(x) {
        int temp = x % 13;
        if(temp >= 10) ans.push_back('A' + temp - 10);
        else ans.push_back('0' + temp);
        x /= 13;
        countx++;
    }
    if(countx == 1) ans.push_back('0');
    else if(countx == 0) ans.push_back('0'), ans.push_back('0');
    return ans;
}

int main() {
    //fin, fout;
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    vector<char> ans;
    ans.push_back('#');
    for(int i = 0; i < 3; i++) {
        vector<char> temp = to_13(a[i]);
        for(int j = temp.size() - 1; j >= 0; j--) ans.push_back(temp[j]);
    }
    for(int i = 0; i < ans.size(); i++) cout << ans[i];
    cout << endl;
    return 0;
}