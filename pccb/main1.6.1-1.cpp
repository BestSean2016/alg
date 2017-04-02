//
// Problem in p-1.6.1-0.png
//

#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>

static void do_sort(int n, int* a) {
    std::qsort(a, n, sizeof(int), [](const void*a, const void* b) {
        int arg1 = *static_cast<const int*>(a);
        int arg2 = *static_cast<const int*>(b);

        if(arg1 < arg2) return -1;
        if(arg1 > arg2) return 1;

        //  return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
        //  return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
        return 0;
    });
}

static int solve(int n, int* a) {
    do_sort(n, a);

    int len = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i] + a[j] > a[k])
                  len = std::max(len, a[i] + a[j] + a[k]);
            }
        }
    }
    return len;
}

int main(int argc, char* argv[]) {
    //get input from stdin
    //int n = 0;
    //std::cin >> n;
    //if (n < 3 or n > 100) {
    //    std::cout << " n >= 3 and n <= 100\n";
    //    return (-1);
    //}
    //int* a = new int[n];
    //for (int i = 0; i < n; i++)
    //    std::cin >> a[i];
    //delete[] len;

    int n = 5;
    int a[5] = {2, 3, 4, 5, 10};
    int len = solve(n, a);
    assert(len == 12);

    n = 4;
    int b[4] = {4, 5, 10, 20};
    len = solve(n, b);
    assert(len == 0);

    return 0;
}
