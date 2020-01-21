// naive logic
// scores 70 points
#include <iostream>
using namespace std;

int N;
int H[200000];

int main() {
    int i, x, y, steps = 0;
    bool to_right = true;
    cin >> N;
    x = 1;
    y = N;
    for (i=0; i<N; i++) {
        cin >> H[i];
    }

    while (y > 0 && x > 0) {
        if (to_right) {
            if ((x % 3 == 2) && (H[x / 3] >= y)) {
                to_right = false;
                y--;
            } else {
                x++;
            }
        } else if (x <= 3) {
            x--;
        } else if ((x % 3 == 1) && (H[x / 3 - 1] >= y)) {
            to_right = true;
            y--;
        } else {
            x--;
        }
        steps++;
    }
    if (y == 0) {
        cout << "DROP" << endl << x << endl << steps << endl;
    } else {
        cout << "ESCAPE" << endl << y << endl << steps << endl;
    }

    return 0;
}