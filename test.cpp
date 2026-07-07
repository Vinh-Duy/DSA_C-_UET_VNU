#include <iostream>
#include <string>

using namespace std;

long long n,k;

long long a[25];

bool Try(int i, long long sum){
    if (i == n-1){
        if (sum == k){
            return true;
        }
        return false;
    }
    if (sum > k){
        return false;
    }
    // Chon phan tu a[i+1]
    // Try(i + 1,sum + a[i+1]);
    // Try(i + 1,sum);
    return Try(i + 1,sum + a[i+1]) | Try(i + 1,sum);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // input
    cin >> n >> k;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }

    // for (int i =0; i < n;i++){
    //     cout << a[i] << endl;
    // }

    // Try(1,0);
    // Try(1,a[1]);

    bool result = Try(0,0) | Try(0,a[0]);

    if (result == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}