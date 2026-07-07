#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <cinttypes>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <istream>
#include <ostream>

using namespace std;

int n,k;

set<set<int> > a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // input
    cin >> n >> k;
    // __builtin_popcount(n) la so bit 1 trong bieu dien nhi phan cua n
    
    for (int i = 0; i < (1<<n);i++){
        if (__builtin_popcount(i) == k){
            set<int> b;
            for (int j =0; j < n;j++){
                if ((i>>j)&1){
                    b.insert(j+1);
                }
            }
            a.insert(b);
        }
    }

    for (set<set<int> >::iterator c=a.begin();c!=a.end();c++){
        for (set<int>::iterator x=(*c).begin();x!=(*c).end();x++){
            cout << *x << " ";
        }
        cout << endl;
    }

    return 0;
}