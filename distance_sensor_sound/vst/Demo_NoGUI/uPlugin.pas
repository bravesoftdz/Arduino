unit uPlugin;

interface
uses Windows, DVstUtils, DAEffect, DAEffectX,
     DAudioEffect, DAudioEffectX, DVstTemplate, Forms,
     Math, DDspUtils, SysUtils, classes;

type
 APlugin = class(TVstTemplate)
 public
  old1, old2: array[0..1] of single;
  procedure initializeParameters; override;
  function DoFilter(num: integer; i, cutoff, res: single): single;
  procedure processAudio(const inputs, outputs: TArrayOfSingleArray;
   sampleframes: Integer); override;
  constructor Create(audioMaster: TAudioMasterCallbackFunc);
 end;

implementation

constructor APlugin.Create(audioMaster: TAudioMasterCallbackFunc);
var numPrograms, numParameters: integer;
begin
 canDos := [receiveVstEvents, receiveVstMidiEvent,
  sendVstEvents, sendVstMidiEvent];
 Properties := [prCanMono, prCanReplacing];
 numInputs := 2;
 numOutputs := 2;
 numPrograms := 1;
 numParameters := 2;
 UniqueID := 'TBD2';
 EffectName := 'NoGUIDemo';
 ProductName := 'NoGUIDemo';
 VendorName := 'Tobybear';
 VendorVersion := 1;
 initialDelay := 0;
 tailSize := 0;
 inherited Create(audiomaster, numPrograms, numParameters, nil);
end;

procedure APlugin.initializeParameters;
begin
 ParameterProperties[0].name := 'cutoff';
 ParameterProperties[1].name := 'resonance';
 setParameter(0, 1);
 setParameter(1, 0);
end;

function APlugin.DoFilter(num: integer; i, cutoff, res: single): single;
var fb: single;
begin
 fb := res + res / (1 - cutoff * 0.9);
 old1[num] := old1[num] + cutoff * (i - old1[num] + fb * (old1[num] - old2[num])) + kDenorm;
 old2[num] := old2[num] + cutoff * (old1[num] - old2[num]);
 result := f_limit(old2[num]);
end;

procedure APlugin.processAudio(const inputs, outputs: TArrayOfSingleArray;
  sampleframes: Integer);
var i: integer;
    cut, res: single;
begin
 cut := getParameter(0) * 0.8;
 res := getParameter(1);
 for i := 0 to sampleFrames - 1 do
 begin
  outputs[0, i] := DoFilter(0, inputs[0, i], cut, res);
  outputs[1, i] := DoFilter(1, inputs[1, i], cut, res);
 end;
end;

end.



