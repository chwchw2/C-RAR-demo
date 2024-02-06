function robot(value)
global t;
global emg;
global amp;
global ex;


queue_index=0;
ptp.ptpMode=0;
ptp.x=200.0;
ptp.y=0.0;
ptp.z=0.0;
ptp.r=0.0;
time = 0.0;
t = toc();
if(t>1)
    calllib('DobotDll','SetPTPCmd',ptp,true,queue_index);
    
%     amp = amp+5*(value-emg)/emg;
%     if amp > 300
%         amp = 300;
%     end
%     if amp <0
%         amp = 0;
%     end
%     
%     emg = value;
end
tic
