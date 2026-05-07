// Solution to https://atcoder.jp/contests/abc456/tasks/abc456_a
#include <cstdio>
using namespace std;

int main(){
  int sum;
  scanf("%d", &sum);
  int i, j, k;
  for(i = 1; i <=6; i++){
    for(j = 1; j <= 6; j++){
      for(k = 1; k <=6; k++){
        if(sum == (i+ j + k)){
          printf("Yes\n");
          return 0;
        }
      }
    }
  }
  printf("No\n");
  return 0;
}