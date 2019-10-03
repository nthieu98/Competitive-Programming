#include <bits/stdc++.h>

using namespace std;

const int X[4] = {1, 0, -1, 0};
const int Y[4] = {0, -1, 0, 1};
int m, n;
string s;
int v[1003][1003], d[1003][1003];
bool mark[1003][1003];
pair <int, int> S, F;
queue <pair <int, int> > q;

void bfs() {
    q.push(S);
    mark[S.first][S.second] = 1;
    pair <int, int> foo, bar;
    int d_foo;
    while (!q.empty()) {
        foo = q.front();
        q.pop();
        d_foo = d[foo.first][foo.second];
        for (int i = 0; i < 4; ++i) {
            bar = {foo.first + X[i], foo.second + Y[i]};
            if (
                bar.first < 0
                || bar.second < 0
                || bar.first >= m
                || bar.second >= n
                || v[bar.first][bar.second]
                || mark[bar.first][bar.second]
                ) {
                    continue;
            }
            mark[bar.first][bar.second] = 1;
            d[bar.first][bar.second] = d_foo + 1;
            q.push(bar);
        }
    }
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j) {
            v[i][j] |= s[j] == '#';
            if (s[j] == 'S') {
                S = {i, j};
            }
            if (s[j] == 'F') {
                F = {i, j};
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j) {
            v[i][j] |= s[j] == '#';
        }
    }
    bfs();
    cout << d[F.first][F.second] - 1;
}