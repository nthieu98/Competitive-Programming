#include <bits/stdc++.h>

using namespace std;

int main()
{
  freopen("inp.txt", "w", stdout);
  srand(time(0));
  int n = 10;
  int m = rand() % 25 + 1;
  cout << n << " " << m << endl;
  for(int i = 1; i <= n; i ++){
    int x = rand() % 5 + 1;
    cout << x << " ";
  }
  return 0;
}
