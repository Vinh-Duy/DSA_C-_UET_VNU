#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a,b,c;
    cin >> a>> b>> c;
    if (a + b > c && b + c > a && a + c > b){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
