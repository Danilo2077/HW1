//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "uTestClass.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
Test *LoadTest;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
 LoadTest=new Test();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::CheckAnswersButtonClick(TObject *Sender)
{
   int score = LoadTest->checkAnswers();
	ShowMessage("Ви правильно вдповіли на  " + IntToStr(score) + " питання") ;
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Timer1Timer(TObject *Sender)
{

	TimeLeft--;

	LabelTimeLeft->Caption = "Час, що залишився " + IntToStr(TimeLeft) + " сек";


	if (TimeLeft <= 0)
	{
		Timer1->Enabled = false;
		Form4->Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormShow(TObject *Sender)
{
   if (OpenDialog1->Execute())
	{

		LoadTest->loadTestFromFile(OpenDialog1->FileName);
		LoadTest->createTest(this);
	}
		TimeLeft = 360;
		Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

