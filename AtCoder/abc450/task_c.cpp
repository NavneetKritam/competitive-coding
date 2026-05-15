// Solution to https://atcoder.jp/contests/abc450/tasks/abc450_c
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main(){
  int h, w, i, j;
  vector<bool> bw;
  string s;
  cin >> h >> w;
  for(i = 0; i < h; i++){
    cin >> s;
    for(j = 0; j < w; j++){
      if(s[j] == '#')
        bw.push_back(false);
      else
        bw.push_back(true);
    }
  }
  vector<bool> vis(h * w, false);
  stack<int> walk;
  int ans = 0, mini, minj, maxi, maxj, posi, posj;
  for(i = 0; i < h; i++){
    for(j = 0; j < w; j++){
      if(vis[i * w + j] || !bw[i * w + j])
        continue;
      walk.push(i * w + j);
      mini = i; maxi = i; minj = j; maxj = j;
      while(!walk.empty()){
        posi = walk.top() / w; posj = walk.top() % w;
        walk.pop();
        if(vis[posi * w + posj] || !bw[posi * w + posj])
          continue;
        mini = (posi < mini) ? posi : mini; maxi = (posi > maxi) ? posi : maxi;
        minj = (posj < minj) ? posj : minj; maxj = (posj > maxj) ? posj : maxj;
        vis[posi * w + posj] = true;
        if(posi > 0)
          walk.push((posi - 1) * w + posj);
        if(posi < h - 1)
          walk.push((posi + 1) * w + posj);
        if(posj > 0)
          walk.push(posi * w + posj - 1);
        if(posj < w - 1)
          walk.push(posi * w + posj + 1);
      }
      if(mini == 0 || maxi == (h - 1) || minj == 0 || maxj == (w - 1))
        continue;
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}