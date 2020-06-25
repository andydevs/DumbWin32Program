#include "TomskaTextCyclerFactory.h"

TextCycler* TomskaTextCyclerFactory::createTextCycler() {
	TextCycler* cycler = new TextCycler();
	cycler->push_text(L"You're gonna turn into a zombie");
	cycler->push_text(L"I'm Tom. You're Chris");
	cycler->push_text(L"I love cake!");
	cycler->push_text(L"That is a bearded bear bearing a beer with a beard.");
	return cycler;
}