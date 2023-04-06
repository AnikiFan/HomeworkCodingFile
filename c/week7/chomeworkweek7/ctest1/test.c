/* 2254298 信11 范潇 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、整个程序不允许出现任何形式的循环
   --------------------------------------------------------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：将整数n分解后输出
	 输入参数：
	 返 回 值：
	 说    明：1、函数名、形参、返回类型均不准动
			   2、不允许使用64位整数
   ***************************************************************************/
void convert(int n)
{
	int min = 0;

	if (n < 0) {
		printf("- ");
		n = -n;
	}
	if (n < 0 && n == -n)
		min = 1;//需要特判的原因在于n为-2147483648时n - n % 10得不到预期结果,而这一步的预期目标是提取最小位
	if (n / 10 == 0) {
		printf("%c ", n % 10 + 48);//0的ascill码是48
		return;
	}
	if (min == 1) {
		convert(214748364);
		printf("%c ", 8 + 48);
	}
	else {
		convert((n - n % 10) / 10);
		printf("%c ", n % 10 + 48);
	}
	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	int n;
	printf("请输入一个整数\n");

	convert(n = -2147483648);
	printf("\n");

	return 0;
}