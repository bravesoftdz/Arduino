object EnhancedGateDataModule: TEnhancedGateDataModule
  OldCreateOrder = False
  OnCreate = VSTModuleCreate
  OnDestroy = VSTModuleDestroy
  Flags = [effFlagsHasEditor, effFlagsCanReplacing]
  Version = '1.0'
  EffectName = 'Simple Gate'
  ProductName = 'Enhanced Audio Gate'
  VendorName = 'ASIO-VST Delphi Project'
  PlugCategory = vpcEffect
  CanDos = [vcdReceiveVstEvents, vcdReceiveVstMidiEvent, vcdPlugAsChannelInsert, vcdPlugAsSend, vcd2in2out, vcdBypass]
  SampleRate = 44100.000000000000000000
  CurrentProgram = -1
  UniqueID = 'EAGa'
  ShellPlugins = <>
  Programs = <>
  ParameterProperties = <
    item
      Max = 1.000000000000000000
      Curve = ctLinear
      DisplayName = 'Power'
      CurveFactor = 1.000000000000000000
      SmoothingFactor = 1.000000000000000000
      StepFloat = 1.000000000000000000
      SmallStepFloat = 1.000000000000000000
      LargeStepFloat = 1.000000000000000000
      MaxInteger = 1
      LargeStepInteger = 1
      ShortLabel = 'Power'
      VSTModule = Owner
      OnParameterChange = EAGPowerChange
      OnCustomParameterDisplay = EAGOnOffDisplay
    end
    item
      Min = -80.000000000000000000
      Max = 1.000000000000000000
      Curve = ctLinear
      DisplayName = 'Threshold'
      Units = 'dB'
      CurveFactor = 1.000000000000000000
      SmoothingFactor = 1.000000000000000000
      StepFloat = 1.000000000000000000
      SmallStepFloat = 1.000000000000000000
      LargeStepFloat = 1.000000000000000000
      MinInteger = -80
      MaxInteger = 0
      LargeStepInteger = 1
      ShortLabel = 'Thrshld'
      VSTModule = Owner
      OnParameterChange = EAGThresholdChange
    end
    item
      Min = 0.009999999776482582
      Max = 1000.000000000000000000
      Curve = ctLogarithmic
      DisplayName = 'Attack'
      Units = 'ms'
      CurveFactor = 100000.000000000000000000
      SmoothingFactor = 1.000000000000000000
      StepFloat = 1.000000000000000000
      SmallStepFloat = 0.100000001490116100
      LargeStepFloat = 10.000000000000000000
      MinInteger = -200
      MaxInteger = 300
      ShortLabel = 'Attack'
      VSTModule = Owner
      OnParameterChange = EAGAttackChange
    end
    item
      Min = 0.009999999776482582
      Max = 2.500000000000000000
      Curve = ctLogarithmic
      DisplayName = 'Hold'
      Units = 'ms'
      CurveFactor = 250.000000000000000000
      SmoothingFactor = 1.000000000000000000
      MinInteger = -200
      MaxInteger = 24
      StepInteger = 0
      LargeStepInteger = 0
      ShortLabel = 'Hold'
      VSTModule = Owner
      OnParameterChange = EAGHoldChange
    end
    item
      Min = 5.000000000000000000
      Max = 5000.000000000000000000
      Curve = ctLogarithmic
      DisplayName = 'Decay'
      Units = 'ms'
      CurveFactor = 1000.000000000000000000
      SmoothingFactor = 1.000000000000000000
      StepFloat = 10.000000000000000000
      SmallStepFloat = 1.000000000000000000
      LargeStepFloat = 100.000000000000000000
      MinInteger = 70
      MaxInteger = 370
      ShortLabel = 'Decay'
      VSTModule = Owner
      OnParameterChange = EAGDecayChange
    end
    item
      Max = 1.000000000000000000
      Curve = ctLinear
      DisplayName = 'Duck'
      CurveFactor = 1.000000000000000000
      SmoothingFactor = 1.000000000000000000
      StepFloat = 1.000000000000000000
      SmallStepFloat = 1.000000000000000000
      LargeStepFloat = 1.000000000000000000
      MaxInteger = 1
      LargeStepInteger = 1
      ShortLabel = 'Duck'
      VSTModule = Owner
      OnParameterChange = EAGDuckChange
      OnCustomParameterDisplay = EAGOnOffDisplay
    end
    item
      Max = 1.000000000000000000
      Curve = ctLinear
      DisplayName = 'Stereo Link'
      CurveFactor = 1.000000000000000000
      SmoothingFactor = 1.000000000000000000
      StepFloat = 1.000000000000000000
      SmallStepFloat = 1.000000000000000000
      LargeStepFloat = 1.000000000000000000
      MaxInteger = 1
      LargeStepInteger = 1
      ShortLabel = 'Link'
      VSTModule = Owner
      OnParameterChange = EAGStereoLinkChange
      OnCustomParameterDisplay = EAGOnOffDisplay
    end
    item
      Max = 1.000000000000000000
      Curve = ctLinear
      DisplayName = 'Side Chain Source'
      CurveFactor = 1.000000000000000000
      SmoothingFactor = 1.000000000000000000
      StepFloat = 1.000000000000000000
      SmallStepFloat = 1.000000000000000000
      LargeStepFloat = 1.000000000000000000
      MaxInteger = 1
      LargeStepInteger = 1
      ShortLabel = 'SCSrc'
      VSTModule = Owner
      OnParameterChange = EAGSideChainSourceChange
      OnCustomParameterDisplay = EAGSideChainSourceDisplay
    end
    item
      Min = 20.000000000000000000
      Max = 4000.000000000000000000
      Curve = ctLogarithmic
      DisplayName = 'Lo Cut'
      Units = 'Hz'
      CurveFactor = 200.000000000000000000
      SmoothingFactor = 1.000000000000000000
      StepFloat = 20.000000000000000000
      SmallStepFloat = 20.000000000000000000
      LargeStepFloat = 20.000000000000000000
      MinInteger = 20
      MaxInteger = 4000
      StepInteger = 20
      LargeStepInteger = 20
      ShortLabel = 'LoCut'
      VSTModule = Owner
      OnParameterChange = EAGLoCutChange
    end
    item
      Min = 0.200000002980232200
      Max = 20.000000000000000000
      Curve = ctLogarithmic
      DisplayName = 'Hi Cut'
      Units = 'kHz'
      CurveFactor = 100.000000000000000000
      SmoothingFactor = 1.000000000000000000
      StepFloat = 20.000000000000000000
      SmallStepFloat = 20.000000000000000000
      LargeStepFloat = 20.000000000000000000
      MinInteger = 200
      MaxInteger = 20000
      StepInteger = 20
      LargeStepInteger = 20
      ShortLabel = 'HiCut'
      VSTModule = Owner
      OnParameterChange = EAGHiCutChange
    end
    item
      Min = 1.000000000000000000
      Max = 10.000000000000000000
      Curve = ctLinear
      DisplayName = 'Ratio'
      CurveFactor = 1.000000000000000000
      SmoothingFactor = 1.000000000000000000
      StepFloat = 0.500000000000000000
      SmallStepFloat = 0.100000001490116100
      LargeStepFloat = 1.000000000000000000
      MinInteger = 1
      MaxInteger = 10
      LargeStepInteger = 1
      ShortLabel = 'Ratio'
      VSTModule = Owner
      OnParameterChange = EAGRatioChange
    end
    item
      Min = 1.000000000000000000
      Max = 6.000000000000000000
      Curve = ctLinear
      DisplayName = 'Knee'
      Units = 'dB'
      CurveFactor = 1.000000000000000000
      SmoothingFactor = 1.000000000000000000
      StepFloat = 0.200000002980232200
      SmallStepFloat = 0.100000001490116100
      LargeStepFloat = 1.000000000000000000
      MinInteger = 1
      MaxInteger = 6
      LargeStepInteger = 1
      ShortLabel = 'Knee'
      VSTModule = Owner
      OnParameterChange = EAGKneeChange
    end
    item
      Min = -80.000000000000000000
      Max = 1.000000000000000000
      Curve = ctLinear
      DisplayName = 'Range'
      Units = 'dB'
      CurveFactor = 1.000000000000000000
      SmoothingFactor = 1.000000000000000000
      StepFloat = 1.000000000000000000
      SmallStepFloat = 0.100000001490116100
      LargeStepFloat = 10.000000000000000000
      MinInteger = -80
      MaxInteger = 0
      ShortLabel = 'Range'
      VSTModule = Owner
      OnParameterChange = EAGRangeChange
    end>
  OnEditOpen = VSTModuleEditOpen
  OnSampleRateChange = VSTModuleSampleRateChange
  OnProcess = VSTModuleProcessBypass
  OnProcessReplacing = VSTModuleProcessBypass
  Left = 552
  Top = 84
  Height = 150
  Width = 215
end
