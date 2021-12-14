#include <bits/stdc++.h>

using namespace std;

#define int long long int

string removeLeadingZeros(string str) {

    const regex pattern("^0+(?!$)");

    // Replaces the matched
    // value with given string
    str = regex_replace(str, pattern, "");
    return str;
}

string toBinary(int n) {
    string binary = "";
    while (n) {
        binary += (n % 2 + '0');
        n /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

int binaryToDecimal(string s) {
    int ans = 0;
    string s_copy = s;
    reverse(s_copy.begin(), s_copy.end());

    int multiplier = 1;
    for (auto i: s_copy) {
        ans += (multiplier * (i - '0'));
        multiplier *= 2;
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;
    //cin>>t;
    while (t--) {
        int x = 29;
        string bin = toBinary(x);
        int dec = binaryToDecimal(bin);
        cout << bin << endl;
        cout << dec << endl;
    }
}