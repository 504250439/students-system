#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int num = 0;


struct student
{
	int id;//学号
	char name[20];
	char sex[3];//性别
	int age;
	char major[20];//专业
	struct student *next;
};
struct student students[1000];//学生人数



void menu( );//菜单
void write();//写入文件
void input();//输入学生信息
void all();//查看所有学生信息
void find();//寻找学生
void findid();//通过学号找学生
void findname();//通过名字找学生
void charge(int i );//修改学生信息
void out(int i);//删除学生信息



int main()
{
	FILE *fp;
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
	switch(choose)				//选出服务并进行跳转
	{
	case 1 :
		input();
		break;
	case 2:
		all();
		break; 
	case 3:
		find();
		break;
	case 4:
		printf("\n\n直接找出学生便可以修改\n");
		find();
		break;
	case 5:
		printf("\n\n直接找出学生便可以删除\n");
		find();
		break;
	}
}



//学生信息的写入
void write()
{
	FILE *fp;
	int i; 
	if ((fp = fopen("\E:\students.txt", "w+")) == NULL) //防止无法打开文件后崩溃
	{
		printf("不能打开文件!\n");

		return;
	}


	for (i = 0; i<num; i++) //写入学生信息

	{

		if (fwrite(&students[i], sizeof(struct student), 1, fp) != 1)
		{

			printf("写入文件错误!\n");

		}

	}
	fclose(fp);

}





//遍历全部学生
void all()
{
	FILE *fp;
	
	if ((fp = fopen("\E:\students.txt", "r")) == NULL)
	{
		printf("无法打开文件\n");
		return;
	}


	
	printf("学号\t姓名\t性别\t年龄\t专业\n");
	for (int i = 0; i < 1000; i++)		//输出所有学生信息

	{

		

		fread(&students[i], sizeof(struct student), 1, fp);

		if (students[i].id == 0)
			break;

		printf("-------------------------------------------------------------\n");

		printf("%d\t%s\t%s\t%d\t%s\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].major);

	}

	fclose(fp);

	menu();
	 
}



//输入学生信息
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
		
		
		
		printf("是否继续?(y/n)");

		if (getchar() == 'n')

		{
			break;
			
		}

	}
	system("cls");
	menu();
}



//找出学生
void find()
{
	int i = 1;
	
	FILE *fp;

	if ((fp = fopen("\E:\students.txt", "rb")) == NULL)
	{
		printf("无法打开文件\n");
		return;
	}


	//先打开文件并进行遍历,并写入内存中
	for (int i = 0; i < 1000; i++)

	{

		fread(&students[i], sizeof(struct student), 1, fp);

		if (students[i].id == 0)
			break;

	}

	fclose(fp);




	printf("-------------------------------------------------------------\n\n");
	printf("1.通过学号查找\n");
	printf("2.通过姓名查找\n");
	printf("3.返回菜单\n");
	
	scanf("%d", &i);

	if (i == 1)
	{
		findid();
	}
	else if (i == 2)
	{
		findname();
	}
	else
		menu();

}



//用学号来找学生
void findid()
{
	int i,s;
	int g = 0 ,number=0;
	FILE *fp;

	if ((fp = fopen("\E:\students.txt", "rb+")) == NULL)
	{
		printf("无法打开文件\n");
		return;
	}
	
	system("cls");
	printf("请输入学号 : ");
	scanf("%d", &s);
	for ( i = 0; i < 1000; i++)
	{
		

		if (s == students[i].id)
		{
	
			printf("学号\t姓名\t性别\t年龄\t专业\n");
			printf("%d\t%s\t%s\t%d\t%s\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].major);
			g++;
			number = i;
		}
	}
	if (g == 0)
		printf("没有这个学生\n");
	
	fclose(fp);

	getchar();

	printf("\n1.继续查找?\n");
	printf("\n2.修改学生信息\n");
	printf("\n\n3.删除学生信息\n");
	printf("\n\n4.返回菜单\n");

	scanf("%d", &g);

	switch (g)
	{
	case 1:
		find();
		break;
	case 2:
		charge(number);
		break;
	case 3:
		out(number);
		break;
	case 4:
		system("cls");
		menu();
		break;
	}

}


//用姓名来找学生
void findname()
{
	int i,g=0;
	int number=0;
	char s[20];
	FILE *fp;

	if ((fp = fopen("\E:\students.txt", "rb")) == NULL)
	{
		printf("无法打开文件\n");
		return;
	}

	system("cls");
	printf("请输入姓名 : ");
	scanf("%s", s);

	for (i = 0; i < 1000; i++)
	{


		if (strcmp(s,students[i].name)==0)
		{
			printf("学号\t姓名\t性别\t年龄\t专业\n");
			printf("%d\t%s\t%s\t%d\t%s\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].major);
			g++;
			number = i;
		}
		if (students[i].id == 0)
			break;

	}
	if (g == 0)
		printf("没有这个学生\n");

	fclose(fp);

	printf("\n\n1.继续查找?\n");
	printf("\n\n2.修改学生信息\n");
	printf("\n\n3.删除学生信息\n");
	printf("\n\n4.返回菜单\n");

	scanf("%d", &g);

	switch (g)
	{
	case 1:
		find();
		break;
	case 2:
		charge(number);
		break;
	case 3:
		out(number);
		break;
	case 4:
		system("cls");
		menu();
		break;
	}

}



//修改学生信息
void charge(int i)
{
	int w,g=0;

	FILE *fp;

	if ((fp = fopen("\E:\students.txt", "w+")) == NULL)
	{
		printf("无法打开文件\n");
		return;
	}

	system("cls");
	
	printf("-------------------------------------------------------------\n");
	printf("学号\t姓名\t性别\t年龄\t专业\n");
	printf("%d\t%s\t%s\t%d\t%s\n\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].major);
	printf("-------------------------------------------------------------\n");

	printf("\n1.修改学生学号\n");
	printf("2.修改学生姓名\n");
	printf("3.修改学生性别\n");
	printf("4.修改学生年龄\n");
	printf("5.修改学生专业\n");
	printf("按任意其他健退出\n");
	scanf("%d", &w);

	switch (w)
	{
	case 1 :
		printf("请输入新的学号 : ");
		scanf("%d", &students[num+1].id);
		break;
	case 2:
		printf("请输入新的姓名 : ");
		scanf("%s", students[num + 1].name);

		break;
	case 3:
		printf("请输入新的性别 : ");
		scanf("%s", students[num + 1].sex);
		break;
	case 4:
		printf("请输入新的年龄 : ");
		scanf("%d", &students[i].age);
		break;
	case 5:
		printf("请输入新的专业 : ");
		scanf("%s", students[num + 1].major);
		break;
	default:
		break;
	}
	
	write();
	num++;
	printf("修改成功\n");

	printf("\n1.继续修改\n");
	printf("\n2.返回菜单\n");

	scanf("%d", &g);

	switch (g)
	{
	case 1:
		charge(i);
		break;
	case 2:
		system("cls");
		menu();
		break;
	}
}



//删除学生
void out(int i)
{

	FILE *fp;

	if ((fp = fopen("\E:\students.txt", "w+")) == NULL)
	{
		printf("无法打开文件\n");
		return;
	}
	
	for (i; i < 1000; i++)    //用后一个学生覆盖前一个学生,实现删除;
	{
		students[i] = students[i + 1];
		if (students[i + 1].id == 0)
			break;

	}
	fclose(fp);
	printf("seccesssssssssssssssssssss\n");
	menu();
}