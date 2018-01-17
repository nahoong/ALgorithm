#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<vector <int> > map;
int a[10][10];
void merge(int d) {

	cout << map.size() << endl;
	cout << map.end() - map.begin() << endl;
	cout << sizeof(a)/sizeof(a[0]) << endl;

	switch (d) {
	case 0:			//위로 합치기
		for (int i = 0; i < map.size(); i++) {

		}

		break;

	default:
		break;
	}
}
int main(int argc, char**argv) {

	int N;
	cin >> N;
	map.assign(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	merge(1);





	
	
	return 0;

}