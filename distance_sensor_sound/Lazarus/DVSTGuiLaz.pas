{ Diese Datei wurde automatisch von Lazarus erzeugt. Sie darf nicht bearbeitet werden!
Dieser Quelltext dient nur dem ‹bersetzen und Installieren des Packages.
 }

unit DVSTGuiLaz; 

interface

uses
  DGuiMidiKeys, DGuiStaticWaveform, DGuiADSRGraph, LazarusPackageIntf; 

implementation

procedure Register; 
begin
  RegisterUnit('DGuiMidiKeys', @DGuiMidiKeys.Register); 
  RegisterUnit('DGuiStaticWaveform', @DGuiStaticWaveform.Register); 
  RegisterUnit('DGuiADSRGraph', @DGuiADSRGraph.Register); 
end; 

initialization
  RegisterPackage('DVSTGuiLaz', @Register); 
end.
