#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)

using namespace std;

struct xy {
	int x;
	int y;
};
int p, q;
//int max_y, max_x;
xy map[100001];
int remap[500][500];

void make_map() {
	int cx = 1;
	int cy = 1;

	for (int i = 1; i < 100001; i++) {
		map[i].x = cx;
		map[i].y = cy;
		remap[cx][cy] = i;
		//if (i< 10)	cout << "&(" << i << ") = (" << cx << "," << cy << ")" << endl;
		cx = cx + 1;
		cy = cy - 1;

		if (cy < 1) {
			//max_x = cx;
			cy = cx;
			cx = 1;
			//max_y = cy;
		}
		//if (i < 15) cout << remap[cx][cy] << endl;
		
	}

	//cout << "°ËÁõ"<<max_x << "," << max_y << endl;
}

int main(int argc, char** argv) {

	freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	int tcc = tc;
	make_map();
	
	while (tc--) {
		cin >> p >> q;
		int r = map[p].x + map[q].x;
		int c = map[p].y + map[q].y;
		cout<< "#"<<tcc-tc<< " " <<remap[r][c]<<endl;
	}
}