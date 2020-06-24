#include "TextCycler.h"

TextCycler::TextCycler() {
	m_currentText = 0;
}

TextCycler::~TextCycler() {
	// Free memory in vector (I'm using auto because I'm lazy)
	for (auto it = m_texts.begin(); it != m_texts.end(); ++it) {
		free(*it);
	}
}

void TextCycler::push_text(const TCHAR text[]) {
	m_texts.push_back(_tcsdup(text));
}

void TextCycler::next_text() {
	m_currentText = (m_currentText + 1) % m_texts.size();
}

TCHAR* TextCycler::current_text() {
	return m_texts[m_currentText];
}