#include<iostream>
#include<vector>
#include<bitset>

using namespace std;
//N�� �Է¹ް� ��Ʈ����ũ�� ���
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

	//1�� ������ 3�����Ϸ���...?
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

	//1�� ������ �� 3���� �Ϸ���...? for�� �������� ���� ��¥
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
	//���̰� ������ ��Ʈ��� �̷��� �ϴ°͵� ���������..
	for (int i = 0; i < (1 << N); i++) {
		cout << bitset<4>(i) << ' ';
		cout << endl;
	}


	return  0;

}