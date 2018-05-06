#pragma once
/********************************************************
*Author: 刘进											*
*Date:2017-05-06										*
*Description:一系列函数头存放，供主函数调用				*
*********************************************************/

//用于存放函数头

#ifndef LEVEL
#define LEVEL

/************************************
*level:输入积分返回其对应的等		*
*		级，如果输入错误则返回0		*
*************************************/
int level(double integral);

#endif // !LEVEL

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

#ifndef INTEGRAL

#define INTEGRAL
/****************************
*integral:此函数用于累计积分*
*****************************/
void integral(void);

#endif // !INTEGRAL

#ifndef INTEGRAL_SYSTEM

#define INTEGRAL_SYSTEM
/****************************
*integral_system:积分系统	*
*****************************/
void integral_system(void);

#endif // !INTEGRAL_SYSTEM

#ifndef MEMBERSHIP

#define MENBERSHIP
/********************************
*membership:输出会员的基本信息	*
*包括积分情况，会员性质等		*
*********************************/
void membership(void);
#endif // !MEMBERSHIP

#ifndef DISCOUNT_RATE

#define DISCOUNT_RATE
/****************************************
*discount_rate:函数依据会员目前的积分	*
*计算出其所享有的折扣，并返回折扣率		*
*****************************************/
double discount_rate();
#endif // !DISCOUNT_RATE

#ifndef CONSUMPTION_DISCOUNT_SYSTEM

#define CONSUMPTION_DISCOUNT_SYSTEM
/********************************************
*consumption_discount_system:进入积分系统	*
*********************************************/
void consumption_discount_system(void);

#endif // !CONSUMPTION_DISCOUNT_SYSTEM

#ifndef CONSUMPTION_DISCOUNT

#define CONSUMPTION_DISCOUNT
/****************************************
*consumption_discount:进入消费折扣系统	*
*****************************************/
void consumption_discount(void)

#endif // !CONSUMPTION_DISCOUNT
