#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll A = 1532839971;
const ll MOD = 1945521975;
int expo[100001];

class Hash {
public:
    vector<ll> hash, revHash;
    int n;
    Hash(string& str) {
        n = str.length();
        hash.resize(n);
        revHash.resize(n);
        hash[0] = str[0] - 'a' + 1;
        revHash[0] = str.back() - 'a' + 1;
        for (int i=1; i<n; i++) {
            hash[i] = (hash[i-1] * A + str[i] - 'a' + 1) % MOD;
            revHash[i] = (revHash[i-1] * A + str[n-1-i] - 'a' + 1) % MOD;
        }
    }
    ll findHash(int s, int e) {
        ll ans = hash[e];
        if (s != 0)
            ans = (ans + (MOD - (hash[s-1]*expo[e-s+1])%MOD)%MOD)%MOD;
        return ans;
    }
    ll findRevHash(int s, int e) { //indices s and e are w.r.t to original string (and not reversed one)
        ll ans = revHash[n-1-s];
        if (e != n-1)
            ans = (ans + (MOD - (revHash[n-e-2] * expo[e-s+1])%MOD) % MOD) % MOD;
        return ans;
    }
    ll isPalindrome(int s, int e) {
        return findHash(s, e) == findRevHash(s, e);
    }
};

int main() {
	expo[0] = 1;
	for (int i=1; i<=1e5; i++) expo[i] = (expo[i-1]*A) % MOD;
	string str = "abcba";
	Hash h(str);
	cout << h.isPalindrome(0, 4) << endl;
	return 0;
}
