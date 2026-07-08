#include <bits/stdc++.h>

using namespace std;

int n,k,target;
vector<int> A;
vector<int> group;
vector<int> ans;

bool backtrack(int idx){
    if (idx == n){
        return true;
    }

    for (int j = 0; j<k; j++){
        if(group[j] + A[idx] <=target){
            group[j] += A[idx];
            ans[idx] = j+1;
            if (backtrack(idx+1)) return true;
            group[j] -= A[idx];
        }
    if (group[j]==0) break;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // input
    cin >> n >> k ;
    A.resize(n);
    ans.resize(n);
    group.assign(k,0);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i];
    }

    if (sum % k != 0) {
        cout << "ze\n";
        return 0;
    }

    target = sum / k;

    if (backtrack(0)) {
        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    } else {
        cout << "ze\n";
    }

    return 0;
}