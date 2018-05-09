/********************************************************
*Author: ����											*
*Date:2018-05-08										*
*Description:������������ϵͳ�ĺ�����������������		*
*********************************************************/

#include "stdafx.h"
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<conio.h>
#include "��Ա��Ȩ����.h"

;
//�ȼ��������ö�ط�����
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
/*---------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------*/
//��ӡ��Ա��Ϣ�ĺ�����Ҳ�кö�ط����ã��������Ǹ�����
void membership(void)
{
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

}
/*---------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------*/
//���º�������˻���ϵͳ���ۼƹ���
double integral_accumulative(double this_integral)
{
	//����ȫ�ֱ���
	extern double nowintegral;
	//����Ŀǰ�ĵȼ�
	int nowlevel;

	//����Ŀǰ�ĵȼ�
	nowlevel = level(nowintegral);

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
		puts("\n�����λ��һ������");
		break;
	//4-5���ı���Ϊ1.2
	case 4:
	case 5:
		rate = 1.2;
		puts("\n�����λ��һ���������");
		break;
	//6���ı���Ϊ1.5
	case 6:
		rate = 1.5;
		puts("\n�����λ��һ���屶����");
		break;
	//7���ı���Ϊ1.6
	case 7:
		puts("\n�����λ��һ���ﱶ����");
		rate = 1.6;
		break;
	//8���ı���Ϊ1.7
	case 8:
		puts("\n�����λ��һ���߱�����");
		rate = 1.7;
		break;
	//9���ı���Ϊ1.8
	case 9:
		puts("\n�����λ��һ��˱�����");
		rate = 1.8;
		break;
	//10���ı���Ϊ2.0
	case 10:
		puts("\n�����λ�ö�������");
		rate = 2.0;
		break;
	//���ų����������������ʱrate=0.0����������ʾ
	default:
		system("cls");
		puts("ϵͳ�����ˣ�����������");
		//��ӡ���ؽ���
		puts("\n\n\n\n\n\n");
		puts("-------------------------------------------");
		puts("��������˳�ϵͳ��");
		_getch();
		exit(0);
	}

	//�������ջ��ֽ��
		finally_integral = nowintegral + rate*this_integral;

	//�������յĻ��ֽ��
	return finally_integral;
}

void integral(void)
{
	//����
	system("cls");
	//������ؼ���
	for (int i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(500);
	}

	system("cls");//����
	//�����ӭ��
	printf("***�� ӭ �� �� �� �� ϵ ͳ��***\n\n");
	Sleep(800);

	//����ȫ�ֱ���
	extern double nowintegral;

	//����membership��������ӡ��Ա��������
	membership();

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
			printf("�����Ƿ��������");
			//�����ȴ������������
			_getch();
			printf("\r�����뱾�λ���:");
		}
	} while (this_integral<0.0);
	
	//����������
	Sleep(500);

	//�������ջ���
	nowintegral = integral_accumulative(this_integral);

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
		int call = -1;

		//��ӡ������ʽ
		puts("\n\n\n\n\n\n");
		puts("-------------------------------------------");

		//���춯̬Ч��
		for (int i = 0; i < 5; i++)
		{
			printf(".");
			Sleep(500);
		}

		//���������
		puts("\r��call\n");
		puts("����ϵͳ 1\t�������˵� 0");

		//�����û��������
		while (call != '0'&&call != '1')
		{
			call = _getch();
		}

		//���call=0���������˵�
		if (call == '0')
		{
			//����
			system("cls");
			//������ؼ���
			for (int i = 0; i < 3; i++)
			{
				printf(".");
				Sleep(500);
			}

			break;
		}
	}
}
/*---------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------*/
//����������������˻����ۿ۵Ĺ���
void integral_discount_system(void)
{
	
	for (;;)
	{
		//���û��ֺ���
		integral_discount();

		//����ִ�б���
		int call = -1;

		//��ӡ������ʽ
		puts("\n\n\n\n\n\n");
		puts("-------------------------------------------");
		//���춯̬Ч��
		for (int i = 0; i < 5; i++)
		{
			printf(".");
			Sleep(500);
		}

		//���������
		puts("\r��call\n");
		puts("�����ۿ� 1\t�������˵� 0");

		//�����û��������
		while (call != '0'&&call != '1')
		{
			call = _getch();
		}

		//���call=0���������˵�
		if (call == '0')
		{
			//����
			system("cls");
			//������ؼ���
			for (int i = 0; i < 3; i++)
			{
				printf(".");
				Sleep(500);
			}

			break;
		}
	}
}

