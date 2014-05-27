object frmMain: TfrmMain
  Left = 74
  Top = 121
  Width = 891
  Height = 558
  Caption = 'Dual Trace Oscilloscope Ver 4.2.2'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -9
  Font.Name = 'Verdana'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnActivate = FormActivate
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 12
  object Panel2: TPanel
    Left = 0
    Top = 461
    Width = 883
    Height = 43
    Align = alClient
    BevelInner = bvLowered
    BevelWidth = 2
    TabOrder = 0
    inline frmInputControl1: TfrmInputControl
      Left = 4
      Top = 4
      Align = alLeft
      Font.Color = clBtnText
      inherited Panel2: TPanel
        Font.Color = clBtnText
      end
      inherited Panel3: TPanel
        Font.Color = clBtnText
      end
    end
    object StaticText1: TStaticText
      Left = 726
      Top = 12
      Width = 141
      Height = 16
      Cursor = crHandPoint
      Anchors = [akTop, akRight]
      Caption = 'http://www.delphiforfun.org/'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -9
      Font.Name = 'Verdana'
      Font.Style = [fsUnderline]
      ParentFont = False
      TabOrder = 1
      OnClick = StaticText1Click
    end
  end
  object statustext: TPanel
    Left = 0
    Top = 0
    Width = 883
    Height = 33
    Align = alTop
    BevelInner = bvLowered
    BevelWidth = 2
    Caption = 'Oscilloscope'
    Color = clMaroon
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
  end
  object Panel5: TPanel
    Left = 0
    Top = 33
    Width = 883
    Height = 428
    Align = alTop
    Caption = 'Panel5'
    TabOrder = 2
    object Panel6: TPanel
      Left = 628
      Top = 1
      Width = 117
      Height = 426
      Align = alLeft
      BevelInner = bvLowered
      BevelWidth = 2
      TabOrder = 0
      object btnRun: TSpeedButton
        Left = 8
        Top = 8
        Width = 41
        Height = 25
        Hint = 'Run'
        AllowAllUp = True
        GroupIndex = 1
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000000000000000000000000000000000000FF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000FF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FF000000000000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FF000000000000000000000000000000000000000000FF
          00FFFF00FFFF00FFFF00FF000000000000000000000000000000000000000000
          000000000000000000000000000000000000FF00FFFF00FFFF00FF0000000000
          00000000000000000000000000000000000000000000000000000000000000FF
          00FFFF00FFFF00FFFF00FF000000000000000000000000000000000000000000
          000000FF00FF000000000000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
          FF000000000000000000000000000000000000FF00FF000000FF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000000000000000000000000000
          000000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
          FF000000000000000000000000000000000000FF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
        ParentShowHint = False
        ShowHint = True
        OnClick = btnRunClick
      end
      object btnDual: TSpeedButton
        Left = 9
        Top = 72
        Width = 96
        Height = 25
        Hint = 'Dual input'
        AllowAllUp = True
        GroupIndex = 2
        Caption = 'Dual inp.'
        ParentShowHint = False
        ShowHint = True
        OnClick = btnDualClick
      end
      object BtnOneFrame: TSpeedButton
        Left = 50
        Top = 8
        Width = 39
        Height = 25
        Hint = 'Single frame'
        AllowAllUp = True
        GroupIndex = 1
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000000000000000000000000000000000000FF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FF000000FF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000
          00000000FF00FFFF00FF000000000000000000000000FF00FF00000000000000
          0000000000000000000000000000000000000000000000FF00FF000000000000
          000000000000FF00FF0000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000000000FF00FF00000000000000
          0000000000000000000000000000000000000000000000FF00FFFF00FF000000
          000000000000FF00FF000000000000000000FF00FFFF00FFFF00FFFF00FF0000
          00000000FF00FFFF00FFFF00FF000000000000000000FF00FF00000000000000
          0000FF00FFFF00FFFF00FFFF00FF000000FF00FFFF00FFFF00FFFF00FF000000
          000000000000000000000000000000000000FF00FFFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FF00000000000000000000000000000000000000
          0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000
          000000000000000000000000000000000000FF00FFFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
        ParentShowHint = False
        ShowHint = True
        OnClick = BtnOneFrameClick
      end
      object Panel3: TPanel
        Left = 91
        Top = 8
        Width = 13
        Height = 15
        BevelInner = bvLowered
        Color = clMaroon
        TabOrder = 0
      end
      object GroupBox1: TGroupBox
        Left = 8
        Top = 185
        Width = 105
        Height = 232
        Caption = 'Trigger'
        TabOrder = 1
        object btnTriggCh1: TSpeedButton
          Left = 8
          Top = 52
          Width = 33
          Height = 22
          GroupIndex = 3
          Down = True
          Caption = 'Ch1'
        end
        object btnTriggCh2: TSpeedButton
          Left = 8
          Top = 75
          Width = 33
          Height = 22
          GroupIndex = 3
          Caption = 'Ch2'
        end
        object btnTrigPositiv: TSpeedButton
          Left = 8
          Top = 99
          Width = 33
          Height = 22
          GroupIndex = 4
          Caption = '+'
        end
        object btnTrigNegativ: TSpeedButton
          Left = 8
          Top = 123
          Width = 33
          Height = 22
          GroupIndex = 4
          Caption = '-'
        end
        object Label4: TLabel
          Left = 75
          Top = 12
          Width = 7
          Height = 12
          Caption = '0'
        end
        object Label3: TLabel
          Left = 8
          Top = 215
          Width = 94
          Height = 10
          Caption = 'Level (-128 to +128): '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -8
          Font.Name = 'Verdana'
          Font.Style = []
          ParentFont = False
        end
        object btnTrigerOn: TSpeedButton
          Left = 8
          Top = 31
          Width = 33
          Height = 22
          AllowAllUp = True
          GroupIndex = 5
          Caption = 'On'
          OnClick = btnTrigerOnClick
        end
        object TrigLevelBar: TTrackBar
          Left = 56
          Top = 24
          Width = 41
          Height = 185
          Max = 128
          Min = -128
          Orientation = trVertical
          Frequency = 128
          Position = 0
          SelEnd = 0
          SelStart = 0
          TabOrder = 0
          TickMarks = tmBoth
          TickStyle = tsAuto
          OnChange = TrigLevelBarChange
        end
      end
      object SpectrumBtn: TBitBtn
        Left = 8
        Top = 40
        Width = 41
        Height = 25
        Hint = 'Spectrum'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        OnClick = SpectrumBtnClick
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000000000000000000000000000000000000FF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FF00000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000FF00FF000000
          FF00FFFF00FF000000FF00FF000000FF00FF000000FF00FF000000FF00FF0000
          00FF00FFFF00FFFF00FFFF00FF000000FF00FFFF00FF000000FF00FF000000FF
          00FF000000FF00FF000000FF00FF000000FF00FFFF00FFFF00FFFF00FF000000
          FF00FFFF00FF000000FF00FF000000FF00FF000000FF00FF000000FF00FF0000
          00FF00FFFF00FFFF00FFFF00FF000000FF00FFFF00FF000000FF00FF000000FF
          00FF000000FF00FF000000FF00FF000000FF00FFFF00FFFF00FFFF00FF000000
          FF00FFFF00FF000000FF00FF000000FF00FF000000FF00FF000000FF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FF000000FF00FFFF00FFFF00FFFF00FF000000FF
          00FF000000FF00FF000000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000
          FF00FFFF00FFFF00FFFF00FF000000FF00FF000000FF00FF000000FF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FF000000FF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FF000000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000FF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FF000000FF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FF000000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000FF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FF000000FF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FF000000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FF000000FF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF}
      end
      object CalibrateBtn: TBitBtn
        Left = 48
        Top = 40
        Width = 57
        Height = 25
        Hint = 'Set zero level'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        OnClick = CalibrateBtnClick
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000000000000000000000000000000000000FF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FF000000000000000000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000000000000000FF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FF000000000000000000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000000000000000000000000000
          00FF00FFFF00FFFF00FFFF00FFFF00FF000000000000FF00FFFF00FFFF00FFFF
          00FFFF00FF000000000000000000FF00FFFF00FFFF00FFFF00FFFF00FF000000
          FF00FFFF00FF000000FF00FFFF00FFFF00FFFF00FFFF00FF000000FF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FF000000FF00FFFF00FF000000FF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000
          FF00FFFF00FF000000FF00FFFF00FF0000000000000000000000000000000000
          00000000FF00FFFF00FFFF00FF000000FF00FFFF00FF000000FF00FFFF00FFFF
          00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000
          FF00FFFF00FF000000FF00FFFF00FFFF00FFFF00FFFF00FF000000FF00FFFF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FF000000000000FF00FFFF00FFFF00FFFF
          00FFFF00FF000000000000000000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000000000000000000000000000
          00FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FF000000000000000000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
          FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000000000000000FF00
          FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
          00FFFF00FF000000000000000000FF00FFFF00FFFF00FFFF00FF}
      end
    end
    object Panel1: TPanel
      Left = 1
      Top = 1
      Width = 96
      Height = 426
      Align = alLeft
      BevelInner = bvLowered
      BevelWidth = 2
      TabOrder = 1
      object GrpChannel1: TGroupBox
        Left = 8
        Top = 8
        Width = 81
        Height = 201
        Caption = 'Channel 1'
        TabOrder = 0
        object Label5: TLabel
          Left = 48
          Top = 16
          Width = 28
          Height = 12
          Caption = 'Ofset'
        end
        object Label6: TLabel
          Left = 8
          Top = 16
          Width = 23
          Height = 12
          Caption = 'Gain'
        end
        object btnCh1On: TSpeedButton
          Left = 8
          Top = 64
          Width = 33
          Height = 22
          AllowAllUp = True
          GroupIndex = 6
          Down = True
          Caption = 'On'
          OnClick = btnCh1OnClick
        end
        object btnCH1Gnd: TSpeedButton
          Left = 8
          Top = 88
          Width = 33
          Height = 22
          AllowAllUp = True
          GroupIndex = 7
          Caption = 'Gnd'
          OnClick = btnCH1GndClick
        end
        object trOfsCh1: TTrackBar
          Left = 48
          Top = 32
          Width = 25
          Height = 161
          Max = 160
          Min = -160
          Orientation = trVertical
          Frequency = 20
          Position = 0
          SelEnd = 0
          SelStart = 0
          TabOrder = 0
          TickMarks = tmBottomRight
          TickStyle = tsAuto
          OnChange = trOfsCh1Change
        end
        object upGainCh1: TUpDown
          Left = 12
          Top = 40
          Width = 16
          Height = 20
          Associate = edtGainCh1
          Min = 0
          Max = 6
          Position = 3
          TabOrder = 1
          Wrap = False
        end
        object edtGainCh1: TEdit
          Left = 8
          Top = 40
          Width = 4
          Height = 20
          TabOrder = 2
          Text = '3'
          OnChange = edtGainCh1Change
        end
      end
      object grpChannel2: TGroupBox
        Left = 7
        Top = 216
        Width = 82
        Height = 201
        Caption = 'Channel 2'
        TabOrder = 1
        object Label7: TLabel
          Left = 48
          Top = 16
          Width = 28
          Height = 12
          Caption = 'Ofset'
        end
        object Label8: TLabel
          Left = 8
          Top = 16
          Width = 23
          Height = 12
          Caption = 'Gain'
        end
        object btnCh2On: TSpeedButton
          Left = 8
          Top = 64
          Width = 33
          Height = 22
          AllowAllUp = True
          GroupIndex = 6
          Down = True
          Caption = 'On'
          OnClick = btnCh2OnClick
        end
        object btnCH2Gnd: TSpeedButton
          Left = 8
          Top = 88
          Width = 33
          Height = 22
          AllowAllUp = True
          GroupIndex = 7
          Caption = 'Gnd'
          OnClick = btnCH2GndClick
        end
        object trOfsCh2: TTrackBar
          Left = 48
          Top = 32
          Width = 25
          Height = 161
          Max = 160
          Min = -160
          Orientation = trVertical
          Frequency = 20
          Position = 0
          SelEnd = 0
          SelStart = 0
          TabOrder = 0
          TickMarks = tmBottomRight
          TickStyle = tsAuto
          OnChange = trOfsCh2Change
        end
        object upGainCh2: TUpDown
          Left = 12
          Top = 40
          Width = 16
          Height = 20
          Associate = edtGainCh2
          Min = 0
          Max = 6
          Position = 3
          TabOrder = 1
          Wrap = False
        end
        object edtGainCh2: TEdit
          Left = 8
          Top = 40
          Width = 4
          Height = 20
          TabOrder = 2
          Text = '3'
          OnChange = edtGainCh2Change
        end
      end
    end
    object Panel4: TPanel
      Left = 745
      Top = 1
      Width = 137
      Height = 426
      Align = alClient
      BevelInner = bvLowered
      BevelWidth = 2
      TabOrder = 2
      object GroupBox2: TGroupBox
        Left = 8
        Top = 8
        Width = 121
        Height = 169
        Caption = 'Time'
        TabOrder = 0
        object Label2: TLabel
          Left = 8
          Top = 120
          Width = 89
          Height = 13
          AutoSize = False
          Caption = 'Horizontal gain'
          WordWrap = True
        end
        object ScaleLbl: TLabel
          Left = 8
          Top = 20
          Width = 32
          Height = 12
          Caption = 'Scale:'
        end
        object sp11025Sample: TSpeedButton
          Left = 8
          Top = 40
          Width = 49
          Height = 22
          GroupIndex = 6
          Down = True
          Caption = '11,025'
          OnClick = sp11025SampleClick
        end
        object sp22050Sample: TSpeedButton
          Left = 8
          Top = 64
          Width = 49
          Height = 22
          GroupIndex = 6
          Caption = '22,050'
          OnClick = sp22050SampleClick
        end
        object sp44100Sample: TSpeedButton
          Left = 8
          Top = 88
          Width = 49
          Height = 22
          GroupIndex = 6
          Caption = '44,100'
          OnClick = sp44100SampleClick
        end
        object SweepEdt: TEdit
          Left = 8
          Top = 139
          Width = 29
          Height = 20
          TabOrder = 0
          Text = '1'
          OnChange = SweepEdtChange
        end
        object SweepUD: TUpDown
          Left = 37
          Top = 139
          Width = 16
          Height = 20
          Associate = SweepEdt
          Min = 1
          Max = 10
          Position = 1
          TabOrder = 1
          Wrap = False
        end
      end
      object GroupBox3: TGroupBox
        Left = 8
        Top = 184
        Width = 121
        Height = 161
        Caption = 'Capture frame'
        TabOrder = 1
        object btnExpand1: TSpeedButton
          Left = 8
          Top = 31
          Width = 23
          Height = 22
          GroupIndex = 8
          Down = True
          Caption = 'X1'
          OnClick = btnExpand1Click
        end
        object btnExpand2: TSpeedButton
          Left = 32
          Top = 30
          Width = 23
          Height = 22
          GroupIndex = 8
          Caption = 'X2'
          OnClick = btnExpand2Click
        end
        object btnExpand4: TSpeedButton
          Left = 56
          Top = 30
          Width = 23
          Height = 22
          GroupIndex = 8
          Caption = 'X4'
          OnClick = btnExpand4Click
        end
        object btnExpand8: TSpeedButton
          Left = 80
          Top = 30
          Width = 23
          Height = 22
          GroupIndex = 8
          Caption = 'X8'
          OnClick = btnExpand8Click
        end
        object Label11: TLabel
          Left = 8
          Top = 16
          Width = 41
          Height = 12
          Caption = 'Expand:'
        end
        object Label13: TLabel
          Left = 8
          Top = 56
          Width = 27
          Height = 12
          Caption = 'Gain:'
        end
        object btnGain0: TSpeedButton
          Left = 8
          Top = 72
          Width = 33
          Height = 22
          GroupIndex = 9
          Caption = '/2'
          OnClick = btnGain0Click
        end
        object btnGain1: TSpeedButton
          Left = 40
          Top = 72
          Width = 33
          Height = 22
          GroupIndex = 9
          Down = True
          Caption = 'X1'
          OnClick = btnGain1Click
        end
        object btnGain2: TSpeedButton
          Left = 72
          Top = 72
          Width = 33
          Height = 22
          GroupIndex = 9
          Caption = 'X2'
          OnClick = btnGain2Click
        end
        object Label12: TLabel
          Left = 37
          Top = 109
          Width = 47
          Height = 12
          Caption = '<-- X -->'
          OnDblClick = Label12DblClick
        end
        object trStartPos: TTrackBar
          Left = 4
          Top = 120
          Width = 113
          Height = 33
          Max = 400
          Min = -400
          Orientation = trHorizontal
          Frequency = 40
          Position = 0
          SelEnd = 0
          SelStart = 0
          TabOrder = 0
          TickMarks = tmBottomRight
          TickStyle = tsAuto
          OnChange = trStartPosChange
        end
      end
      object GroupBox4: TGroupBox
        Left = 8
        Top = 352
        Width = 121
        Height = 65
        TabOrder = 2
        object Label9: TLabel
          Left = 8
          Top = 13
          Width = 28
          Height = 12
          Caption = 'Scale'
        end
        object Label1: TLabel
          Left = 50
          Top = 13
          Width = 30
          Height = 12
          Caption = 'Inten.'
        end
        object Label10: TLabel
          Left = 86
          Top = 13
          Width = 27
          Height = 12
          Caption = 'focus'
        end
        object upBeamLight: TUpDown
          Left = 56
          Top = 32
          Width = 17
          Height = 25
          Min = -180
          Max = 150
          Increment = 15
          Position = 1
          TabOrder = 0
          Wrap = False
          OnClick = upBeamLightClick
        end
        object upFocus: TUpDown
          Left = 96
          Top = 32
          Width = 17
          Height = 25
          Min = 1
          Max = 6
          Position = 1
          TabOrder = 1
          Wrap = False
          OnClick = upFocusClick
        end
        object UpScaleLight: TUpDown
          Left = 16
          Top = 32
          Width = 17
          Height = 25
          Min = 25
          Max = 200
          Increment = 10
          Position = 70
          TabOrder = 2
          Wrap = False
          OnChanging = UpScaleLightChanging
        end
      end
    end
    object PageControl1: TPageControl
      Left = 97
      Top = 1
      Width = 531
      Height = 426
      ActivePage = Runsheet
      Align = alLeft
      TabOrder = 3
      object IntroSheet: TTabSheet
        Caption = 'Introduction'
        ImageIndex = 1
        object Memo1: TMemo
          Left = 0
          Top = 0
          Width = 523
          Height = 399
          Align = alClient
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = []
          Lines.Strings = (
            
              'This simple oscilloscope uses the Windows Wavein API to capture ' +
              'data from'
            
              'a sound card and display it in the screen area above.   Use the ' +
              'Windows'
            
              '"Volume Controls - Options - Properties"  dialog and select "Rec' +
              'ording'
            
              'Controls" to select input source(s) to be displayed.    After th' +
              'e Start button'
            
              'is clicked, any messages describing capture problems will be dis' +
              'played here.'
            ''
            
              'Version  2: A "Trigger" capability has been added.  Each scan is' +
              ' triggered'
            
              'when the signal rises above (+) or below (-) the preset trigger ' +
              'level.  To '
            
              'improve the image capture of transient events, there is now a "C' +
              'apture'
            
              'Single Frame" button.  Use he "Trigger" feature to control when ' +
              'the frame'
            'will be captured.'
            ''
            
              'Version 3  Spectrum analysis of Captured frames.  User selectabl' +
              'e Sample'
            'rates.  Time scale ref.lines on display.'
            ''
            
              'Version 4:  Dual trace function added.  Improved visual layout. ' +
              '  Improved'
            
              'controls.  Input signal selectable via buttons.    Settings save' +
              'd from run to'
            
              'run.  Many thanks to "Krille", a very sharp Delphi programmer fr' +
              'om Sweden.')
          ParentFont = False
          TabOrder = 0
        end
      end
      object Runsheet: TTabSheet
        Caption = 'Oscilloscope'
        inline frmOscilloscope1: TfrmOscilloscope
          Width = 523
          Height = 399
          Align = alClient
          inherited Image2: TImage
            Left = 42
            Width = 440
          end
          inherited Image3: TImage
            Left = 483
          end
          inherited Image8: TImage
            Left = 472
          end
          inherited Image10: TImage
            Left = 471
          end
          inherited imgScreen: TImage
            Left = 42
            Width = 440
          end
        end
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 192
    Top = 24
    object File1: TMenuItem
      Caption = 'File'
      object menuSaveImage1: TMenuItem
        Caption = 'Save Image'
        OnClick = menuSaveImage1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object menuExit: TMenuItem
        Caption = 'Exit'
        OnClick = menuExitClick
      end
    end
    object Screen1: TMenuItem
      Caption = 'Screen'
      object Color1: TMenuItem
        Caption = 'Color'
        object menuBlack: TMenuItem
          Caption = 'Black'
          OnClick = menuBlackClick
        end
        object MenuGreen: TMenuItem
          Caption = 'Green'
          OnClick = MenuGreenClick
        end
      end
      object Data1: TMenuItem
        Caption = 'Data'
        object MenuData_Time: TMenuItem
          Caption = 'Time'
          OnClick = MenuData_TimeClick
        end
      end
    end
  end
end
