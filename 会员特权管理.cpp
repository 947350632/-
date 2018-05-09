/********************************************************
*Author: 刘进											*
*Date:2018-05-08										*
*Description:关于三个积分系统的函数，供主函数调用		*
*********************************************************/

#include "stdafx.h"
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<conio.h>
#include "会员特权管理.h"

;
//等级函数，好多地方调用
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
/*---------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------*/
//打印会员信息的函数，也有好多地方调用，不过就是个过客
void membership(void)
{
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

}
/*---------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------*/
//以下函数组成了积分系统的累计功能
double integral_accumulative(double this_integral)
{
	//声明全局变量
	extern double nowintegral;
	//定义目前的等级
	int nowlevel;

	//计算目前的等级
	nowlevel = level(nowintegral);

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
		puts("\n您本次获得一倍积分");
		break;
	//4-5级的倍率为1.2
	case 4:
	case 5:
		rate = 1.2;
		puts("\n您本次获得一点二倍积分");
		break;
	//6级的倍率为1.5
	case 6:
		rate = 1.5;
		puts("\n您本次获得一点五倍积分");
		break;
	//7级的倍率为1.6
	case 7:
		puts("\n您本次获得一点溜倍积分");
		rate = 1.6;
		break;
	//8级的倍率为1.7
	case 8:
		puts("\n您本次获得一点七倍积分");
		rate = 1.7;
		break;
	//9级的倍率为1.8
	case 9:
		puts("\n您本次获得一点八倍积分");
		rate = 1.8;
		break;
	//10级的倍率为2.0
	case 10:
		puts("\n您本次获得二倍积分");
		rate = 2.0;
		break;
	//不排除输入错误的情况，此时rate=0.0，并给出提示
	default:
		system("cls");
		puts("系统出错了！！！！！！");
		//打印返回界面
		puts("\n\n\n\n\n\n");
		puts("-------------------------------------------");
		puts("按任意键退出系统！");
		_getch();
		exit(0);
	}

	//计算最终积分结果
		finally_integral = nowintegral + rate*this_integral;

	//返回最终的积分结果
	return finally_integral;
}

