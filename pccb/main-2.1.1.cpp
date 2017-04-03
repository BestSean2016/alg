//
// recursion for Fibonacci sequence
//

#include <cstddef>
#include <iostream>
#include <vector>

static uint64_t count = 0;
uint64_t fib1(uint64_t n) {
    if (n <= 1) return n;
    count++;
    return fib1(n - 1) + fib1(n - 2);
}

static std::vector<uint64_t> memo;
static uint64_t fib2_(uint64_t n) {
    if (n <= 1) return memo[n] = n;
    if (memo[n] > 0) return memo[n];
    count++;
    return memo[n] = fib2_(n - 1) + fib2_(n - 2);
}
uint64_t fib2(uint64_t n) {
    memo.clear();
    memo.assign(n + 1, 0);
    count = 0;
    return fib2_(n);
}

int main() {
    uint64_t n;
    std::cin >> n;
    //std::cout << fib1(n) << ", ";
    //std::cout << count << std::endl;
    std::cout << fib2(n) << ", ";
    std::cout << count << std::endl;

    for(auto f : memo)
        std::cout << f << ", ";

    std::cout << std::endl;

    return (0);
}
