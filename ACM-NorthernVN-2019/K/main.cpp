#include <bits/stdc++.h>

using namespace std;

int const N = 100005;
int const M = 1000010;

int n, x;
int mark[M], f[M][3];
int p[10];
vector<int> d[M];
vector<int> prime;

void sieve()
{
  for(int i = 2; i < M; i++) if(!mark[i]) {
    prime.push_back(i);
    for(int j = i+i; j < M; j += i){
      mark[j] = 1;
      d[j].push_back(i);
    }
  }
}

void prepare()
{
  p[1] = 10;
  for(int i = 2; i <= 7; i++) p[i] = p[i-1] * 10;
  f[0][1] = 0;
  f[0][0] = 0;
  f[1][1] = 1;
  f[1][0] = 1;
  for(int i = 2; i < M; i++) {
    for(int pl = 0; pl <= 1; pl++) {
      f[i][pl] = 1 - f[i-1][1-pl];
      int numch = upper_bound(p+1, p+8, i) - p;
      f[i][pl] = max(f[i][pl], 1 - f[i - numch][1-pl]);
      int pos = lower_bound(prime.begin(), prime.end(), i) - prime.begin();
      if(prime[pos] == i) {
        f[i][pl] = max(f[i][pl], 1- f[1][1-pl]);
      }
      else{
        int res = i;
        for(int j = 0; j < d[i].size(); j++){
          res = res / d[i][j] * (d[i][j] - 1);
        }

        f[i][pl] = max(f[i][pl], 1 - f[i - res][1-pl]);
      }
    }
  }
}

int main()
{
  int T;
  sieve();
  prepare();
  cin >> T;
  for(int _ = 1; _ <= T; _++) {
    cin >> x;
    if(f[x][1]) cout << "BACH\n";
    else cout << "KHOA\n";
  }
  return 0;
}
