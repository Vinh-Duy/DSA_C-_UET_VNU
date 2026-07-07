#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b,c,x,y,z;
    cin >> a >> b >> c >> x >> y >> z;
    if (c < z) {
            cout << "1\n";
        } 
        else if (c == z && b < y) {
            cout << "1\n";
        } 
        else if (c == z && b == y && a < x) {
            cout << "1\n";
        }
        else {
            cout << "2\n";
        }
    return 0;
}