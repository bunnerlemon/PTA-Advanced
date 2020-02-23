#include <bits/stdc++.h>
using namespace std;
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)
const int maxn = 1e5+5;

vector<int> num;

bool check[maxn];
vector<int> prime;

//∞£ œ…∏
void ei_prime() {
    check[0] = check[1] = true;
    check[2] = false;
    for(int i = 2; i < maxn; i++) {
        if(!check[i]) prime.push_back(i);
        for(int j = 0; j < prime.size() && prime[j] * i < maxn; j++) {
            check[i * prime[j]] = true;
            if(!(i % prime[j])) break;
        }
    }
}

bool isprime(int n) {
    if(n == 0 || n == 1) return false;
    if(n == 2) return true;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

void solve(int n, int base) {
    num.clear();
    while(n) {
        num.push_back(n % base);
        n /= base;
    }
}

int convert(int base) {
    int x = 0;
    for(int i = 0; i < (int) num.size(); i++) {
        x = x * base + num[i];
    }
    return x;
}

// int _convert(int base) {
//     int x = 0;
//     for(int i = (int)num.size() - 1; i >= 0; i--) {
//         x = x * base + num[i];
//     }
//     return x;
// }

bool judge(int n, int x) {
    //cout << n << " " << x << endl;
    if(!check[n] && !check[x]) return true;
    else return false;
    // if(isprime(n) && isprime(x)) return true;
    // else return false;
}

int main() {
    ios::sync_with_stdio(false);
    //fin;
    int a, b;
    ei_prime();
    while(cin >> a) {
        if(a < 0) return 0;
        cin >> b;
        solve(a, b);
        if(judge(a, convert(b))) cout << "Yes" << endl;
        else cout << "No" << endl;
    }    
    return 0;
}