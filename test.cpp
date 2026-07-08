#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> A;
int target;
int dp[1<<10];
int parent[1<<10];
int group[10];

bool solve() {
    int total = (1<<n) -1;
    fill(dp, dp + (1<<n) ,-1);
    dp[0] = 0;
    for (int i =0 ;i < (1<<n); ++i){
        if (dp[i] == -1) continue;
        for (int j = 0; j<n;j++){
            if(!(i & (1 << j))){
                int next = i | (1<<j);
                if (dp[i] + A[j] <= target){
                    int sumn = (dp[i] + A[j] == target) ? 0 : dp[i] + A[j];
                    if (dp[next] == -1){
                        dp[next] = sumn;
                        parent[next] = i;
                    }
                }
            }
        }
    }
    return dp[total] ==0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // input
    cin >> n >> k ;

    A.resize(n);
    int sum = 0;
    for (int i =0; i<n; i++){
        cin >> A[i];
        sum += A[i];
    }

    if (sum % k != 0){
        cout << "ze\n";
        return 0;
    }

    target = sum/k;

    if (!solve()){
        cout << "ze\n";
        return 0;
    }

    int curmask = (1<<n) -1;
    int curgroup = k;
    int cursum = 0;

    while (curmask > 0){
        int premask = parent[curmask];
        int diff = curmask ^ premask;
        int idx = __builtin_ctz(diff);

        group[idx] = curgroup;
        cursum += A[idx];

        if (cursum ==target){
            curgroup --;
            cursum = 0;
        }
        curmask = premask;
    }

    for (int i =0; i<n;++i){
        cout << group[i] << (i ==n-1 ? "" :" ");
    }
    cout << "\n";
    
    return 0;
}