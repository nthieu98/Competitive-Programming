#include <bits/stdc++.h>

using namespace std;

int R, C, H, V;
int a[110][110], sum[110][110];
vector<int> pos;

int get(int xu, int yu, int xd, int yd){
  return sum[xd][yd] - sum[xu][yd] - sum[xd][yu] + sum[xu][yu];
}

int run(){
  memset(sum, 0, sizeof(sum));
  pos.clear();
  sum[1][1] = a[1][1];
  for(int i = 1; i <= R; i++)
    for(int j = 1; j <= C; j++)
      sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + a[i][j];
  if(!sum[R][C]) return 1;
  if((sum[R][C]%(H+1) != 0)|| (sum[R][C]%((H+1)*(V+1)) != 0)) return 0;
  int p = sum[R][C] / (H+1);
  int c = 0;
  int pre = 0;
  pos.push_back(0);
  for(int i = 1; i <= R; i++)
    if(sum[i][C] - sum[pre][C] == p) {
      pos.push_back(i);
      pre = i;
    }
  if(pos.size()-1 != H+1) return 0;
  p = sum[R][C] / ((H+1)*(V+1));
  c = 0;
  pre = 0;
  for(int j = 1; j <= C; j++){
    int flag = 0;
    for(int i = 0; i < pos.size()-1; i++){
      int k = get(pos[i], pre, pos[i+1], j);
      if(k != p) {
        flag = 1;
        break;
      }
    }
    if(!flag){
      pre = j;
      c++;
    }
  }
  if(c != V+1) return 0;
  return 1;
}

int main()
{
  freopen("inp.txt", "r", stdin);
  int T;
  string st;
  cin >> T;
  for(int i = 1; i <= T; i++){
    cin >> R >> C >> H >> V;
    for(int j = 1; j <= R; j++){
      cin >> st;
      for(int k = 0; k < st.size(); k++)
        if(st[k] == '@') a[j][k+1] = 1;
        else a[j][k+1] = 0;
    }
    cout << "Case #" << i << ": ";
    if(run()) cout << "POSSIBLE\n";
    else  cout << "IMPOSSIBLE\n";
  }
  return 0;
}
