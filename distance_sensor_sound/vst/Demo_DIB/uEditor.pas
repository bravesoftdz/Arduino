unit uEditor;
// In this file all editor related stuff is managed.
// It can practically be an own program that just has to send
// some data via setParameter/setParameterAutomated to the
// main plugin/algorithm.

interface
uses Windows, Forms, DAudioEffectX, Controls, Classes, ExtCtrls, ComCtrls, Graphics,
  StdCtrls, Messages, cDIBImageList, cDIBSlider, cDIBControl, cDIBImage,
  cDIBPanel, cDIBFeatures, cDIBTimer, DVstTemplate;

type
  TPluginEditorWindow = class(TForm)
    Ctrl: TLabel;
    updater: TDIBTimer;
    bg: TDIBImageContainer;
    DIBImageList1: TDIBImageList;
    par0: TDIBSlider;
    par1: TDIBSlider;
    vu_l: TDIBImageContainer;
    vu_r: TDIBImageContainer;
    gain_l: TLabel;
    gain_r: TLabel;
    procedure UpdaterTimer(Sender: TObject);
    procedure par0Change(Sender: TObject);
  private
    FEffect:AudioEffectX;
    procedure OnEditorOpen(var Msg: TMessage); message WM_EDITOROPEN;
  public
    manually: boolean;
    property Effect: AudioEffectX read FEffect write FEffect;
  private
    procedure WMEraseBkgnd(var m: TWMEraseBkgnd); message WM_ERASEBKGND;
  end;

implementation
uses sysutils;

{$R *.DFM}

procedure TPluginEditorWindow.WMEraseBkgnd(var m : TWMEraseBkgnd);
begin m.Result:=LRESULT(False) end;

procedure TPluginEditorWindow.UpdaterTimer(Sender: TObject);
var j: integer;
begin
 manually := true;
 //parameters are written to the graphic controls
 //for performance reasons, always make sure you update a graphic
 //control only if the actual value it represents has changed!
 j := round(effect.getParameter(0) * 100); if j <> par0.position then par0.position := j;
 j := round(effect.getParameter(1) * 100); if j <> par1.position then par1.position := j;
 manually := false;
end;

procedure TPluginEditorWindow.par0Change(Sender: TObject);
begin
 //graphic control is written to parameter
 if manually then exit;
 if assigned(effect) then effect.setParameterAutomated(
  (sender as TDIBSlider).Tag, (sender as TDIBSlider).position / 100);
end;

procedure TPluginEditorWindow.OnEditorOpen(var Msg: TMessage);
begin
 Effect := TVstTemplate(Msg.WParam);
 updater.enabled := true;
end;

end.

