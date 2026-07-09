#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int n, m, res[N][N], curStep = 1;
bool visited[N][N];
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

// hàm kiểm tra ô (x, y) có nằm trong bảng chữ nhật nxm không
bool inside(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

bool success() {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (!visited[i][j]) return false;
    }
    return true;
}

void backtrack(int x, int y) {
    visited[x][y] = true;
    res[x][y] = curStep;
    curStep++;
    if (success()) return;
    for (int k = 0; k <= 7; k++) {
        int x1 = x + dx[k];
        int y1 = y + dy[k];
        if (inside(x1, y1) && !visited[x1][y1]) {
            backtrack(x1, y1);
            if (success()) return;
            visited[x1][y1] = false;
            res[x1][y1] = 0;
            curStep--;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n >> m;

    backtrack(1, 1);
    
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cout << res[i][j] << " \n"[j == m];

    return 0;
}