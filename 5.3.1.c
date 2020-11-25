#include<stdio.h>
#include<string.h>
void itobin(unsigned int, char*); // 将第一个参数的二进制表示显示到第二个参数指向的字符数组中。
static void itobin_sub(unsigned int, char *);
int main(void)
{
	char num[33];
	unsigned int i;
	scanf("%d", (int *)&i);
	itobin(i, num);
	puts(num);
	return 0;
}

void itobin(unsigned int i, char *str)
{
	memset(str, '0', 32 * sizeof(char));
	str[32] = '\0';
	itobin_sub(i, str + 31);
}

static void itobin_sub(unsigned int i, char *str)
{
	if (i)
		itobin_sub(i>>1, str - 1);
	*str = (i & 1) + '0';
}