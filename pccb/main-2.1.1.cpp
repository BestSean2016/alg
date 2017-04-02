//
// recursion for Fibonacci sequence
//

#include <iostream>
#include <vector>

static int count = 0;
int fib1(int n) {
    if (n <= 1) return n;
    count++;
    return fib1(n - 1) + fib1(n - 2);
}

static std::vector<int> memo;
static int fib2_(int n) {
    if (n <= 1) return memo[n] = n;
    if (memo[n] > 0) return memo[n];
    count++;
    return memo[n] = fib2_(n - 1) + fib2_(n - 2);
}
int fib2(int n) {
    memo.clear();
    memo.resize(n + 1);
    count = 0;
    return fib2_(n);
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fib1(n) << ", ";
    std::cout << count << std::endl;
    std::cout << fib2(n) << ", ";
    std::cout << count << std::endl;

    for(auto f : memo)
        std::cout << f << ", ";

    std::cout << std::endl;

    return (0);
}
