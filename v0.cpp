// simulation exercise for beginners
// students only need to write the flying logic and will see a graphical representation of the flight path
#include <iostream>
using namespace std;
int N, X, Y;
int H[200000];
string area[6001][2001];	// [x][y] convention

void print_area() {
	int x, y;
	cout << endl;
	for (y=N; y>0; y--) {
		printf("%2d ", y);
		for (x=1; x<=3*N; x++) {
			cout << area[x][y] << " ";
		}
		cout << endl;
	}
	cout << "   ";
	for (x=1; x<=3*N; x++)
		printf("%2d ", x);
	cout << endl;
	printf("bird is at (%d, %d). Press ENTER for next step...", X, Y);
}

void init_area() {
	int x, y, i, j;
	for (x=1; x<=3*N; x++)
		for (y=1; y<=N; y++)
			area[x][y] = "  ";
	for (i=0; i<N; i++) {
		x = (i+1) * 3;
		for (y=1; y<=H[i]; y++) {
			area[x][y] = "**";
		}
	}
}

int main() {
	int i, j;
	string direction, temp;
	cin >> N;
	for (i=0; i<N; i++)
		cin >> H[i];
	init_area();
	X = 1; Y = N;
	direction = ">>";
	area[X][Y] = direction;
	print_area();
	getline(cin, temp);
	while (true) {
		area[X][Y] = "  ";

		// *** your flying logic begins here
		X++;
		// *** your flying logic ends here
		
		area[X][Y] = direction;
		getline(cin, temp);
		print_area();
	}

	return 0;
}
