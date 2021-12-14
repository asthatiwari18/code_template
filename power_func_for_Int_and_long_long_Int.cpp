#include <bits/stdc++.h>

using namespace std;

#define int long long int

int power(int x,  int y)
{
    int temp;
    if( y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;
    //cin>>t;
    while (t--) {
        int x = 29;
        int y = 3;
        cout << power(29,3) << endl;
    }
}
