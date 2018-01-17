#include<iostream>
#define MAX 51
#define BLANK 0
#define WALL 1
#define CLEANED 2

using namespace std;

int main(int argc, char** argv) {
	int N, M;
	cin >> N >> M;

	int map[MAX][MAX] = { 0 };
	bool map_check[MAX][MAX] = { false };
	int cRow, cCol, cDir;
	cin >> cRow >> cCol >> cDir;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int Answer = 0;
	int dRow[] = { -1, 0 , 1, 0 };
	int dCol[] = { 0, 1, 0, -1 };

	while (1) {
		if (map[cRow][cCol] == BLANK) {
			Answer += 1;
			map[cRow][cCol] = CLEANED;
		}

		int flag = 0;

		for (int i = 0; i < 4; i++) {

			int nextDir = (cDir - 1 + 4) % 4;
			int nextRow = cRow + dRow[nextDir];
			int nextCol = cCol + dCol[nextDir];

			if (map[nextRow][nextCol] == BLANK) {
				cDir = nextDir;
				cRow = nextRow;
				cCol = nextCol;

				flag = 1;
				break;
			}
			else {
				cDir = nextDir;
			}

		}

		if (flag == 0) {
			if (map[cRow - dRow[cDir]][cCol - dCol[cDir]] == WALL) {
				cout << Answer << endl;
				break;
			}
			else {
				cRow = cRow - dRow[cDir];
				cCol = cCol - dCol[cDir];
			}
		}
	}

	return 0;

}

