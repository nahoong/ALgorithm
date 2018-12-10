#include<iostream>
using namespace std;

int map[1001][1001] = { -1, };
int visit[1001] = { 0, };
int queue[1001] = { 0, };
int rear, front;

void depthFirstSearch(int N, int vertex) {
	visit[vertex] = 1;
	for (int i = 1; i <= N; i++) {
		if (map[vertex][i] == 1 && !visit[i]) {
			cout << i << ' ';
			depthFirstSearch(N, i);
		}
	}
}
void breadthFirstSearch(int N, int vertex)
{
	visit[vertex] = 1;
	cout << vertex << ' ';
	queue[rear++] = vertex;
	while (front < rear)
	{
		vertex = queue[front++];
		for (int i = 1; i <= N; i++)
		{
			if (map[vertex][i] == 1 && !visit[i])
			{
				visit[i] = 1;
				cout << i << ' ';
				queue[rear++] = i;
			}
		}
	}
}

int main() {

	int N, M, V;
	cin >> N >> M >> V;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = 0;
		}
		visit[i] = 0;
		queue[i] = 0;
	}
	front = 0;
	rear = 0;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}

	cout << V << ' ';
	depthFirstSearch(N, V);
	cout << endl;
	for (int i = 1; i <= N; i++) {
		visit[i] = 0;
	}
	breadthFirstSearch(N, V);
	cout << endl;
}