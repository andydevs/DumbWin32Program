#include "BushworldTextCyclerFactory.h"

TextCycler* BushworldTextCyclerFactory::createTextCycler() {
	TextCycler* cycler = new TextCycler();
	cycler->push_text(L"I'm Yute Uncle Barry!");
	cycler->push_text(L"NAAAAaaaaAAAAHHH!");
	cycler->push_text(L"They're bureaucrats, Morty! I don't respect them!");
	cycler->push_text(L"Oh don't worry your little morty head morty!");
	cycler->push_text(L"I was having a little Morty sleep");
	return cycler;
}