#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class SegTree {
public:
	vector<ll> tree;
	int N;
	SegTree(const int n) {
		N = n;
		while (__builtin_popcount(N) != 1) N++;
		tree.resize(2*N);
	}
	SegTree(const vector<int>& arr) {
		N = arr.size();
		while (__builtin_popcount(N) != 1) N++;
		tree.resize(2*N); //may require changes, e.g. initialize with INFINITY in case of min-max problem
		for (int i=0; i<arr.size(); i++) tree[i+N] = arr[i];
		for (int i=N-1; i>0; i--) tree[i] = tree[2*i] + tree[2*i+1]; //may require changes
	}
	ll f(int ql, int qr, ll newVal, int node, int l, int r) {
		if (ql > r || qr < l) return 0;
		if (ql <= l && qr >= r) {
			if (newVal != -1e18) tree[node] = newVal;
			return tree[node];
		}
		int mid = (l+r)/2;
		ll sum = f(ql, qr, newVal, 2*node, l, mid) + f(ql, qr, newVal, 2*node+1, mid+1, r); //may require changes
		tree[node] = tree[2*node] + tree[2*node+1]; //may require changes
		return sum;
	}
	ll f(int ql, int qr, ll newVal = -1e18) {
		return f(ql, qr, newVal, 1, 0, N-1);
	}
};

int main() {
	int n, q; cin>>n>>q;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	SegTree st(arr);
	while (q--) {
		int type, a, b; cin>>type>>a>>b;
		if (type == 1) st.f(a-1, a-1, b);
		else cout << st.f(a-1, b-1) << '\n';
	}
	return 0;
}

