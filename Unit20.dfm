object Form20: TForm20
  Left = 0
  Top = 0
  Caption = 'Form20'
  ClientHeight = 651
  ClientWidth = 1123
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnShow = FormShow
  TextHeight = 15
  object ResultLabel: TLabel
    Left = 876
    Top = 702
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
    Left = 759
    Top = 559
    Width = 74
    Height = 15
    Caption = 'LabelTimeLeft'
  end
  object CheckAnswersButton: TButton
    Left = 759
    Top = 593
    Width = 121
    Height = 25
    Caption = #1055#1088#1086#1074#1077#1088#1080#1090#1100' '#1058#1077#1089#1090
    TabOrder = 0
    OnClick = CheckAnswersButtonClick
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 968
    Top = 456
  end
  object OpenDialog1: TOpenDialog
    Left = 984
    Top = 200
  end
end
