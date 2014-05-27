unit uEditor;

interface
uses Windows, Forms, DAudioEffectX, Messages, ExtCtrls,
     Classes, Graphics, StdCtrls, Controls, DVstUtils,
     DVstTemplate, DAEffectX;

type
  TPluginEditorWindow = class(TForm)
    Ctrl: TLabel;
    Updater: TTimer;
    par0: TScrollBar;
    par1: TScrollBar;
    par2: TScrollBar;
    par3: TScrollBar;
    par4: TScrollBar;
    par5: TScrollBar;
    Label1: TLabel;
    Label2: TLabel;
    vu_l: TShape;
    vu_r: TShape;
    gain_l: TLabel;
    gain_r: TLabel;
    procedure UpdaterTimer(Sender: TObject);
    procedure par0Change(Sender: TObject);
  private
    FEffect: TVstTemplate;
  public
    manually: boolean;
    fPar: array of single;
    property Effect: TVstTemplate read FEffect write FEffect;
  private
    procedure OnEditorOpen(var Msg: TMessage); message WM_EDITOROPEN;
  end;

implementation
uses sysutils, uplugin;
{$R *.DFM}

procedure TPluginEditorWindow.UpdaterTimer(Sender: TObject);
var j: integer;
begin
 if (not assigned(Effect)) or(not Effect.editorNeedsUpdate) then exit;
 manually := true;
 // parameters are written to the graphic controls
 // for performance reasons, always make sure you update a graphic
 // control only if the actual value it represents has changed!
 with Effect do
 begin
  j := round(getParameter(0) * 100);
  if j <> par0.position then par0.position := j;
  j := round(getParameter(1) * 100);
  if j <> par1.position then par1.position := j;
  j := round(getParameter(2) * 100);
  if j <> par2.position then par2.position := j;
  j := round(getParameter(3) * 100);
  if j <> par3.position then par3.position := j;
  j := round(getParameter(4) * 100);
  if j <> par4.position then par4.position := j;
  j := round(getParameter(5) * 100);
  if j <> par5.position then par5.position := j;
 end;
 manually := false;
 Effect.editorNeedsUpdate := false;
end;

procedure TPluginEditorWindow.par0Change(Sender: TObject);
begin
 // graphic control is written to parameter
 if manually then exit;
 if assigned(effect) then
  effect.setParameterAutomated((Sender as TScrollbar).Tag,
   (Sender as TScrollbar).Position / 100);
end;

procedure TPluginEditorWindow.OnEditorOpen(var Msg: TMessage);
begin
 Effect := TVstTemplate(Msg.WParam);
end;

end.

