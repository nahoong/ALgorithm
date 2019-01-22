#include<iostream>
#include<cstring>
using namespace std;

int map[1001][1001];
int visit[1001];
int queue[1001];
int N, front, rear;

void dfs(int v) {
	visit[v] = 1;
	for (int i = 1; i <= N; i++) {
		if (map[v][i] == 1 && !visit[i]) {
			cout << i << ' ';
			dfs(i);
		}
	}
}

void bfs(int v) {
	visit[v] = 1;
	cout << v << ' ';
	queue[rear++] = v;
	while (front < rear) {
		v = queue[front++];
		for (int i = 1; i <= N; i++) {
			if (map[v][i] == 1 && !visit[i]) {
				visit[i]=1;
				cout << i << ' ';
				queue[rear++] = i;
			}
		}
	}
	cout << endl;
}

int main() {

	int M, V;
	cin >> N >> M >> V;

	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));
	memset(queue, 0, sizeof(queue));

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}

	cout << V << ' ';
	dfs(V);
	cout << endl;

	memset(visit, 0, sizeof(visit));

	front = rear = 0;
	bfs(V);
}