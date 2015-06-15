#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char *argv[])
{
	vector <int> v(1, 0);
	int & r = v[0];
	std::cout << r << std::endl;

	for (int i = 0; i < 1000000; i++) {
		v.push_back(i);
	}

	std::cout << r << std::endl;
	return 0;
}
