#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv) {

	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int B, C;
	cin >> B >> C;
	int Mb;
	long long Mc;	//부감독관의 수는 overflow가능성있음 백만 고사장 각백만명일떄..
	Mb = 0;
	Mc = 0;

	for (int i = 0; i < N; i++) {
		Mb += 1;
		if (A[i] - B > 0) {
			int temp = (A[i] - B) / C;
			if ((A[i] - B) % C == 0) {
				Mc += temp;
			}
			else {
				Mc = Mc + temp + 1;
			}
		}
	}

	cout << Mb + Mc << endl;
	return 0;
}