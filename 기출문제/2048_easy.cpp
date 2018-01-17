#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;
vector<int> map;
int Answer;

void merge(int d) {

	switch (d) {
	case 0:
		//cout << "come here " << N << endl;
		for (int i = 0; i < N; i++)
		{
			vector<int> arr_merge(0);
			for (int j = N-1; j >= 0; j--) {
				if (map[N*j + i] != 0)
					arr_merge.push_back(map[N*j + i]);
				map[N*j + i] = 0;
				//cout << "push succes the size is " << arr_merge.size()<<endl;
			}
			int temp;
			for (int j = 0; j < N; j++) {
				if (arr_merge.empty()) break;
				temp = arr_merge.back();
				arr_merge.pop_back();
				if (!arr_merge.empty()) {
					if (temp == arr_merge.back()) {
						temp *= 2;
						arr_merge.pop_back();
					}
				}
				//cout << "pop succes the size is " << arr_merge.size() << endl;
				map[N*j + i] = temp;
			}
		}
		break;
	case 1:
		//cout << "come here " << N << endl;
		for (int i = 0; i < N; i++)
		{
			vector<int> arr_merge(0);
			for (int j = 0; j < N; j++) {
				if (map[N*j + i] != 0)
					arr_merge.push_back(map[N*j + i]);
				map[N*j + i] = 0;
				//cout << "push succes the size is " << arr_merge.size()<<endl;
			}
			int temp;
			for (int j = N-1 ; j >=0; j--) {
				if (arr_merge.empty()) break;
				temp = arr_merge.back();
				arr_merge.pop_back();
				if (!arr_merge.empty()) {
					if (temp == arr_merge.back()) {
						temp *= 2;
						arr_merge.pop_back();
					}
				}
				//cout << "pop succes the size is " << arr_merge.size() << endl;
				map[N*j + i] = temp;
			}
		}
		break;
	case 2:
		//cout << "come here " << N << endl;
		for (int i = 0; i < N; i++)
		{
			vector<int> arr_merge(0);
			for (int j = 0; j < N; j++) {
				if (map[N*i + j] != 0)
					arr_merge.push_back(map[N*i + j]);
				map[N*i + j] = 0;
				//cout << "push succes the size is " << arr_merge.size()<<endl;
			}
			int temp;
			for (int j = N-1; j >=0; j--) {
				if (arr_merge.empty()) break;
				temp = arr_merge.back();
				arr_merge.pop_back();
				if (!arr_merge.empty()) {
					if (temp == arr_merge.back()) {
						temp *= 2;
						arr_merge.pop_back();
					}
				}
				//cout << "pop succes the size is " << arr_merge.size() << endl;
				map[N*i + j] = temp;
			}
		}
		break;
	case 3:
		//cout << "come here " << N << endl;
		for (int i = 0; i < N; i++)
		{
			vector<int> arr_merge(0);
			for (int j = N-1; j >=0 ; j--) {
				if (map[N*i + j] != 0)
					arr_merge.push_back(map[N*i + j]);
				map[N*i + j] = 0;
				//cout << "push succes the size is " << arr_merge.size()<<endl;
			}
			int temp;
			for (int j = 0; j < N; j++) {
				if (arr_merge.empty()) break;
				temp = arr_merge.back();
				arr_merge.pop_back();
				if (!arr_merge.empty()) {
					if (temp == arr_merge.back()) {
						temp *= 2;
						arr_merge.pop_back();
					}
				}
				//cout << "pop succes the size is " << arr_merge.size() << endl;
				map[N*i + j] = temp;
			}
		}
		break;
	default:
		break;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i*N + j] <<' ';
		}
		cout << endl;
	}
	cout << endl;
}
void process(int deep) {

	if (deep == 1) {

		if(*max_element(map.begin(), map.end()) >= Answer)
		Answer = *max_element(map.begin(), map.end());
		return ;
	}
	vector<int> copy_map(N*N);
	copy(map.begin(), map.end(), copy_map.begin());

	for (int i = 0; i < 4; i++) {
		merge(i);
		process(deep+1);
		copy(copy_map.begin(), copy_map.end(), map.begin());
	}
	
}

int main(int argc, char** argv) {

	cin >> N;
	map.assign(N*N,0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i*N + j];
		}
	}

	process(0);
	cout << Answer << endl;

}