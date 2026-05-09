// Solution to https://atcoder.jp/contests/abc457/tasks/abc457_a
#include <vector>
#include <cstdio>
using namespace std;
int main(){
  int n, x, i, temp;
  vector<int> a;
  scanf("%d", &n);
  for(i = -0; i < n; i++){
    scanf("%d", &temp);
    a.push_back(temp);
  }
  scanf("%d", &x);
  printf("%d\n", a[x - 1]);
  return 0;
}