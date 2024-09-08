#include "uTestClass.h"
#include <cstdlib>
#include <ctime>
#include <random>
#include <fstream>
#include <locale>
#include <codecvt>
#include <algorithm>
#include "Unit20.h"
#include "Unit21.h"
void Test::createTest(TForm *form)
{

	for (int i = 0; i < 4; ++i) {
		TRadioGroup *radioGroup = new TRadioGroup(form);
		radioGroup->Parent = form;
		radioGroup->Caption = questions[i];
		radioGroup->Left = 10;
		radioGroup->Top = 10 + (i * 150);
		radioGroup->Width = 700;
		radioGroup->Height = 150;
		for (int j = 0; j < 4; ++j) {
			radioButtons[i][j] = new TRadioButton(radioGroup);
			radioButtons[i][j]->Parent = radioGroup;
			radioButtons[i][j]->Caption = answers[i][j];
			radioButtons[i][j]->Left = 10;
			radioButtons[i][j]->Top = 20 + (j * 30);
			radioButtons[i][j]->Width = 700;
		}
	}
}

int Test::checkAnswers() // перевірка
{
	int score = 0;
    for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (radioButtons[i][j]->Checked && j == correctAnswerIndex[i])
			{
				score++;
			}
		}
	}
	return score;
}

void Test::loadTestFromFile(AnsiString fileName)
{
	std::wifstream file(fileName.c_str());
	file.imbue(std::locale(std::locale::classic(), new std::codecvt_utf8<wchar_t>));

	if (!file.is_open())
	{
		ShowMessage("Не вдалося відкрити файл!");
		return;
	}

	std::wstring line;
	int questionIndex = -1;
	int lineIndex = 0;

	while (std::getline(file, line))
	{
		if (line.empty()) continue;

		if (lineIndex % 6 == 0) // Питання  номер рядка ділиться на 6 без остачі(0 6 12 18)
		{
			questionIndex++;
			questions[questionIndex] = AnsiString(line.substr(line.find(L'.') + 1).c_str()).c_str();
		}
		else if (lineIndex % 6 >= 1 && lineIndex % 6 <= 4) // Відповіді  номер рядка ділиться на 6 і має залишок від 1 до 4
		{
			int answerIndex = lineIndex % 6 - 1;
			answers[questionIndex][answerIndex] = AnsiString(line.substr(3).c_str()).c_str();
		}
		else if (lineIndex % 6 == 5) // (5,11,16,20,)
		{
			correctAnswerIndex[questionIndex] = std::stoi(line);
		}

		lineIndex++;
	}

	file.close();
}
void Test::RandomTEST(TForm *form, AnsiString fileName)
{
	loadTestFromFile(fileName);
	const int numQuestions = 4;
	std::vector<int> indices(numQuestions);
	for(int i = 0; i < numQuestions; ++i) {
		indices[i] = i;
	}

	std::srand(unsigned(std::time(0)));

	std::random_shuffle(indices.begin(), indices.end());

	AnsiString tempQuestions[4];
	AnsiString tempAnswers[4][4];
	int tempCorrectAnswerIndex[4];

	for(int i = 0; i < numQuestions; ++i) {
		tempQuestions[i] = questions[indices[i]];
		for(int j = 0; j < 4; ++j) {
			tempAnswers[i][j] = answers[indices[i]][j];
		}
		tempCorrectAnswerIndex[i] = correctAnswerIndex[indices[i]];
	}

	for(int i = 0; i < numQuestions; ++i) {
		questions[i] = tempQuestions[i];
		for(int j = 0; j < 4; ++j) {
			answers[i][j] = tempAnswers[i][j];
		}
		correctAnswerIndex[i] = tempCorrectAnswerIndex[i];
	}
	createTest(form);
}
void SaveFromTest(TForm *form, AnsiString fileName)
{
	std::wofstream outFile(fileName.c_str());
	outFile.imbue(std::locale(std::locale::classic(), new std::codecvt_utf8<wchar_t>));
	if (!outFile.is_open())
	{
		ShowMessage(L"Не вдалося відкрити файл для запису!");
		return;
    }
	auto getCorrectAnswerIndex = [](TRadioButton *rb1, TRadioButton *rb2, TRadioButton *rb3, TRadioButton *rb4) -> int {
		if (rb1->Checked) return 0;
		if (rb2->Checked) return 1;
		if (rb3->Checked) return 2;
        if (rb4->Checked) return 3;
		return -1;
	};
	// цикл для збереженя питаннь
	for (int i = 1; i <= 4; i++)
    {
		TEdit *editQuestion = dynamic_cast<TEdit*>(form->FindComponent("EditQuestion" + IntToStr(i)));
		if (editQuestion)
		{
			std::wstring question = editQuestion->Text.c_str();
			outFile << question << std::endl;
		}
		for (int j = 1; j <= 4; j++)
		{
			TEdit *editAnswer = dynamic_cast<TEdit*>(form->FindComponent("EditAnswer" + IntToStr((i - 1) * 4 + j)));
			if (editAnswer)
			{
				std::wstring answer = editAnswer->Text.c_str();
				outFile << answer << std::endl;
			}
		}
		int correctAnswer = getCorrectAnswerIndex(
			dynamic_cast<TRadioButton*>(form->FindComponent("RadioButton" + IntToStr((i - 1) * 4 + 1))),
			dynamic_cast<TRadioButton*>(form->FindComponent("RadioButton" + IntToStr((i - 1) * 4 + 2))),
			dynamic_cast<TRadioButton*>(form->FindComponent("RadioButton" + IntToStr((i - 1) * 4 + 3))),
			dynamic_cast<TRadioButton*>(form->FindComponent("RadioButton" + IntToStr((i - 1) * 4 + 4)))
		);
		outFile << correctAnswer << std::endl;
	}
	outFile.close();
}

