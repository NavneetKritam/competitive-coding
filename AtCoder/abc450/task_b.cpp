// Solution to https://atcoder.jp/contests/abc450/tasks/abc450_b
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
  int i, j, n, k, temp;
  scanf("%d", &n);
  vector<unordered_map<int, int>> c(n, unordered_map<int, int>());
  for(i = 0; i < n; i++){
    for(j = i + 1; j < n; j++){
      scanf("%d", &temp);
      c[i][j] = temp;
    }
  }
  bool ans = false;
  for(i = 0; i < n; i++){
    if(ans)
      break;
    for(j = i + 1; j < n; j++){
      if(ans)
        break;
      for(k = j + 1; k < n; k++){
        if(c[i][j] + c[j][k] < c[i][k]){
          ans = true;
          break;
        }
      }
    }
  }
  printf("%s\n", (ans) ? "Yes": "No");
  return 0;
}