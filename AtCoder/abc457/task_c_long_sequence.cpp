// Solution to https://atcoder.jp/contests/abc457/tasks/abc457_c
#include <cstdio>
#include <vector>
using namespace std;

int main(){
  vector<vector<int>> a;
  int i, j, temp, l, n, p;
  long long k;
  scanf("%d %lld", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &l);
    a.push_back(vector<int>());
    for(j = 0; j < l; j++){
      scanf("%d", &temp);
      a[i].push_back(temp);
    }
  }
  int ansi, ansj;
  long long mul;
  for(i = 0; i < n; i++){
    scanf("%d", &temp);
    if(k > 0){
      mul = temp * a[i].size();
      if(mul < k)
        k -= mul;
      else{
        ansi = i;
        ansj = k % a[i].size();
        if(ansj == 0)
          ansj = a[i].size() - 1;
        else
          ansj--;
        k = 0;
      }
        
    }
  }
  printf("%d\n", a[ansi][ansj]);
  return 0;
}