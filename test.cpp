#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int n, m, res[N][N];
bool visited[N][N];
bool found = false;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool inside(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void backtrack(int x, int y, int curStep) {
    visited[x][y] = true;
    res[x][y] = curStep;

    if (curStep == n * m) {
        found = true;
        return;
    }

    for (int k = 0; k <= 7; k++) {
        int x1 = x + dx[k];
        int y1 = y + dy[k];
        
        if (inside(x1, y1) && !visited[x1][y1]) {
            backtrack(x1, y1, curStep + 1);
            
            if (found) return;
            
            visited[x1][y1] = false;
            res[x1][y1] = 0;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (cin >> n >> m) {
        backtrack(1, 1, 1);
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << res[i][j] << (j == m ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}