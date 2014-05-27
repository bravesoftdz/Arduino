unit uPlugin;

interface
uses Windows, DVstUtils, uEditor, DAEffect, DAEffectX,
     DAudioEffect, DAudioEffectX, DVstTemplate, Forms,
     Math, DDspUtils, Sysutils;

type
 APlugin = class(TVSTTemplate)
  private
 public
//  procedure processMIDI(ev: VstMidiEvent); override;
  procedure initializeParameters; override;
  constructor Create(audioMaster: TAudioMasterCallbackFunc);
  procedure editorIdle(Sender: TObject);
  procedure sendMidi;
 end;

implementation

constructor APlugin.Create(audioMaster: TAudioMasterCallbackFunc);
var numPrograms, numParameters: integer;
begin
 canDos := [receiveVstEvents, receiveVstMidiEvent, sendVstEvents, sendVstMidiEvent];
 Properties := [prCanMono, prCanReplacing];
 numInputs := 2;
 numOutputs := 2;
 numPrograms := 1;
 numParameters := 1;
 UniqueID := 'ABCE'; // change this!!!
 EffectName := 'Ekim ARDUINO-VST'; // change this!!!
 ProductName := 'Ekim ARDUINO-VST'; // change this!!!
 VendorName := 'EkimTheKing'; // change this!!!
 VendorVersion := 1;
 initialDelay := 0;
 tailSize := 0;
 // You can replace "TPluginEditorWindow" with "nil" if you do not want an own
 // editor window and use the host's default representation
 inherited Create(audiomaster, numPrograms, numParameters, TPluginEditorWindow);
 OnEditorIdle := EditorIdle;
end;

procedure APlugin.initializeParameters;
begin
 // Here you can define the properties for each parameter.
 // This is however optional, if you don't define anything
 // a default linear mapping of 0..1 wil be assumed.
 ParameterProperties[0].min := -24;
 ParameterProperties[0].max := 24;
 ParameterProperties[0].name := 'Transpose';
 ParameterProperties[0].units := 'semitones';
 ParameterProperties[0].curve := ctLinear;
 setParameterEx(0, 0);

end;


procedure APlugin.sendMidi;
begin
//
end;

// This procedure is for processing VST MIDI input and output.
// MIDI input could be processed as shown in the example below,
// MIDI output can be generated by calling one of the MIDI_*
// procedures (look in DVstTemplate.pas for them).
(*
procedure APlugin.processMIDI(ev: VstMidiEvent);
var
 newnote, time, data1, data2, status, channel: integer;
begin
 channel := ev.midiData[0] and $0F;
 status := ev.midiData[0] and $F0;
 data1 := ev.midiData[1] and $7F;
 data2 := ev.midiData[2] and $7F;
 time := ev.deltaFrames;
 // example MIDI code:
 if (status = $90) and (data2 > 0) then // "Note On" ?
 begin
  // data1 contains note number
  // data2 contains note velocity
  newnote := round(f_limit(data1 + getParameterEx(0), 0, 120));
  MIDI_NoteOn(channel, newnote, data2, time);
 end
 else if ((status = $90) and (data2 = 0)) or
  (status = $80) then // "Note Off" ?
 begin
  // data1 contains note number
  // data2 contains note off velocity
  // send "Note Off" back to host (MIDI thru)
  newnote := round(f_limit(data1 + getParameterEx(0), 0, 120));
  MIDI_NoteOff(channel, newnote, data2, time);
 end
 else if (status = $A0) then // "Polyphonic Aftertouch" ?
 begin
  // data1 contains note number
  // data2 contains aftertouch value
 end
 else if (status = $B0) then // "MIDI Controller" ?
 begin
  // data1 contains CC number
  // data2 contains data value
 end
 else if (status = $C0) then // "Program Change" ?
 begin
  // data1 contains program number
 end
 else if (status = $D0) then // "Channel Aftertouch" ?
 begin
  // data1 contains channel aftertouch value
 end
 else if (status = $E0) then // "Pitchbend" ?
 begin
  // data1 and data2 make up the 12 bit pitchbend value
 end;
end;
*)

procedure APlugin.editorIdle(Sender: TObject);
begin
 // Here you can directly access the editor form from the plugin.
// with (Sender as TPluginEditorWindow) do
//  label3.Caption := 'transpose: ' + inttostr(round(getParameterEx(0)));
end;

end.


