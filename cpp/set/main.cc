#include <iostream>
#include <set>
using namespace std;

int main(){
	int array[] = {1, 2, 1, 3, 4, 5, 4};
	//set<int> s;
	multiset<int> s;
	for(auto e : array) s.insert(e);

	cout << s.size() << endl;
	for(auto e : s) cout << e << "  ";
	cout << endl;

	cout << s.count(5) << endl;
	return 0;
}
