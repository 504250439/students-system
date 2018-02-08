#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>
#define mm 1000

int num = 0;
int i = 0;
char s[30], g[30];

struct student
{
	int id;//学号
	char name[20];
	char sex[3];//性别
	int age;
	char major[20];//专业
}students[mm];



void menu();//菜单
void write();//写入文件
void input();//输入学生信息
void all();
void find();
void findid();
void findname();
void out();
void charge();



int main()
{
	system("md E:\students");
	system("cls");
	
	menu();
	return 0;
}


//主菜单
void menu()
{
	int choose;
	printf("************************************************欢迎使用学生管理系统*****************************************\n");
	printf("\t\t\t\t 1.录入学生信息 \n");
	printf("\t\t\t\t 2.查看所有学生信息 \n");
	printf("\t\t\t\t 3.学生信息查找 \n");
	printf("\t\t\t\t 4.修改学生信息 \n");
	printf("\t\t\t\t 5.删除学生信息 \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t2018.1.30.版本1.0\n");
	printf("**********************************************************************************************************\n");
	printf("请选择你要的服务\n");

	scanf("%d", &choose);
	switch (choose)				//选出服务并进行跳转
	{
	case 1:
		input();
		break;
	case 2:
		all();
		break;
	case 3:
		find();
		break;
	case 4:
		charge();
		break;
	case 5:
		out();
		break;

	}
}

void input()
{
	while (1)

	{
		system("cls");
		printf("请输入学号:");

		scanf("%d", &students[num].id);

		getchar();



		printf("请输入姓名:");

		scanf("%s", &students[num].name);

		getchar();


		printf("请输入年龄:");

		scanf("%d", &students[num].age);

		getchar();



		printf("请输入性别:");

		scanf("%s", &students[num].sex);

		getchar();


		printf("请输入专业:");

		scanf("%s", &students[num].major);

		getchar();

		num++;


		write(); //写入文件

		printf("写入成功\n");

		printf("是否继续?(y/n)");

		if (getchar() == 'n')

		{
			break;

		}

	}
	system("cls");
	menu();
}

void write()
{
	FILE *fp;
	
	
	sprintf(s, "E:\\students\\%d.txt", students[i].id);

	if ((fp = fopen(s, "w+")) == NULL)
	{
		printf("不能打开文件!\n");

		return;
	}

	if (fwrite(&students[i], sizeof(struct student), 1, fp) != 1)
	{

		printf("写入文件错误!\n");

	}


	fclose(fp);
	i++;
	return;
}


void all()
{
	int i = 0;
	FILE *fp;
	long handle;
	struct _finddata_t fileinfo;

	system("cls");

	if ((handle = _findfirst("E:\\students\\*.txt", &fileinfo)) == -1L)
	{
		printf("现在还没有学生\n");
		menu();
	}
	else
	{
		printf("学号\t姓名\t性别\t年龄\t专业\n");
		do
		{
			sprintf(s, "E:\\students\\%s" ,fileinfo.name);
			if ((fp = fopen(s, "r+")) == NULL)
			{
				printf("无法打开文件\n");
				return;
			}
	
			fread(&students[i], sizeof(struct student), 1, fp);
			printf("%d\t%s\t%s\t%d\t%s\t\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].major);
		}while (_findnext(handle, &fileinfo) == 0);
	}

	printf("按任意键返回菜单\n");
	getchar();
	getchar();
	system("cls");
	menu();

}


void find()
{
	int s = 0;

	
	printf("1.通过学号查找\n");
	printf("2.通过姓名查找\n");
	scanf("%d", &s);

	switch (s)
	{
	case 1:
		findid();
		break;
	case 2 :
		findname();
		break;
}

}

void findid()
{
	FILE *fp;
	
	system("cls");
	
	printf("请输入学号 : ");
	scanf("%s", g);
	
	sprintf(s, "E:\\students\\%s.txt", g);

	if ((fp = fopen(s, "r+")) == NULL)
		{
			printf("没有这个学生\n");
			return;
		}
	
	fread(&students[i], sizeof(struct student), 1, fp);

	printf("学号\t姓名\t性别\t年龄\t专业\n");
	printf("%d\t%s\t%s\t%d\t%s\t\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].major);

	fclose(fp);

	


}


void findname()
{
	FILE *fp;
	long handle;
	struct _finddata_t fileinfo;
	char a[30];

	system("cls");



	printf("请输入名字\n");
	scanf("%s", a);

	if ((handle = _findfirst("E:\\students\\*.txt", &fileinfo)) == -1L)
	{
		printf("现在还没有学生\n");
		menu();
	}
	else
	{
		do
		{
			sprintf(s, "E:\\students\\%s", fileinfo.name);
			if ((fp = fopen(s, "r+")) == NULL)
			{
				printf("无法打开文件\n");
				return;
			}
			fread(&students[i], sizeof(struct student), 1, fp);
			if (strcmp(a, students[i].name) == 0)
			{
				printf("学号\t姓名\t性别\t年龄\t专业\n");
				printf("%d\t%s\t%s\t%d\t%s\t\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].major);
				break;
			}
		} while (_findnext(handle, &fileinfo) == 0);
	}




}




void out()
{
	FILE *fp;
	int t;
	system("cls");
	printf("请输入你想要删除学生的学号\n");
	scanf("%s", g);
	sprintf(s, "E:\\students\\%s.txt", g);
	if ((fp = fopen(s, "r+")) == NULL)
	{
		printf("没有这个学生\n");
		return;
	}
	fread(&students[i], sizeof(struct student), 1, fp);
	printf("学号\t姓名\t性别\t年龄\t专业\n");
	printf("%d\t%s\t%s\t%d\t%s\t\n\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].major);
	fclose(fp);
	
	printf("你确定要删除这位学生吗:1.确定,2.否\n");
	scanf("%d", &t);
	if (t == 2)
	{
		system("cls");
		return;
	}
	if (remove(s))
	{
		printf("删除文件失败\n");
		return;
	}
	else
		printf("删除成功\n");

}


void charge()
{
	int y;
	FILE *fp;
	system("cls");
	printf("请输入学号 : ");
	scanf("%s", g);
	sprintf(s, "E:\\students\\%s.txt", g);
	if ((fp = fopen(s, "r+")) == NULL)
	{
		printf("没有这个学生\n");
		return;
	}
	fread(&students[i], sizeof(struct student), 1, fp);
	printf("学号\t姓名\t性别\t年龄\t专业\n");
	printf("%d\t%s\t%s\t%d\t%s\t\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].major);
	
	printf("请输出你要修改的值\n");
	
	printf("\n1.修改学生学号\n");
	printf("2.修改学生姓名\n");
	printf("3.修改学生性别\n");
	printf("4.修改学生年龄\n");
	printf("5.修改学生专业\n");
	printf("按任意其他健退出\n");
	scanf("%d", &y);
	switch (y)
	{
	case 1:
		printf("请输入新的学号 : ");
		scanf("%d", &students[i].id);
		break;
	case 2:
		printf("请输入新的姓名 : ");
		scanf("%s", students[i].name);

		break;
	case 3:
		printf("请输入新的性别 : ");
		scanf("%s", students[i].sex);
		break;
	case 4:
		printf("请输入新的年龄 : ");
		scanf("%d", &students[i].age);
		break;
	case 5:
		printf("请输入新的专业 : ");
		scanf("%s", students[i].major);
		break;
	}
	write();
	menu();
}


