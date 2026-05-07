// Solution to https://atcoder.jp/contests/abc456/tasks/abc456_b
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int main(){
  int temp;
  map<int, map<int, int>> counts_map;
  int num[] = {4, 5, 6};
  for(int i = 0; i < 3; i++){
    counts_map[i] = map<int, int>();
    counts_map[i][4] = 0; counts_map[i][5] = 0; counts_map[i][6] = 0;
    for(int j = 0; j < 6; j++){
      scanf("%d", &temp);
      if(temp >=4 && temp <=6){
        counts_map[i][temp] = counts_map[i][temp] + 1;
      }
    }
  }
  int product = 0;
  do{
      
      int temp_product = 1;
    for(int i=0; i < 3; i++){
      temp_product *= counts_map[i][num[i]];
    }
    product += temp_product;
  } while(next_permutation(num, num + 3));
  printf("%f\n", product / (float) 216);
}