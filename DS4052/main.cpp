//--测试示波器读数据并存储
//--作者：洛书荼
#include "DS4052.h"

int main()
{
	// 实例化一个对象
	ds4052 theDS4052;

	// 连接示波器
	theDS4052.initConnect();

	int status = 0;
	while (1)
	{
		// 设置通道
		std::cout << "请输入通道号（输入 -1 退出）" << std::endl;
		std::cin >> status;

		
		if (status == -1)
		{
			break;
		}
		else if(status == 1)
		{
			theDS4052.setChannel(1);
			theDS4052.saveChannelData(1, 2048);
		}
		else if (status == 2)
		{
			theDS4052.setChannel(2);
			theDS4052.saveChannelData(2, 2048);
		}
	}
	
	// 断开连接
	theDS4052.~ds4052();

	std::cout << "Hello World!\n";
	system("pause");
}