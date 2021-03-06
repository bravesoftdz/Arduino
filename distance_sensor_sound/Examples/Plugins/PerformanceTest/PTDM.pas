unit PTDM;

interface

uses 
  FastMove, Windows, Messages, SysUtils, Classes, Forms, DAVDCommon,
  DVSTEffect, DVSTEffectFunctions, DVSTModule;

type
  TPerformanceTestModule = class(TVSTModule)
    procedure VSTModuleEditOpen(Sender: TObject; var GUI: TForm; ParentWindow: Cardinal);
    procedure VSTModuleProcess(const Inputs, Outputs: TAVDArrayOfSingleDynArray; SampleFrames: Integer);
    procedure VSTModuleProcessDoubleReplacing(const Inputs, Outputs: TAVDArrayOfDoubleDynArray; SampleFrames: Integer);
    procedure VSTModuleCreate(Sender: TObject);
  private
    function GetProcessorCycles: Double;
  public
    Cycles       : Double;
    CycleCounter : Integer;
    procedure PatchProcessCalls;
    property ProcessorCycles : Double read GetProcessorCycles;
  end;

implementation

{$R *.DFM}

uses
  PTGUI, DVSTBasicModule;

var StartStop  : function:Int64;

function RDTSC: Int64;
asm
 DW  0310Fh
end;

function NoRDTSC: Int64;
begin
 result:=0;
end;

function IsRDTSCPresent: Boolean;
 function HasRDTSC: Boolean; assembler;
 asm
  PUSH  EBX
  PUSHFD
  PUSHFD
  POP   EAX
  MOV   EDX,EAX
  XOR   EAX,0040000h
  PUSH  EAX
  POPFD
  PUSHFD
  POP   EAX
  XOR   EAX,EDX
  JZ   @@1
  PUSHFD
  POP   EAX
  MOV   EDX,EAX
  XOR   EAX,0200000h
  PUSH  EAX
  POPFD
  PUSHFD
  POP   EAX
  XOR   EAX,EDX
@@1:  POPFD
  TEST  EAX,EAX
  JZ   @@2
  MOV   EAX,1
  DW   0A20Fh
  TEST  EDX,010h
  SETNZ  AL
@@2:  POP   EBX
 end;

begin
 try
  Result := HasRDTSC;
  if Result then RDTSC;
 except
  Result := False;
 end;
end;

procedure ProcessFunc(Effect: PVSTEffect; Inputs, Outputs: PPSingle; SampleFrames: Integer); cdecl;
var Start,Stop    : Int64;
begin
 with TPerformanceTestModule(Effect^.vObject) do
  begin
   Start := StartStop;
   HostCallProcess(Inputs, Outputs, SampleFrames);
   Stop := StartStop;
   Cycles := CycleCounter / (CycleCounter + 1) * Cycles + (Stop - Start) / (CycleCounter + 1);
   inc(CycleCounter);
  end;
end;

procedure ProcessReplacingFunc(Effect: PVSTEffect; Inputs, Outputs: PPSingle; SampleFrames: Integer); cdecl;
var Start,Stop    : Int64;
begin
 with TPerformanceTestModule(Effect^.vObject) do
  begin
   Start := StartStop;
   HostCallProcessReplacing(Inputs, Outputs, SampleFrames);
   Stop := StartStop;
   Cycles := CycleCounter / (CycleCounter + 1) * Cycles + (Stop - Start) / (CycleCounter + 1);
   inc(CycleCounter);
  end;
end;

procedure ProcessDoubleReplacingFunc(Effect: PVSTEffect; Inputs, Outputs: PPDouble; SampleFrames: Integer); cdecl;
var Start,Stop    : Int64;
begin
 with TPerformanceTestModule(Effect^.vObject) do
  begin
   Start := StartStop;
   HostCallProcessDoubleReplacing(Inputs, Outputs, SampleFrames);
   Stop := StartStop;
   Cycles := CycleCounter / (CycleCounter + 1) * Cycles + (Stop - Start) / (CycleCounter + 1);
   inc(CycleCounter);
  end;
end;

function TPerformanceTestModule.GetProcessorCycles: Double;
begin
 result := Cycles;
end;

procedure TPerformanceTestModule.PatchProcessCalls;
begin
 CycleCounter := 0;
 FEffect.Process := ProcessFunc;
 FEffect.ProcessReplacing := ProcessReplacingFunc;
 FEffect.ProcessDoubleReplacing := ProcessDoubleReplacingFunc;
end;

procedure TPerformanceTestModule.VSTModuleCreate(Sender: TObject);
var DataTest   : TAVDDoubleDynArray;
    DataGetmem : PSingle;
begin
 SetMinimumBlockAlignment(mba8Byte);
 DataGetmem := GetMemory(8192 * SizeOf(Single));
 SetLength(DataTest, 8192);
 FindMaximum(PSingle(@DataTest[0]), 8192);
 FindMaximum(DataGetmem, 8192);
end;

procedure TPerformanceTestModule.VSTModuleEditOpen(Sender: TObject; var GUI: TForm; ParentWindow: Cardinal);
begin
 GUI := TFmPerformanceTest.Create(Self);
end;

procedure TPerformanceTestModule.VSTModuleProcess(const Inputs,
  Outputs: TAVDArrayOfSingleDynArray; SampleFrames: Integer);
begin
 Move(Inputs[0, 0], Outputs[0, 0], SampleFrames * SizeOf(Single));
 Move(Inputs[1, 0], Outputs[1, 0], SampleFrames * SizeOf(Single));
end;

procedure TPerformanceTestModule.VSTModuleProcessDoubleReplacing(const Inputs,
  Outputs: TAVDArrayOfDoubleDynArray; SampleFrames: Integer);
begin
 Move(Inputs[0, 0], Outputs[0, 0], SampleFrames * SizeOf(Single));
 Move(Inputs[1, 0], Outputs[1, 0], SampleFrames * SizeOf(Single));
end;

initialization

if IsRDTSCPresent
 then StartStop:=RDTSC
 else StartStop:=NoRDTSC;

end.