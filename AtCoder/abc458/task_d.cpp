// Solution to https://atcoder.jp/contests/abc458/tasks/abc458_d
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

int main(){
  int x, a, b, q;
  scanf("%d", &x);
  int median = x;
  priority_queue<int, vector<int>> l;
  priority_queue<int, vector<int>, greater<int>> g;
  scanf("%d", &q);
  while(q--){
    scanf("%d %d", &a, &b);
    if(a > b)
      swap(a, b);
    if(a <= median && b >= median){
      l.push(a);
      g.push(b);
    }
    else{
      if(a >= median && b >= median){
        g.push(a);
        g.push(b);
        l.push(median);
        median = g.top();
        g.pop();
      }
      else{
        l.push(a);
        l.push(b);
        g.push(median);
        median = l.top();
        l.pop();
      }
    }
    printf("%d\n", median);
  }
}