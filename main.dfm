object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object label: TLabel
    Left = 224
    Top = 56
    Width = 25
    Height = 15
    Caption = 'label'
  end
  object VirtualStringTree1: TVirtualStringTree
    Left = 8
    Top = 8
    Width = 593
    Height = 345
    AccessibleName = 'TITLE'
    Colors.BorderColor = 15987699
    Colors.DisabledColor = clGray
    Colors.DropMarkColor = 15385233
    Colors.DropTargetColor = 15385233
    Colors.DropTargetBorderColor = 15385233
    Colors.FocusedSelectionColor = 15385233
    Colors.FocusedSelectionBorderColor = 15385233
    Colors.GridLineColor = 15987699
    Colors.HeaderHotColor = clBlack
    Colors.HotColor = clBlack
    Colors.SelectionRectangleBlendColor = 15385233
    Colors.SelectionRectangleBorderColor = 15385233
    Colors.SelectionTextColor = clBlack
    Colors.TreeLineColor = 9471874
    Colors.UnfocusedColor = clGray
    Colors.UnfocusedSelectionColor = clWhite
    Colors.UnfocusedSelectionBorderColor = clWhite
    Header.AutoSizeIndex = 0
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    TabOrder = 0
    OnAddToSelection = add_to_selection
    OnGetText = get_text
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <
      item
        Position = 0
        Text = 'URL'
        Width = 250
      end
      item
        Position = 1
        Text = 'TITLE'
        Width = 250
      end>
  end
  object Open_file: TButton
    Left = 128
    Top = 367
    Width = 75
    Height = 25
    Caption = 'Open_file'
    TabOrder = 1
    OnClick = Open_fileClick
  end
  object Deletefile: TButton
    Left = 416
    Top = 359
    Width = 75
    Height = 25
    Caption = 'Deletefile'
    TabOrder = 2
    OnClick = DeletefileClick
  end
  object OpenDialog1: TOpenDialog
    Left = 16
    Top = 360
  end
end
