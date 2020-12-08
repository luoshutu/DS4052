%% 处理保存的txt示波器数据
% 洛书荼
% 20201202

%% 清理
clear;
clc;

%% 读取数据
% 加载数据
testData = importdata("data5.txt");
% 波形数据长度
theLen = 0;
for i = 3:11
    theLen = theLen * 10 + testData(i) - 48;
end

% 获取波形数据
theWave = testData(12:theLen-1);

% 示波器档位
t_div = 100e-9;         % s/div
a_div = 2;              % v/div
delta_t = t_div / 100;  % 时间间距
delta_a = a_div / 32;   % 幅度间距

figure;
plot((0:length(theWave)-1) * delta_t, (theWave) * delta_a); 
title("波形图");
xlabel("时间（单位 S ）");
ylabel("幅值（单位 V ）");