object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 609
  ClientWidth = 1048
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnMouseDown = FormMouseDown
  OnMouseMove = FormMouseMove
  OnMouseUp = FormMouseUp
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 144
    Top = 400
    Width = 150
    Height = 21
    Alignment = taCenter
    Caption = #1048#1079#1084#1077#1085#1077#1085#1080#1077' '#1089#1082#1086#1088#1086#1089#1090#1080
  end
  object Label2: TLabel
    Left = 328
    Top = 400
    Width = 150
    Height = 21
    Alignment = taCenter
    Caption = #1057#1082#1086#1088#1086#1089#1090#1100' '#1074#1088#1072#1097#1077#1085#1080#1103
  end
  object Label3: TLabel
    Left = 512
    Top = 400
    Width = 150
    Height = 21
    Alignment = taCenter
    Caption = #1048#1079#1084#1077#1085#1077#1085#1080#1077' '#1084#1072#1089#1096#1090#1072#1073#1072
  end
  object Shape1: TShape
    Left = 0
    Top = 272
    Width = 137
    Height = 113
  end
  object Button1: TButton
    Left = 32
    Top = 504
    Width = 75
    Height = 25
    Caption = #1055#1088#1086#1076#1086#1083#1078#1080#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 32
    Top = 544
    Width = 75
    Height = 25
    Caption = #1055#1072#1091#1079#1072
    TabOrder = 1
    OnClick = Button2Click
  end
  object TrackBar1: TTrackBar
    Left = 144
    Top = 440
    Width = 150
    Height = 45
    TabOrder = 2
  end
  object TrackBar2: TTrackBar
    Left = 328
    Top = 440
    Width = 150
    Height = 45
    TabOrder = 3
  end
  object TrackBar3: TTrackBar
    Left = 512
    Top = 440
    Width = 150
    Height = 45
    TabOrder = 4
    OnChange = TrackBar3Change
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 600
    Width = 1048
    Height = 9
    Panels = <>
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 200
    Top = 512
  end
  object Timer2: TTimer
    OnTimer = Timer2Timer
    Left = 392
    Top = 520
  end
  object Timer3: TTimer
    OnTimer = Timer3Timer
    Left = 568
    Top = 512
  end
end
