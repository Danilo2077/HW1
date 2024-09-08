//---------------------------------------------------------------------------

#ifndef Unit20H
#define Unit20H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm20 : public TForm
{
__published:	// IDE-managed Components
	TLabel *ResultLabel;
	TButton *CheckAnswersButton;
	TTimer *Timer1;
	TLabel *LabelTimeLeft;
	TOpenDialog *OpenDialog1;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall CheckAnswersButtonClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private: int TimeLeft;	// User declarations
public:		// User declarations
	__fastcall TForm20(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm20 *Form20;
//---------------------------------------------------------------------------
#endif
