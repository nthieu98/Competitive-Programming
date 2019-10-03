#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const int N = 1003;

int n, m;
int sx, sy, fx, fy;
int a[N][N], d[N][N], mk[N][N];
deque <pair<int, int> > q;

void BFS()
{
  q.push_back(make_pair(sx, sy));
  mk[sx][sy] = 1;
  while(!q.empty()){
    pair<int, int> u = q.front();
    int xx = u.first;
    int yy = u.second;
    q.pop_front();
    for(int id = 0; id < 4; id++){
      int nx = xx+dx[id];
      int ny = yy+dy[id];
      if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
      if(!mk[nx][ny] && !a[nx][ny]){
        mk[nx][ny] = 1;
        d[nx][ny] = d[xx][yy] + 1;
        q.push_back(make_pair(nx, ny));
      }
    }
  }
}

int main()
{
  freopen("inp.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  string st;
  for(int i = 1; i <= n; i++){
    cin >> st;
    for(int j = 0; j < st.size(); j++){
      if(st[j] == 'S'){
        sx = i;
        sy = j+1;
      }
      else if(st[j] == 'F'){
        fx = i;
        fy = j+1;
      }
      else if(st[j] == '#'){
        a[i][j+1] = 1;
      }
    }
  }
  for(int i = 1; i <= n; i++){
    cin >> st;
    for(int j = 0; j < st.size(); j++){
      if(st[j] == '#'){
        a[i][j+1] = 1;
      }
    }
  }
  BFS();
  cout << d[fx][fy]-1;
  return 0;
}
