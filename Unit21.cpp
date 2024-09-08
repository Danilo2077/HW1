//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit21.h"
#include "Unit22.h"
#include "uTestClass.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm21 *Form21;

//---------------------------------------------------------------------------
__fastcall TForm21::TForm21(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm21::CreateFromTestButtonClick(TObject *Sender)
{
	TSaveDialog *saveDialog = new TSaveDialog(this);
    saveDialog->Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
	saveDialog->DefaultExt = "txt";
    if (saveDialog->Execute())
    {
	SaveFromTest(this, saveDialog->FileName);
    }
	delete saveDialog;
}

//---------------------------------------------------------------------------

