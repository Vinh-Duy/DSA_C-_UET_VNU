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

set<vector<int> > a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // input
    cin >> n >> k;
    // __builtin_popcount(n) la so bit 1 trong bieu dien nhi phan cua n
    // next_permutation(s) liet ke hoan vi tiep theo cua tap s
    for (int i = 0; i < (1<<n);i++){
        if (__builtin_popcount(i) == k){
            vector<int> b;
            for (int j =0; j < n;j++){
                if ((i>>j)&1){
                    b.push_back(j+1);
                }
            }
            do
            {
                a.insert(b);
            } while (next_permutation(b.begin(),b.end()));
        }
    }

    // vector<int> s;
    // s.push_back(1);
    // s.push_back(2);
    // s.push_back(3);
    // s.push_back(4);
    // In ra tat ca hoan vi cua mang s
    // do
    // {
    //     for (vector<int>::iterator d=s.begin();d!=s.end();d++){
    //         cout << *d << " ";
    //     }
    //     cout << endl;
    // } while (next_permutation(s.begin(),s.end()));
    

    for (set<vector<int> >::iterator c=a.begin();c!=a.end();c++){
        for (vector<int>::const_iterator x=(*c).begin();x!=(*c).end();x++){
            cout << *x << " ";
        }
        cout << endl;
    }

    return 0;
}