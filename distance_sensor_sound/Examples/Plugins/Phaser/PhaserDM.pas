unit PhaserDM;

interface

uses 
  Windows, Messages, SysUtils, Classes, Forms, DAVDCommon, DVSTModule, DDspPhaser;

type
  TPhaserModule = class(TVSTModule)
    procedure VSTModuleProcess(const inputs, outputs: TAVDArrayOfSingleDynArray; const sampleframes: Integer);
    procedure PMDepthChange(Sender: TObject; const Index: Integer; var Value: Single);
    procedure PMFeedbackChange(Sender: TObject; const Index: Integer; var Value: Single);
    procedure PMMinimumChange(Sender: TObject; const Index: Integer; var Value: Single);
    procedure PMMaximumChange(Sender: TObject; const Index: Integer; var Value: Single);
    procedure PMRateChange(Sender: TObject; const Index: Integer; var Value: Single);
    procedure PMStagesChange(Sender: TObject; const Index: Integer; var Value: Single);
    procedure VSTModuleOpen(Sender: TObject);
    procedure VSTModuleClose(Sender: TObject);
    procedure VSTModuleEditOpen(Sender: TObject; var GUI: TForm;
      ParentWindow: Cardinal);
    procedure VSTModuleProcessDoubleReplacing(const Inputs,
      Outputs: TAVDArrayOfDoubleDynArray; const SampleFrames: Integer);
  private
    fPhaser : array [0..1] of TPhaser;
  public
  end;

implementation

{$R *.DFM}

uses
  PhaserFrm;

procedure TPhaserModule.VSTModuleOpen(Sender: TObject);
begin
 fPhaser[0] := TPhaser.Create;
 fPhaser[1] := TPhaser.Create;
end;

procedure TPhaserModule.VSTModuleClose(Sender: TObject);
begin
 fPhaser[0].Free;
 fPhaser[1].Free;
end;

procedure TPhaserModule.VSTModuleEditOpen(Sender: TObject; var GUI: TForm;
  ParentWindow: Cardinal);
begin
  GUI := TPhaserForm.Create(Self);
end;

procedure TPhaserModule.PMDepthChange(
  Sender: TObject; const Index: Integer; var Value: Single);
begin
 if Assigned(fPhaser[0]) and Assigned(fPhaser[1]) then
  begin
   fPhaser[0].Depth := 0.01*Value;
   fPhaser[1].Depth := fPhaser[0].Depth;
   if assigned(EditorForm) then
    with (EditorForm As TPhaserForm) do
     if SBDepth.Position <> round(fPhaser[0].Depth)
      then SBDepth.Position := round(fPhaser[0].Depth);
  end;
end;

procedure TPhaserModule.PMFeedbackChange(
  Sender: TObject; const Index: Integer; var Value: Single);
begin
 if Assigned(fPhaser[0]) and Assigned(fPhaser[1]) then
  begin
   fPhaser[0].Feedback := 0.01*Value;
   fPhaser[1].Feedback := fPhaser[0].Feedback;
   if assigned(EditorForm) then
    with (EditorForm As TPhaserForm) do
     if SBFeedback.Position <> round(fPhaser[0].Feedback)
      then SBFeedback.Position := round(fPhaser[0].Feedback);
  end;
end;

procedure TPhaserModule.PMMinimumChange(
  Sender: TObject; const Index: Integer; var Value: Single);
begin
 if Assigned(fPhaser[0]) and Assigned(fPhaser[1]) then
  begin
   fPhaser[0].Minimum := Value;
   fPhaser[1].Minimum := fPhaser[0].Minimum;
   if assigned(EditorForm) then
    with (EditorForm As TPhaserForm) do
     if SBMinimum.Position <> round(fPhaser[0].Minimum)
      then SBMinimum.Position := round(fPhaser[0].Minimum);
  end;
end;

procedure TPhaserModule.PMMaximumChange(
  Sender: TObject; const Index: Integer; var Value: Single);
begin
 if Assigned(fPhaser[0]) and Assigned(fPhaser[1]) then
  begin
   fPhaser[0].Maximum := Value;
   fPhaser[1].Maximum := fPhaser[0].Maximum;
   if assigned(EditorForm) then
    with (EditorForm As TPhaserForm) do
     if SBMaximum.Position <> round(fPhaser[0].Maximum)
      then SBMaximum.Position := round(fPhaser[0].Maximum);
  end;
end;

procedure TPhaserModule.PMRateChange(
  Sender: TObject; const Index: Integer; var Value: Single);
begin
 if Assigned(fPhaser[0]) and Assigned(fPhaser[1]) then
  begin
   fPhaser[0].Rate := Value;
   fPhaser[1].Rate := fPhaser[0].Rate;
   if assigned(EditorForm) then
    with (EditorForm As TPhaserForm) do
     if SBRate.Position <> round(fPhaser[0].Rate)
      then SBRate.Position := round(fPhaser[0].Rate);
  end;
end;

procedure TPhaserModule.PMStagesChange(
  Sender: TObject; const Index: Integer; var Value: Single);
begin
 if Assigned(fPhaser[0]) and Assigned(fPhaser[1]) then
  begin
   fPhaser[0].Stages := round(Value);
   fPhaser[1].Stages := fPhaser[0].Stages;
   if assigned(EditorForm) then
    with (EditorForm As TPhaserForm) do
     if SBDepth.Position <> fPhaser[0].Stages
      then SBDepth.Position := fPhaser[0].Stages;
  end;
end;

procedure TPhaserModule.VSTModuleProcess(const inputs, outputs: TAVDArrayOfSingleDynArray; const sampleframes: Integer);
var i: Integer;
begin
 for i := 0 to sampleframes - 1 do
  begin
   outputs[0,i] := fPhaser[0].Process(inputs[0,i]);
   outputs[1,i] := fPhaser[0].Process(inputs[1,i]);
  end;
end;

procedure TPhaserModule.VSTModuleProcessDoubleReplacing(const Inputs,
  Outputs: TAVDArrayOfDoubleDynArray; const SampleFrames: Integer);
var i: Integer;
begin
 for i := 0 to sampleframes - 1 do
  begin
   outputs[0,i] := fPhaser[0].Process(inputs[0,i]);
   outputs[1,i] := fPhaser[0].Process(inputs[1,i]);
  end;
end;

end.