double discount_rate()
{
	//����ȫ�ֱ������ڵĻ���
	extern double nowintegral;
	//�����ۿ���
	double rate;

	//����ȼ�
	int nowlevel;
	//����ȼ�
	nowlevel = level(nowintegral);

	//�����ۿ���
	switch (nowlevel)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		rate = 0.95;
		puts("\n��ϲ����������Ϊ��������");
		break;
	case 6:
	case 7:
	case 8:
		rate = 0.90;
		puts("\n��ϲ����������Ϊ������");
		break;
	case 9:
	case 10:
		rate = 0.85;
		puts("\n��ϲ����������Ϊ��������");
		break;
	default:
		system("cls");
		puts("ϵͳ�����ˣ�����������");
		//��ӡ���ؽ���
		puts("\n\n\n\n\n\n");
		puts("-------------------------------------------");
		puts("��������˳�ϵͳ��");
		_getch();
		exit(0);
	}

	//�����ۿ���
	return rate;
}

void integral_discount(void)
{
	//����
	system("cls");
	//������ؼ���
	for (int i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(500);
	}

	system("cls");
	//�����ӭ��
	printf("***�� ӭ �� �� �� �� �� �� ϵ ͳ��***\n\n");
	Sleep(500);

	//������ʾ
	printf("!!!ѡ�������ۿ۴˴����ѽ���������֣�\n\n");
	Sleep(1500);

	//����ȫ�ֱ���
	extern double nowintegral;

	//����membership��������ӡ��Ա��������
	membership();

	//����˴��˵�
	double this_count;

	//��ʾ����˴����ѽ��
	printf("������˴����ѽ�");
	//������ƴ���

	while (scanf_s("%lf",&this_count ) == 0)
	{
		printf("�������벻����Ҫ��");
		//���յ������ַ�
		while (getchar() != '\n');
		getchar();
		_getch();
		printf("\r������˴����ѽ�");
	}

	//�����ӳټ���
	Sleep(500);
	//�����ۿ���

	double discount;
	//�����ۿ���

	discount = discount_rate();
	//�����ӳټ���

	Sleep(500);
	//���������Ҫ�Ľ��
	printf("\n���ۿۺ󱾴����ѽ��Ϊ��%.2f\n", this_count*discount);

}
/*---------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------*/
//�������ɸ�ϵͳ�����ϵͳ�Ļ��ֻ�������
void integral_shop_system(void)
{
	//����
	system("cls");
	//������ؼ���
	for (int i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(500);
	}

	system("cls");
	//�����ӭ��
	printf("***�� ӭ �� �� �� �� �� �� ϵ ͳ��***\n\n");
	Sleep(500);

	//����membership��������ӡ��Ա��������
	membership();

	puts("\n\n\n\n\n\n");
	puts("-------------------------------------------");
	puts("�����������...");
	_getch();

	//��������̳�
	integral_shop();
}

void integral_shop(void)
{
	//����ϵͳ������ѭ��
	for (;;)
	{
		//����ȫ�ֱ���
		extern double nowintegral;

		//ִ����������
		system("cls");
		//ִ�м��ش���
		for (int i = 0; i < 3; i++)
		{
			printf(".");
			Sleep(500);
		}

		//��ռ��أ�����ʾ������
		printf("\r����ǰ�Ļ����ǣ�%.2f\n\n", nowintegral);
		puts("������������ѡ������Ʒ\n\n");

		//���ݻ�Ա��ݽ�����Ӧ���̳�
		if (level(nowintegral) <= 5)
		{
			//����߼���Ա�̳�
			small_shop();

			//������Ʊ���
			int call = -1;

			//��ʾ�û�ѡ��
			puts("\n\n\n\n\n\n");
			puts("-------------------------------------------");
			puts("call��Ʒ��Ӧ���ֲ鿴����,�������˵� 0��\n");
			puts("��call");

			//����������������
			while (call < 0 || call>8)
			{
				call = _getch()-'0';
			}

			//�ж����������Ϊ0���������
			if (call == 0)
			{
				break;
			}
			else
			{	
				//��ӡ������Ϣ
				exchange_system(call);
	
			}//end if (call == 0)
		}
		else
		{
			//�����ؼ���Ա�̳�
			small_shop();
			big_shop();

			//������Ʊ���
			int call = -1;

			//��ʾ�û�ѡ��
			puts("\n\n\n\n\n\n");
			puts("-------------------------------------------");
			puts("call��Ʒ��Ӧ���ֲ鿴����,�������˵� 0��\n");
			puts("��call");

			//�����û����������
			scanf_s("%d", &call);
			while (call < 1 || call>14)
			{
				puts("��call��ȷ������!");
				//���յ������ַ�
				while (getchar() != '\n');
				getchar();
				scanf_s("%d", &call);
			}

			//�ж���������֣����Ϊ0��������
			if (call == 0)
			{
				break;
			}
			else
			{
				//��ӡ������Ϣ
				exchange_system(call);
			}//enf if (call == 0)
		}
	}
}

