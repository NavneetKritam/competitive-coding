// Solution to https://atcoder.jp/contests/abc450/tasks/abc450_a
#include <cstdio>
using namespace std;
int main(){
  int i, n;
  scanf("%d", &n);
  for(i = n; i > 0; i--){
    printf("%d%c", i, (i == 1) ? '\n': ',');
  }
  return 0;
}