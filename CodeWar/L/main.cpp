#include <bits/stdc++.h>

using namespace std;

int KA, KB, KC, DA, DB, DC;
int x[10];
int ansmin, ansmax;

int sum()
{
  int s = 0;
  for(int i = 1; i <= 9; i++) {
    if(x[i] < 0) return -1;
    s += x[i];
  }
  return s;
}

void print()
{
  for(int i = 1; i <= 9; i++) cout << x[i] << " ";
  cout << endl;
}

void brute_force()
{
  int Ux1 = min(min(KC, DB), DA);
  int Ux2 = min(DA, min(DB, KC));
  for(int x1 = abs(min(KA, 0)); x1 <= Ux1; x1++){
    for(int x4 = 0; x4 <= min(KA + x1, DC); x4++){
      for(int x2 = abs(min(KB, 0)); x2 <= Ux2 - x1; x2++) {
        for(int x5 = 0; x5 <= (KB + x2, DC); x5++){
          x[1] = x1;
          x[2] = x2;
          x[4] = x4;
          x[5] = x5;
          x[9] = KA + x[1] - x[4];
          x[8] = KB + x[2] - x[5];
          x[3] = (KC - x[1] - x[2] - x[8] - x[9]);
          if(x[3] % 2 != 0) continue;
          x[3] = x[3] / 2;
          x[6] = DB - x[1] - x[2] - x[3] - x[9];
          x[7] = DA - x[1] - x[2] - x[3] - x[8];
          int tmp = sum();
          if(tmp == -1) continue;
          ansmin = min(ansmin, tmp);
          //if(tmp == 4) print();
          ansmax = max(ansmax, tmp);
        }
      }
    }
  }
}

void cheat()
{
  int Ux1 = min(min(KC, DB), DA);
  int Ux2 = min(DA, min(DB, KC));
  x[1] = Ux1;
  x[2] = Ux2 - x[1];
  x[4] = 0;
  x[5] = 0;
  x[9] = KA + x[1] - x[4];
  x[8] = KB + x[2] - x[5];
  x[3] = (KC - x[1] - x[2] - x[8] - x[9]);
  if(x[3] % 2 != 0) {
    x[4] ++;
    x[9] --;
    x[3] ++;
  }
  x[3] = x[3] / 2;
  x[6] = DB - x[1] - x[2] - x[3] - x[9];
  x[7] = DA - x[1] - x[2] - x[3] - x[8];
   int tmp = sum();
  if(tmp == -1) return;
  ansmin = min(ansmin, tmp);
  //if(tmp == 4) print();
  ansmax = max(ansmax, tmp);

}

int main()
{
  freopen("inp.txt", "r", stdin);
  cin >> KA >> KB >> KC >> DA >> DB >> DC;
  ansmin = 1e9;
  ansmax = -1;
  //brute_force();
  cheat();
  if(ansmin == 1e9 || ansmax == -1){
    cout << -1;
  }
  else {
    cout << ansmin << " " << ansmax;
  }
  return 0;
}
