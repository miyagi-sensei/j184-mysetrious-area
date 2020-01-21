// scores 100 pts with O(n) solutions
// this solution creates a reverse mapping data structure so it can do fast lookup of the location of the rock given a height
#include <iostream>
using namespace std;

int main() {
    long long N;
    long long H[200001];
    long long rev_map[200001];  // reverse map to assist the search for the next obstacle rock

    long long i, x, y, left_bound, right_bound, h;
    long long steps = 0;
    bool to_right = true;
    cin >> N;
    x = 1;
    y = N;
    left_bound = 0;
    right_bound = N;
    for (i=1; i<=N; i++) {
        cin >> h;
        rev_map[h] = i;
    }

    while (y > 0) {
        if (to_right) {
            if ((rev_map[y] * 3) > x && rev_map[y] < right_bound) {
                right_bound = rev_map[y];
            }
            steps += right_bound * 3 - x;
            x = right_bound * 3 - 1;
            to_right = false;
            y--;
        } else {
            if ((rev_map[y] * 3) < x && rev_map[y] > left_bound) {
                left_bound = rev_map[y];
            } else if (left_bound == 0) {
                cout << "ESCAPE" << endl << y << endl << steps + x << endl;
                return 0;
            }
            steps += x - (left_bound * 3 + 1) + 1;
            x = left_bound * 3 + 1;
            to_right = true;
            y--;
        }
    }
    cout << "DROP" << endl << x << endl << steps << endl;

    return 0;
}