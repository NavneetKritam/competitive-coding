// Solution to https://atcoder.jp/contests/abc458/tasks/abc458_c
#include <iostream>
#include <string>
using namespace std;

int main(){
  int ans = 0, i, n;
  string s;
  cin >> s;
  for(i = 0; i < s.size(); i++){
    if(s[i] == 'C'){
      ans += 1;
      ans += (i < s.size() - i - 1) ? i : (s.size() - i - 1);
    }
  }
  printf("%d\n", ans);
}