#include <stdio.h>
#include <stdlib.h>
#define clear_stdin() fpurge(stdin)
#define MAX 100
struct student;
void get_info(struct student *); // 从键盘读入学生信息
int get_choice(void); // 从键盘读入用户选项
void sort_info(struct student *, int); // 将学生信息结构体数组按成绩顺序重排
static int cmp(const void *, const void *);
void print_student_info(struct student *, int, float); // 在数组中查询对应成绩学生的信息并输出，若未查询到，则提示用户没有相应结果
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
		puts("2. 查找成绩为某分数的学生");
		puts("3. 退出");
		switch(get_choice())
		{
			case '1':
				sort_info(data, student_cnt);
				print_info(data, student_cnt);
				break;
			case '2':
				sort_info(data, student_cnt);
				float score;
				printf("输入想查询的成绩：");
				if (scanf("%f", &score) == 0)
				{
					clear_stdin();
					goto label;
				}
				clear_stdin();
				print_student_info(data, student_cnt, score);
				break;
			case '3':
				exit(0);
			default:
				label:
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
	if (((struct student *)stu_a)->score - ((struct student *)stu_b)->score > 1e-6)
		return -1;
	else if (((struct student *)stu_a)->score - ((struct student *)stu_b)->score < -1e-6)
		return 1;
	else
		return 0;
}

void print_student_info(struct student *data, int cnt, float score)
{
	struct student *tgt, temp;
	temp.score = score;
	if ((tgt = bsearch(&temp, data, cnt, sizeof(struct student), cmp)) == NULL)
		puts("找不到该分数的学生。");
	else
		printf("%s %.1f\n", tgt->name, tgt->score);
}

void print_info(struct student *data, int cnt)
{
	for (int i = 0; i < cnt; i++)
		printf("%s %.1f\n", data[i].name, data[i].score);
}