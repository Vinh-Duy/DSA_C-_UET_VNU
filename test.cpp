#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a;
    cin >> a;
    if (a>=9.0){
        cout << "VERY TOXIC";
    }
    else if (a >= 5.0 && a < 9.0)
    {
        cout << "TOXIC";
    }
    else if (a<5.0)
    {
        cout << "SAFE";
    }
    
    return 0;
}