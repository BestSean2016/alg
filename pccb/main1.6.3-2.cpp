//
// Problem in p-1.6.3-2.png
//

//
// check does the ka + kb = m - kc - kd exists or not
// for O(n^2)
//

#include <vector>
#include <set>
#include <cstddef>
#include <cassert>


static std::set<int> sum_of_two;
static void get_all_sum_of_two(std::vector<int>& N) {
  for (size_t a = 0; a < N.size(); ++a)
      for (size_t b = 0; b < N.size(); ++b)
          sum_of_two.insert(N[a] + N[b]);
}

int solve(std::vector<int>& N, int m) {
    get_all_sum_of_two(N);
    for (size_t c = 0; c < N.size(); ++c)
        for (size_t d = 0; d < N.size(); ++d)
            if (sum_of_two.find(m - N[c] - N[d]) != sum_of_two.end())
                return 1;

    return 0;
}


int main() {
    std::vector<int> N({1, 3, 5});
    assert(solve(N, 10) == 1);
    assert(solve(N, 9) == 0);
    return 0;
}