#pragma once

#include <tchar.h>
#include <vector>

class TextCycler
{
private:
	std::vector<TCHAR*> m_texts;
	int m_currentText;
public:
	TextCycler();
	~TextCycler();
	void push_text(const TCHAR text[]);
	void next_text();
	TCHAR* current_text();
};

