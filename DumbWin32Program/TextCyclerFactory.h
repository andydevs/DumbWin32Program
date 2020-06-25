#pragma once
#include "TextCycler.h"
class TextCyclerFactory
{
public:
	TextCyclerFactory() {};
	TextCyclerFactory(const TextCyclerFactory& other) {};
	~TextCyclerFactory() {};
	virtual TextCycler* createTextCycler() = 0;
};