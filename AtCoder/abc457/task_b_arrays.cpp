// Solution to https://atcoder.jp/contests/abc457/tasks/abc457_b
#include <cstdio>
#include <vector>

using namespace std;

int main(){
  int n, i, j, temp, l, x, y;
  vector<vector<int>> a;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &l);
    a.push_back(vector<int>());
    for(j = 0; j < l; j++){
      scanf("%d", &temp);
      a[i].push_back(temp);
    }
  }
  scanf("%d %d", &x, &y);
  printf("%d\n", a[x - 1][y - 1]);
  return 0;
}