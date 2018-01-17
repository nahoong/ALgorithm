#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;
int N;
int K;
int Answer;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<vector<int> > map;
vector<vector<int> > visit;
vector<int> max_x;
vector<int> max_y;


bool chk(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < N;
}
void dfs(int deep, int cx, int cy, int k) {

	Answer = max(Answer, deep);

	for (int i = 0; i < 4; i++) {
		int nx = cx + dx[i];
		int ny = cy + dy[i];
		if (!chk(nx, ny) || visit[nx][ny] == 1)	continue;
		int temp = map[nx][ny];
		if (map[nx][ny] < map[cx][cy]) {
			visit[nx][ny] = 1;
			dfs(deep + 1, nx, ny, k);
			visit[nx][ny] = 0;
		}

		if (k == 0 && map[nx][ny] - K < map[cx][cy] && map[nx][ny] >= map[cx][cy]) {
			visit[nx][ny] = 1;
			map[nx][ny] = map[cx][cy] - 1;
			dfs(deep + 1, nx, ny, k + 1);
			map[nx][ny] = temp;
			visit[nx][ny] = 0;
		}
		
	}


}
int main(int argc, char** argv) {

	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {

		Answer = 0;
		cin >> N;
		cin >> K;
		map.assign(N, vector<int>(N, 0));
		visit.assign(N, vector<int>(N, 0));
		int max = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] > max) max = map[i][j];

			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == max) {
					max_x.push_back(i);
					max_y.push_back(j);
					//cout << i << " . " << j << endl;
				}
			}
		}
		for (int i = 0; i < max_x.size(); i++) {
			visit[max_x[i]][max_y[i]] = 1;
			dfs(1, max_x[i], max_y[i], 0);
			visit[max_x[i]][max_y[i]] = 0;
		}
		max_x.clear();
		max_y.clear();
		cout << '#' << test_case + 1 << ' ';
		cout << Answer << endl;
	}
	return 0;
}
