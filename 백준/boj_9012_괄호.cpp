#include <iostream>
#include <stack>
#include <string>

using namespace std;

#pragma warning(disable:4996)

bool Check(string s) {
	int len = (int)s.length();

	stack<char> st;

	for (int i = 0; i < len; i++) {
		
		if (s[i] == '(') {
			st.push(s[i]);
		}
		else {
			if (!st.empty()) {
				st.pop();
			}
			else {
				return false;
			}
		}
	}

	return st.empty();
}

int main() {

	freopen("input.txt", "r", stdin);

	int n;

	cin >> n;

	while (n--) {

		string str;
		cin >> str;

		if (Check(str) == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
