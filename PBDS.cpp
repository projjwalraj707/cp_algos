#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;
//less<int>: comparator, other comparators: greater<int>, less_equal<int> ...

int main() {
	PBDS A;
	A.insert(5);
	A.insert(2);
	int orderThElement = *A.find_by_order(1); // returns kth element
	int cntSmallerThan = A.order_by_key(5); //returns the number of elements smaller than key; but < or <= ??? Depends upon the comparator;
	//ALl methods of a set - lower_bound(), upper_bound(), erase() are also supported;
	return 0;
}
