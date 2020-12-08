//--����ʾ���������ݲ��洢
//--���ߣ�����ݱ
#include "DS4052.h"

int main()
{
	// ʵ����һ������
	ds4052 theDS4052;

	// ����ʾ����
	theDS4052.initConnect();

	int status = 0;
	while (1)
	{
		// ����ͨ��
		std::cout << "������ͨ���ţ����� -1 �˳���" << std::endl;
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
	
	// �Ͽ�����
	theDS4052.~ds4052();

	std::cout << "Hello World!\n";
	system("pause");
}