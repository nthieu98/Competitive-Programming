#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int T;
int sum[N];

void prepare()
{
  for(int i = 1; i <= 1000000; i++){
    int k = i;
    int c = 0;
    while(k != 1){
      if(k&1) {
        c++;
        k++;
      }
      else{
        c++;
        k >>= 1;
      }
    }
    sum[i] = sum[i-1] + c;
  }
}

int main()
{
  int x, y;
  cin >> T;
  sum[0] = 0;
  prepare();
  for(int i = 1; i <= T; i++){
    scanf("%d %d", &x, &y);
    printf("Case #%d\n%d\n", i, sum[y]-sum[x-1]);
  }
  return 0;
}
