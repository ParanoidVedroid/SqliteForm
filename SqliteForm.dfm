object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 500
  ClientWidth = 791
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Table: TVirtualStringTree
    Left = 8
    Top = 8
    Width = 775
    Height = 385
    EditDelay = 0
    Header.AutoSizeIndex = 0
    Header.Height = 17
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    TabOrder = 0
    TreeOptions.SelectionOptions = [toFullRowSelect, toMultiSelect]
    OnGetText = OnGetText
    Columns = <
      item
        Position = 0
        Text = 'id'
        Width = 48
      end
      item
        Position = 1
        Text = 'URL'
        Width = 338
      end
      item
        Position = 2
        Text = 'Title'
        Width = 383
      end>
  end
  object OpenDB: TButton
    Left = 16
    Top = 408
    Width = 153
    Height = 49
    Caption = 'Open'
    TabOrder = 1
    OnClick = OpenDBClick
  end
  object DeleteItem: TButton
    Left = 224
    Top = 408
    Width = 153
    Height = 49
    Caption = 'Delete record'
    TabOrder = 2
    OnClick = DeleteItemClick
  end
  object ClearTable: TButton
    Left = 432
    Top = 408
    Width = 153
    Height = 49
    Caption = 'Clear history'
    TabOrder = 3
    OnClick = ClearTableClick
  end
end
