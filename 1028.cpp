#include <bits/stdc++.h>
using namespace std;
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)
struct node {
    string id, name;
    int score;
};
bool cmp_one(node &a, node &b) {
    return a.id < b.id;
}
bool cmp_two(node &a, node &b) {
    if(a.name == b.name) return a.id < b.id;
    else return (a.name < b.name);
}
bool cmp_three(node &a, node &b) {
    if(a.score == b.score) return a.id < b.id;
    else return a.score < b.score;
}
vector<node> p;
int main() {
    //fin, fout;
    ios::sync_with_stdio(false);
    int n, c;
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        node stu;
        cin >> stu.id >> stu.name >> stu.score;
        p.push_back(stu);
    }
    if(c == 1) sort(p.begin(), p.end(), cmp_one);
    else if(c == 2) sort(p.begin(), p.end(), cmp_two);
    else sort(p.begin(), p.end(), cmp_three);
    for(int i = 0; i < p.size(); i++) {
        cout << p[i].id << " " << p[i].name << " " << p[i].score << endl;
    }
    return 0;
}