// Solution to https://atcoder.jp/contests/abc457/tasks/abc457_d
#include <cstdio>
#include <utility>
#include <algorithm>
#include <climits>
#include <queue>
#include <vector>
#define ll long long

using namespace std;

struct Compare {
    bool operator()(const pair<ll, int>& one, const pair<ll, int>& two) {
        if (one.first > two.first)
            return true;
        else if (one.first == two.first)
            return (one.second < two.second);
        else
            return false;
    }
};

int main() {
    int n, i, j;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, Compare> a;
    ll temp, k, mul, next;
    scanf("%d %lld", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%lld", &temp);
        a.push(make_pair(temp, i + 1));
    }
    while (k > 0) {
        if (a.size() > 0) {

            ll temp1 = a.top().first;
            int temp2 = a.top().second;
            a.pop();
            next = a.top().first;
            if (next == temp1)
                mul = 1;
            else
                mul = (next - temp1) / (temp2)+(((next - temp1) % (temp2) > 0) ? 1 : 0);
            if (mul > k)
                mul = k;
            k -= mul;
            mul = temp1 + temp2 * mul;
            j = temp2;
            a.push(make_pair(mul, j));
        }
        else {
            a.push(make_pair(a.top().first + k * a.top().second, 0));
            a.pop();
            k = 0;
        }
    }
    printf("%lld\n", a.top().first);

    return 0;
}