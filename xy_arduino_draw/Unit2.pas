unit Unit2;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, IdBaseComponent, IdComponent, IdCustomTCPServer, IdCustomHTTPServer, IdHTTPServer,idContext,
  ExtCtrls, CPort,inifiles, MidiDeviceComboBox, MidiType, MidiOut;

type
  TForm2 = class(TForm)
    IdHTTPServer1: TIdHTTPServer;
    Memo1: TMemo;
    Button1: TButton;
    ComPort: TComPort;
    ConnButton: TButton;
    PortButton: TButton;
    Panel1: TPanel;
    Image1: TImage;
    Button2: TButton;
    Timer1: TTimer;
    CheckBox1: TCheckBox;
    MidiOutput1: TMidiOutput;
    ComboBox1: TComboBox;
    Label1: TLabel;
    procedure IdHTTPServer1CommandGet(AContext: TIdContext; ARequestInfo: TIdHTTPRequestInfo;
      AResponseInfo: TIdHTTPResponseInfo);
    procedure Button1Click(Sender: TObject);
    procedure ConnButtonClick(Sender: TObject);
    procedure PortButtonClick(Sender: TObject);
    procedure ComPortAfterClose(Sender: TObject);
    procedure ComPortAfterOpen(Sender: TObject);
    procedure ComPortRxChar(Sender: TObject; Count: Integer);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormShow(Sender: TObject);
    procedure Image1MouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure Image1MouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure Image1MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure Button2Click(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure CheckBox1Click(Sender: TObject);
    procedure ComboBox1Change(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
    FInitFlag:Boolean;
    FIni:TMemIniFile;
    CanvasDraw : Boolean;
    LastX,LastY:integer;
    DeltaX,DeltaY:integer;
    CommandStr : String;
    xBuffer : integer;
    xBufferPos : integer;
    xArray : Array[1..10000] of string[25];
    isBusy : boolean;
    ArduinoStr : String;
    FirstClick : Boolean;
    xMover : integer;
    last_i2,last_i3,last_i4 : integer;
    SensorReads : Array[1..3,1..1000] of integer;
    maxSensorRead : integer;
  end;

var
  Form2: TForm2;
  j2,j3,j4:integer;

implementation

{$R *.dfm}

procedure TForm2.Button1Click(Sender: TObject);
begin
 if Button1.Caption = 'online' then
 begin
  IdHTTPServer1.Active := true;
  Button1.Caption := 'offline';
 end else
 if Button1.Caption = 'offline' then
 begin
  IdHTTPServer1.Active := true;
  Button1.Caption := 'online';
 end;
end;

procedure TForm2.Button2Click(Sender: TObject);
begin
 Image1.Canvas.Rectangle(0,0,Image1.Width,Image1.Height);
end;

procedure TForm2.CheckBox1Click(Sender: TObject);
begin
 if CheckBox1.Checked then
 begin
  MidiOutput1.ProductName := ComboBox1.Text;
  MidiOutput1.Open;
  xMover := 0;
 end else MidiOutput1.Close;
end;

procedure TForm2.ComboBox1Change(Sender: TObject);
begin
 if CheckBox1.Checked then MidiOutput1.Close;
 MidiOutput1.ProductName := ComboBox1.Text;
 if CheckBox1.Checked then MidiOutput1.Open;
end;

procedure TForm2.ComPortAfterClose(Sender: TObject);
begin
  ConnButton.Caption := 'Connect';
end;

procedure TForm2.ComPortAfterOpen(Sender: TObject);
begin
  ConnButton.Caption := 'Disconnect';
end;

procedure TForm2.ComPortRxChar(Sender: TObject; Count: Integer);
var
 Str:String;
 s,s2,s3,s4:String;
 k2,k3,k4:string;
 i,j,k,l,m:integer;
 i1,i2,i3,i4:integer;
begin
 ComPort.ReadStr(Str, Count);

 if pos(chr(10),Str)<>0 then
 begin
  ArduinoStr := ArduinoStr+Str;

  if memo1.lines.Count>800 then Memo1.Lines.Clear;

memo1.text := memo1.text + 'Arduino:'+ArduinoStr;

  //run as midi device
  if CheckBox1.Checked then
  begin
   s := copy(ArduinoStr,1,pos(chr(13),ArduinoStr)-1);
   delete(s,1,pos(':',s));

   s2 := copy(s,1,pos(':',s)-1);   delete(s,1,pos(':',s));
   delete(s2,pos('.',s2),1);
   s3 := copy(s,1,pos(':',s)-1);   delete(s,1,pos(':',s));
   delete(s3,pos('.',s3),1);
   s4 := copy(s,1,pos(':',s)-1);   delete(s,1,pos(':',s));
   delete(s4,pos('.',s4),1);

   val(s2,i2,m);
   if i2>120 then i2 :=0;
   if i2<6 then i2 := 0;


   val(s3,i3,m);
   if i3>120 then i3 :=0;
   if i3<6 then i3 := 0;

   val(s4,i4,m);
   if i4>120 then i4 :=0;
   if i4<6 then i4 := 0;
(*
   k2 := '';
   if ((i2-last_i2)>20) or ((i2-last_i2)<-20) then
   begin
    inc(j2);
    if j2<8 then begin i2 := last_i2; k2 := '*'; end else begin k2 := '+'; j2 := 0; end;
   end else j2 := 0;

   k3 := '';
   if ((i3-last_i3)>20) or ((i3-last_i3)<-20) then
   begin
    inc(j3);
    if j3<8 then begin i3 := last_i3; k3 := '*'; end else begin k3 := '+'; j3 := 0; end;
   end else j3 := 0;

   k4 := '';
   if ((i4-last_i4)>20) or ((i4-last_i4)<-20) then
   begin
    inc(j4);
    if j4<8 then begin i4 := last_i4; k4 := '*'; end else begin k4 := '+'; j4 := 0; end;
   end else j4 := 0;
*)
//memo1.Lines.Add(copy(ArduinoStr,1,pos(chr(13),ArduinoStr)-1)+' --- '+inttostr(i2)+k2+', '+IntToStr(i3)+k3+', '+IntToStr(i4)+k4);


   inc(xMover);
   if (xMover>Image1.Width) then
   begin
     xMover := 0;
     Image1.Canvas.Rectangle(0,0,Image1.Width,Image1.Height);
   end;

//  MidiOutput1.NoteOff(2,Last_i2 ,127);
//  MidiOutput1.NoteOn(2,i2 ,127);

   image1.Canvas.pen.Width := 4;
   image1.Canvas.pen.Color := RGB(255,0,0);
   Image1.Canvas.MoveTo(xMover-1,last_i2+50);
   Image1.Canvas.LineTo(xMover,i2+50);
   last_i2 := i2;

   MidiOutput1.NoteOff(0,Last_i3 ,127);
   MidiOutput1.NoteOn(0,i3 ,127);

   image1.Canvas.pen.Color := RGB(0,255,0);
   Image1.Canvas.MoveTo(xMover-1,last_i3+200);
   Image1.Canvas.LineTo(xMover,i3+200);
   last_i3 := i3;

   if (last_i4<>i4) then
   begin
//  MidiOutput1.NoteOff(0,Last_i4 div 3,127);
//  MidiOutput1.NoteOn(0,i4 div 3,127);
   end;

//  MidiOutput1.NoteOff(1,Last_i4 ,127);
//  MidiOutput1.NoteOn(1,i4 ,127);

   image1.Canvas.pen.Color := RGB(0,0,255);
   Image1.Canvas.MoveTo(xMover-1,last_i4+350);
   Image1.Canvas.LineTo(xMover,i4+350);
   last_i4 := i4;




   Label1.Caption := 'Sensors: A:'+s2+' B:'+s3+' C:'+s4;
  end;

  //run as xy plotter
  if not CheckBox1.Checked then
  begin
   if pos('Z',ArduinoStr)<>0 then isBusy := False;
  end;

  Delete(ArduinoStr,1,pos(chr(10),ArduinoStr));
 end else
 begin
  ArduinoStr := ArduinoStr+Str;
 end;


end;

procedure TForm2.ConnButtonClick(Sender: TObject);
var
 i :integer;
begin
 j2 := 0;
 j3 := 0;
 j4 := 0;
   xBuffer :=0;
   xBufferPos := 0;
   for i := 1 to 10000 do
    xArray[i] := '';
  isBusy := false;

  if ComPort.Connected then
    ComPort.Close
  else
    ComPort.Open;
end;

procedure TForm2.FormClose(Sender: TObject; var Action: TCloseAction);
begin
   if Assigned(FIni) then
   begin
     FIni.WriteString('ComPort', 'ComPort', ComPort.Port );
     FIni.WriteString('ComPort','BaudRate', BaudRateToStr( ComPort.BaudRate ) );
     FIni.WriteString('ComPort','FlowControl', FlowControlToStr(ComPort.FlowControl.FlowControl ));
     FIni.UpdateFile;
     FIni.Free;
   end;
end;

procedure TForm2.FormCreate(Sender: TObject);
var
 i:integer;
 j:integer;
begin
 FirstClick := TRUE;
   xBuffer :=0;
   xBufferPos := 0;
   for i := 1 to 10000 do
    xArray[i] := '';
   isBusy := false;

   ComboBox1.Clear;
   for i := 0 To MidiOutput1.NumDevs - 1 do
   begin
    MidiOutput1.DeviceID := i;
    ComboBox1.Items.Add(MidiOutput1.ProductName);
   end;
   ComboBox1.ItemIndex := 0;

end;

procedure TForm2.FormShow(Sender: TObject);
begin
 if not FInitFlag then begin
   FInitFlag := true;
   FIni := TMemIniFile.Create( ExtractFilePath(Application.ExeName)+'terminal.ini');
   ComPort.Port := FIni.ReadString('ComPort', 'ComPort',ComPort.Port);
   ComPort.BaudRate := StrToBaudRate( FIni.ReadString('ComPort','BaudRate', '19200'));
   ComPort.FlowControl.FlowControl := StrToFlowControl( FIni.ReadString('ComPort','FlowControl', 'Hardware'));
//   ConnButton.Click;
 end;
end;

procedure TForm2.IdHTTPServer1CommandGet(AContext: TIdContext; ARequestInfo: TIdHTTPRequestInfo;
  AResponseInfo: TIdHTTPResponseInfo);
var
  I: Integer;
  RequestedDocument, FileName, CheckFileName: string;
begin
  // requested document
  RequestedDocument := ARequestInfo.Document;
  // log request
  memo1.lines.add('Client: ' + ARequestInfo.RemoteIP + ' request for: ' + RequestedDocument);

  // 001
  if Copy(RequestedDocument, 1, 1) <> '/' then
    // invalid request
    raise Exception.Create('invalid request: ' + RequestedDocument);

  // 002
  // convert all '/' to '\'
  FileName := RequestedDocument;
  I := Pos('/', FileName);
  while I > 0 do
  begin
    FileName[I] := '\';
    I := Pos('/', FileName);
  end;

  // locate requested file
  FileName := ExtractFilePath(Application.ExeName) + FileName;

  try
    CheckFileName := FileName;
    if FileExists(CheckFileName) then
    begin
      // return file as-is
      // log
      Memo1.Lines.Add('Returning Document: ' + CheckFileName);
      // open file stream
      AResponseInfo.ContentStream := TFileStream.Create(CheckFileName, fmOpenRead or fmShareCompat);
    end;
  finally
    if Assigned(AResponseInfo.ContentStream) then
    begin
      // response stream does exist
      // set length
      AResponseInfo.ContentLength := AResponseInfo.ContentStream.Size;
      // write header
      AResponseInfo.WriteHeader;
      // return content
      AResponseInfo.WriteContent;
      // free stream
      AResponseInfo.ContentStream.Free;
      AResponseInfo.ContentStream := nil;
    end else
    if AResponseInfo.ContentText <> '' then
    begin
      // set length
      AResponseInfo.ContentLength := Length(AResponseInfo.ContentText);
      // write header
      AResponseInfo.WriteHeader;
      // return content
    end else
    begin
     if not AResponseInfo.HeaderHasBeenWritten then
     begin
        // set error code
        AResponseInfo.ResponseNo := 404;
        AResponseInfo.ResponseText := 'Document not found';
        // write header
        AResponseInfo.WriteHeader;
     end;
     // return content
     AResponseInfo.ContentText := 'The document requested is not availabe.';
     AResponseInfo.WriteContent;
    end;
  end;
end;

procedure TForm2.Image1MouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
 if not CanvasDraw then
 begin
  Memo1.Lines.Add(inttostr(x)+';'+IntToStr(y));
  image1.Canvas.MoveTo(x,y);

  if not FirstClick then
  begin
   CommandStr := '';
   DeltaX := x-LastX;
   DeltaY := y-LastY;
   if (DeltaX<0) then CommandStr := CommandStr + chr(177)+chr(71)+chr(70+(DeltaX*(-1))) ;// '1;'+IntToStr(DeltaX*(-1))+';';
   if (DeltaX>0) then CommandStr := CommandStr + chr(177)+chr(72)+chr(70+(DeltaX*(1))) ;// '2;'+IntToStr(DeltaX)+';';

   if (DeltaY<0) then CommandStr := CommandStr + chr(177)+chr(73)+chr(70+(DeltaY*(-1)));// '3;'+IntToStr(DeltaY*(-1))+';';
   if (DeltaY>0) then CommandStr := CommandStr + chr(177)+chr(74)+chr(70+(DeltaY*(1)));// '4;'+IntToStr(DeltaY)+';';

   inc(xBuffer);
   if (xBuffer>10000) then xBuffer := 1;

   xArray[xBuffer] := CommandStr;
  end;
  FirstClick := False;

  LastX := x;
  LastY := y;
  inc(xBuffer);
  if (xBuffer>10000) then xBuffer := 1;
  xArray[xBuffer] := chr(177)+chr(76)+chr(70+100);

 end;

 CanvasDraw := True;
end;

procedure TForm2.Image1MouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
begin
 if CheckBox1.Checked then
 begin
  MidiOutput1.NoteOff(0,LastX div 10,127);
  MidiOutput1.NoteOn(0,x div 10,127);
  LastX := x;
 end else
 begin
  if canvasDraw then
  begin

   CommandStr:='';
   DeltaX := x-LastX;
   DeltaY := y-LastY;
   if (DeltaX<0) then CommandStr := CommandStr + chr(177)+chr(71)+chr(70+(DeltaX*(-1))) ;// '1;'+IntToStr(DeltaX*(-1))+';';
   if (DeltaX>0) then CommandStr := CommandStr + chr(177)+chr(72)+chr(70+(DeltaX*(1))) ;// '2;'+IntToStr(DeltaX)+';';

   if (DeltaY<0) then CommandStr := CommandStr + chr(177)+chr(73)+chr(70+(DeltaY*(-1)));// '3;'+IntToStr(DeltaY*(-1))+';';
   if (DeltaY>0) then CommandStr := CommandStr + chr(177)+chr(74)+chr(70+(DeltaY*(1)));// '4;'+IntToStr(DeltaY)+';';

   if (ComPort.Connected) then
   begin
    inc(xBuffer);
    if (xBuffer>10000) then xBuffer := 1;

    xArray[xBuffer] := CommandStr;
//   ComPort.WriteStr(CommandStr);
   end;

   Memo1.Lines.Add('delta:'+inttostr(DeltaX)+';'+IntToStr(DeltaY));
   Image1.Canvas.LineTo(x,y);

   LastX := x;
   LastY := y;

  end;
 end;
end;

procedure TForm2.Image1MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
 CanvasDraw := False;
 inc(xBuffer);
 if (xBuffer>10000) then xBuffer := 1;
 xArray[xBuffer] := chr(177)+chr(75)+chr(70+100);
end;

procedure TForm2.PortButtonClick(Sender: TObject);
begin
  ComPort.ShowSetupDialog;
end;

procedure TForm2.Timer1Timer(Sender: TObject);
var
 i,j : integer;
 s : String;
begin
 if not isBusy then
 begin
  caption := IntToStr(random(1000));
  begin
   repeat
    inc(xBufferPos);
   until (xArray[xBufferPos]<>'') or (xBufferPos>10000);
   if (xBufferPos>10000) then xBufferPos := 1;

   if xArray[xBufferPos]<>'' then
   begin
    isBusy := TRUE;
    s := '';
    i := 0;
    repeat
     inc(i);
     if xArray[i]<>'' then
     begin
      s := s + xArray[i];
      xArray[i] := '';
     end;
    until (i>=10000) or (Length(s)>=55);
    xBufferPos := xBufferPos+i;
   if (xBufferPos>10000) then xBufferPos := 1;

    memo1.lines.Add('buffer: '+inttostr(length(s))+'        ('+inttostr(xBufferPos)+')');
    ComPort.WriteStr(s);
   end;
  end;
 end;

end;

end.
