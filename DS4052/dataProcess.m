%% �������txtʾ��������
% ����ݱ
% 20201202

%% ����
clear;
clc;

%% ��ȡ����
% ��������
testData = importdata("data5.txt");
% �������ݳ���
theLen = 0;
for i = 3:11
    theLen = theLen * 10 + testData(i) - 48;
end

% ��ȡ��������
theWave = testData(12:theLen-1);

% ʾ������λ
t_div = 100e-9;         % s/div
a_div = 2;              % v/div
delta_t = t_div / 100;  % ʱ����
delta_a = a_div / 32;   % ���ȼ��

figure;
plot((0:length(theWave)-1) * delta_t, (theWave) * delta_a); 
title("����ͼ");
xlabel("ʱ�䣨��λ S ��");
ylabel("��ֵ����λ V ��");