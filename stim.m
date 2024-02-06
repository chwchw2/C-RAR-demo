function stim(value)
global fgen;
global ex;
global amp;
global emg;
global threshold;
global ampamp;

% if value == -1
%     fprintf(fgen,append('SOURCE1:VOLT 50 mv'));
%     fprintf(fgen,'OUTPUT1 ON');
%     emg = threshold;
%     amp = 50;
% elseif value  == -2
%     fprintf(fgen,'OUTPUT1 OFF');
% else
%     fprintf(fgen,append('SOURCE1:VOLT ',int2str(value),' mv'));
%     ampamp = [ampamp value];
% end