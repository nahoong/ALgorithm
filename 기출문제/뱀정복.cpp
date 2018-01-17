#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int L, N;
//vector<vector<int> > visit;
int duration = 0;
int run_more = 1;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int cdir = 3;	//index of d[]
int cx, cy;
struct arr_xy {
	int kx, ky;

	bool operator == (const arr_xy value) {
		if (value.kx == kx && value.ky == ky)
			return true;
		return false;
	}
};
vector<arr_xy> visit;
arr_xy xy;

bool chk(int x, int y) {
	return 0 <= x && x < 2 * L + 1 && 0 <= y && y < 2 * L + 1;
}

bool chk(arr_xy xy) {
	for (int i = 0; i < visit.size(); i++) {
		if (visit[i].kx == xy.kx && visit[i].ky == xy.ky) {
			return false;
		}
	}
	return true;
}

void func(int t, int d) {

	arr_xy xy;

	//visit.resize(visit.size() + t);

	for (int i = 0; i < t; i++) {
		int nx = cx + dx[cdir];
		int ny = cy + dy[cdir];
		xy.kx = nx;
		xy.ky = ny;
		if (chk(nx, ny) && chk(xy)) {
			duration++;
			cx = nx;
			cy = ny;
			run_more = 1;
			visit.push_back(xy);
		}
		else {
			duration++;
			run_more = 0;
			return;
		}
	}

	cdir = (cdir + 4 + d) % 4;
	return;

}
int main(int argc, char** argv) {

	cin >> L >> N;

	//vector< vector<int> > visit(2 * L + 1, vector<int>(2 * L + 1, 0));


	vector<int> handle_time(N);
	vector<int> handle_dirc(N);
	cx = L;
	cy = L;
	xy.kx = cx;
	xy.ky = cy;
	visit.push_back(xy);
	for (int i = 0; i < N; i++) {
		char temp;
		cin >> handle_time[i] >> temp;
		if (temp == 'L') {
			handle_dirc[i] = 1;
		}
		else {
			handle_dirc[i] = -1;
		}
		if (run_more)
			func(handle_time[i], handle_dirc[i]);	// 점찍기
	}
	
	vector<int> visitx(visit.size());
	for (int i = 0; i < visit.size(); i++) {
		visitx[i] = visit[i].kx;
		cout << '(' << visit[i].kx << '.' << visit[i].ky << ')' << endl;
	}

	xy.kx = 2;
	xy.ky = 5;
	vector<arr_xy>::iterator it;
	it = find( visit.begin(), visit.end(), xy);
	cout << "3번쨰 요소 : " << visit.at(3).kx << endl;
	cout << "총 크기 : " << visit.size() << endl;
	cout << "찾은위치와 첫포인터 간의 간격 : " << it - visit.begin() << endl;
	//it = find(visitx.begin(), visitx.end()-4, 9);
	//cout << it - visitx.begin() << endl;
	cout << visit.begin()-visit.end() << endl;
	cout << duration << endl;
	return 0;
}