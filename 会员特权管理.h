#pragma once
/********************************************************
*Author: 刘进											*
*Date:2018-05-08										*
*Description:一系列函数头存放，供主函数调用				*
*********************************************************/

//用于存放函数头
//1
#ifndef LEVEL
#define LEVEL

/************************************
*level:输入积分返回其对应的等		*
*		级，如果输入错误则返回0		*
*************************************/
int level(double integral);

#endif // !LEVEL

//2
#ifndef MEMBERSHIP

#define MENBERSHIP
/********************************
*membership:输出会员的基本信息	*
*包括积分情况，会员性质等		*
*********************************/
void membership(void);
#endif // !MEMBERSHIP

//3.1
#ifndef INTEGRAL_ACCUMULATIVE

#define INTEGRAL_ACCUMULATIVE

/********************************************
*integral_accumulative:该函数接收两个数据	*
*一个是会员的原始积分，另一个是本次积分，	*
*函数将依照会员目前的等级进行倍率积分，并	*
*将返回会员的最终积分。如果出错将返回原始	*
*积分										*
*********************************************/
double integral_accumulative(double original_integral, double this_integral);

#endif // !INTEGRAL_ACCUMULATIVE

//3.2
#ifndef INTEGRAL

#define INTEGRAL
/****************************
*integral:此函数用于累计积分*
*****************************/
void integral(void);

#endif // !INTEGRAL

//3.3
#ifndef INTEGRAL_SYSTEM

#define INTEGRAL_SYSTEM
/****************************
*integral_system:积分系统	*
*****************************/
void integral_system(void);

#endif // !INTEGRAL_SYSTEM

//4.1
#ifndef DISCOUNT_RATE

#define DISCOUNT_RATE
/****************************************
*discount_rate:函数依据会员目前的积分	*
*计算出其所享有的折扣，并返回折扣率		*
*****************************************/
double discount_rate();
#endif // !DISCOUNT_RATE

//4.2
#ifndef INTEGRAL_DISCOUNT_SYSTEM

#define INTEGRAL_DISCOUNT_SYSTEM
/********************************************
*consumption_discount_system:进入积分系统	*
*********************************************/
void integral_discount_system(void);

#endif // !INTEGRAL_DISCOUNT_SYSTEM

//4.3
#ifndef CONSUMPTION_DISCOUNT

#define CONSUMPTION_DISCOUNT
/****************************************
*consumption_discount:进入消费折扣系统	*
*****************************************/
void integral_discount(void);

#endif // !CONSUMPTION_DISCOUNT

//5.1
#ifndef INTEGRAL_SHOP_SYSTEM

#define INTEGRAL_SHOP_SYSTEM

/********************************************
*integral_shop_system:简单打印出出厂画面	*
*********************************************/
void integral_shop_system(void);

#endif // !INTEGRAL_SHOP_SYSTEM

//5.2
#ifndef INTEGRAL_SHOP

#define INTEGRAL_SHOP

/************************************
*integral_shop:利用无限循环控制整个	*
*				系统的正常运作		*
*************************************/
void integral_shop(void);

#endif // !INTEGRAL_SHOP

//5.3
#ifndef SMALL_SHOP

#define SMALL_SHOP

/********************************
*small_shop:打印小件商品的信息	*
*********************************/
void small_shop(void);

#endif // !SMALL_SHOP

//5.4
#ifndef BIG_SHOP

#define BIG_SHOP

/********************************
*big_shop:打印大件商品的信息	*
*********************************/
void big_shop(void);
#endif // !BIG_SHOP

//5.5
#ifndef SHOP_GOOD

#define SHOP_GOOD

/************************************
*shop_good:需要一个参数，根据参数	*
*			打印具体的商品数据		*
*************************************/
void shop_good(int i);
#endif // !SHOP_GOOD

