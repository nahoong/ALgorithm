#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)

int map[25][25];
int visit[25][25];
int N;
int area;
vector<int> zip;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

bool inarea(int a, int b) {
	return (a >= 0 && a < N && b >= 0 && b < N);
}
void dfs(int a, int b) {
	visit[a][b] = 1;
	for (int d = 0; d < 4; d++) {
		int na = a + dx[d];
		int nb = b + dy[d];
		if (!visit[na][nb] && map[na][nb] == 1 && inarea(na, nb)) {
			area++;
			dfs(na, nb);
		}
	}
}
int main() {

	freopen("input.txt", "r", stdin);

	cin >> N;

	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < N; i++) {
		//int j = 0;
		//do {
		//	c = getchar();
		//	map[i][j] = c-'0';
		//	j++;
		//} while (c != '\n');
		//이방법은 맨처음 엔터도 같이 들어가서 좋지 않음....
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if (!visit[i][j] && map[i][j] == 1) {
				visit[i][j] = 1;
				area = 1;
				dfs(i,j);
				zip.push_back(area);
			}
		}
	}

	cout << zip.size() << endl;
	sort(zip.begin(), zip.end());
	for (int i = 0; i < int(zip.size()); i++) {
		cout << zip.at(i) << endl;
	}
}

