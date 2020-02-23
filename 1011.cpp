#include <bits/stdc++.h>
#define fin freopen("in.txt", "r", stdin)
using namespace std;
typedef long long ll;
const int maxn = 1e3+5;
struct node {
    double odds[3];
}p[3];
char result[3] = {'W', 'T', 'L'};
int main() {
    fin;
    /*double max_sum = 1;
    for(int i = 0; i < 3; i++) {
        int id = 0;
        for(int j = 0; j < 3; j++) {
            cin >> p[i].odds[j];
            if(p[i].odds[id] < p[i].odds[j]) id = j;
        }
        cout << result[id] << " "; 
        max_sum *= p[i].odds[id];
        //cout << max_sum << "\n";
    }
    max_sum *= 0.65;
    max_sum -= 1;
    max_sum *= 2;
    printf("%.2f\n", max_sum);*/
    float a, b;
    int c;
    while(cin >> a) {
        getchar();
        cin >> b;
        getchar();
        cin >> c;
        cout << a << b << c << endl;
    }
    return 0;
}