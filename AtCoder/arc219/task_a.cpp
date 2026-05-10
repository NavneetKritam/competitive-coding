// Solution to https://atcoder.jp/contests/arc219/tasks/arc219_a
// a recursive version of this is
// start index, end index and with a list of strings to be matched
// if the index is start==end then all the strings must match at start index and that is output string
// If not there are two choices, select 0 as answer and advance it with one eliminating with it all strings having 0 at start index
// If this returns true, return the ans string
// if start > end, container is not empty return false and no string else empty string with true
// If container of numbers is zero size then return the (end - start + 1) times 0 and return the string
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

pair<bool, string> find_t(int start, int end, vector<int> ns, const vector<string> &s) {
  string ans;
  if(start > end)
    if(ns.size() > 0)
      return make_pair(false, ans);
    else
      return make_pair(true, ans);
  // Case 0
  vector<int> zeros;
  for(int i = 0; i < ns.size(); i++)
    if(s[ns[i]][start] != '0')
      zeros.push_back(ns[i]);
  pair<bool, string> pair_ans = find_t(start + 1, end, zeros, s);
  if(pair_ans.first){
    return make_pair(pair_ans.first, '0' + pair_ans.second);
  }
  zeros.clear();
  for(int i = 0; i < ns.size(); i++)
    if(s[ns[i]][start] != '1')
      zeros.push_back(ns[i]);
  pair_ans = find_t(start + 1, end, zeros, s);
  if(pair_ans.first){
    return make_pair(pair_ans.first, '1' + pair_ans.second);
  }
  return make_pair(false, ans);
}

int main(){
  int n, m, i;
  cin >> n >> m;
  vector<string> s;
  string temp;
  vector<int> ns;
  for(i = 0; i < n; i++){
    cin >> temp;
    s.push_back(temp);
    ns.push_back(i);
  }
  pair<bool, string> pair_ans;
  pair_ans = find_t(0, m - 1, ns, s);
  if(pair_ans.first){
    cout << "Yes" << endl;
    cout << pair_ans.second << endl;
  }
  else{
    cout <<  "No" << endl;
  }
  return 0;
}