global gLCApp;
global gLCDoc;
global gChans;
global gChansData;
global a;
global t;
global emg;
global amp;
global fgen;
global ex;
global threshold;
threshold = 1;
global ampamp;
ampamp = [50];
% gLCApp = Labchart app과 연결
try
    gLCApp = actxGetRunningServer('ADIChart.Application');
catch err
    error('Please start LabChart before running this script.');
end
if (isempty(gLCApp.ActiveDocument))
    error('Please open a document in LabChart before running this script.');
end


% gLCDoc = 문서와 연결
gLCDoc = gLCApp.ActiveDocument;

gChans = [1];

RegisterLCEvents(gLCDoc);

% Robot과 연결
loadlibrary('DobotDll.dll','DobotDll.h');

% libfunctionsview DobotDll

ch=blanks(128);  
queue_index=0;
ptp.ptpMode=0;
ptp.x=200.0;
ptp.y=0.0;
ptp.z=0.0;
ptp.r=0.0;
time = 0.0;
fwBuffer = '                                                               ';
versionBuffer = '                                                             ';

%create pointer piont to charArrays
str1= libpointer('cstring',ch);
%search the magician device res1:device number res2:device address
[res1,res2]=calllib('DobotDll','SearchDobot',str1,128);
%create pointer piont to device address
str2= libpointer('cstring',res2);
%contect device res3:contect result 0:success 1:error 2:timeout
[res3,res4,fwtype,version,time]=calllib('DobotDll','ConnectDobot',str2, 115200,fwBuffer,versionBuffer,time);

calllib('DobotDll','SetPTPCmd',ptp,true,queue_index);

% Waveform Generator
% fgen = visa('AGILENT',"USB0::0x0957::0x2807::MY59000746::0");
% set (fgen,'timeout', 30);
% fopen(fgen);
% 
% fprintf (fgen, '*IDN?');
% idn = fscanf (fgen);
% fprintf (idn)
% fprintf ('\n\n')
% 
% fprintf (fgen, '*RST');
% fprintf (fgen, '*CLS');
% pause (1);

%Set initial parameters
% fprintf(fgen,'SOURce1:DATA:VOLatile:CLEar');
% fprintf(fgen,'SOURce1:FUNCtion Pulse')
% fprintf(fgen,'SOURce1:FUNCtion:Pulse:WIDTh 1 ms')
% fprintf(fgen,'SOURCE1:VOLT 50 mv')
% fprintf(fgen,'SOURCE1:freq 0.33 hz')
tic
% emg = threshold;
% amp = 50;
% ex = 1;
%calllib('DobotDll','DisconnectDobot'); 
