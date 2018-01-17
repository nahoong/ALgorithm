#include<iostream>
#include<string>
#pragma warning(disable:4996)



using namespace std;

int maxNum = 0;
int swapCnt;
int visited[1000000];

void swap(char &a, char &b) 
{
	char temp = a;
	a = b;
	b = temp;

}

void solve(string str, int n)
{
	if (n == swapCnt)
	{
		maxNum = atoi(str.c_str()) > maxNum ? atoi(str.c_str()) : maxNum;
		return;
	}

	if (visited[atoi(str.c_str())] == true)
		return;

	visited[atoi(str.c_str())] = true;

	for (int i = 0; i < strlen(str.c_str()); i++)
	{
		for (int j = i + 1; j < strlen(str.c_str()); j++)
		{
			swap(str[i], str[j]);
			solve(str, n + 1);
			swap(str[i], str[j]);
		}
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;

	for (int p = 1; p <= tc; p++)
	{

		string num;
		cin >> num >> swapCnt;

		maxNum = 0;
		solve(num, 0);

		cout << "#" << p << " " << maxNum << endl;

	}

	return 0;
}