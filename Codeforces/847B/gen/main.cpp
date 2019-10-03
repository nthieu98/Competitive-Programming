#include <bits/stdc++.h>

using namespace std;

int n;
int dd[1000];

int main()
{
  freopen("inp.txt", "w", stdout);
  srand(time(0));
  int n = rand() % 20 + 1;
  cout << n << endl;
  for(int i = 1; i <= n; i++){

    int x = rand() % 100 +1;
    while(dd[x]) x = rand()%100+1;
    cout << x << " ";
  }
  return 0;
}
