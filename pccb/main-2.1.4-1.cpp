//
// select some number from a array A of n integers
// to make the sum of these number equals a number k
// 1 <= n <= 20
// -10^8 <= a(i) <= 10^8
// -10^8 <= k <= 10^8
//

#include <iostream>
#include <vector>
#include <cassert>

using std::vector;
using std::cout;
using std::endl;

static int n, k;
static vector<int> a;

bool dfs(int i, int sum) {
    cout << "i = " << i << ", sum = " << sum << endl;
    if (i == n) return sum == k;
    if (dfs(i + 1, sum)) return true;
    if (dfs(i + 1, sum + a[i])) return true;
    return false;
}


int main() {
    a.assign({1, 2, 4, 7});
    n = 4, k = 13;
    assert(dfs(0, 0) == true);

    k = 15;
    assert(dfs(0, 0) == false);

    return 0;
}

/*
i = 0, sum = 0
i = 1, sum = 0
i = 2, sum = 0
i = 3, sum = 0
i = 4, sum = 0
i = 4, sum = 7
i = 3, sum = 4
i = 4, sum = 4
i = 4, sum = 11
i = 2, sum = 2
i = 3, sum = 2
i = 4, sum = 2
i = 4, sum = 9
i = 3, sum = 6
i = 4, sum = 6
i = 4, sum = 13
 */