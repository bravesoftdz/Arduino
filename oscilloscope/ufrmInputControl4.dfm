object frmInputControl: TfrmInputControl
  Left = 0
  Top = 0
  Width = 689
  Height = 35
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  Constraints.MaxHeight = 35
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clMaroon
  Font.Height = -9
  Font.Name = 'Verdana'
  Font.Style = []
  ParentFont = False
  TabOrder = 0
  object pnlButtons: TPanel
    Left = 121
    Top = 0
    Width = 104
    Height = 35
    Align = alLeft
    BevelOuter = bvNone
    BorderWidth = 5
    ParentColor = True
    TabOrder = 0
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 121
    Height = 35
    Align = alLeft
    BevelOuter = bvNone
    Caption = 'Audio Recorder Control'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -8
    Font.Name = 'Verdana'
    Font.Style = []
    ParentColor = True
    ParentFont = False
    TabOrder = 1
    object lblStereo: TLabel
      Left = 14
      Top = 23
      Width = 45
      Height = 10
      Caption = 'Mono input'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -8
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
    end
  end
  object Panel3: TPanel
    Left = 225
    Top = 0
    Width = 264
    Height = 35
    Align = alLeft
    Alignment = taLeftJustify
    BevelOuter = bvNone
    Caption = '  Gain'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGray
    Font.Height = -8
    Font.Name = 'Verdana'
    Font.Style = []
    ParentColor = True
    ParentFont = False
    TabOrder = 2
    object trInpVoume: TTrackBar
      Left = 32
      Top = 3
      Width = 201
      Height = 25
      Max = 65535
      Orientation = trHorizontal
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = trInpVoumeChange
    end
  end
end
