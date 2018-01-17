#include<iostream>
#include<vector>

using namespace std;

int dice[6] = { 0, };
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int N, M;
// 동쪽1, 서쪽2, 북쪽3, 남쪽4

bool chk(int cx, int cy) {
	return 0 <= cx && cx < N && 0 <= cy && cy < M;
}

int main(int argc, char** argv) {

	int x, y;
	int K;
	cin >> N >> M >> x >> y >> K;

	vector<vector<int> > map(N, vector<int>(M));
	vector<int> order(K);
	int cx, cy;

	cx = x;
	cy = y;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}

	int temp;
	for (int i = 0; i < K; i++) {
		cin >> order[i];
		if (order[i] < 0 || order[i]>4 ) continue;
		int nx = cx + dx[order[i] - 1];
		int ny = cy + dy[order[i] - 1];
		if (!chk(nx, ny))	continue;
		//cout << "들어옴" << endl;
		switch (order[i]) {
		case 1:
			//cout << "1번명령 동쪽" << endl;
			temp = dice[0];
			dice[0] = dice[3];
			dice[3] = dice[5];
			dice[5] = dice[2];
			dice[2] = temp;
			break;
		case 2:
			//cout << "2번명령 서쪽" << endl;
			temp = dice[0];
			dice[0] = dice[2];
			dice[2] = dice[5];
			dice[5] = dice[3];
			dice[3] = temp;
			break;
		case 3:
			//cout << "3번명령 북쪽" << endl;
			temp = dice[0];
			dice[0] = dice[4];
			dice[4] = dice[5];
			dice[5] = dice[1];
			dice[1] = temp;
			break;
		case 4:
			//cout << "4번명령 남쪽" << endl;
			temp = dice[0];
			dice[0] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[4];
			dice[4] = temp;
			break;
		}
		if (map[nx][ny]) {
			dice[5] = map[nx][ny];
			map[nx][ny] = 0;
		}
		else {
			map[nx][ny] = dice[5];
		}
		cx = nx;
		cy = ny;
		cout << dice[0] << endl;
		
	}
	return 0;
	
}
