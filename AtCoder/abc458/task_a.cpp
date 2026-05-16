// Solution to https://atcoder.jp/contests/abc458/tasks/abc458_a
#include <cstdio>
using namespace std;

int main(){
  int i, j, n;
  char s[31];
  scanf("%s", s);
  scanf("%d", &n);
  for(i = 0; s[i] != '\0'; i++)
  ;
  for(j = n; j < i - n; j++)
    printf("%c", s[j]);
  printf("\n");
  return 0;
}