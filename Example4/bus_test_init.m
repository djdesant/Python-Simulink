%% Transfer Function Definition
modelname = 'bus_test';

% Model Run Speed.
Ts=1e-3;

%% Parameters
% num=Simulink.Parameter;
% num.Value=sysd.Numerator{1};
% num.CoderInfo.StorageClass='ExportedGlobal';
% 
% den=Simulink.Parameter;
% den.Value=sysd.Denominator{1};
% den.CoderInfo.StorageClass='ExportedGlobal';

InputSignal=Simulink.Parameter;
InputSignal.Value=0;
InputSignal.CoderInfo.StorageClass='SimulinkGlobal';

%% Signals

OutputSignal=Simulink.Signal;
OutputSignal.CoderInfo.StorageClass='SimulinkGlobal';

SimTime=Simulink.Signal;
SimTime.CoderInfo.StorageClass='SimulinkGlobal';

%% Bus signals

create_buses()
