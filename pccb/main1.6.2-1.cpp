/*
Description

        An army of ants walk on a horizontal pole of length l cm, each with a constant speed of 1 cm/s. When a walking ant reaches an end of the pole, it immediatelly falls off it. When two ants meet they turn back and start walking in opposite directions. We know the original positions of ants on the pole, unfortunately, we do not know the directions in which the ants are walking. Your task is to compute the earliest and the latest possible times needed for all ants to fall off the pole.
Input

        The first line of input contains one integer giving the number of cases that follow. The data for each case start with two integer numbers: the length of the pole (in cm) and n, the number of ants residing on the pole. These two numbers are followed by n integers giving the position of each ant on the pole as the distance measured from the left end of the pole, in no particular order. All input integers are not bigger than 1000000 and they are separated by whitespace.
Output

        For each case of input, output two numbers separated by a single space. The first number is the earliest possible time when all ants fall off the pole (if the directions of their walks are chosen appropriately) and the second number is the latest possible such time.
Sample Input

2
10 3
2 6 7
214 7
11 12 7 13 176 23 191
Sample Output

4 8
38 207 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

void solve(int length, std::vector<int>& N, int& max_time, int& min_time) {
    max_time = std::numeric_limits<int>::min(),
    min_time = std::numeric_limits<int>::max();
    for (int pos : N) {
        max_time = std::max(max_time, std::max(pos, length - pos));
        min_time = std::min(min_time, std::min(pos, length - pos));
    }
}


void solve2(int length, std::vector<int>& N, int& max_time, int& min_time) {
    max_time = std::numeric_limits<int>::min();
    for (int pos : N)
        max_time = std::max(max_time, std::max(pos, length - pos));
    min_time = length - max_time;
}

int main() {
    std::vector<int> N({2, 6, 7});
    int max_time, min_time;
    solve(10, N, max_time, min_time);
    assert(max_time == 8 && min_time == 2);
    solve2(10, N, max_time, min_time);
    assert(max_time == 8 && min_time == 2);

    N.clear();
    N.assign({11, 12, 7, 13, 176, 23, 191});
    solve(214, N, max_time, min_time);
    assert(max_time == 207 && min_time == 7);
    solve2(214, N, max_time, min_time);
    assert(max_time == 207 && min_time == 7);
    return 0;
}