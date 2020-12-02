//-----功能：-----用于获取示波器波形，并存储为txt文件---//
//-----时间：-----2020_12_02_18_14----------------------//
//---版本号：-----V1------------------------------------//
//-----作者：-----洛书荼--------------------------------//
#pragma once
#ifndef _DS4052_H
#define _DS4052_H

#include <visa.h>
#include <iostream>
#include <stdio.h>
#include <string>

struct someCommand
{
	std::string channel[3]	= { " ", ":wav:source chan1\n", ":wav:source chan2\n" }; // 通道
	std::string readData	= ":wav:data?\n";
	std::string scale[3] = { " ", ":CHANnel1:SCALe?\n" , ":CHANnel2:SCALe?\n" };
};

class ds4052
{
public:
	ds4052();
	~ds4052();
	
	// 设置通道
	void setChannel(int channel);
	// 存储数据
	void saveChannelData(int dataLength);
	// 初始化接口，连接示波器
	void initConnect();

private:
	// 向示波器发送SCPI 命令
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
