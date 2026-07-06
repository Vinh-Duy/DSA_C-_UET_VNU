#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);

    int n;
    cin >> n;
    for(int i = 0;i<(1<<n);++i){
        for (int j = n-1; j>=0;--j){
            cout << ((i>>j)&1);
        }
        cout << endl;
    }
    return 0; 
}