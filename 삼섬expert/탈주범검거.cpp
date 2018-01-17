#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;

int N, M, R, C, L;

struct place {
	int r, c, time;
};

const int dir[4][2] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};

const int open[8][4] = {
	{0,0,0,0},
	{1,1,1,1},
	{0,1,0,1},
	{1,0,1,0},
	{1,0,0,1},
	{1,1,0,0},
	{0,1,1,0},
	{0,0,1,1}
};

int board[52][52][4];

int visit[52][52];
place queue[52 * 52];
int head, tail;

int in_range(int r, int c) {
	if (r >= 0 && r < N &&c >= 0 && c < M)	return 1;
	return 0;
}

void init() {
	memset(visit, 0, sizeof(visit));
	head = tail = 0;
}
int main(int argc, char* argv) {

	freopen("input.txt", "r", stdin);
	int tc;

	cin >> tc;
	int tcc = tc;
	while (tc--) {

		cin >> N >> M >> R >> C >> L;
		init();
		int type;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> type;

				for (int d = 0; d < 4; d++)	board[i][j][d] = open[type][d];
			}
		}

		int count=1;
		visit[R][C] = 1;
		queue[tail++] = { R,C,1 };
		place p;
		int nr, nc, nt, opp_d;

		while (head != tail) {
			p = queue[head++];
			for (int d = 0; d < 4; d++) {
				nr = p.r + dir[d][0];
				nc = p.c + dir[d][1];
				nt = p.time + 1;

				opp_d = (d + 2) % 4;

				if (in_range(nr,nc) && !visit[nr][nc] && nt <= L && board[p.r][p.c][d] && board[nr][nc][opp_d]) {
					count++;
					visit[nr][nc] = 1;
					queue[tail++] = { nr,nc,nt };
				}
			}

		}

		cout << "#" << tcc-tc << " " << count << endl;

	}
}
