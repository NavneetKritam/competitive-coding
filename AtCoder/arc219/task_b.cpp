// Solution to https://atcoder.jp/contests/arc219/tasks/arc219_b
// We can start with P since the operation is its own inverse so finding Q of (1..N) is same as finding finding it from P
// In the case of P it will just mean to find lexicographically highest operation, so from Q to P will make it smallest one
// For each pair of l, r we have to determine if it is indeed the one which produces larger permutation (that will make P be smallest)
// Now that is only possible if given pair l, r we can say that it is valid if doing reverse produces a greater permutation
// Now that l will only count towards the ans if that is not arranged in an order which if reversing from 0 to l -1 can produce a smaller
// For any lr embedded in larger lr the count of that is inclusive of that lr in so that If l!=r the condition shuld hold for all
#include <cstdio>
#include <vector>
#include <algorithm>
#define BIG 998244353
using namespace std;

int main(){
  int t, i, j, temp, n, ans, max, k;
  vector<int> p, maxm;
  scanf("%d", &t);
  bool to_add;
  while(t--){
    scanf("%d", &n);
    to_add = true;
    for(i = 0; i < n; i++){
      scanf("%d", &temp);
      p.push_back(temp);
      if(to_add == true){
        if(i + 1 != temp)
          to_add = false;
      }
    }
    if(n == 1){
      p.clear();
      printf("1\n");
      continue;
    }
    ans = 0;
    max = 0;
    for(i = 0; i < n; i++){
      if(max < p[i]){
        max = p[i];
      }
      maxm.push_back(max);
    }
    for(i = 0; i < n - 1; i++){
      for(j = i + 1; j < n; j++){
        max = maxm[i];
        if(max > p[j]){
          break;
        }
        else{
          ans = (ans + 1) % BIG;
        }
      }
    }
    if(to_add)
      ans = (ans + 1) % BIG;
    printf("%d\n", ans);
    maxm.clear();
    p.clear();
  }
}