//--测试示波器读数据并存储
//--作者：洛书荼
#include "DS4052.h"

int main()
{
	// 实例化一个对象
	ds4052 theDS4052;

	// 连接示波器
	theDS4052.initConnect();
	// 设为通道一
	theDS4052.setChannel(1);
	
	char status = 0;
	while (std::cin >> status)
	{
		if (status == 100)
		{
			break;
		}
		else
		{
			theDS4052.saveChannelData(2048);
		}
	}
	
	// 断开连接
	theDS4052.~ds4052();

	std::cout << "Hello World!\n";
}