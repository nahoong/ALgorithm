// find_if example
#include <iostream>     // std::cout
#include <algorithm>    // std::find_if
#include <vector>       // std::vector

bool IsOdd(int i) {
	return ((i % 2) == 1);
}

int main() {
	std::vector<int> myvector;

	myvector.push_back(10);
	myvector.push_back(25);
	myvector.push_back(40);
	myvector.push_back(55);
	myvector.push_back(52);
	myvector.push_back(43);
	myvector.push_back(19);
	myvector.push_back(90);
	myvector.push_back(99);

	//std::vector<int>::iterator it = std::find_if(myvector.begin(), myvector.end(), IsOdd);
	std::vector<int>::iterator ite = std::find(myvector.begin(), myvector.end(), 43);
	//std::cout << "The first odd value is " << *it << '\n';
	std::cout << "the number you find is " << *ite << '\n';
	return 0;
}