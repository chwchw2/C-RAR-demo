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
global t;
global emg;
global amp;
global ex;
global i;
global threshold;

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


if length(chanSamples)>=5000 %100kHz sampling rate
    disp (max(abs(chanSamples(1:5000))))
    if max(abs(chanSamples(1:5000)))>threshold
         robot(1);
%     else
%         ex = ex+1;
     end
end
% if ex>150
%     amp = amp +10;
%     stim(amp)
%     ex = 1;
% end


if newSamplesMax > 0
    nSamples = length(gT);
    gT = [gT; [nSamples:nSamples+newSamplesMax-1]'*gBlockSecsPerTick];
end

%plot the latest 5000 samples
% plotRange = max(1,minChanLength-5000):minChanLength;
% slot = 1;

