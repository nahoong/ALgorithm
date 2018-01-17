#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };	// L=1 D=-1
int cx, cy;
int cdir = 0;	//오른쪽으로 가는중
bool die = false;
int cnt;
struct axis {
	int x;
	int y;

	axis() : x(0), y(0) {

	}
	axis(int a, int b) : x(a), y(b) {

	}
	bool operator == (const axis value) {
		if (value.x == x && value.y == y)
			return true;
		return false;
	}
};
vector<axis> snack;
vector<vector<int> > apple;


bool chk(int nx, int ny) {
	return 0 <= nx && nx < N && 0 <= ny && ny < N;
}
void game(int time, char turn, vector<vector<int> > apple) {

	vector<axis>::iterator it;
	for (int i = 0; i < time; i++) {
		cnt++;
		int nx = cx + dx[cdir];
		int ny = cy + dy[cdir];
		//cout << nx << ',' << ny << endl;
		axis xy(nx, ny);
		if (chk(nx, ny)) {
			if (apple[nx][ny] == 1) {
				apple[nx][ny] = 0;
			}
			else {
				snack.erase(snack.begin());
			}
			it = find(snack.begin(), snack.end(), xy);
			if (it == snack.end()) {
				snack.push_back(xy);
				cx = nx;
				cy = ny;
			}
			else {
				die = true;
				return;
			}
		}
		else {
			die = true;
			return;
		}
	}

	if (turn == 'D') {
		cdir = (cdir + 1) % 4;
	}
	else {
		cdir = (cdir + 3) % 4;
	}
	return;
}

int main(int argc, char** argv) {

	cin >> N;

	vector<vector<int> > apple(N, vector<int>(N, 0));
	cnt = 0;
	axis xy;
	/*xy.x = 0;
	xy.y = 0;*/
	snack.push_back(xy);

	cx = 0;
	cy = 0;

	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		apple[x][y] = 1;
	}

	int L;
	int time;
	char turn;
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> time >> turn;
		if (!die) {
			game(time, turn, apple);
		}
	}
	if (!die) {
		game(N + 1, 'D', apple);
	}

	//for (int i = 0; i < snack.size() ; i++) {
	//	cout << snack[i].x << ',' << snack[i].y << endl;
	//}
	cout << cnt << endl;
	return 0;
}


