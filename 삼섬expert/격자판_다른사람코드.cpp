#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

int T;
int pad[4][4];
bool visited[10000000];
int result = 0;

void dfs(int r, int c, int dep, int num)
{
	if (r < 0 || r >= 4 || c < 0 || c >= 4) {
		return;
	}
	if (dep == 7) {
		num = num * 10 + pad[r][c];
		if (!visited[num]) {
			result++;
			visited[num] = true;
		}
		return;
	}
	dfs(r - 1, c, dep + 1, num * 10 + pad[r][c]);
	dfs(r + 1, c, dep + 1, num * 10 + pad[r][c]);
	dfs(r, c - 1, dep + 1, num * 10 + pad[r][c]);
	dfs(r, c + 1, dep + 1, num * 10 + pad[r][c]);
}



int main()
{
	freopen("input.txt", "r", stdin);
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {

		result = 0;
		fill_n(visited, 10000000, false);
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				cin >> pad[i][j];
			}
		}
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				dfs(i, j, 1, 0);
			}
		}
		cout << "#" << tc << " " << result << endl;
	}
	return 0;
}