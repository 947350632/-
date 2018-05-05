#include "stdafx.h"
#include<stdlib.h>;
#include<math.h>
#include<Windows.h>
#include"会员特权管理.h"

int level(double integral)
{
	//定义需要的返回值
	int ret;

	//依据输入num的大小确定返回值的大小
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
	//如果输入一个<0的数字则返回0
	//并给出相对应的提示
	else
	{
		printf("您的会员积分已不足0。\n");
		ret = 0;
	}

	//返回积分integral对应的等级
	return ret;
 }

double integral_accumulative(double original_integral,double this_integral)
{
	//定义此时的会员等级
	int nowlevel;
	//计算出会员等级
	nowlevel = level(original_integral);

	//定义最终积分
	double finally_integral=0.0;
	//定义积分等级倍率
	double rate = 0.0;

	//依据会员等级计算倍率
	switch (nowlevel)
	{
	//1-3级的倍率为1.0
	case 1:
	case 2:
	case 3:
		rate = 1.0;
		break;
	//4-5级的倍率为1.2
	case 4:
	case 5:
		rate = 1.2;
		break;
	//6级的倍率为1.5
	case 6:
		rate = 1.5;
		break;
	//7级的倍率为1.6
	case 7:
		rate = 1.6;
		break;
	//8级的倍率为1.7
	case 8:
		rate = 1.7;
		break;
	//9级的倍率为1.8
	case 9:
		rate = 1.8;
		break;
	//10级的倍率为2.0
	case 10:
		rate = 2.0;
		break;
	//不排除输入错误的情况，此时rate=0.0，并给出提示
	default:
		rate = 0.0;
		break;

	}

	//判断程序的原始会员积分是否输入正确，如果错误返回原始积分
	if (fabs(rate - 0.0) < 1e-6)
	{
		printf("程序出现错误\n");
		finally_integral = original_integral;
	}
	//计算最终积分结果
	else
	{
		finally_integral = original_integral + rate*this_integral;
	}
	//返回最终的积分结果
	return finally_integral;
}

void integral(void)
{
	system("cls");
	//输出欢迎语
	printf("欢 迎 进 入 积 分 系 统！\n\n");
	Sleep(800);
	//声明全局变量
	extern double nowintegral;

	//定义目前的等级
	int nowlevel;
	//计算目前的等级
	nowlevel = level(nowintegral);

	//判断会员的身份并输出
	if (nowlevel <= 5)
	{
		printf("您目前是本店的高级会员\n\n");
	}
	else
	{
		printf("您目前的是本店的特级会员\n\n");
	}
	//输出目前的积分
	printf("您目前的积分是：%.2f\n\n", nowintegral);

	//定义本次积分
	double this_integral = -1.0;
	printf("请输入本次积分:");
	do
	{
		//读入本次积分
		scanf_s("%lf", &this_integral);
		//检查是否有输入错误
		if (this_integral < 0.0)
		{
			//如果输入错误的话
			//使用一个字符数组将输入的错误字符吸收掉
			char b[10];
			gets_s(b);
			//给出错误提示语
			printf("请检查是否输入错误！\n");
			printf("请输入本次积分:");
		}
	} while (this_integral<0.0);
	
	//计算最终积分
	nowintegral = integral_accumulative(nowintegral, this_integral);
	//打印最终的积分
	printf("\n您目前的积分是%.2f\n\n", nowintegral);

}

void integral_system(void)
{
	for (;;)
	{
		//调用积分函数
		integral();
		//定义执行变量
		int call = 0;
		//打印这界面格式
		puts("\n\n\n\n\n");
		puts("--------------------------------------------------------");
		//制造动态效果
		for (int i = 0; i < 5; i++)
		{
			printf(".");
			Sleep(500);
		}
		//打出主界面
		puts("\r请call\n");
		puts("积分系统 1\t返回主菜单 2");

		//读入用户输入的数
		scanf_s("%d", &call);
		while (call != 1 && call != 2)
		{
			printf("您的输入有误！\n");
			//吸收掉错误的输入元素
			char a[10];
			gets_s(a);

			//短暂停留后清屏进入下一节
			system("pause");
			system("cls");

			//打出主界面
			puts("请call\n");
			puts("积分系统 1\t返回主菜单 2");
			scanf_s("%d", &call);
		}

		//如果call=2，返回主菜单
		if (call == 2)
		{
			break;
		}
	}
}
