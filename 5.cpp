#include <iostream>
#include <vector>

using namespace std;

template<class elemtype>
int seqsearch(const vector<elemtype> &list, const elemtype &item){
	for (int i = 0; i < list.size(); ++i){
		if (item == list[i]){
			return i;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	vector<int> list;
	list.push_back(14);
	list.push_back(5);
	list.push_back(23);
	list.push_back(8);
	list.push_back(5);
	list.push_back(7);
	list.push_back(6);
	list.push_back(12);
	int s=23;
	cout<<seqsearch(list,s);
	return 0;
}