void small_shop(void)
{
	//��ӡ���߼���Ա��Ʒ
	printf("1. ����������\t2. ����ϴ����\n");
	printf("3. ϴ��Һ    \t4. ��������ɡ\n");
	printf("5. ����ֽ  \t6. ��Ľϣ����\n");
	printf("7. ��������  \t8. �ƶ���Դ\n");
}

void big_shop(void)
{
	//��ӡ���ؼ���Ա��Ʒ
	printf("9. ɽ�����г�\t10.�ź�ƽ�⳵\n");
	printf("11.��Ͳϴ�»�\t12.����U��\n");
	printf("13.���ܵ���  \t14.iPhone X\n");
}

void shop_good(int call)
{
	system("cls");

	//������������ִ�ӡ����ϸ��Ϣ
	switch (call)
	{
	case 1:
		//��ӡ����������Ʒ��Ϣ
		puts("��Ʒ���ƣ�������(4-6ƬҶ��)");
		puts("��Ʒë�أ�1.0kg");
		puts("�Ƿ񺬻��裺�����Ժ�");
		puts("�������ڣ���");
		puts("�� �� ��:��20.00");
		puts("������֣�449");
		break;
		//��ӡϴ�������Ʒ��Ϣ
	case 2:
		puts("��Ʒ���ƣ���ʿ��ϴ����");
		puts("��Ʒë�أ�380.00g");
		puts("���ʣ�����");
		puts("��Ʒ�ߴ磨cm��:44x17 * 23");
		puts("�� �� ��:��22.90");
		puts("������֣�499");
		break;
		//��ӡϴ��Һ����Ʒ��Ϣ
	case 3:
		puts("��Ʒ���ƣ��������ྻϴ��Һ");
		puts("��Ʒë�أ�1.1kg");
		puts("���ͣ���ϴ");
		puts("��װ��λ��ƿװ");
		puts("�����ڣ�3��");
		puts("�� �� ��:��24.90");
		puts("������֣�549");
		break;
		//��ӡ��ɡ����Ʒ��Ϣ
	case 4:
		puts("��Ʒ���ƣ���������ɡ");
		puts("��Ʒë�أ�310.00g");
		puts("��ɫ�������ۣ����̣��ϣ��ף������(��ѡһ��)");
		puts("�Ƿ��Զ�:�ֶ� ");
		puts("�� �� ��:��26.90");
		puts("������֣�599");
		break;
		//��ӡ��ֽ��Ʒ��Ϣ
	case 5:
		puts("��Ʒ���ƣ�����ȡʽ��ֽ");
		puts("��Ʒë�أ�3.26kg");
		puts("������2��");
		puts("���ͣ�����");
		puts("������200�����*20��ֽ��");
		puts("�� �� ��:��39.90");
		puts("������֣�899");
		break;
		//��ӡ������Ʒ��Ϣ
	case 6:
		puts("��Ʒ���ƣ�������Ľϣϣ����ζ����");
		puts("��Ʒë�أ�2.86kg");
		puts("ÿ����12");
		puts("�Ƿ��ǣ�����");
		puts("��������205g");
		puts("������:6����");
		puts("�������ڣ�20180505");
		puts("�� �� ��:��56.10");
		puts("������֣�1199");
		break;
		//��ӡ����������Ʒ��Ϣ
	case 7:
		puts("��Ʒ���ƣ��ݲ���BOOST ���� �ļ��ഺ��");
		puts("��Ʒë�أ�100.00g");
		puts("�Ƿ�˫������������");
		puts("�����ʽ���Ҷ�ʽ");
		puts("��ɫ����ɫ����ɫ��õ�����ɫ������ɫ");
		puts("�� �� ��:��199.00");
		puts("������֣�3699");
		break;
		//��ӡ��籦��Ʒ��Ϣ
	case 8:
		puts("��Ʒ���ƣ�ZMIQB815");
		puts("��Ʒë�أ�0.62kg");
		puts("������15000mAh");
		puts("��о���ͣ�����ӵ��");
		puts("�ӿ�������3");
		puts("������֧��switch�ʼǱ�PD 2.0Э��");
		puts("��ɫ���ɫ ");
		puts("�� �� ��:��269.00");
		puts("������֣�4999");
		break;
		//��ӡɽ�����г���Ʒ��Ϣ
	case 9:
		puts("��Ʒ���ƣ����ã�FOREVER�� 27�����г�ɽ�س�");
		puts("��Ʒë�أ�19.0kg");
		puts("���ܲ��ʣ����Ͻ�");
		puts("�������ͣ�2����");
		puts("�������ͣ�ֱ��");
		puts("��ɫ�����̣��ں죬������");
		puts("�� �� ��:��899.00");
		puts("������֣�19999");
		break;
		//��ӡ�ź�ƽ�⳵����Ʒ��Ϣ
	case 10:
		puts("��Ʒ���ƣ�С�ף�MI�� ���ư�Ninebot �ź�ƽ�⳵");
		puts("��Ʒë�أ�15.9kg");
		puts("����ʱ�٣�10-20km/h");
		puts("����������20-30km");
		puts("���ö��󣺳���");
		puts("��ɫ����ɫ����ɫ");
		puts("�� �� ��:��1999.00");
		puts("������֣�41999");
		break;
		//��ӡ��Ͳϴ�»�����Ʒ��Ϣ
	case 11:
		puts("��Ʒ���ƣ�������Haier)˫���ܱ�Ƶ��Ͳϴ�»�");
		puts("��Ʒë�أ�77.0kg");
		puts("��Ʒ���ͣ���Ͳ");
		puts("ϴ��������8kg");
		puts("��ɫ����ɫ");
		puts("�� �� ��:��2499.00");
		puts("������֣�45999");
		break;
		//��ӡU�̵���Ʒ��Ϣ
	case 12:
		puts("��Ʒ���ƣ���ʿ�٣�Kingston��HXS3");
		puts("��Ʒë�أ�50.00g");
		puts("�ӿڣ�USB3.1");
		puts("������512G");
		puts("�� �� ��:��2199.00");
		puts("������֣�45999");
		break;
		//��ӡ���ӵ���Ʒ��Ϣ
	case 13:
		puts("��Ʒ���ƣ�С�׵���4A ��׼��");
		puts("��Ʒë�أ�16.3kg");
		puts("�ֱ��ʣ�������");
		puts("��Ļ�ߴ磺55Ӣ��");
		puts("�� �� ��:��2599.00");
		puts("������֣�54999");
		break;
		//��ӡiPhone X����Ʒ��Ϣ
	case 14:
		puts("��Ʒ���ƣ�AppleiPhone X");
		puts("��Ʒë�أ�440.00g");
		puts("�����ڴ棺64GB");
		puts("����֧�֣��ƶ���ͨ����4G�ֻ�");
		puts("��ɫ����ɫ����ջ�ɫ");
		puts("�����������棬�ٷ�����");
		puts("�� �� ��:��8316.00");
		puts("������֣�179999");
		break;
		//��ӡ����Ԥ�ϵ����
	default:
		system("cls");
		puts("ϵͳ�����ˣ�����������");
		//��ӡ���ؽ���
		puts("\n\n\n\n\n\n");
		puts("-------------------------------------------");
		puts("��������˳�ϵͳ��");
		_getch();
		exit(0);
	}
}

