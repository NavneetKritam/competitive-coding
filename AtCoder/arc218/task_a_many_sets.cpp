// Solution to https://atcoder.jp/contests/arc218/tasks/arc218_a
#include <cstdio>
#include <unordered_map>
#include <algorithm>
#define BIG 998244353

using namespace std;

int main(){
  int temp, i, j, n, m, seq; 
  int a[500][500];
  unordered_map<int, int> prev_e, next_e;
  scanf("%d %d", &n, &m);
  for(i = 0; i < n; i++){
    for(j = 0; j < m; j++){
      scanf("%d", &temp);
      a[i][j] = temp;
    }
  }
  seq = 1;
  for(i = 0; i < n; i++){
    if(i == 0){
      for(j = 0; j < m; j++)
        if(next_e.find(a[i][j]) != next_e.end())
          next_e[a[i][j]] += 1;
        else
        next_e[a[i][j]] = 1;
    }
    else{
      for(j = 0; j < m; j++)
        if(prev_e.find(a[i][j]) != prev_e.end()){
          if(next_e.find(a[i][j]) == next_e.end())
            next_e[a[i][j]] = 0;
          next_e[a[i][j]] = (next_e[a[i][j]] + ( BIG + (seq - prev_e[a[i][j]]) % BIG) % BIG) % BIG;
        }
        else{
          if(next_e.find(a[i][j]) == next_e.end())
            next_e[a[i][j]] = 0;
            next_e[a[i][j]] = (next_e[a[i][j]] + seq) % BIG;
        }
        
      for(auto it: prev_e){
        if(next_e.find(it.first) != next_e.end())
          next_e[it.first] = (next_e[it.first] + (m * it.second) % BIG) % BIG;
        else
           next_e[it.first] = ((m * it.second) % BIG);
          
      }
    }
    
      prev_e.clear();
      for(auto it: next_e)
        prev_e[it.first] = it.second;
      next_e.clear();
    seq = (seq * m) % BIG;
  }
  int ans = 0;
    for(auto it: prev_e)
      ans = (ans + it.second) % BIG;
    printf("%d\n", ans);
  return 0;
}