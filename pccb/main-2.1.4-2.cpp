/*
 * Lake Counting
Time Limit: 1000MS		Memory Limit: 65536K

 * Description
Due to recent rains, water has pooled in various places in Farmer John's field, which is represented by a rectangle of N x M (1 <= N <= 100; 1 <= M <= 100) squares. Each square contains either water ('W') or dry land ('.'). Farmer John would like to figure out how many ponds have formed in his field. A pond is a connected set of squares with water in them, where a square is considered adjacent to all eight of its neighbors.

Given a diagram of Farmer John's field, determine how many ponds he has.

Input
* Line 1: Two space-separated integers: N and M

* Lines 2..N+1: M characters per line representing one row of Farmer John's field. Each character is either 'W' or '.'. The characters do not have spaces between them.

Output
* Line 1: The number of ponds in Farmer John's field.

Sample Input

10 12
W........WW
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.

Sample Output

3

Hint
OUTPUT DETAILS:

There are three ponds: one in the upper left, one in the lower left,and one along the right side.

Source
USACO 2004 November

 */


#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>

using std::cout;
using std::endl;
using std::string;

int N, M;
string yard;

int next(int x, int dx, int dy) {
    int h = x % M, v = (x - h) / M;
    h += dx, v += dy;
    int pos = v * M + h;
    return (pos >=0 && pos < N * M) ? pos : -1;
}

void dfs(int i) {
    yard[i] = '.';
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int n = next(i, dx, dy);
            if (n < 0) continue;
            if (yard[n] == 'W')
                dfs(n);
        }
    }
}

int solve() {
    int lakes = 0;
    for (int i = 0; i < (int)yard.length(); i++) {
        if (yard[i] == 'W') {
            cout << yard << endl;
            dfs(i);
            lakes++;
        }
    }
    return lakes;
}

int main() {
    N = 10, M = 12;
    yard =
            "W........WW"
            ".WWW.....WWW"
            "....WW...WW."
            ".........WW."
            ".........W.."
            "..W......W.."
            ".W.W.....WW."
            "W.W.W.....W."
            ".W.W......W."
            "..W.......W.";

    assert(solve() == 3);
    cout << yard << endl;

    return 0;
}