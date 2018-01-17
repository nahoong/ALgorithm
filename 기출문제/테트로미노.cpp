#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int map[501][501];
int visit[501][501] = { 0 };
int func(int x, int y, int cnt) {
	if (cnt == 4) return map[x][y];

	visit[x][y] = 1;
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)	continue;
		if (visit[nx][ny])	continue;
		ret = max(ret, func(nx, ny, cnt+1));
	}
	visit[x][y] = 0;
	return ret + map[x][y];
}

int func(int x, int y) {
	int sum = map[x][y], min_v = 2000;

	for (int i = 0; i <4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)	continue;
		sum += map[nx][ny];
		min_v = min(min_v, map[nx][ny]);
	}
	return sum - min_v;
}

int main(int argc, char** argv) {

	cin >> N >> M;	
	int sum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];		
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp = max(func(i, j), func(i, j, 1));
			sum = max(temp, sum);
		}
	}
	cout << sum << endl;
	return 0;

}