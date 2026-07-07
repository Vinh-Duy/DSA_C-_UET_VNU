#include <iostream>
#include <string>

using namespace std;

int n;

void Try(int i,string s){
    if (i==n){
        cout << s << endl;
        return;
    }
    if (s.back() == 'A'){
        Try(i + 1,s + 'B');
        Try(i + 1,s + 'C');
    }
    else if (s.back() == 'B'){
        Try(i + 1,s + 'A');
        Try(i + 1,s + 'C');
    }
    else {
        Try(i + 1,s + 'A');
        Try(i + 1,s + 'B');
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    Try(1,"A");
    Try(1,"B");
    Try(1,"C");

    return 0;
}