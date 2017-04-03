#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cstddef>
#include <cstdlib>
#include <cassert>

using std::cout;
using std::endl;
using std::vector;
using std::function;

typedef const void* CPVOID;

/* Loop invariants and the correctness of insertion sort
 * I NSERTION-SORT (A)
1 for j = 2 to A.length
2     key = A[j]
3     // Insert A[j] into the sorted sequence A[1 ... j-1].
4     i = j - 1
5     while i > 0 and A[i] > key
6         A[i + 1] = A[i]
7         i = i - 1
8     A[i] = key
*/


template <typename T>
void insertion_sort(T* A, int64_t size,
                    function<int(CPVOID, CPVOID)> cmp) {
    for(int64_t j = 1; j < size; ++j) {
        int64_t i = j - 1;
        for (; i >= 0 and (cmp(A + i, A + j) > 0); --i)
            A[i + 1] = A[i];
        A[i] = A[j];
    }
}

int cmpint(CPVOID a, CPVOID b) {
    if (*(int*)a == *(int*)b) return 0;
    if (*(int*)a >  *(int*)b) return 1;
    if (*(int*)a <  *(int*)b) return -1;

    return (0);
}

int main() {
    srand(time(0));
    int N = rand();
    cout << N << endl;

    int* A = new int[N];
    for (int i = 0; i < N; ++i)
        A[i] = rand();

    insertion_sort(A, N, cmpint);

    for (int i = 1; i < N; ++i)
        assert(A[i] >= A[i - 1]);

    return 0;
}