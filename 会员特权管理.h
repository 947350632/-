#pragma once
/********************************************************
*Author: ����											*
*Date:2018-05-08										*
*Description:һϵ�к���ͷ��ţ�������������				*
*********************************************************/

//���ڴ�ź���ͷ
//1
#ifndef LEVEL
#define LEVEL

/************************************
*level:������ַ������Ӧ�ĵ�		*
*		���������������򷵻�0		*
*************************************/
int level(double integral);

#endif // !LEVEL

//2
#ifndef MEMBERSHIP

#define MENBERSHIP
/********************************
*membership:�����Ա�Ļ�����Ϣ	*
*���������������Ա���ʵ�		*
*********************************/
void membership(void);
#endif // !MEMBERSHIP

//3.1
#ifndef INTEGRAL_ACCUMULATIVE

#define INTEGRAL_ACCUMULATIVE

/********************************************
*integral_accumulative:�ú���������������	*
*һ���ǻ�Ա��ԭʼ���֣���һ���Ǳ��λ��֣�	*
*���������ջ�ԱĿǰ�ĵȼ����б��ʻ��֣���	*
*�����ػ�Ա�����ջ��֡������������ԭʼ	*
*����										*
*********************************************/
double integral_accumulative(double original_integral, double this_integral);

#endif // !INTEGRAL_ACCUMULATIVE

//3.2
#ifndef INTEGRAL

#define INTEGRAL
/****************************
*integral:�˺��������ۼƻ���*
*****************************/
void integral(void);

#endif // !INTEGRAL

//3.3
#ifndef INTEGRAL_SYSTEM

#define INTEGRAL_SYSTEM
/****************************
*integral_system:����ϵͳ	*
*****************************/
void integral_system(void);

#endif // !INTEGRAL_SYSTEM

//4.1
#ifndef DISCOUNT_RATE

#define DISCOUNT_RATE
/****************************************
*discount_rate:�������ݻ�ԱĿǰ�Ļ���	*
*������������е��ۿۣ��������ۿ���		*
*****************************************/
double discount_rate();
#endif // !DISCOUNT_RATE

//4.2
#ifndef INTEGRAL_DISCOUNT_SYSTEM

#define INTEGRAL_DISCOUNT_SYSTEM
/********************************************
*consumption_discount_system:�������ϵͳ	*
*********************************************/
void integral_discount_system(void);

#endif // !INTEGRAL_DISCOUNT_SYSTEM

//4.3
#ifndef CONSUMPTION_DISCOUNT

#define CONSUMPTION_DISCOUNT
/****************************************
*consumption_discount:���������ۿ�ϵͳ	*
*****************************************/
void integral_discount(void);

#endif // !CONSUMPTION_DISCOUNT

//5.1
#ifndef INTEGRAL_SHOP_SYSTEM

#define INTEGRAL_SHOP_SYSTEM

/********************************************
*integral_shop_system:�򵥴�ӡ����������	*
*********************************************/
void integral_shop_system(void);

#endif // !INTEGRAL_SHOP_SYSTEM

//5.2
#ifndef INTEGRAL_SHOP

#define INTEGRAL_SHOP

/************************************
*integral_shop:��������ѭ����������	*
*				ϵͳ����������		*
*************************************/
void integral_shop(void);

#endif // !INTEGRAL_SHOP

//5.3
#ifndef SMALL_SHOP

#define SMALL_SHOP

/********************************
*small_shop:��ӡС����Ʒ����Ϣ	*
*********************************/
void small_shop(void);

#endif // !SMALL_SHOP

//5.4
#ifndef BIG_SHOP

#define BIG_SHOP

/********************************
*big_shop:��ӡ�����Ʒ����Ϣ	*
*********************************/
void big_shop(void);
#endif // !BIG_SHOP

//5.5
#ifndef SHOP_GOOD

#define SHOP_GOOD

/************************************
*shop_good:��Ҫһ�����������ݲ���	*
*			��ӡ�������Ʒ����		*
*************************************/
void shop_good(int i);
#endif // !SHOP_GOOD

