// Solution to https://atcoder.jp/contests/abc456/tasks/abc456_c
#include <string>
#include <iostream>
#define BIG 998244353
using namespace std;

int main() {
    string s;
    cin >> s;
    int i, current, ans = 0;
    current = 1;
    ans = (ans + current) % BIG;
    for (i = s.size() - 2; i >= 0; i--) {
        if (s[i] != s[i + 1])
            current = (current + 1) % BIG;
        else
            current = 1;
        ans = (ans + current) % BIG;
    }
    cout << ans << endl;
}