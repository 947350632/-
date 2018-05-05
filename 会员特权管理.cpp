#include "stdafx.h"
#include<stdlib.h>;
#include<math.h>
#include<Windows.h>
#include"��Ա��Ȩ����.h"

int level(double integral)
{
	//������Ҫ�ķ���ֵ
	int ret;

	//��������num�Ĵ�Сȷ������ֵ�Ĵ�С
	if (integral > 100000)
	{
		ret = 10;
	}
	else if (integral > 50000)
	{
		ret = 9;
	}
	else if (integral > 20000)
	{
		ret = 8;
	}
	else if (integral > 10000)
	{
		ret = 7;
	}
	else if (integral > 5000)
	{
		ret = 6;
	}
	else if (integral > 2000)
	{
		ret = 5;
	}
	else if (integral > 1000)
	{
		ret = 4;
	}
	else if (integral > 300)
	{
		ret = 3;
	}
	else if (integral > 100)
	{
		ret = 2;
	}
	else if (integral >= 0)
	{
		ret = 1;
	}
	//�������һ��<0�������򷵻�0
	//���������Ӧ����ʾ
	else
	{
		printf("���Ļ�Ա�����Ѳ���0��\n");
		ret = 0;
	}

	//���ػ���integral��Ӧ�ĵȼ�
	return ret;
 }

double integral_accumulative(double original_integral,double this_integral)
{
	//�����ʱ�Ļ�Ա�ȼ�
	int nowlevel;
	//�������Ա�ȼ�
	nowlevel = level(original_integral);

	//�������ջ���
	double finally_integral=0.0;
	//������ֵȼ�����
	double rate = 0.0;

	//���ݻ�Ա�ȼ����㱶��
	switch (nowlevel)
	{
	//1-3���ı���Ϊ1.0
	case 1:
	case 2:
	case 3:
		rate = 1.0;
		break;
	//4-5���ı���Ϊ1.2
	case 4:
	case 5:
		rate = 1.2;
		break;
	//6���ı���Ϊ1.5
	case 6:
		rate = 1.5;
		break;
	//7���ı���Ϊ1.6
	case 7:
		rate = 1.6;
		break;
	//8���ı���Ϊ1.7
	case 8:
		rate = 1.7;
		break;
	//9���ı���Ϊ1.8
	case 9:
		rate = 1.8;
		break;
	//10���ı���Ϊ2.0
	case 10:
		rate = 2.0;
		break;
	//���ų����������������ʱrate=0.0����������ʾ
	default:
		rate = 0.0;
		break;

	}

	//�жϳ����ԭʼ��Ա�����Ƿ�������ȷ��������󷵻�ԭʼ����
	if (fabs(rate - 0.0) < 1e-6)
	{
		printf("������ִ���\n");
		finally_integral = original_integral;
	}
	//�������ջ��ֽ��
	else
	{
		finally_integral = original_integral + rate*this_integral;
	}
	//�������յĻ��ֽ��
	return finally_integral;
}

void integral(void)
{
	system("cls");
	//�����ӭ��
	printf("�� ӭ �� �� �� �� ϵ ͳ��\n\n");
	Sleep(800);
	//����ȫ�ֱ���
	extern double nowintegral;

	//����Ŀǰ�ĵȼ�
	int nowlevel;
	//����Ŀǰ�ĵȼ�
	nowlevel = level(nowintegral);

	//�жϻ�Ա����ݲ����
	if (nowlevel <= 5)
	{
		printf("��Ŀǰ�Ǳ���ĸ߼���Ա\n\n");
	}
	else
	{
		printf("��Ŀǰ���Ǳ�����ؼ���Ա\n\n");
	}
	//���Ŀǰ�Ļ���
	printf("��Ŀǰ�Ļ����ǣ�%.2f\n\n", nowintegral);

	//���屾�λ���
	double this_integral = -1.0;
	printf("�����뱾�λ���:");
	do
	{
		//���뱾�λ���
		scanf_s("%lf", &this_integral);
		//����Ƿ����������
		if (this_integral < 0.0)
		{
			//����������Ļ�
			//ʹ��һ���ַ����齫����Ĵ����ַ����յ�
			char b[10];
			gets_s(b);
			//����������ʾ��
			printf("�����Ƿ��������\n");
			printf("�����뱾�λ���:");
		}
	} while (this_integral<0.0);
	
	//�������ջ���
	nowintegral = integral_accumulative(nowintegral, this_integral);
	//��ӡ���յĻ���
	printf("\n��Ŀǰ�Ļ�����%.2f\n\n", nowintegral);

}

void integral_system(void)
{
	for (;;)
	{
		//���û��ֺ���
		integral();
		//����ִ�б���
		int call = 0;
		//��ӡ������ʽ
		puts("\n\n\n\n\n");
		puts("--------------------------------------------------------");
		//���춯̬Ч��
		for (int i = 0; i < 5; i++)
		{
			printf(".");
			Sleep(500);
		}
		//���������
		puts("\r��call\n");
		puts("����ϵͳ 1\t�������˵� 2");

		//�����û��������
		scanf_s("%d", &call);
		while (call != 1 && call != 2)
		{
			printf("������������\n");
			//���յ����������Ԫ��
			char a[10];
			gets_s(a);

			//����ͣ��������������һ��
			system("pause");
			system("cls");

			//���������
			puts("��call\n");
			puts("����ϵͳ 1\t�������˵� 2");
			scanf_s("%d", &call);
		}

		//���call=2���������˵�
		if (call == 2)
		{
			break;
		}
	}
}
