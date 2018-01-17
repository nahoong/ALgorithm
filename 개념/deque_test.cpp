#include<iostream>
#include<deque>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;

int main(int argc, char** argv) {

	freopen("input.txt", "r", stdin);
	int N;
	cin >> N;
	deque<int> a;

	a.push_back(1);
	a.push_front(10);
	a.push_back(2);
	a.push_front(3);
	a.push_back(1);

	cout << N << "시작" << endl;
	for (int i = 0; i < a.size(); i++) {
		cout << "a[" << i << "] = " << a[i] << endl;
	}
	int size = find(a.begin(), a.end(), 10) - a.begin();
	cout << "총위치 " << a.size() << endl << "10을 찾은위치 " << size << endl;
	size = find(a.begin(), a.end(), 99) - a.begin();
	cout << "총위치 " << a.size() << endl << "10을 찾은위치 " << size << endl;
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " -> ";
	}
	cout << endl;

	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " -> ";
	}
	cout << endl;

	a.pop_front();
	a.pop_front();
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " -> ";
	}
	cout << endl;
	a.pop_back();
	a.pop_back();

	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " -> ";
	}
	cout << endl;



	
}