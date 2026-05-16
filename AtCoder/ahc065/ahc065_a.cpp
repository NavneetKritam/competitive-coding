// There will be one conveyer belt which start from (0, n/2) and move like this
// down from 0,n/2 till 0,n-1 and then right 1,n-1 then up to 1,1 then right 2,1 and then down 2,n-1
// then right 3,n-1 then up 3,1 then right 4,1 and so on if n is even then n-1, n-1 will be entered from 
// n-2, n-1 then it will go up to n-1,0 then left to 0,0 then down to 0,n/2-1
// If n is odd, then up from 0,n/2 to 0,0 right 1,0 then down to 1,n-2 right to 2,n-2 and then up 3,0
// and so on until n-2,0 enters n-1,0 then down to n-1,n-1 then left to 0,n-1 then up to 0,n/2+1
// then a function which takes init position and number of rotations in + and - and give the final
// position of the box
// generate a map from the position of conveyer belt wrt to init position ie index and the position on grid
// We have intiial position, we have number of moves till the position up, down, and reverse map
// Get position of an element in current belt by doing current box to go, its position (also do reverse map of a)
// Position is intial position of current box to go (plus-minus) % length of converyer belt(normalize it to positive)
// For each find if the going plus is nearest or going minus by doing if current position to 0 is nearer ahead
// of below

#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> make_conveyer_belt(int n) {
    int i, j;
    vector<pair<int, int>> ans;
    if (n & 1) {
        ans.push_back(make_pair(0, n >> 1));
        //upturn
        for (j = (n >> 1) - 1; j >= 0; j--)
            ans.push_back(make_pair(0, j));
        while (ans.back().first != n - 2) {
            i = ans.back().first;
            i++;
            if (i & 1) {
                for (j = 0; j < n - 1; j++)
                    ans.push_back(make_pair(i, j));
            }
            else {
                for (j = n - 2; j >= 0; j--)
                    ans.push_back(make_pair(i, j));
            }
        }
        // down turn
        for (j = 0; j < n; j++)
            ans.push_back(make_pair(n - 1, j));
        // left turn
        for (j = n - 2; j >= 0; j--)
            ans.push_back(make_pair(j, n - 1));
        //upturn
        for (j = n - 2; j > (n >> 1); j--)
            ans.push_back(make_pair(0, j));
    }
    else {
        ans.push_back(make_pair(0, n >> 1));
        // first down turn to n - 1
        for (i = (n >> 1) + 1; i < n; i++)
            ans.push_back(make_pair(0, i));
        while (ans.back().first != n - 2) {
            i = ans.back().first;
            i++;
            if (i & 1) {
                for (j = n - 1; j > 0; j--)
                    ans.push_back(make_pair(i, j));
            }
            else {
                for (j = 1; j < n; j++)
                    ans.push_back(make_pair(i, j));
            }
        }
        for (j = n - 1; j >= 0; j--)
            ans.push_back(make_pair(n - 1, j));
        // left turn
        for (j = n - 2; j >= 0; j--)
            ans.push_back(make_pair(j, 0));
        //for down turn
        for (j = 1; j < (n >> 1); j++)
            ans.push_back(make_pair(0, j));
    }
    return ans;
}

unordered_map<int, int> reverse_map(const vector<pair<int, int>>& conv, const int n) {
    int i;
    unordered_map<int, int> ans;
    for (i = 0; i < conv.size(); i++)
        ans[conv[i].first * n + conv[i].second] = i;
    return ans;
}

int main() {
    int n, i, j, temp;
    scanf("%d", &n);
    vector<pair<int, int>> conv_belt = make_conveyer_belt(n);
    FILE* out;
    printf("%d\n", 1);
    printf("%d ", conv_belt.size());
    for (i = 0; i < conv_belt.size(); i++)
        printf("%d %d%c", conv_belt[i].first, conv_belt[i].second, (i == conv_belt.size() - 1) ? '\n' : ' ');
    unordered_map<int, int> rmap = reverse_map(conv_belt, n);
    vector<pair<int, int>> a(n * n, make_pair(0, 0));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &temp);
            a[temp] = make_pair(i, j);
        }
    }
    vector<pair<bool, int>> ans;
    i = 0;
    pair<int, int> init_pos;
    int t = 0, plus = 0, minus = 0;
    int conv_pos;
    int sqr = n * n;
    while (i < sqr) {
        init_pos = a[i];
        conv_pos = rmap[init_pos.first * n + init_pos.second];
        conv_pos = (conv_pos + (plus - minus) % sqr + sqr) % sqr;
        if (conv_pos < (sqr - conv_pos)) {
            minus = (minus + conv_pos);
            ans.push_back(make_pair(false, conv_pos));
            t += minus;
        }
        else {
            plus += sqr - conv_pos;
            t += plus;
            ans.push_back(make_pair(true, (sqr - conv_pos)));
        }
        i++;
    }
    int expended = 0, last_index = -1;
    for (i = 0; i < ans.size(); i++) {
        if (expended + ans[i].second > 100000)
            break;
        expended += ans[i].second;
        last_index = i;
    }
    printf("%d\n", expended);
    for (i = 0; i < last_index; i++) {
        if (ans[i].first) {
            for (j = 0; j < ans[i].second; j++)
                printf("0 1\n");
        }
        else {
            for (j = 0; j < ans[i].second; j++)
                printf("0 -1\n");
        }
    }
}