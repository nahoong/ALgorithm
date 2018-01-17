#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#pragma warning(disable:4996)

using namespace std;
int Answer;
string map[4][4];
vector<string> song;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool chk(int x, int y) {
	return 0 <= x && x < 4 && 0 <= y &&y < 4;
}
void dfs(int i, int j, string length,int deep) {

	if (deep==6) {
		if (find(song.begin(), song.end(),length) == song.end()) {
			song.push_back(length);
			return;
		}
		return;
	}
	
	for (int num = 0; num < 4; num++) {
		int nx = i + dx[num];
		int ny = j + dy[num];
		if (!chk(nx, ny))	continue;
		dfs(nx, ny, length + map[nx][ny], deep + 1);
	}
}
int main(int argc, char** argv) {

	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				//cout << map[i][j] << ' ';
				dfs(i, j, map[i][j], 0);
			}
			//cout << endl;
		}

		
		Answer = song.size();
	
		cout << "#" << t + 1 << ' ' << Answer << endl;
	}

	return 0;
}