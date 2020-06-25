#pragma once
#include "TextCyclerFactory.h"
class TomskaTextCyclerFactory : public TextCyclerFactory
{
	TextCycler* createTextCycler();
};