void exchange_system(int call)
{
	for (;;)
	{
		//��ӡ��Ʒ��ϸ��Ϣ
		shop_good(call);

		//��ӡ������
		puts("\n\n\n\n\n\n");
		puts("-------------------------------------------");
		puts("�������� 1\t������һ�� 0");

		//������Ʊ���
		int call1 = -1;

		//�����û���������
		while (call1 != '1' && call1 != '0')
			call1 = _getch();

		//��Ӧ�û���������
		if (call1 == '0')
		{
			break;
		}
		else
		{
			buy(call);
		}
	}
}

void buy(int call)
{
	for (;;)
	{
		system("cls");

		//��ӡ������
		puts("��ȷ�ϻ������");
		puts("\n\n\n\n\n\n");
		puts("-------------------------------------------");
		puts("ȷ�� 1\t������һ�� 0");

		//������Ʊ���������ȫ�ֱ���
		int call1 = -1;
		extern double nowintegral;

		//�����û����̵�����
		while (call1 != '1' && call1 != '0')
		{
			call1 = _getch();
		}

		//��Ӧ����
		if (call1 == '0')
		{
			break;
		}
		else
		{
			//�����Ӧ��Ʒ�Ļ���
			double price = need_integral(call);

			//�жϻ����ɹ����
			if (nowintegral >= price)
			{
				//��ȥ���ĵĻ���
				nowintegral = nowintegral - price;

				system("cls");
				puts("**��ϲ�㻻���ɹ�**");

				_getch();
				break;
			}
			else
			{
				system("cls");
				puts("----�ܱ�Ǹ�����Ļ��ֲ��㣡----");

				//�ؼ���Ա���벹��۹���
				if (level(nowintegral) > 5)
				{
					//��ӡ�������
					puts("\n\n\n\n\n\n");
					puts("-------------------------------------------");
					puts("RMB����� 1\t���� 0");

					//������Ʊ���
					int call2 = -1;

					//�����û����̲���
					while (call2 != '1' && call2 != '0')
					{
						call2 = _getch();
					}

					//��Ӧ�û����̲���
					if (call2 == '0')
					{
						break;
					}
					else
					{
						system("cls");

						//���ջ�Ա�ȼ�ȷ����ԱRMB�۲�۱���
						if (level(nowintegral <= 8))
							//6-8����Ա����ң�����=1:20
							printf("����Ҫ�Ĳ��Ϊ��%.2fԪ", (price - nowintegral) / 20.0);
						else
							//9-10����Ա����ң��䷹=1:30
							printf("����Ҫ�Ĳ��Ϊ��%.2fԪ", (price - nowintegral) / 30.0);

						//��ӡ�����ж��Ƿ���ɲ����
						puts("\n\n\n\n\n\n");
						puts("-------------------------------------------");
						puts("ȷ����ɲ���� 1\t���� 0");

						//������Ʊ���
						int call3 = -1;

						//�����û����̲���
						while (call3 != '1' && call3 != '0')
						{
							call3 = _getch();
						}

						//��Ӧ�û����̲���
						if (call3 == '1')
						{
							system("cls");
							puts("**��ϲ�㻻���ɹ�**");
							nowintegral = 0.0;
						}
							
						break;
					}
				}
				//�߼���Ա��������˳�
				_getch();
				break;
			}
		}
	}
}

