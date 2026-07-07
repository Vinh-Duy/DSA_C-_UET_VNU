#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a;
    getline(cin, a);
    for (int i=0; i<3;i++){
        cout << a<<"\n";
    }
    return 0;
}
