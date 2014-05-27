unit uEditor;

interface
uses Windows, Forms, DAudioEffectX, Messages, ExtCtrls,
     Classes, Graphics, StdCtrls, Controls, 
     DVstTemplate, DAEffectX, DVstUtils;

type
  TPluginEditorWindow = class(TForm)
    Ctrl: TLabel;
    Updater: TTimer;
    Button1: TButton;
    Button2: TButton;
    VolumeBar: TScrollBar;
    Label1: TLabel;
    NoteBar: TScrollBar;
    Label2: TLabel;
    procedure UpdaterTimer(Sender: TObject);
    procedure par0Change(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure VolumeBarChange(Sender: TObject);
    procedure NoteBarChange(Sender: TObject);
  private
    FEffect: TVstTemplate;
  public
    manually: boolean;
    fPar: array of single;
    LastNote,LastVelocity : integer;
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
(*
 if (not assigned(Effect)) or(not Effect.editorNeedsUpdate) then exit;
 manually := true;
 // parameters are written to the graphic controls
 // for performance reasons, always make sure you update a graphic
 // control only if the actual value it represents has changed!
 with Effect do
 begin
  j := round(getParameter(0) * 100);
  if j <> par0.position then par0.position := j;
 end;
 manually := false;
 Effect.editorNeedsUpdate := false;
*) 
end;

procedure TPluginEditorWindow.par0Change(Sender: TObject);
begin
 // graphic control is written to parameter
 if manually then exit;
 if assigned(effect) then
  Effect.setParameterAutomated((Sender as TScrollbar).Tag,
   (Sender as TScrollbar).Position / 100);
end;

procedure TPluginEditorWindow.OnEditorOpen(var Msg: TMessage);
begin
 Effect := TVstTemplate(Msg.WParam);
end;

procedure TPluginEditorWindow.Button1Click(Sender: TObject);
begin
 LastNote := NoteBar.Position;
 Effect.MIDI_NoteOn(0,LastNote ,127);
end;

procedure TPluginEditorWindow.Button2Click(Sender: TObject);
begin
 Effect.MIDI_NoteOff(0,LastNote ,127);
end;

procedure TPluginEditorWindow.VolumeBarChange(Sender: TObject);
begin
// Effect.MIDI_NoteOn(0,LastNote,VolumeBar.Position);
//  Effect.MIDI_Out( $F0, $7F, $04, $01, $7F, $7F, $F7  );
  Label1.Caption := 'Volume: '+inttostr(VolumeBar.Position);
end;

procedure TPluginEditorWindow.NoteBarChange(Sender: TObject);
begin
 Label2.Caption := 'Note: '+inttostr(NoteBar.Position);
 Effect.MIDI_NoteOff(0,LastNote ,127);
 Effect.MIDI_NoteOn(0,NoteBar.Position ,127);
 LastNote := NoteBar.Position;

end;

end.