double need_integral(int call)
{
	//���巵�ر���
	double ret;

	switch (call)
	{
	case 1://�������Ļ���
		ret = 449.0;
		break;
	case 2://ϴ����Ļ���
		ret = 499.0;
		break;
	case 3://ϴ��Һ�Ļ���
		ret = 549.0;
		break;
	case 4://��ɡ�Ļ���
		ret = 599.0;
		break;
	case 5://��ֽ�Ļ���
		ret = 899.0;
		break;
	case 6://ţ�̵Ļ���
		ret = 1199.0;
		break;
	case 7://���������Ļ���
		ret = 3699.0;
		break;
	case 8://�ƶ���Դ�Ļ���
		ret = 4999.0;
		break;
	case 9://���г��Ļ���
		ret = 19999.0;
		break;
	case 10://ƽ�⳵�Ļ���
		ret = 41999.0;
		break;
	case 11://����ϴ�»��Ļ���
	case 12://512GU�̵Ļ���
		ret = 45999.0;
		break;
	case 13://���ӻ��Ļ���
		ret = 52999.0;
		break;
	case 14://�ֻ��Ļ���
		ret = 179999.0;
		break;
	default:
		system("cls");
		puts("ϵͳ�����ˣ�����������");
		//��ӡ���ؽ���
		puts("\n\n\n\n\n\n");
		puts("-------------------------------------------");
		puts("��������˳�ϵͳ��");
		_getch();
		exit(0);
	}

	return ret;
}