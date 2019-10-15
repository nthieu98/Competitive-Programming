#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
  freopen("inp.txt", "w", stdout);
  srand(time(0));
  int n = rand() % 10 + 1;
  cout << n << endl;
  for(int i = 1; i <= n+3; i++){
    int s = rand() % 2;
    int x = rand() % 10 + 1;
    if(s) cout << "-";
    cout << x << " ";
  }
}
