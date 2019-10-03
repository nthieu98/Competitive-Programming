#include <bits/stdc++.h>

using namespace std;

const int N = 100;

pair<int, int> ci[N], ca[N];
vector<int> tree;
double d[N][N], dc[N][N], dcur[N];
int mk[N];

double dis(pair<int, int> x, pair<int, int> y)
{
  return sqrt((x.first-y.first)*(x.first-y.first) + (x.second-y.second)*(x.second-y.second));
}

int main()
{
  int n, k;
  cin >> n >> k;
  int x, y;
  for(int j = 1; j <= k; j++){
    cin >> x >> y;
    ca[j] = make_pair(x, y);
  }
  for(int i = 1; i <= n-k; i++){
    cin >> x >> y;
    ci[i] = make_pair(x, y);
  }
  n-=k;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= k; j++){
      d[i][j] = dis(ci[i], ca[j]);
    }
    for(int j = 1; j <= n; j++){
      dc[i][j] = dis(ci[i], ci[j]);
    }
  }
  double ans = 1000000000.0;
  double cur;
  for(int i = 1; i <= n; i++){
    memset(mk, 0, sizeof(mk));
    tree.clear();
    mk[i] = 1;
    tree.push_back(i);
    cur = 0.0;
    double cmin;
    for(int j = 1; j <= k; j++) {
      cur += d[i][j];
      dcur[j] = d[i][j];
    }
    do{
      double p = 0.0;
      int pos;
      for(int j = 1; j <= n; j++)if(!mk[j]){
        double g = 0.0;
        for(int pc = 1; pc <= k; pc++){
          if(d[j][pc] < dcur[pc]) g = g + (dcur[pc] - d[j][pc]);
        }
        cmin = dc[tree[0]][j];
        for(int jj = 1; jj < tree.size(); jj++){
          if(cmin > dc[tree[jj]][j]) cmin = dc[tree[jj]][j];
        }
        g -= cmin;
        if(p < g){
          p = g;
          pos = j;
        }
      }
      if(p == 0.0) break;
      tree.push_back(pos);
      for(int j = 1; j <= k; j++){
        if(d[pos][j] < dcur[j]) {
          dcur[j] = d[pos][j];
        }
      }
      mk[pos] = 1;
      cur -= p;
      }while(1);
    ans = min(ans, cur);
  }
  printf("%0.5f", ans);
  return 0;
}
