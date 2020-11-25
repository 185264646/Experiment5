#include<stdio.h>
#define M 10
#define N 3
int main(void)
{
	int a[M], b[M];				/* 数组a存放圈中人的编号，数组b存放出圈人的编号 
								 */
	int i, j, k;
	for (i = 0; i < M; i++)		/* 对圈中人按顺序编号1—M */
		a[i] = i + 1;
	for (i = M, j = 0; i > 0; i--)
	{
		/* i表示圈中人个数，初始为M个，剩1个人时结束循环；j表示当前报数人的位置 */
		for (k = 1; k <= N; k++)	/* 1至N报数 */
		{
			while(!a[j])
				if (++j > M - 1)
					j = 0;  /* 最后一个人报数后第一个人接着报，形成一个圈 */
			if (++j > M - 1)
				j = 0;
		}
		// b[M - i] =j ? _______ : ______;	/* 将报数为N的人的编号存入数组b */
		b[M - i] = j ? a[j - 1] : a[M - 1];
		if(--j == -1)
			j = M - 1;
		a[j] = 0;
		#if 0
		if (j)
			for (k = --j; k < i; k++)	/* 压缩数组a，使报数为N的人出圈 
										 */
				______________;
		#endif
	}
	for (i = 0; i < M; i++)	/* 按次序输出出圈人的编号 */
		printf("%6d", b[i]);
	// printf("%6d\n", a[0]);	/* 输出圈中最后一个人的编号 */
	return 0;
}