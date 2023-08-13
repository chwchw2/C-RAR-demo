function doOnNewSamples(newTicks)
%To debug thus function, set a breakpoint in it and call it manually
%from the MATLAB command line after sampling has been stopped.
%Example event handler called when sampling, whenever new samples might be 
%available, typically 20 times a second.
%This example gets any new samples from channel gChan, appends them to
%the gChan1Data vector, then plots the latest 5000 samples.
global gLCDoc;
global gLatestBlock;
global gBlockSecsPerTick;
global gLatestTickInBlock;
global gChans;
global gChansData;
global gT;
%disp('OnNewSamples called')
gLatestTickInBlock = gLatestTickInBlock+newTicks;
% HRESULT GetChannelData([in]ChannelDataFlags flags, [in]long channelNumber, [in]long blockNumber, [in]long startSample, [in]long numSamples, [out,retval]VARIANT *data) const;
% For the sampling case we can pass -1 for the number of samples parameter,
% meaning return all available samples
newSamplesMax = 0; %max new samples added across channels
minChanLength = 1e30; %number of samples in the shortest channel

slot = 1;
for ch = gChans
% HRESULT GetChannelData([in]ChannelDataFlags flags, [in]long channelNumber, [in]long blockNumber, [in]long startSample, [in]long numSamples, [out,retval]VARIANT *data) const;
% For the sampling case we can pass -1 for the number of samples parameter,
% meaning return all available samples
    chanSamples = gLCDoc.GetChannelData (1, ch, gLatestBlock+1, length(gChansData{slot})+1, -1);
    gChansData{slot} = [gChansData{slot}; chanSamples'];
    if minChanLength > length(gChansData{slot})
        minChanLength = length(gChansData{slot});
    end
    if newSamplesMax < length(chanSamples)
        newSamplesMax = length(chanSamples);
    end
    slot = slot+1;
end

if newSamplesMax > 0
    nSamples = length(gT);
    gT = [gT; [nSamples:nSamples+newSamplesMax-1]'*gBlockSecsPerTick];
end

%plot the latest 5000 samples
plotRange = max(1,minChanLength-5000):minChanLength;
slot = 1;

% ========================================
global chA;
global str1;
global str2;
global res1;
global res2;
global res3;
global res4;
global fwtype;
global version;

global queue_index;
global ptp;
global time;
global fwBuffer;
global versionBuffer;
global threshold;


if mean(abs(chanSamples(1:200))) >= threshold
    disp ('bursted');
    calllib('DobotDll','SetQueuedCmdStartExec');
    ptpstruct=libstruct('tagPTPCmd',ptp);
    ptpstructptr=libpointer('tagPTPCmdPtr',ptpstruct);
    queue_index_ptr=libpointer('uint64Ptr',queue_index);
    calllib('DobotDll','SetPTPCmd',ptpstructptr,true,queue_index_ptr);
    calllib('DobotDll','SetQueuedCmdStopExec');
    pause (0.5);
end



% ========================================

% for ch = gChans
%     subplot(length(gChans),1,slot), plot(gT(plotRange),gChansData{slot}(plotRange));
%     channelStr = ['Channel ' int2str(ch)];
%     title(channelStr);
%     slot = slot+1;
% end
