#pragma once
#include <string>
#include <set>
#include <vector>
using namespace std;
class AbstractParsingStrategy {
public:
	virtual vector<string> parse(string str) = 0;
};
