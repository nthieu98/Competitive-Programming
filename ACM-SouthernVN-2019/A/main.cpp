#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
long long x[N], y[N];
long long res;
int n;

long long _S(int i, int j, int k) {
	long long res = abs((x[i]*y[j] - x[j]*y[i]) + (x[j]*y[k] - x[k]*y[j]) + (x[k]*y[i] - x[i]*y[k]));
	return res;
}

long long _search(int ll, int rr, int l, int r) {
	int x, y, m;
	while(l+2 < r) {
		x = l + (r-l)/3;
    y = r - (r-l)/3;
    if (_S(ll, rr, x) < _S(ll, rr, y)) {
      l = x;
    } else {
      r = y;
    }
	}
	long long res = 0;
		//cout << x << ' ' << y << endl;
  for (int i = l; i <= r; i++) {
    res = max(res, _S(ll, rr, i));
  }
  return res;

}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		x[i+n] = x[i];
		y[i+n] = y[i];
	}

	x[2*n] = x[0];
	y[2*n] = y[0];

	res = 0;
	for (int i = 0; i < n; i++) {
    for (int j = i + 2; j < n; j++)
      res = max(res, _search(i, j, i, j));
	}

	printf("%0.1llf\n", 1.0 * res / 2);
	return 0;
}
