//--����ʾ���������ݲ��洢
//--���ߣ�����ݱ
#include "DS4052.h"

int main()
{
	// ʵ����һ������
	ds4052 theDS4052;

	// ����ʾ����
	theDS4052.initConnect();
	// ��Ϊͨ��һ
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
	
	// �Ͽ�����
	theDS4052.~ds4052();

	std::cout << "Hello World!\n";
}