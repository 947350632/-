#pragma once

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



