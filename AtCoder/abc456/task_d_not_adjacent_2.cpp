// Solution to https://atcoder.jp/contests/abc456/tasks/abc456_d
#include <string>
#include <iostream>
#include <vector>

#define BIG 998244353

using namespace std;

int main(){
  string in;
  cin >> in;
  vector<vector<int>> substring_count(in.size(), vector<int>(4));
  for(int i = in.size() - 1; i >= 0; i--){
    if(i == in.size() - 1){
      for(int j = 0; j < 4; j++){
        if(in.at(i) != 'a' + j)
          substring_count[i][j] = 1;
        else
          substring_count[i][j] = 0;
      }
    }
    if(i != in.size() - 1){
      for(int j = 0; j < 4; j++){
        substring_count[i][j] = 0;
        if(in.at(i) != 'a' + j)
          substring_count[i][j] = (substring_count[i][j] + (1 + substring_count[i + 1][in.at(i) - 'a']) % BIG) % BIG;
        substring_count[i][j] = (substring_count[i][j] + substring_count[i + 1][j]) % BIG;
      }
    }
  }
  printf("%d\n", substring_count[0][3]);
}
