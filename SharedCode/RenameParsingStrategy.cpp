#include "RenameParsingStrategy.h"
vector<string> RenameParsingStrategy::parse(string str) {
	vector<string> holder;
	string store = str.substr(0, str.find(' '));
	string store2 = str.substr(str.find(' ')+1);
	holder.push_back(store + " " + store2);
	holder.push_back(store);
	return holder;
}