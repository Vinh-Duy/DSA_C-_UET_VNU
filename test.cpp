#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a,b;
    cin >> a >> b;
    if (a == 0) {
        if (b == 0) {
            cout << "INFINITE SOLUTIONS\n";
        } else {
            cout << "NO SOLUTION\n";
        }
    } else {
        if (b % a == 0) {
            cout << -b / a << "\n";
        } else {
            cout << "NO SOLUTION\n";
        }
    }
}