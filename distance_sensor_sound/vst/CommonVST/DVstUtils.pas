//******************************************************************************
//
//  DVstUtils.pas
//  21 May 2003
//
//  Part of the VST 2.3 SDK for Delphi
//  by Frederic Vanmol
//     http://www.axiworld.be
//     frederic@axiworld.be
//
//------------------------------------------------------------------------------
//
//  Types : PPERect
//          PERect
//          ERect
//
//  Functions : FourCharToLong
//              FMod
//              dB2string
//              db2stringRound              
//              float2string
//              long2string
//              float2stringAsLong
//              Hz2string (new)
//              ms2string (new)
//              gapSmallValue
//              invGapSmallValue
//
//  Note : This unit requires the Delphi Math unit, which can be found on the
//         Delphi cd if you don't have it installed yet
//
//******************************************************************************
unit
    DVstUtils;

interface

type
    PPERect = ^PERect;
    PERect = ^ERect;
    ERect = record
      top,
      left,
      bottom,
      right   : Smallint;
    end;


function FourCharToLong(C1, C2, C3, C4: Char): Longint;

function FMod(d1, d2: Double): Double;

procedure dB2string(value: Single; text: PChar);
procedure dB2stringRound(value: single; text: pchar);
procedure float2string(value: Single; text: PChar);
procedure long2string(value: Longint; text: PChar);
procedure float2stringAsLong(value: Single; text: PChar);
procedure Hz2string(samples, sampleRate: Single; text: pchar);
procedure ms2string(samples, sampleRate: Single; text: pchar);

function gapSmallValue(value, maxValue: Double): Double;
function invGapSmallValue(value, maxValue: Double): Double;



implementation

uses
    Math, SysUtils;

{ this function converts four char variables to one longint. }
function FourCharToLong(C1, C2, C3, C4: Char): Longint;
begin
  Result := Ord(C4)  + (Ord(C3) shl 8) + (Ord(C2) shl 16) + (Ord(C1) shl 24);
end;

function FMod(d1, d2: Double): Double;
var
   i: Integer;
begin
  try
    i := Trunc(d1 / d2);
  except
    on EInvalidOp do i := High(Longint);
  end;
  Result := d1 - (i * d2);
end;

procedure dB2string(value: Single; text: PChar);
begin
  if (value <= 0) then
    StrCopy(text, '   -oo  ')
  else
    float2string(20 * log10(value), text);
end;

procedure dB2stringRound(value: single; text: pchar);
begin
  if (value <= 0) then
    StrCopy(text, '    -96 ')
  else
    long2string(Round(20 * log10(value)), text);
end;

procedure float2string(value: Single; text: PChar);
begin
  StrCopy(text, PChar(Format('%f', [value])));
end;

procedure long2string(value: Longint; text: PChar);
begin
  if (value >= 100000000) then
  begin
    StrCopy(text, ' Huge!  ');
    Exit;
  end;

  StrCopy(text, PChar(Format('%7d', [Value])));  // sprintf(aString, '%7d', value);
end;

procedure float2stringAsLong(value: Single; text: PChar);
begin
  if (value >= 100000000) then
  begin
    StrCopy(text, ' Huge!  ');
    Exit;
  end;

  StrCopy(text, PChar(Format('%7.0f', [value])));  // sprintf(aString, '%7d', value);
end;

procedure Hz2string(samples, sampleRate: single; text: pchar);
begin
  if (samples = 0) then
    float2string(0, text)
  else
    float2string(sampleRate / samples, text);
end;

procedure ms2string(samples, sampleRate: single; text: pchar);
begin
  float2string(samples * 1000 / sampleRate, text);
end;

function gapSmallValue(value, maxValue: double): double;
begin
  Result := Power(maxValue, value);
end;

function invGapSmallValue(value, maxValue: double): double;
var
   r: Double;
begin
  r := 0;
  if (value <> 0) then
    r := logN(maxValue, value);
  Result :=  r;
end;

end.
