/* 实验5-1程序改错与跟踪调试题程序 */
#include<stdio.h>
void strcate(char[], char[]);
void strdelc(char[], char);
int main(void)
{
	char a[] = "Language", b[100] = "Programming";  // 给字符数组a分配额外的空间
	printf("%s %s\n", b, a);
	strcate(b, a);
	printf("%s %s\n", b, a);
	strdelc(b, 'a');
	printf("%s\n", b);
	return 0;
}

void strcate(char t[], char s[])
{
	int i = 0, j = 0;
	while (t[i++]);
	i--;  // 把多加的1减回来
	while ((t[i++] = s[j++]) != '\0');
}

void strdelc(char s[], char c)
{
	int j, k;
	for (j = k = 0; s[j] != '\0'; j++)
	{
		if (s[j] != c)
			s[k++] = s[j];
	}
	s[k] = '\0';  // 加上字符串结尾的空字符
}

