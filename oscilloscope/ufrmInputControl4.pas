unit ufrmInputControl4;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms,
  Dialogs,AMixer,mmsystem, Buttons, ComCtrls, StdCtrls, ExtCtrls;

type
  TfrmInputControl = class(TFrame)
    trInpVoume: TTrackBar;
    pnlButtons: TPanel;
    Panel2: TPanel;
    Panel3: TPanel;
    lblStereo: TLabel;

    procedure AdjustVolume;
    function GetSelectedDevice: integer;
    procedure InitRecorderControls;
    procedure MixerChange(Sender: TObject; MixerH: HMixer; ID: Integer);
    procedure SelectDevice(aInp: integer);
    procedure SetVolume(aValue: integer);
    procedure trInpVoumeChange(Sender: TObject);

    procedure SelectComponentClick(Sender: TObject);
  private
    FMixer: TAudioMixer;
    procedure AddControls(aParent: TWinControl; aMixerID,
      aDestination: integer);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  end;

implementation

{$R *.dfm}


const

  DEST     = 0; //Destination  1= Recorder Control

constructor TfrmInputControl.Create(AOwner: TComponent);
begin
  inherited;
  FMixer := TAudioMixer.Create(self);
  FMixer.OnControlChange := MixerChange;
  AddControls(pnlButtons ,FMixer.MixerId,DEST);
  InitRecorderControls;
  pnlButtons.AutoSize := true;

{  //DEV_MIX := getConnectionIndex(FMixer.MixerId,DEST,MIXERLINE_COMPONENTTYPE_SRC_LAST);
  DEV_MIC  := GetComponentIndex(FMixer.MixerId,DEST,MIXERLINE_COMPONENTTYPE_SRC_MICROPHONE);
  DEV_CD   := GetComponentIndex(FMixer.MixerId,DEST,MIXERLINE_COMPONENTTYPE_SRC_COMPACTDISC);
  DEV_AUX  := GetComponentIndex(FMixer.MixerId,DEST,MIXERLINE_COMPONENTTYPE_SRC_ANALOG);
  DEV_LINE := GetComponentIndex(FMixer.MixerId,DEST,MIXERLINE_COMPONENTTYPE_SRC_LINE);
  DEV_WAVE := GetComponentIndex(FMixer.MixerId,DEST,MIXERLINE_COMPONENTTYPE_SRC_WAVEOUT);
  //DEV_WAVE := GetComponentIndex(FMixer.MixerId,DEST,MIXERLINE_COMPONENTTYPE_SRC_UNDEFINED);}

end;

destructor TfrmInputControl.Destroy;
begin
  FreeAndNil(FMixer);
  inherited;
end;


procedure TfrmInputControl.AddControls(aParent:TWinControl;aMixerID:integer;aDestination:integer);
















































      myBtn := TSpeedButton.Create(aParent);
      myBtn.Parent := aParent;
      myBtn.Align := alLeft;
      myBtn.Width := 40;
      myBtn.Tag   := C;
      myBtn.GroupIndex := 2;
      myBtn.AllowAllUp := False;
      myBtn.Caption    := ExtractBtnCaption(AM.Destinations[aDestination].Connections[C].Data.szShortName,
                                            AM.Destinations[aDestination].Connections[C].Data.dwComponentType);
      myBtn.OnClick := SelectComponentClick;
    end;








procedure TfrmInputControl.InitRecorderControls;
var
  L,R,M   : Integer;
  VD,MD   : Boolean;
  Stereo  : Boolean;
  IsSelect: Boolean;
  loop    : Integer;
begin
  FMixer.Destinations[DEST];

  for Loop := 0 to pnlButtons.ControlCount -1 do
  begin
    FMixer.GetVolume(DEST,TSpeedButton(pnlButtons.Controls[Loop]).Tag,L,R,M,Stereo,VD,MD,IsSelect);
      TSpeedButton(pnlButtons.Controls[Loop]).Down := M>0 ;

      if TSpeedButton(pnlButtons.Controls[Loop]).Down then
      begin
        lblStereo.Visible := not Stereo;
      end;
  end;

  AdjustVolume;
end;

procedure TfrmInputControl.SelectDevice(aInp:integer);
var
  L,R,M   : Integer;
  VD,MD   : Boolean;
  Stereo  : Boolean;
  IsSelect: Boolean;
begin
  FMixer.GetVolume (DEST,aInp,L,R,M,Stereo,VD,MD,IsSelect);
  FMixer.SetVolume (DEST,aInp,L,R,1);        //1= select
  trInpVoume.Position := L;
end;

procedure TfrmInputControl.AdjustVolume;
var
  L,R,M   : Integer;
  VD,MD   : Boolean;
  Stereo  : Boolean;
  IsSelect: Boolean;
  myDev   : integer;
begin
  myDev  := GetSelectedDevice;

  if myDev > -1 then
  begin
    FMixer.GetVolume(DEST,myDev,L,R,M,Stereo,VD,MD,IsSelect);
    trInpVoume.Position := L;
  end;
end;

procedure TfrmInputControl.SetVolume(aValue:integer);
var
  myDev : integer;
begin
  myDev  := GetSelectedDevice;

  if myDev > -1 then
    FMixer.SetVolume(DEST,myDev,aValue,aValue,1);
end;

function TfrmInputControl.GetSelectedDevice:integer;
var
  L,R,M   : Integer;
  VD,MD   : Boolean;
  Stereo  : Boolean;
  IsSelect: Boolean;
  loop    : integer;
begin
  Result := -1;

  if pnlButtons.ControlCount=0 then
    Exit;

  for loop := 0 to pnlButtons.ControlCount do
  begin
    FMixer.GetVolume(DEST,Loop,L,R,M,Stereo,VD,MD,IsSelect);
    if M > 0 then
    begin
      Result := Loop;
      Break;
    end;
  end;
end;

procedure TfrmInputControl.trInpVoumeChange(Sender: TObject);
begin
  SetVolume(trInpVoume.Position);
end;

procedure TfrmInputControl.MixerChange(Sender: TObject; MixerH: HMixer; ID: Integer);
begin
  InitRecorderControls;
end;

procedure TfrmInputControl.SelectComponentClick(Sender: TObject);
begin
  SelectDevice(TSpeedButton(sender).Tag);
end;

end.