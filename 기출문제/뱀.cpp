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

int chk(int d, int t_1, int t) {
	cout << "교차점 판단" << endl;
	vector<arr_xy>::iterator it;
	int start = visit.size() - t;
	int end = visit.size();
	int duration = 0;
	if (d == 0 || d == 3) {
		for (int i = 0; i < t; i++) {
			it = find(visit.begin(), visit.end() - t - t_1, visit.at(start + i));
			if (it != visit.end()-t-t_1)
				return duration;
			duration++;
			cout << "일치하는 좌표없음" << endl;
		}
	}
	else if (d == 1 || d == 2) {
		for (int i = 0; i < t; i++) {
			it = find(visit.begin(), visit.end() - t - t_1, visit.at(end - i -1));
			if (it != visit.end()-t-t_1)
				return duration;
			duration++;
			cout << "일치하는 좌표없음" << endl;
		}
	}
	return 0;
	
	
}

void func(int t_1, int t, int d) {
	
	arr_xy xy;
	arr_xy xy_f;
	xy_f.kx = cx;
	xy_f.ky = cy;
	int flag = 0;
	//visit.resize(visit.size() + t);

	for (int i = 0; i < t; i++) {
		int nx = cx + dx[cdir];
		int ny = cy + dy[cdir];
		xy.kx = nx;
		xy.ky = ny;
		cout << i << "번째func" << endl;
		if (chk(nx, ny)) {
			duration++;
			cx = nx;
			cy = ny;
			run_more = 1;
			visit.push_back(xy);
		}
		else {
			cout << "범위 가출" << endl;
			duration++;
			run_more = 0;
			return;
		}
	}

	flag = chk(cdir, t_1, t);
	if (flag > 0) {
		duration -= flag;
		run_more = 0;
		return;
	}

	cdir = (cdir + 4 + d) % 4;
	return;

}
int main(int argc, char** argv) {

	cin >> L >> N;

	//vector< vector<int> > visit(2 * L + 1, vector<int>(2 * L + 1, 0));
	

	vector<int> handle_time(N+1);
	vector<int> handle_dirc(N+1);
	handle_time[0] = 0;
	cx = L;
	cy = L;
	xy.kx = cx;
	xy.ky = cy;
	visit.push_back(xy);
	for (int i = 1; i < N+1; i++) {
		char temp;
		cin >> handle_time[i] >> temp;
		if (temp == 'L') {
			handle_dirc[i] = 1;
		}
		else {
			handle_dirc[i] = -1;
		}
		if(run_more)
			func(handle_time[i-1], handle_time[i], handle_dirc[i]);	// 점찍기
	}

	cout << duration << endl;
	return 0;
}