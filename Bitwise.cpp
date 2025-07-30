#include <bits/stdc++.h>
using namespace std;

int MSB(int num) {
	//MostSignificantBits(b'1011) == 3
	return (int)log2(num);
	//Alternate way: 
	//return 31 - __builtin_clz(num);
}

int invertBits(int num) {
	//invertBits(b'1001110) == b'0110001
	int numOfBits = (int)log2(num)+1;
	return ((1 << numOfBits) - 1) ^ num;
}

int main() {
	cout << invertBits(4);
	return 0;
}
