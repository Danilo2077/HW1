//---------------------------------------------------------------------------

#ifndef Unit21H
#define Unit21H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm21 : public TForm
{
__published:	// IDE-managed Components
	TButton *CreateFromTestButton;
	TGroupBox *GroupBox1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	TGroupBox *GroupBox2;
	TRadioButton *RadioButton5;
	TRadioButton *RadioButton6;
	TRadioButton *RadioButton7;
	TRadioButton *RadioButton8;
	TGroupBox *GroupBox3;
	TLabel *Label4;
	TRadioButton *RadioButton9;
	TRadioButton *RadioButton10;
	TRadioButton *RadioButton11;
	TRadioButton *RadioButton12;
	TGroupBox *GroupBox4;
	TRadioButton *RadioButton13;
	TRadioButton *RadioButton14;
	TRadioButton *RadioButton15;
	TRadioButton *RadioButton16;
	TEdit *EditQuestion1;
	TEdit *EditAnswer1;
	TEdit *EditAnswer2;
	TEdit *EditAnswer3;
	TEdit *EditAnswer4;
	TEdit *EditQuestion3;
	TEdit *EditAnswer9;
	TEdit *EditAnswer10;
	TEdit *EditAnswer11;
	TEdit *EditAnswer12;
	TEdit *EditQuestion2;
	TEdit *EditAnswer5;
	TEdit *EditAnswer6;
	TEdit *EditAnswer7;
	TEdit *EditAnswer8;
	TEdit *EditQuestion4;
	TEdit *EditAnswer13;
	TEdit *EditAnswer14;
	TEdit *EditAnswer15;
	TEdit *EditAnswer16;
	TOpenDialog *OpenDialog1;
	void __fastcall CreateFromTestButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm21(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm21 *Form21;
//---------------------------------------------------------------------------
#endif
