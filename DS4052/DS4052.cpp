//-----功能：-----用于获取示波器波形，并存储为txt文件---//
//-----时间：-----2020_12_02_18_14----------------------//
//---版本号：-----V1------------------------------------//
//-----作者：-----洛书荼--------------------------------//
#include "DS4052.h"

ds4052::ds4052()
{
	matches = buffer;
	count = 0;
}

ds4052::~ds4052()
{
	// 断开连接
	viClose(vi);
	viClose(defaultRM);
}

//--函数：void ds4052::initConnect()---//
//--输入：无---------------------------//
//--输出：无---------------------------//
//--功能：初始化接口，连接示波器-------//
void ds4052::initConnect()
{
	viOpenDefaultRM(&defaultRM);
	//获取 VISA 的 USB 资源
	viFindRsrc(defaultRM, ViString("USB?*"), &list, &nmatches, matches);
	viOpen(defaultRM, matches, VI_NULL, VI_NULL, &vi);
	// 复位示波器设置
	//viPrintf(vi, ViString("*RST\n"));
}

//--函数：void ds4052::setChannel()----//
//--输入：通道号-----------------------//
//--输出：无---------------------------//
//--功能：设置读取通道-----------------//
void ds4052::setChannel(int channel)
{
	sendCommand(command.channel[channel]);
}

//--函数：void ds4052::saveChannelData()-//
//--输入：数据长度-----------------------//
//--输出：无-----------------------------//
//--功能：存当前的示波器波形数据---------//
void ds4052::saveChannelData(int channel, int dataLength)
{
	char *buf = (char *)malloc(dataLength * sizeof(char)); 
	memset(buf, 0 , dataLength * sizeof(char));

	// 发送读取命令
	sendCommand(command.readData);

	// 读取结果
	viScanf(vi, ViString("%t\n"), buf);

	std::string path = "./data/CH" + std::to_string(channel) + "_data" + std::to_string(count) + ".txt";
	count++;
	//打开文件
	FILE *outFile = fopen(path.c_str(), "w");

	for (int i = 0; i < dataLength; i++)
	{
		//写入数据
		fprintf(outFile, "%d ", unsigned char(buf[i]));
	}
	//关闭文件
	fclose(outFile);
	free(buf);
}

//--函数：void ds4052::sendCommand()---//
//--输入：SCPI命令---------------------//
//--输出：无---------------------------//
//--功能：向示波器发送SCPI 命令--------//
void ds4052::sendCommand(std::string command)
{
	char* Temp = const_cast<char*> (command.c_str());
	// 发送命令
	viPrintf(vi, ViString(Temp));
}



