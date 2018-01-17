#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)


using namespace std;

int Answer;
int N;
vector<vector<int> >  map;
int dx[] = { -1,1,1,-1 };
int dy[] = { 1,1,-1,-1 };
int visit[101] = { 0, };

bool chk(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < N;
}

void dfs(int sx, int sy, int nx, int ny, int cnt, int dir) {

	if (cnt != 0 && sx == nx && sy == ny) {
		Answer = max(Answer, cnt);
		return;
	}

	for (int i = 0; i < 2; i++) {
		if (dir == 3 && i == 1)	break;
		int nextX = nx + dx[dir + i];
		int nextY = ny + dy[dir + i];
		if (chk(nextX, nextY) && visit[map[nextX][nextY]] == 0) {
			visit[map[nextX][nextY]] = 1;
			dfs(sx, sy, nextX, nextY, cnt + 1, dir + i);
			visit[map[nextX][nextY]] = 0;
		}
	}
	
}

int main(int argc, char** argv) {

	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	
	for (int test_case = 0; test_case < T; test_case++) {
		Answer = -1;
		cin >> N;
		map.assign(N, vector<int>(N,0));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dfs(i, j, i, j, 0, 0);
			}
		}
		cout << "# " << test_case + 1 << ' ';
		cout << Answer << endl;

	}
	return 0;
}