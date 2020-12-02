//-----���ܣ�-----���ڻ�ȡʾ�������Σ����洢Ϊtxt�ļ�---//
//-----ʱ�䣺-----2020_12_02_18_14----------------------//
//---�汾�ţ�-----V1------------------------------------//
//-----���ߣ�-----����ݱ--------------------------------//
#pragma once
#ifndef _DS4052_H
#define _DS4052_H

#include <visa.h>
#include <iostream>
#include <stdio.h>
#include <string>

struct someCommand
{
	std::string channel[3]	= { " ", ":wav:source chan1\n", ":wav:source chan2\n" }; // ͨ��
	std::string readData	= ":wav:data?\n";
	std::string scale[3] = { " ", ":CHANnel1:SCALe?\n" , ":CHANnel2:SCALe?\n" };
};

class ds4052
{
public:
	ds4052();
	~ds4052();
	
	// ����ͨ��
	void setChannel(int channel);
	// �洢����
	void saveChannelData(int dataLength);
	// ��ʼ���ӿڣ�����ʾ����
	void initConnect();

private:
	// ��ʾ��������SCPI ����
	void sendCommand(std::string command);

private:
	ViSession	defaultRM, vi;
	ViChar		buffer[VI_FIND_BUFLEN];
	ViRsrc		matches;
	ViUInt32	nmatches;
	ViFindList	list;

	someCommand command;
	long		count;
};


#endif // !_DS4052_H
