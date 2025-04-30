//https://cp-algorithms.com/string/z-function.html
#include <bits/stdc++.h>
using namespace std;

int cntOccurences(string& str, string& pattern, int n, int m, vector<int>& piTable) {
	int itr1 = 0, itr2 = 0, ans = 0;
	while (itr1 < n) {
		if (str[itr1] == pattern[itr2]) {
			itr1++;
			itr2++;
			if (itr2 == m) {
				itr2 = piTable.back();
				ans++;
			}
		}
		else if (itr2 == 0) itr1++;
		else itr2 = piTable[itr2-1];
	}
	return ans;
}

vector<int> KMP(string& pattern) {
	int n = pattern.length();
	vector<int> ans(n);
	int s = 0, e = 1;
	while (e < n) {
		if (pattern[s] == pattern[e]) ans[e++] = ++s;
		else if (s != 0) s = ans[s-1];
		else e++;
	}
	return ans;
}

vector<int> Z_Func(string& str) {
	int n = str.size();
	vector<int> ans(n);
	int s = 0, e = 0;
	for (int i=1; i<n; i++) {
		if (i < e) ans[i] = min(ans[i-s], e-i);
		while (i+ans[i] < n && str[ans[i]] == str[i+ans[i]]) ans[i]++;
		if (i+ans[i] > e) {
			s = i;
			e = i+ans[i];
		}
	}
	return ans;
}

int main() {
	string str = "abcabcabcabc";
	string pattern = "abc";
	vector<int> piTableForPattern = KMP(pattern);
	for (int x: Z_Func(str)      ) cout << x << ' '; cout << '\n';
	for (int x: piTableForPattern) cout << x << ' '; cout << '\n';
	int cnt = cntOccurences(str, pattern, str.length(), pattern.length(), piTableForPattern);
	cout << cnt << endl;
	return 0;
}

