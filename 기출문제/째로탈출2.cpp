#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 11
#define INF 0x7fffffff
using namespace std;

char map[MAX_SIZE][MAX_SIZE];
int m, n;
int bx, by;
int rx, ry;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void input() {
	cin >> m >> n;
	getchar();

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = getchar();
			if (map[i][j] == 'B') {
				bx = i;
				by = j;
			}
			else if (map[i][j] == 'R') {
				rx = i;
				ry = j;
			}
		}
		getchar();
	}
}

void print() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", map[i][j]);
		}
		puts("");
	}
	puts("");
}

bool priority_inspect(int d) {//레드가 높으면 1 아니면 0
	switch (d) {
	case 0:
		if (rx < bx) return 1;
		else return 0;
		break;
	case 1:
		if (rx > bx) return 1;
		else return 0;
		break;
	case 2:
		if (ry < by) return 1;
		else return 0;
		break;
	case 3:
		if (ry > by) return 1;
		else return 0;
		break;
	}
}

int move(int d) {//위 아래 왼 오

	bool red_zero = 0, blue_zero = 0;
	bool red_stop = 0, blue_stop = 0;
	bool red_prio = priority_inspect(d);
	int nrx;
	int nry;
	int nbx;
	int nby;

	//둘다 못움직일 때 까지 와일
	while (!blue_stop || !red_stop) {

		if (!red_stop) {
			nrx = rx + dx[d];
			nry = ry + dy[d];

			if (nrx < 0 || nry < 0 || nrx >= m || nry >= n || map[nrx][nry] == '#') red_stop = 1;
			else if (map[nrx][nry] == 'O') {
				red_stop = 1;
				red_zero = 1;
			}
			else {
				rx = nrx;
				ry = nry;
			}
		}

		if (!blue_stop) {
			nbx = bx + dx[d];
			nby = by + dy[d];

			if (nbx < 0 || nby < 0 || nbx >= m || nby >= n || map[nbx][nby] == '#') blue_stop = 1;
			else if (map[nbx][nby] == 'O') {
				blue_stop = 1;
				blue_zero = 1;
			}
			else {
				bx = nbx;
				by = nby;
			}
		}
	}

	//공의 위치가 같을 때
	if (rx == bx && ry == by) {
		if (d == 0) {
			if (red_prio) bx++;
			else rx++;
		}
		else if (d == 1) {
			if (red_prio) bx--;
			else rx--;
		}
		else if (d == 2) {
			if (red_prio) by++;
			else ry++;
		}
		else {
			if (red_prio) by--;
			else ry--;
		}
	}

	if (blue_zero) return 0; // 블루 제로 들어감
	else if (red_zero) return 1; // 레드 제로 들어감
	else return 2; // 제로 발견 못함
}

int dfs(int d) {//깊이
	if (d == 10) return INF;

	int brx = rx;
	int bry = ry;
	int bbx = bx;
	int bby = by;
	int ret = INF;

	for (int i = 0; i < 4; i++) {
		int tmp = move(i);

		if (tmp == 1) return d + 1;
		else if (tmp == 2) {
			int tmp2 = dfs(d + 1);
			if (ret > tmp2) ret = tmp2;
		}

		rx = brx;
		ry = bry;
		bx = bbx;
		by = bby;
	}

	return ret;
}


int main() {

	//freopen("input.txt", "r", stdin);
	//setbuf(stdout, NULL);

	//int t;
	//scanf("%d", &t);

	//while (t--){

	input();
	int ret = dfs(0);
	printf("%d\n", ret == INF ? -1 : ret);

	//}

	return 0;
}