void integral(void)
{
	//清屏
	system("cls");
	//制造加载假象
	for (int i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(500);
	}

	system("cls");//清屏
	//输出欢迎语
	printf("***欢 迎 进 入 积 分 系 统！***\n\n");
	Sleep(800);

	//声明全局变量
	extern double nowintegral;

	//调用membership函数，打印会员身份与积分
	membership();

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
			printf("请检查是否输入错误！");
			//给出等待按任意键继续
			_getch();
			printf("\r请输入本次积分:");
		}
	} while (this_integral<0.0);
	
	//制造计算假象
	Sleep(500);

	//计算最终积分
	nowintegral = integral_accumulative(this_integral);

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
		int call = -1;

		//打印这界面格式
		puts("\n\n\n\n\n\n");
		puts("-------------------------------------------");

		//制造动态效果
		for (int i = 0; i < 5; i++)
		{
			printf(".");
			Sleep(500);
		}

		//打出主界面
		puts("\r请call\n");
		puts("积分系统 1\t返回主菜单 0");

		//读入用户输入的数
		while (call != '0'&&call != '1')
		{
			call = _getch();
		}

		//如果call=0，返回主菜单
		if (call == '0')
		{
			//清屏
			system("cls");
			//制造加载假象
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
//以下三个函数完成了积分折扣的功能
void integral_discount_system(void)
{
	
	for (;;)
	{
		//调用积分函数
		integral_discount();

		//定义执行变量
		int call = -1;

		//打印这界面格式
		puts("\n\n\n\n\n\n");
		puts("-------------------------------------------");
		//制造动态效果
		for (int i = 0; i < 5; i++)
		{
			printf(".");
			Sleep(500);
		}

		//打出主界面
		puts("\r请call\n");
		puts("积分折扣 1\t返回主菜单 0");

		//读入用户输入的数
		while (call != '0'&&call != '1')
		{
			call = _getch();
		}

		//如果call=0，返回主菜单
		if (call == '0')
		{
			//清屏
			system("cls");
			//制造加载假象
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
	//声明全局变量现在的积分
	extern double nowintegral;
	//定义折扣率
	double rate;

	//定义等级
	int nowlevel;
	//计算等级
	nowlevel = level(nowintegral);

	//计算折扣率
	switch (nowlevel)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		rate = 0.95;
		puts("\n恭喜您本次消费为您九五折");
		break;
	case 6:
	case 7:
	case 8:
		rate = 0.90;
		puts("\n恭喜您本次消费为您九折");
		break;
	case 9:
	case 10:
		rate = 0.85;
		puts("\n恭喜您本次消费为您八五折");
		break;
	default:
		system("cls");
		puts("系统出错了！！！！！！");
		//打印返回界面
		puts("\n\n\n\n\n\n");
		puts("-------------------------------------------");
		puts("按任意键退出系统！");
		_getch();
		exit(0);
	}

	//返回折扣率
	return rate;
}

void integral_discount(void)
{
	//清屏
	system("cls");
	//制造加载假象
	for (int i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(500);
	}

	system("cls");
	//输出欢迎语
	printf("***欢 迎 进 入 消 费 折 扣 系 统！***\n\n");
	Sleep(500);

	//给出提示
	printf("!!!选择消费折扣此次消费将不计入积分！\n\n");
	Sleep(1500);

	//声明全局变量
	extern double nowintegral;

	//调用membership函数，打印会员身份与积分
	membership();

	//定义此次账单
	double this_count;

	//提示输入此次消费金额
	printf("请输入此次消费金额：");
	//输入控制处理

	while (scanf_s("%lf",&this_count ) == 0)
	{
		printf("您的输入不符合要求！");
		//吸收掉输错的字符
		while (getchar() != '\n');
		getchar();
		_getch();
		printf("\r请输入此次消费金额：");
	}

	//制造延迟假象
	Sleep(500);
	//定义折扣率

	double discount;
	//计算折扣率

	discount = discount_rate();
	//制造延迟假象

	Sleep(500);
	//输出本次需要的金额
	printf("\n经折扣后本次消费金额为：%.2f\n", this_count*discount);

}
/*---------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------*/
//以下若干个系统完成了系统的积分换购功能
void integral_shop_system(void)
{
	//清屏
	system("cls");
	//制造加载假象
	for (int i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(500);
	}

	system("cls");
	//输出欢迎语
	printf("***欢 迎 进 入 积 分 换 购 系 统！***\n\n");
	Sleep(500);

	//调用membership函数，打印会员身份与积分
	membership();

	puts("\n\n\n\n\n\n");
	puts("-------------------------------------------");
	puts("按任意键继续...");
	_getch();

	//进入积分商城
	integral_shop();
}

void integral_shop(void)
{
	//进入系统的无限循环
	for (;;)
	{
		//声明全局变量
		extern double nowintegral;

		//执行清屏处理
		system("cls");
		//执行加载处理
		for (int i = 0; i < 3; i++)
		{
			printf(".");
			Sleep(500);
		}

		//清空加载，并显示主画面
		printf("\r您当前的积分是：%.2f\n\n", nowintegral);
		puts("以下是您可以选购的商品\n\n");

		//依据会员身份进入相应的商城
		if (level(nowintegral) <= 5)
		{
			//进入高级会员商城
			small_shop();

			//定义控制变量
			int call = -1;

			//提示用户选择
			puts("\n\n\n\n\n\n");
			puts("-------------------------------------------");
			puts("call商品对应数字查看详情,返回主菜单 0！\n");
			puts("请call");

			//读入键盘输入的数字
			while (call < 0 || call>8)
			{
				call = _getch()-'0';
			}

			//判断输入的数字为0则结束程序
			if (call == 0)
			{
				break;
			}
			else
			{	
				//打印购物消息
				exchange_system(call);
	
			}//end if (call == 0)
		}
		else
		{
			//进入特级会员商城
			small_shop();
			big_shop();

			//定义控制变量
			int call = -1;

			//提示用户选择
			puts("\n\n\n\n\n\n");
			puts("-------------------------------------------");
			puts("call商品对应数字查看详情,返回主菜单 0！\n");
			puts("请call");

			//读入用户输入的数字
			scanf_s("%d", &call);
			while (call < 1 || call>14)
			{
				puts("请call正确的数字!");
				//吸收掉输错的字符
				while (getchar() != '\n');
				getchar();
				scanf_s("%d", &call);
			}

			//判断输入的数字，如果为0结束程序
			if (call == 0)
			{
				break;
			}
			else
			{
				//打印购物消息
				exchange_system(call);
			}//enf if (call == 0)
		}
	}
}

void small_shop(void)
{
	//打印出高级会员商品
	printf("1. 君子兰盆栽\t2. 塑料洗脸盆\n");
	printf("3. 洗衣液    \t4. 三折晴雨伞\n");
	printf("5. 清风抽纸  \t6. 安慕希酸奶\n");
	printf("7. 蓝牙耳机  \t8. 移动电源\n");
}

void big_shop(void)
{
	//打印出特级会员商品
	printf("9. 山地自行车\t10.九号平衡车\n");
	printf("11.滚筒洗衣机\t12.车载U盘\n");
	printf("13.智能电视  \t14.iPhone X\n");
}

void shop_good(int call)
{
	system("cls");

	//依据输入的数字打印其详细信息
	switch (call)
	{
	case 1:
		//打印君子兰的商品信息
		puts("商品名称：君子兰(4-6片叶子)");
		puts("商品毛重：1.0kg");
		puts("是否含花盆：带盆栽好");
		puts("开花季节：秋");
		puts("京 东 价:￥20.00");
		puts("所需积分：449");
		break;
		//打印洗脸盆的商品信息
	case 2:
		puts("商品名称：龙士达洗脸盆");
		puts("商品毛重：380.00g");
		puts("材质：塑料");
		puts("产品尺寸（cm）:44x17 * 23");
		puts("京 东 价:￥22.90");
		puts("所需积分：499");
		break;
		//打印洗衣液的商品信息
	case 3:
		puts("商品名称：蓝月亮洁净洗衣液");
		puts("商品毛重：1.1kg");
		puts("类型：机洗");
		puts("包装单位：瓶装");
		puts("保质期：3年");
		puts("京 东 价:￥24.90");
		puts("所需积分：549");
		break;
		//打印雨伞的商品信息
	case 4:
		puts("商品名称：天堂晴雨伞");
		puts("商品毛重：310.00g");
		puts("颜色：蓝，粉，松绿，紫，米，深藏青(任选一种)");
		puts("是否自动:手动 ");
		puts("京 东 价:￥26.90");
		puts("所需积分：599");
		break;
		//打印抽纸商品信息
	case 5:
		puts("商品名称：清风抽取式面纸");
		puts("商品毛重：3.26kg");
		puts("层数：2层");
		puts("香型：无香");
		puts("抽数：200抽软抽*20包纸巾");
		puts("京 东 价:￥39.90");
		puts("所需积分：899");
		break;
		//打印酸奶商品信息
	case 6:
		puts("商品名称：伊利安慕希希腊风味酸奶");
		puts("商品毛重：2.86kg");
		puts("每箱规格：12");
		puts("是否含糖：含糖");
		puts("净含量：205g");
		puts("保质期:6个月");
		puts("生产日期：20180505");
		puts("京 东 价:￥56.10");
		puts("所需积分：1199");
		break;
		//打印蓝牙耳机商品信息
	case 7:
		puts("商品名称：捷波朗BOOST 劲步 夏季青春版");
		puts("商品毛重：100.00g");
		puts("是否单双耳：单边免提");
		puts("佩戴方式：挂耳式");
		puts("颜色：黑色，白色，玫瑰金，绿色，金绿色");
		puts("京 东 价:￥199.00");
		puts("所需积分：3699");
		break;
		//打印充电宝商品信息
	case 8:
		puts("商品名称：ZMIQB815");
		puts("商品毛重：0.62kg");
		puts("容量：15000mAh");
		puts("电芯类型：锂离子电池");
		puts("接口数量：3");
		puts("其他：支持switch笔记本PD 2.0协议");
		puts("颜色：锖色 ");
		puts("京 东 价:￥269.00");
		puts("所需积分：4999");
		break;
		//打印山地自行车商品信息
	case 9:
		puts("商品名称：永久（FOREVER） 27速自行车山地车");
		puts("商品毛重：19.0kg");
		puts("车架材质：铝合金");
		puts("花鼓类型：2培林");
		puts("车把类型：直把");
		puts("颜色：黑绿，黑红，黑蓝。");
		puts("京 东 价:￥899.00");
		puts("所需积分：19999");
		break;
		//打印九号平衡车的商品信息
	case 10:
		puts("商品名称：小米（MI） 定制版Ninebot 九号平衡车");
		puts("商品毛重：15.9kg");
		puts("理论时速：10-20km/h");
		puts("理论续航：20-30km");
		puts("适用对象：成年");
		puts("颜色：黑色，白色");
		puts("京 东 价:￥1999.00");
		puts("所需积分：41999");
		break;
		//打印滚筒洗衣机的商品信息
	case 11:
		puts("商品名称：海尔（Haier)双喷淋变频滚筒洗衣机");
		puts("商品毛重：77.0kg");
		puts("产品类型：滚筒");
		puts("洗涤容量：8kg");
		puts("颜色：银色");
		puts("京 东 价:￥2499.00");
		puts("所需积分：45999");
		break;
		//打印U盘的商品信息
	case 12:
		puts("商品名称：金士顿（Kingston）HXS3");
		puts("商品毛重：50.00g");
		puts("接口：USB3.1");
		puts("容量：512G");
		puts("京 东 价:￥2199.00");
		puts("所需积分：45999");
		break;
		//打印电视的商品信息
	case 13:
		puts("商品名称：小米电视4A 标准版");
		puts("商品毛重：16.3kg");
		puts("分辨率：超高清");
		puts("屏幕尺寸：55英寸");
		puts("京 东 价:￥2599.00");
		puts("所需积分：54999");
		break;
		//打印iPhone X的商品信息
	case 14:
		puts("商品名称：AppleiPhone X");
		puts("商品毛重：440.00g");
		puts("机身内存：64GB");
		puts("网络支持：移动联通电信4G手机");
		puts("颜色：银色，深空灰色");
		puts("其他：公开版，官方标配");
		puts("京 东 价:￥8316.00");
		puts("所需积分：179999");
		break;
		//打印不可预料的情况
	default:
		system("cls");
		puts("系统出错了！！！！！！");
		//打印返回界面
		puts("\n\n\n\n\n\n");
		puts("-------------------------------------------");
		puts("按任意键退出系统！");
		_getch();
		exit(0);
	}
}

void exchange_system(int call)
{
	for (;;)
	{
		//打印商品详细信息
		shop_good(call);

		//打印主界面
		puts("\n\n\n\n\n\n");
		puts("-------------------------------------------");
		puts("换购此物 1\t返回上一级 0");

		//定义控制变量
		int call1 = -1;

		//读入用户键盘输入
		while (call1 != '1' && call1 != '0')
			call1 = _getch();

		//响应用户键盘输入
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

		//打印主界面
		puts("您确认换购此物？");
		puts("\n\n\n\n\n\n");
		puts("-------------------------------------------");
		puts("确认 1\t返回上一级 0");

		//定义控制变量与声明全局变量
		int call1 = -1;
		extern double nowintegral;

		//读入用户键盘的输入
		while (call1 != '1' && call1 != '0')
		{
			call1 = _getch();
		}

		//响应命令
		if (call1 == '0')
		{
			break;
		}
		else
		{
			//计算对应商品的积分
			double price = need_integral(call);

			//判断换购成功与否
			if (nowintegral >= price)
			{
				//减去消耗的积分
				nowintegral = nowintegral - price;

				system("cls");
				puts("**恭喜你换购成功**");

				_getch();
				break;
			}
			else
			{
				system("cls");
				puts("----很抱歉，您的积分不足！----");

				//特级会员进入补差价功能
				if (level(nowintegral) > 5)
				{
					//打印操作面板
					puts("\n\n\n\n\n\n");
					puts("-------------------------------------------");
					puts("RMB补差价 1\t返回 0");

					//定义控制变量
					int call2 = -1;

					//读入用户键盘操作
					while (call2 != '1' && call2 != '0')
					{
						call2 = _getch();
					}

					//响应用户键盘操作
					if (call2 == '0')
					{
						break;
					}
					else
					{
						system("cls");

						//依照会员等级确定会员RMB折差价比例
						if (level(nowintegral <= 8))
							//6-8级会员人民币：积分=1:20
							printf("你需要的差价为：%.2f元", (price - nowintegral) / 20.0);
						else
							//9-10级会员人民币：戒饭=1:30
							printf("你需要的差价为：%.2f元", (price - nowintegral) / 30.0);

						//打印界面判断是否完成补差价
						puts("\n\n\n\n\n\n");
						puts("-------------------------------------------");
						puts("确认完成补差价 1\t返回 0");

						//定义控制变量
						int call3 = -1;

						//读入用户键盘操作
						while (call3 != '1' && call3 != '0')
						{
							call3 = _getch();
						}

						//响应用户键盘操作
						if (call3 == '1')
						{
							system("cls");
							puts("**恭喜你换购成功**");
							nowintegral = 0.0;
						}
							
						break;
					}
				}
				//高级会员按任意键退出
				_getch();
				break;
			}
		}
	}
}

double need_integral(int call)
{
	//定义返回变量
	double ret;

	switch (call)
	{
	case 1://君子兰的积分
		ret = 449.0;
		break;
	case 2://洗脸盆的积分
		ret = 499.0;
		break;
	case 3://洗衣液的积分
		ret = 549.0;
		break;
	case 4://雨伞的积分
		ret = 599.0;
		break;
	case 5://抽纸的积分
		ret = 899.0;
		break;
	case 6://牛奶的积分
		ret = 1199.0;
		break;
	case 7://蓝牙耳机的积分
		ret = 3699.0;
		break;
	case 8://移动电源的积分
		ret = 4999.0;
		break;
	case 9://自行车的积分
		ret = 19999.0;
		break;
	case 10://平衡车的积分
		ret = 41999.0;
		break;
	case 11://海尔洗衣机的积分
	case 12://512GU盘的积分
		ret = 45999.0;
		break;
	case 13://电视机的积分
		ret = 52999.0;
		break;
	case 14://手机的积分
		ret = 179999.0;
		break;
	default:
		system("cls");
		puts("系统出错了！！！！！！");
		//打印返回界面
		puts("\n\n\n\n\n\n");
		puts("-------------------------------------------");
		puts("按任意键退出系统！");
		_getch();
		exit(0);
	}

	return ret;
}