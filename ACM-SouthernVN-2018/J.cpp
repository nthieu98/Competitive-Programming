#include <bits/stdc++.h>

using namespace std;

enum {MAXN = 1000005};

int n;
int a[MAXN];
int f[MAXN][12];

// int e() {
//     int num = 0, res = 0;
//     for (int i = 0; i < n; ++i) {
//         num = (12 - (a[i] - num + 12) % 12) % 12;
//         res += num;
//     }
//     return res;
// }

// int f() {
//     int num = 0, res = 0;
//     for (int i = n - 1; i >= 0; --i) {
//         num = (num + a[i]) % 12;
//         res += num;
//     }
//     return res;
// }

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= 12;
    }
    // cout << f() << endl;
    // cout << e() << endl;
    // cout << min(f(), e());

    int step = 0;
    for (int j = 0; j < 12; ++j) {
        f[0][j] = (a[0] - j + 12) % 12;
        // cout << f[0][j] << endl;
    }
    for (int j = 0; j < 12; ++j) {
        step = (a[1] - j + 12) % 12;
        f[1][j] = f[0][(12 - step) % 12] + step;
        // cout << f[0][j] << endl;
    }
    for (int i = 2; i < n; ++i) {
        for (int j = 0; j < 12; ++j) {
            step = (a[i] - j + 12) % 12;
            f[i][j] = f[i - 1][(12 - step) % 12]  + step;
            if (a[i] == j)
                f[i][j] = min(f[i][j], f[i - 1][0]);
        }
    }
    int ans = 0x0fffffff;
    for (int j = 0; j < 12; ++j) {
        ans = min(ans, f[n - 1][j] + (12 - j) % 12);
    }
    cout << ans;
 }
