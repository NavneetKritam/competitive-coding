// Solution to https://atcoder.jp/contests/abc450/tasks/abc450_d
#include <cstdio>
using namespace std;

int main(){
  int n, k, temp, i;
  scanf("%d %d", &n, &k);
  int min = -1, max = -1, mina = -1, maxb = -1;
  bool is_k = false, is_mid = false;
  for(i = 0; i < n; i++){
    scanf("%d", &temp);
    int a = temp % k;
    int b = k - a;
    if(a == 0){
      is_k = true;
      continue;
    }
    min = (min == -1) ? a : ((min > a) ? a : min);
    max = (max == -1) ? a : ((max < a) ? a : max);
    if(a == b){
      is_mid = true;
      continue;
    }
    if(a < b)
      mina = (mina == -1) ? a : ((mina < a) ? a : mina);
    if(a > b)
      maxb = (maxb == -1) ? b : ((maxb < b) ? a : maxb); 
  }
  if(n == 1){
    printf("0\n");
  }
  else if(!is_k && !is_mid){
    // Two cases
    int ans;
    if(max != -1 && min != -1)
      ans = max - min;
    if(maxb != -1 && mina != -1 && (ans > (maxb + mina)))
      ans = maxb + mina;
    printf("%d\n", ans);
  }
  else if(is_k){
    // Two cses normally extra case from shifting to k for 0
    int ans;
    if(max != -1)
      ans = max;
    if(min != -1 && (ans > (k - min)))
      ans = k - min;
    if(!is_mid){
      if(maxb != -1 && mina != -1 && (ans > (maxb + mina)))
        ans = maxb + mina;
    }
    else {
      if(maxb != -1 && (ans > (maxb + (k >> 1))))
        ans = (k >> 1) + maxb;
      if(mina != -1 && (ans > (mina + (k >> 1))))
        ans = (k >> 1) + mina;
    }
    printf("%d\n", ans);
  }
  else if(is_mid){
    // Same two cases plus two cases of adjusting maxb to be mid or mina to be mid
    int ans;
    if(max != -1 && min != -1)
      ans = max - min;
    if(maxb != -1 && (ans > (maxb + (k >> 1))))
        ans = (k >> 1) + maxb;
    if(mina != -1 && (ans > (mina + (k >> 1))))
      ans = (k >> 1) + mina;
    printf("%d\n", ans);
  }
  return 0;
}