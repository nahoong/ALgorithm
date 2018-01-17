#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<queue>
//#pragma warning(disable:4996)

using namespace std;

int Answer;

int main() {
	
	int T;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (int test_case = 0; test_case < T; test_case++) {

		queue<int> a;
		queue<int> b;

		a.push(1);
		a.push(2);
		a.push(3);

		cout << "Case # " << test_case << endl;
		cout << a.size() << endl;
		for (int i = 0; i < a.size(); i++) {
			cout << a.back() << " . " << a.front() << endl;
			a.pop();
		}
		cout << a.size()  << endl;
		cout << "---------------" << endl;

	}



	return 0;

}