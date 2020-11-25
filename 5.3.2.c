#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct student;
void get_info(struct student *); // 从键盘读入学生信息
int get_choice(void); // 从键盘读入用户选项
void sort_info(struct student *, int); // 将学生信息结构体数组按成绩顺序重排
static int cmp(const void *, const void *);
void print_info(struct student *, int); // 打印成绩结构体数组

struct student {
	char name[100];
	float score;
} data[MAX];

int student_cnt;

int main(void)
{
	int choice;
	get_info(data);
	do
	{
		puts("您想要做什么？");
		puts("1. 按序打印考生信息");
		puts("2. 退出");
		switch(get_choice())
		{
			case '1':
				sort_info(data, student_cnt);
				print_info(data, student_cnt);
				break;
			case '2':
				exit(0);
			default:
				puts("输入错误， 请重新输入。");
		}
	}
	while (1);
	return 0;
}

void get_info(struct student *data)
{
	if (!scanf("%d", &student_cnt) || student_cnt > 100)
	{
		exit(1);
	};
	for (int i = 0; i < student_cnt; i++)
	{
		if (scanf("%s%f", data[i].name, &data[i].score) != 2)
		{
			exit(1);
		}
	}
	getchar(); // Consume '\n'
}

int get_choice(void)
{
	int choice;
	if ((choice = getchar()) == EOF)
		exit(0);
	else if (choice == '\n')
		return choice;
	else
	{
		while (getchar()!= '\n');
		return choice;
	}
}

void sort_info(struct student *data, int cnt)
{
	qsort(data, cnt, sizeof(struct student), cmp);
}

static int cmp(const void *stu_a, const void *stu_b)
{
	if (((struct student *)stu_a)->score - ((struct student *)stu_b)->score > 0)
		return -1;
	else
		return 1;
}

void print_info(struct student *data, int cnt)
{
	for (int i = 0; i < cnt; i++)
		printf("%s %.0f\n", data[i].name, data[i].score);
}