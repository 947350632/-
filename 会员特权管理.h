#pragma once
/********************************************************
*Author: ����											*
*Date:2017-05-06										*
*Description:һϵ�к���ͷ��ţ�������������				*
*********************************************************/

//���ڴ�ź���ͷ

#ifndef LEVEL
#define LEVEL

/************************************
*level:������ַ������Ӧ�ĵ�		*
*		���������������򷵻�0		*
*************************************/
int level(double integral);

#endif // !LEVEL

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

#ifndef INTEGRAL

#define INTEGRAL
/****************************
*integral:�˺��������ۼƻ���*
*****************************/
void integral(void);

#endif // !INTEGRAL

#ifndef INTEGRAL_SYSTEM

#define INTEGRAL_SYSTEM
/****************************
*integral_system:����ϵͳ	*
*****************************/
void integral_system(void);

#endif // !INTEGRAL_SYSTEM

#ifndef MEMBERSHIP

#define MENBERSHIP
/********************************
*membership:�����Ա�Ļ�����Ϣ	*
*���������������Ա���ʵ�		*
*********************************/
void membership(void);
#endif // !MEMBERSHIP

#ifndef DISCOUNT_RATE

#define DISCOUNT_RATE
/****************************************
*discount_rate:�������ݻ�ԱĿǰ�Ļ���	*
*������������е��ۿۣ��������ۿ���		*
*****************************************/
double discount_rate();
#endif // !DISCOUNT_RATE

#ifndef CONSUMPTION_DISCOUNT_SYSTEM

#define CONSUMPTION_DISCOUNT_SYSTEM
/********************************************
*consumption_discount_system:�������ϵͳ	*
*********************************************/
void consumption_discount_system(void);

#endif // !CONSUMPTION_DISCOUNT_SYSTEM

#ifndef CONSUMPTION_DISCOUNT

#define CONSUMPTION_DISCOUNT
/****************************************
*consumption_discount:���������ۿ�ϵͳ	*
*****************************************/
void consumption_discount(void)

#endif // !CONSUMPTION_DISCOUNT
