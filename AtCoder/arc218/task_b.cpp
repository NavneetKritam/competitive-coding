// Solution to https://atcoder.jp/contests/arc218/tasks/arc218_b
// Case of special arrays
// If it is [1] then Alice always loses, otherwise for [k] Bob does
// If there are n repeating ks, then if k is 1 ALice loses otherwise Bob does
// Invariant: If the array is sorted, The game always resumes after the first min element is completely elimintated
// Then black board resumess with n0 - n element with second - first at the front, in fact, the actual number doesn't matter
// For playing the game, it can be surely assumed that we are playing with number - max before that given number != max
// Approach
// --------------------
// Let's do tower of Hanoi here
// the function will be int win(int player1, int player2, vector<int> &arr)
// ## Reduction of special array and base case
// Base Case: Array of all 0s player 1 wins
// Reduction of other special cases to base case: n ks array, then win is win(player2, player1, [1..1]) or win is win(palyer2, player1, [0..0])
// General Reduction
// ----------------------
// If the array is single 1 or 0 there is no choice but to declare either yourself the loser or the other a loser
// Otherwise in case of other cases the player can decide to either -
// a) Start the game by advancing the pointer to next unequal element and start the match with player 2 or
// b) Advance similarly but start with itself the player
// Base Case: the end is reached:- the player 1 loses
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <format>
using namespace std;
int win(int player1, int player2, vector<int>& arr, vector<int>& change, int p, int first, unordered_map<string, int> &score_map) {
    int pos = change[p];
    if (arr.size() <= pos)
        return player2;
    string rep = format("{},{},{},{}", player1, player2, p, (first) ? '#' : '0');
    if (score_map.find(rep) != score_map.end())
        return score_map[rep];
    int extent = change[p + 1] - pos;
    int new_first = (change[p + 1] < arr.size()) ? arr[change[p + 1]] : -1;
    if (first == 0 && extent == 1) {
        score_map[rep] = win(player2, player1, arr, change, p + 1, new_first, score_map);
        return score_map[rep];
    }
    else if (first == 1) {
        score_map[rep] = win(player2, player1, arr, change, p, 0, score_map);
        return score_map[rep];
    }
    int winner1 = win(player1, player2, arr, change, p + 1, new_first, score_map);
    int winner2 = win(player2, player1, arr, change, p + 1, new_first, score_map);
    if (winner1 == player1 || winner2 == player1) {
        score_map[rep] = player1;
        return player1;
    }
    else {
        score_map[rep] = player2;
        return player2;
    }

}
int main() {
    int t, n, i, temp, last_max = 0;
    scanf("%d", &t);
    while (t--) {
        vector<int> a;
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &temp);
            a.push_back(temp);
        }
        sort(a.begin(), a.end());
        vector<int> change;
        unordered_map<string, int> score_map;
        change.push_back(0);
        last_max = 0;
        temp = a[0];
        for (i = 0; i < n; i++) {
            if (a[i] != temp) {
                last_max = temp;
                temp = a[i];
                a[i] -= last_max;
                change.push_back(i);
            }
            else {
                a[i] -= last_max;
            }
        }
        change.push_back(a.size());
        printf("%s\n", win(0, 1, a, change, 0, a[0], score_map) ? "Bob" : "Alice");
        a.clear();
        change.clear();
        score_map.clear();
    }
    return 0;
}