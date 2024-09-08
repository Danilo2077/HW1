#ifndef UTESTCLASS_H
#define UTESTCLASS_H

#include <vcl.h>
#include <fstream>
#include <sstream>
#include <string>

class Test
{
public:
	AnsiString questions[4];
	AnsiString answers[4][4];
	int correctAnswerIndex[4];
	TRadioButton *radioButtons[4][4];
	Test() {}
	void createTest(TForm *form);
	int checkAnswers();
	void loadTestFromFile(AnsiString fileName);
	void RandomTEST(TForm *sourceForm, AnsiString fileName);
};
	void SaveFromTest(TForm *form,AnsiString fileName);

#endif

