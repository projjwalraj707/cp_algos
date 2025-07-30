#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MSB(ll num) {
        //MostSignificantBits(b'1011) == 3
        return (ll)log2(num);
        //Alternate way:
        //return 31 - __builtin_clz(num);
}

int main() {
	ll num = LLONG_MAX;
	cout << MSB(num);
	return 0;
}

