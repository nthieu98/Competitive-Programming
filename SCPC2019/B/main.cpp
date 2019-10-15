#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int T, R, S, E, n;
int l[N], r[N], h[N];

int main()
{
  cin >> T;

  for(int i = 1; i <= T; i++){
    double di = 0.0;
    scanf("%d %d %d", &R, &S, &E);
    scanf("%d", &n);
    r[0] = S;
    l[n+1] = E;
    for(int j = 1; j <= n; j++){
      scanf("%d %d %d", &l[j], &r[j], &h[j]);
      di += 1.0*(r[j] - l[j]);
      if(h[j] >= R) {
        di += 2.0*(h[j]-R);
        di += M_PI*R;
        di -= 1.0*2*R;
      }
      else{
        di += 2.0*(M_PI/2-asin(1.0*(R-h[j])/R))*R;
        di -= 2.0*sqrt(1.0*R*R-1.0*(R-h[j])*(R-h[j]));
      }
    }
    for(int j = 1; j <= n+1; j++) di += 1.0 * (l[j] - r[j-1]);
    printf("Case #%d\n%0.12f\n", i,di);
  }

  return 0;
}
