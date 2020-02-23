#include <bits/stdc++.h>
#define fin freopen("in.txt", "r", stdin)
using namespace std;
typedef long long ll;
const int maxn = 2e3+5;
const int mxxx = 1e6;
struct node {
    int id, c, m, e;
    double ave;
}p[maxn];
bool v[mxxx];
struct P {
    int a[4];
}t[mxxx];
bool cmp1(node a, node b) {
    return a.c > b.c;
}
bool cmp2(node a, node b) {
    return a.m > b.m;
}
bool cmp3(node a, node b) {
    return a.e > b.e;
}
bool cmp4(node a, node b) {
    return a.ave > b.ave;
}
char ans[4] = {'A', 'C', 'M', 'E'};
int main() {
    fin;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> p[i].id >> p[i].c >> p[i].m >> p[i].e;
        p[i].ave = (p[i].c + p[i].m + p[i].e) * 1.0 / 3;
        v[p[i].id] = true;
    }
    int idx = 0;
    sort(p, p + n, cmp1);
    for(int i = 0; i < n; i++) {
        if(i == 0) t[p[i].id].a[1] = ++idx;
        else {
            if(p[i].c == p[i - 1].c) t[p[i].id].a[1] = idx;
            else t[p[i].id].a[1] = i + 1, idx = i + 1;
        }
    }
    idx = 0;
    sort(p, p + n, cmp2);
    for(int i = 0; i < n; i++) {
        if(i == 0) t[p[i].id].a[2] = ++idx;
        else {
            if(p[i].m == p[i - 1].m) t[p[i].id].a[2] = idx;
            else t[p[i].id].a[2] = i + 1, idx = i + 1;
        }
    }
    idx = 0;
    sort(p, p + n, cmp3);
    for(int i = 0; i < n; i++) {
        if(i == 0) t[p[i].id].a[3] = ++idx;
        else {
            if(p[i].e == p[i - 1].e) t[p[i].id].a[3] = idx;
            else t[p[i].id].a[3] = i + 1, idx = i + 1;
        }
    }
    idx = 0;
    sort(p, p + n, cmp4);
    for(int i = 0; i < n; i++) {
        if(i == 0) t[p[i].id].a[0] = ++idx;
        else {
            if(fabs(p[i].ave - p[i - 1].ave) < 0.0001) t[p[i].id].a[0] = idx;
            else t[p[i].id].a[0] = i + 1, idx = i + 1;
        }
    }
    int x;
    for(int i = 0; i < m; i++) {
        cin >> x;
        if(!v[x]) { cout << "N/A\n"; }
        else {
            int tag = 0, rank = t[x].a[tag];
            for(int i = 1; i < 4; i++) { if(t[x].a[i] < rank) tag = i, rank = t[x].a[i]; } 
            cout << rank << " " << ans[tag] << "\n";
        }
    }
    return 0;
}