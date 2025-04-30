#include <bits/stdc++.h>
using namespace std;

int modulo(string& str, int mod) {
	int ans = 0;
	for (char ch: str) ans = (ans * 10 + (ch-'0')) % mod;
	return ans;
}

string minusOne(string& s) {
	int lastNonZero = s.length()-1;
	while (lastNonZero >= 0 &&s[lastNonZero] == 0) lastNonZero--;
	return s.substr(0, lastNonZero) + string(1, (s[lastNonZero]-1)) + string(s.length()-lastNonZero-1, '9');
}

pair<string,int> longDivision(string& num, int divisor) {
	//returns {quotient, remainder} when num is divided by divisor
	string q;
	int rem = 0;
	for (char digit: num) {
		int temp = rem * 10 + (digit-'0');
		int q_digit = temp/divisor;
		if (q.size() || q_digit != 0) q.push_back('0'+q_digit);
		rem = temp % divisor;
	}
	return {q, rem};
}

int main() {
	string num = "1234567";
	int divisor = 8;
	pair<string, int> ans = longDivision(num, divisor);
	cout << num << " when divided by " << divisor << ", gives " << ans.first << " as quotient and " << ans.second << " as remainder.";
	return 0;
}

