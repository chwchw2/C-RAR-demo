
%load
%DobotDll===================================================================

if ~libisloaded('DobotDll')
    loadlibrary('DobotDll.dll','DobotDll.h');
end
% libfunctionsview DobotDll

global chA;
global queue_index;
global ptp;
global time;
global fwBuffer;
global versionBuffer;
global threshold;

threshold = 70;
chA=blanks(128);
queue_index=0;
ptp.ptpMode=0;
ptp.x=200.0;
ptp.y=0.0;
ptp.z=0.0;
ptp.r=0.0;
time = 0.0;
fwBuffer = '                                                               ';
versionBuffer = '                                                             ';

global str1;
global str2;
global res1;
global res2;
global res3;
global res4;
global fwtype;
global version;

%create pointer piont to charArrays
str1= libpointer('cstring',chA);
%search the magician device res1:device number res2:device address
[res1,res2]=calllib('DobotDll','SearchDobot',str1,128);
%create pointer piont to device address
str2= libpointer('cstring',res2);
%contect device res3:contect result 0:success 1:error 2:timeout
[res3,res4,fwtype,version,time]=calllib('DobotDll','ConnectDobot',str2, 115200,fwBuffer,versionBuffer,time);
%cmd start exec queue
calllib('DobotDll','SetQueuedCmdStartExec');
%create c type struct
ptpstruct=libstruct('tagPTPCmd',ptp);
%create ptp pointer
ptpstructptr=libpointer('tagPTPCmdPtr',ptpstruct);
queue_index_ptr=libpointer('uint64Ptr',queue_index);
%send ptp cmd
calllib('DobotDll','SetPTPCmd',ptpstructptr,true,queue_index_ptr);
calllib('DobotDll','SetQueuedCmdStopExec');
pause (1.5);


%Instructions:
%1) Open a document in LabChart
%2) Run this script in MATLAB
%3) When LabChart starts sampling, the latest data from channels 1, 3 and 4 are plotted in MATLAB (while sampling).
%4) If you stop sampling and make a selection in LabChart, then MATLAB will plot the selection.

global gLCApp;
global gLCDoc;
global gChans; %Array of channel numbers specifying channels to retrieve sampling data from
global gChansData;

%First a reference to a LabChart instance (gLCApp) is obtained, either by attaching to 
%an already running LabChart, or starting LabChart.

try
    gLCApp = actxGetRunningServer('ADIChart.Application');
catch err
    error('Please start LabChart before running this script.');
end
if (isempty(gLCApp.ActiveDocument))
    error('Please open a document in LabChart before running this script.');
end


gLCDoc = gLCApp.ActiveDocument;

gChans = 1; % collect sampling data from channels 1, 3 and 4. [1 3 4]

RegisterLCEvents(gLCDoc); % hook up the OnSelectionChange event and the sampling events such as OnNewSamples and OnBlockStart.


%cmd stop exec queue
%cmd disconnect device
% calllib('DobotDll','SetQueuedCmdStopExec');
% calllib('DobotDll','DisconnectDobot'); 
