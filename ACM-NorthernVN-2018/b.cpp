#include <bits/stdc++.h>

using namespace std;
int n;
long long a[100005];
long long ans, s;

int main() {
    ios_base :: sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    sort (a, a + n);

    //n = unique(a, a + n) - a;
    a[n] = a[n - 1] + 1;
    long long min_s = 0;
    for (int i = 0; i < n; ++i) {
        min_s += a[i];
        if (a[i] != a[i + 1]) {
            ans = max(ans, s - min_s);
            min_s = 0;
        }
    }
    cout << ans;
}