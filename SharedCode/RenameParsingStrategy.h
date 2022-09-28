#pragma once
#include "AbstractParsingStrategy.h"
class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	virtual vector<string> parse(string str);
};