clear all

%load DobotDll
if ~libisloaded('DobotDll')
    loadlibrary('DobotDll.dll','DobotDll.h');
end
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
pause (5);

calllib('DobotDll','SetQueuedCmdStartExec');
ptpstruct=libstruct('tagPTPCmd',ptp);
ptpstructptr=libpointer('tagPTPCmdPtr',ptpstruct);
queue_index_ptr=libpointer('uint64Ptr',queue_index);
calllib('DobotDll','SetPTPCmd',ptpstructptr,true,queue_index_ptr);
calllib('DobotDll','SetQueuedCmdStopExec');
pause (5);

% for i =1:2
%     ptp.ptpMode=0;
%     ptp.x=200.0+10*i;
%     ptp.y=10*i;
%     ptp.z=0.0;
%     ptp.r=0.0;
% 
%     calllib('DobotDll','SetQueuedCmdStartExec')
%     ptpstruct=libstruct('tagPTPCmd',ptp);
%     ptpstructptr=libpointer('tagPTPCmdPtr',ptpstruct);
%     queue_index_ptr=libpointer('uint64Ptr',queue_index);
%     calllib('DobotDll','SetPTPCmd',ptpstructptr,true,queue_index_ptr);
%     calllib('DobotDll','SetQueuedCmdStopExec');
%     pause (5);
%     if i == 2
%             calllib('DobotDll','SetQueuedCmdStartExec')
%             homestruct=libstruct('tagPTPCmd',home);
%             homestructptr=libpointer('tagPTPCmdPtr',homestruct);
%             queue_index_ptr=libpointer('uint64Ptr',queue_index);
%     end
% end


disp('end')

%cmd stop exec queue
%cmd disconnect device
calllib('DobotDll','SetQueuedCmdStopExec');
calllib('DobotDll','DisconnectDobot'); 

