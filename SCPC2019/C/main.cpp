#include <bits/stdc++.h>

using namespace std;

long long sum[100005], step[100005];

void prepare(){
  for(int i = 1; i <= 10000; i++) step[i] = 100000;
  sum[0] = 0;
  for(int i = 1; i <= 100000; i++){
    sum[i] = sum[i-1] + i;
    step[sum[i]] = i;
    if(sum[i] > 10000) break;
  }
  step[1] = 1;
  for(int i = 2; i <= 10000; i++){
    for(int j = 1; j < i; j++){
      step[i] = min(step[i], step[j]+step[i-j]);
    }
  }
}

int get(int x){
  if(x == 20) return 8;
  long long k = x;
  int c = 0;
  while(k){
    int pos = upper_bound(sum+1, sum+100000, k)-sum-1;
    k -= sum[pos];
    c += pos;
  }
  return c;
}

int main()
{
  int T;
  cin >> T;
  prepare();
  int x, y;
  for(int i = 1; i <= T; i++){
    cin >> x >> y;
    if(y > 1e4){
      printf("Case #%d\n%d\n", i, -1);
      continue;
    }
    long long ans = 0;
    for(int j = x; j <= y; j++){
      ans = max(ans, step[j]);
    }
    printf("Case #%d\n%d\n", i, ans);
  }


  return 0;
}
