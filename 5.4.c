#include <stdio.h>
#include <string.h>
void strnins(char *, const char *, int);
int main(void)
{
	char a[] = "like", b[100] = "I  HUST.";
	strnins(b, a, 2);
	puts(b);
	return 0;
}

strnins(char *dest, const char *src, int index)
{
	size_t src_len = strlen(src);
	memmove(dest + index + src_len, dest + index, strlen(dest) - index);
	memmove(dest + index, src, src_len);
}