#include <iostream>
#include <string>

using namespace std;

long long n,k;

long long a[25];

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

    for (int i = 0; i < (1<<n);i++){
        long long sum = 0;
        for(int j = n-1; j >=0;j--){
            if ((i>>j)&1){
                sum += a[j];
            } 
        }
        if (sum == k){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}