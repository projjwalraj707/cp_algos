ll modMul(vector<ll> nums) {
	ll ans = 1;
	for (ll& num: nums) ans = (ans * num) % MOD;
	return ans;
}

ll modAdd(vector<ll> nums) {
	ll ans = 0;
	for (ll& num: nums) ans = (ans + num) % MOD;
	return ans;
}

ll modExp(ll p, ll k) {
	ll ans = 1;
	int mask = 1;
	ll temp = p;
	while (mask <= k) {
		if (mask & k) ans = (ans * temp) % MOD;
		temp = (temp * temp) % MOD;
		mask = mask << 1;
	}
	return ans;
}

ll modInv(ll num) {
	return modExp(num, MOD-2);
}
