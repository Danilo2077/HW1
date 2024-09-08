#include <vcl.h>
#include <vector>
#include <algorithm>
#include <ctime>
#pragma hdrstop
#include "uTestClass.h"
#include "Unit20.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm20 *Form20;
Test *RandomTest;
//---------------------------------------------------------------------------

__fastcall TForm20::TForm20(TComponent* Owner)
	: TForm(Owner)
{
RandomTest=new Test();
}
//---------------------------------------------------------------------------
void __fastcall TForm20::Timer1Timer(TObject *Sender)
{

	TimeLeft--;

	LabelTimeLeft->Caption = "Час, що залишився " + IntToStr(TimeLeft) + " сек";


	if (TimeLeft <= 0)
	{
		Timer1->Enabled = false;
		Form20->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm20::CheckAnswersButtonClick(TObject *Sender)
{
   int score = RandomTest->checkAnswers();
   ShowMessage("Ви правильно вдповіли на  " + IntToStr(score) + " питання") ;
}
//---------------------------------------------------------------------------
void __fastcall TForm20::FormShow(TObject *Sender)
{
     if (OpenDialog1->Execute())
	{
		RandomTest->RandomTEST(this, OpenDialog1->FileName);
	}
	TimeLeft = 360;
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

