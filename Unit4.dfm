object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Form4'
  ClientHeight = 668
  ClientWidth = 1028
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnShow = FormShow
  TextHeight = 17
  object ResultLabel: TLabel
    Left = 472
    Top = 721
    Width = 4
    Height = 21
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LabelTimeLeft: TLabel
    Left = 725
    Top = 576
    Width = 80
    Height = 17
    Caption = 'LabelTimeLeft'
  end
  object CheckAnswersButton: TButton
    Left = 725
    Top = 616
    Width = 121
    Height = 25
    Caption = #1055#1088#1086#1074#1077#1088#1080#1090#1100' '#1058#1077#1089#1090
    TabOrder = 0
    OnClick = CheckAnswersButtonClick
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 568
    Top = 224
  end
  object OpenDialog1: TOpenDialog
    Left = 552
    Top = 352
  end
end
