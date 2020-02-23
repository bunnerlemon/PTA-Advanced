#include <bits/stdc++.h>
using namespace std;
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)

typedef pair<int, string> pis;
map<pis, vector<int> > mp;

int n;

void process_keyword(string keywords, int id) {
    string keyword = "";
    //分离Keyword
    for(int i = 0; i < keywords.length(); i++) {
        if(keywords[i] == ' ') {
            mp[make_pair(3, keyword)].push_back(id);
            keyword = "";
        }
        else {
            keyword = keyword + keywords[i];
        }
    }
    mp[make_pair(3, keyword)].push_back(id);
}

int main() {
    // fin, fout;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    string buf;
    for(int i = 0; i < n; i++) {
        int id;
        cin >> id;
        getline(cin, buf);      //将换行读掉
        for(int j = 1; j < 6; j++) {
            string s;
            getline(cin, s);
            //cout << s << " " << j << endl;
            if(j != 3) {mp[make_pair(j, s)].push_back(id);}
            else process_keyword(s, id);        //若是Keywords,转到keywords处理程序
        }
    }
    int q;
    cin >> q;
    getline(cin, buf);  //将换行读掉
    while(q--) {
        int id = 0;
        string target = "";
        string s;
        bool flag = false;
        getline(cin, s);
        //分离id和后面查询关键词
        for(int i = 0; i < s.length(); i++) {
            if(flag) { target = target + s[i]; continue; }
            if(s[i] == ':') { flag = true, i++; continue; }
            id = id * 10 + s[i] - '0';
        }
        vector<int> ans = mp[make_pair(id, target)];
        cout << id << ": " << target << endl;
        if(ans.size() == 0) {
            cout << "Not Found" << endl;
            continue;
        } 
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++) cout << setw(7) << setfill('0') << ans[i] << endl;
    }
    return 0;
}