#include <bits/stdc++.h>

using namespace std;

int Cx[10][10] = {{0, 1, 1, 1, 0, -1, -1, -1},
                  {0, 1, 1, 1, 0, -1, -1, -1},
                  {0, 1, 0, -1},
                  {-1, 1, 1, -1},
                  {1, 2, 2, 1, -1, -2, -2, -1}};
int Cy[10][10] = {{1, 1, 0, -1, -1, -1, 0, 1},
                  {1, 1, 0, -1, -1, -1, 0, 1},
                  {1, 0, -1, 0},
                  {1, 1, -1, -1},
                  {2, 1, -1, -2, -2, -1, 1, 2}};

int nd[10] = {8, 8, 4, 4, 8};

int n, Kx, Ky;
string pos[10];
int a[10][10];
int mark[10][10], mark2[10][10], mark3[10][10];


bool isCheckmated(int x, int y, int m[10][10])
{
  if(m[x][y]) return true;
  return false;
}

void genMoveMap(int (&m)[10][10])
{
  memset(m, 0, sizeof(m));
  for(int i = 1; i <= 8; i++) {
    for(int j = 1; j <= 8; j++) {
      if(a[i][j] < 6 && a[i][j] > 0) {
        int step = (a[i][j] != 5 && a[i][j] != 1) ? 8 : 1;
        int t = a[i][j] - 1;
        for(int d = 0; d < nd[t]; d++) {
          for(int k = 1; k <= step; k++) {
            int nx = i + Cx[t][d] * k;
            int ny = j + Cy[t][d] * k;
            if(nx < 1 || nx > 8 || ny < 1 || ny > 8) break;
            //if(nx == 5 && ny == 3 && a[nx][ny] == 6) cout << i << " " << j << " " << a[i][j] << endl;
            m[nx][ny] ++;
            if(a[nx][ny]) break;
          }
        }
      }
    }
  }
}

bool moveKing()
{
  for(int i = 0; i < nd[0]; i++){
    int nx = Kx + Cx[0][i];
    int ny = Ky + Cy[0][i];
    if(nx < 1 || nx > 8 || ny < 1 || ny > 8) continue;
    int tmp = a[nx][ny];
    if(tmp == 1) return true;
    else if((tmp > 1 && tmp <= 5) || !tmp){
      a[nx][ny] = a[Kx][Ky];
      a[Kx][Ky] = 0;
      genMoveMap(mark2);
      a[Kx][Ky] = a[nx][ny];
      a[nx][ny] = tmp;
      if(!isCheckmated(nx, ny, mark2)){
        return true;
      }

    }

  }
  return false;
}

bool moveChess()
{
  for(int i = 1; i <= 8; i++) {
    for(int j = 1; j <= 8; j++) {
      if(a[i][j] >= 7 && a[i][j] <= 10) {
        int step = (a[i][j] != 10) ? 8 : 1;
        int t = a[i][j] - 6;
        for(int d = 0; d < nd[t]; d++) {
          for(int k = 1; k <= step; k++) {
            int nx = i + Cx[t][d] * k;
            int ny = j + Cy[t][d] * k;
            int tmp = 0;
            if(nx < 1 || ny > 8 || ny < 1 || ny > 8) break;
            if(a[nx][ny] == 1) return true;
            else if(a[nx][ny] >= 6 && a[nx][ny] <= 10) break;
            else if(a[nx][ny] > 1 && a[nx][ny] <= 5) tmp = a[nx][ny];
            a[nx][ny] = a[i][j];
            a[i][j] = 0;
            genMoveMap(mark3);
            a[i][j] = a[nx][ny];
            a[nx][ny] = tmp;
            if(!isCheckmated(Kx, Ky, mark3)){
              return true;
            }

            if(tmp) break;
          }
        }
      }
    }
  }
  return false;
}

bool whiteMove()
{
  for(int i = 1; i <= 8; i++) {
    for(int j = 1; j <= 8; j++) {
      if(a[i][j] < 6 && a[i][j] >= 1) {
        int step = (a[i][j] != 5 && a[i][j] != 1) ? 8 : 1;
        int t = a[i][j] - 1;
        for(int d = 0; d < nd[t]; d++) {
          for(int k = 1; k <= step; k++) {
            int nx = i + Cx[t][d] * k;
            int ny = j + Cy[t][d] * k;
            int tmp = 0;
            if(nx < 1 || nx > 8 || ny < 1 || ny > 8) break;
            if(a[nx][ny] >= 1 && a[nx][ny] <= 5) break;
            else if (a[nx][ny] >= 6 && a[nx][ny] <= 10) tmp = a[nx][ny];
            a[nx][ny] = a[i][j];
            a[i][j] = 0;
            genMoveMap(mark);
            if(isCheckmated(Kx, Ky, mark)) {
              if(!moveKing() && !moveChess()){
                return true;
              }
            }
            a[i][j] = a[nx][ny];
            a[nx][ny] = tmp;
            if(tmp) break;
          }
        }
      }
    }
  }
  return false;
}


bool process()
{
  for(int i = 1; i <= n; i++) {
    char c0 = pos[i][0];
    int c2 = pos[i][1] - 'a' + 1;
    int c1 = pos[i][2] - '0';
    if(c0 == 'k'){
      a[c1][c2] = 1;
    }
    else if(c0 == 'q'){
      a[c1][c2] = 2;
    }
    else if(c0 == 'r'){
      a[c1][c2] = 3;
    }
    else if(c0 == 'b'){
      a[c1][c2] = 4;
    }
    else if(c0 == 'n'){
      a[c1][c2] = 5;
    }
    else if(c0 == 'K'){
      a[c1][c2] = 6;
      Kx = c1;
      Ky = c2;
    }
    else if(c0 == 'Q'){
      a[c1][c2] = 7;
    }
    else if(c0 == 'R'){
      a[c1][c2] = 8;
    }
    else if(c0 == 'B'){
      a[c1][c2] = 9;
    }
    else {
      a[c1][c2] = 10;
    }
  }
  return whiteMove();
}

int main()
{
  freopen("inp.txt", "r", stdin);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> pos[i];

  }
  if(process()) cout << "true";
  else cout << "false";
  return 0;
}
