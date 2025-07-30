#include <bits/stdc++.h>
using namespace std;

ll findGCD(ll a, ll b) {
	if (!b) return a;
	return findGCD(b, a%b);
}

int main() {
	return 0;
}

