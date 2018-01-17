#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int Answer;
int N, M, K;

struct insec {
	int x;
	int y;
	int sec;
	int dir;

};
bool vector_sort(const insec &a, const insec &b) {
	return a.sec < b.sec;
}
vector<vector<int> > map;
vector<insec> kun;
void game(int time) {

	sort(kun.begin(), kun.end(), vector_sort);

	if (time == M) return;
	////////////////////move
	for (int i = 0; i < kun.size(); i++) {
		//현재 칸을 0으로 
		map[kun[i].x][kun[i].y] = 0;
		//다음좌표 계산
		kun[i].x += dx[kun[i].dir];
		kun[i].y += dy[kun[i].dir];
	}
	for (int i = 0; i < kun.size(); i++) {

		if (kun[i].x*kun[i].y == 0 || kun[i].x == N - 1 || kun[i].y == N - 1) {
			//경계에 들어감
			kun[i].dir = (kun[i].dir + 2) % 4;
			kun[i].sec = kun[i].sec / 2;
		}
		else {
			if (map[kun[i].x][kun[i].y] == 0) {
				map[kun[i].x][kun[i].y] = kun[i].sec;
			}
			//1.숫자가 0보다 클때(뭉친경우 or 두번색칠하는경우)
			else if(map[kun[i].x][kun[i].y] > 0) {
				for (int j = i - 1; j >= 0; j--) {
					if (kun[i].x == kun[j].x&&kun[i].y == kun[j].y) {
						//병균 합체
						map[kun[i].x][kun[i].y] += kun[i].sec;
						kun[i].sec = map[kun[i].x][kun[i].y];
						//이전 작은 병균 제거
						kun.erase(kun.begin() + j, kun.begin() + j + 1);
						i--;
						break;
					}
				}
			}
		}
	}	
	
	for (int i = 0; i < kun.size(); i++) {
		if (kun[i].x*kun[i].y == 0 || kun[i].x == N - 1 || kun[i].y == N - 1) {
		
		}
		else {


		}
	}

	////////////////////
	game(time + 1);
}
int main() {

	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {

		Answer = 0;
		cin >> N >> M >> K;
		map.assign(N, vector<int>(N,0));
		for (int i = 0; i < K; i++) {
			insec a;
			int x, y ,sec, dir;
			cin >> x >> y >> sec >> dir;
			switch (dir) {
			case 1:
				dir = 3;
				break;
			case 2:
				dir = 1;
				break;
			case 3:
				dir = 2;
				break;
			case 4:
				dir = 0;
				break;
			}
			a.x = x;
			a.y = y;
			a.dir = dir;
			a.sec = sec;
			kun.push_back(a);
			map[x][y] = sec;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == 0 || j == 0 | i == N - 1 || j == N - 1)
					map[i][j] = -1;
			}
		}

		game(0);

		for (int i = 0; i < kun.size(); i++) {
			Answer += kun[i].sec;
		}
		kun.clear();
		cout << "#" << test_case + 1 << " " << Answer << endl;

	}
	return 0;
}