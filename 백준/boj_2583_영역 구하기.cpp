#include<iostream>
#include<vector>
#include<algorithm>

#pragma warning(disable:4996)

using namespace std;

int map[111][111] = { 0, };
int M, N, K;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int mark = 1;
int sum = 0;
vector<int> ans;

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

bool area(int ny, int nx) {
	return nx >= 0 && nx < N && ny >= 0 && ny < M;
}
void dfs(int y, int x) {
	map[y][x] = -1 * mark;
	sum++;
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (area(ny, nx) && map[ny][nx] == 0)
			dfs(ny, nx);
	}
}
int main() {


	freopen("input.txt", "r", stdin);

	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2 = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2)	swap(x1, x2);
		if (y1 > y2)	swap(y1, y2);
		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				map[y][x] = 1;
			}
		}
	}

//	for (int y = 0; y < M; y++) {
//		for (int x = 0; x < N; x++) {
//			cout << map[y][x] << "\t";
//	}
//	cout << endl;
//}

	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == 0) {
				dfs(y, x);
				mark++;
				ans.push_back(sum);
				sum = 0;
			}
		}
	}

	//for (int y = 0; y < M; y++) {
	//	for (int x = 0; x < N; x++) {
	//		cout << map[y][x] << "\t";
	//	}
	//	cout << endl;
	//}

	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i < ans.size() - 1)cout << " ";
	}
	cout << endl;

}