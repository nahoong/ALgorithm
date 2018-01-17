#include<iostream>
#include<vector>
#include<bitset>

using namespace std;
//N을 입력받고 비트마스크를 출력
int main() {

	int N;
	cin >> N;

	vector<int> mask(N,0);
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < N; j++) {
			cout << (i & (1 << j)) << ' ';
		}
		cout << endl;
	}

	
	cout << endl;
	cout << endl;

	//1의 개수를 3개로하려면...?
	for (int i = 0; i < (1 << N); i++) {
		int count = 0;
		mask.assign(N, 0);
		for (int j = 0; j < N; j++) {
			if ((i & (1 << j)) != 0 && count<3) {
				count++;
				mask[j] = 1;
			}
			cout << mask[j] << ' ';
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;

	//1의 개수를 딱 3개만 하려면...? for를 돌리세요 ㅅㅂ 진짜
	//for (int i = 0; i < (1 << N); i++) {
	//	int count = 0;
	//	mask.assign(N, 0);
	//	for (int j = 0; j < N; j++) {
	//		if (count > 3)	break;
	//		if ((i & (1 << j)) != 0 && count < 3) {
	//			count++;
	//			mask[j] = 1;
	//		}

	//	}
	//	if (count == 3) {
	//		for (int j = 0; j < N; j++) {
	//			cout << mask[j] << ' ';
	//		}
	//		cout << endl;
	//	}
	//	
	//}


	cout << endl;
	cout << endl;
	//길이가 정해진 비트라면 이렇게 하는것도 방법이지라..
	for (int i = 0; i < (1 << N); i++) {
		cout << bitset<4>(i) << ' ';
		cout << endl;
	}


	return  0;

}