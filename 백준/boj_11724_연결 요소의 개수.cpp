#include<iostream>
#include<vector>
#pragma warning(disable:4996)


using namespace std;
int N, M;
int ans=0;
int map[1001][1001] = { 0, };
int visit[1001] = { 0, };

void dfs(int node) {
	visit[node] = 1;
	for (int i = 1; i <= N; i++) {
		if (map[node][i] && !visit[i]) {
			//cout << i << "¹æ¹®" << endl;
			dfs(i);
		}
	}
}

int main() {
	
	freopen("input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			dfs(i);
			ans++;
		}
	}
	
	cout << ans << endl;
}