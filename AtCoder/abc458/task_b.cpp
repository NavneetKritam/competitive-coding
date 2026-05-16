// Solution to https://atcoder.jp/contests/abc458/tasks/abc458_b
#include <cstdio>
using namespace std;

int main(){
  int i, j, h, w, ans;
  scanf("%d %d", &h, &w);
  for(i = 0; i < h; i++){
    for(j = 0; j < w; j++){
      ans = 0;
      if(i - 1 >= 0)
        ans++;
      if(j - 1 >= 0)
        ans++;
      if(i + 1 < h)
        ans++;
      if(j + 1 < w)
        ans++;
      printf("%d%c", ans, (j == w - 1) ? '\n': ' ');
    }
  }
  return 0;
}