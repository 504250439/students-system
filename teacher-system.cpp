#include<stdio.h>
#include<io.h>
#include<stdlib.h>
#include<string.h>


void menu();					//菜单
void add();						//添加信息
void checkall();				//查看全部
void query();					//查找教师
void amend(int a);				//修改信息
void del(int a);				//删除信息
void sort();					//排序


struct Teacher
{
	int id;
	char name[10];
	char position[20];
	char sex[4];
	char classname1[20];
	char semester1[6];
	char nature1[6];
	char effect1[6];
	char classname2[20];
	char semester2[6];
	char nature2[6];
	char effect2[6];
	char classname3[20];
	char semester3[6];
	char nature3[6];
	char effect3[6];
	int score;
}teacher[100];




void menu()
{
	int choose;
	system("cls");
	printf("************************************************欢迎使用教师管理系统*****************************************\n");
	printf("\t\t\t\t 1.录入教师信息\t\t 2.查看所有教师信息 \n\n");
	printf("\t\t\t\t 3.教师信息查找\t\t 4.修改教师信息 \n\n");
	printf("\t\t\t\t 5.删除教师信息\t\t 6.教师排序 \n\n");
	printf("\t\t\t\t\t 7.退出程序 \n");
	printf("**********************************************************************************************************\n");
	printf("\t\t\t\t\t\t请选择你要的服务\n");


	scanf("%d", &choose);
	switch (choose)				//选出服务并进行跳转
	{
	case 1:
		add();
		break;
	
	case 2:
		checkall();
		break;

	case 3:
		query();
		break;
	case 4:
		query();
		break;
	case 5:
		query();
		break;
	case 6:
		sort();
		break;
	case 7:
		return;
		
	}
}


void add()
{
	FILE *fp;
	int i=0,num=0;
	char sign = 'y';			//判断继续信号
	system("cls");
	Teacher ter[200];

	

	while (sign != 'n'&&sign != 'N')
	{
		printf("************************************************添加教师信息*****************************************\n");
		printf("\t\t\t\t\t\t工号:");
		scanf("%d" , &ter[i].id);
		printf("\t\t\t\t\t\t姓名:");
		scanf("%s" , ter[i].name);
		printf("\t\t\t\t\t\t职位:");
		scanf("%s" , ter[i].position);
		
		printf("\t\t\t\t\t\t性别:");
		scanf("%s" ,ter[i].sex);
		while (strcmp(ter[i].sex, "男") != 0 && strcmp(ter[i].sex, "女") != 0)
		{
			printf("t\t\t\t\t性别只限男女\n");
			printf("\t\t\t\t\t\t性别:");
			scanf("%s", ter[i].sex);
		}
		printf("\t\t\t\t\t\t课程名称1:");
		scanf("%s" , ter[i].classname1);
		printf("\t\t\t\t\t\t开学学期1:");
		scanf("%s" , ter[i].semester1);
		printf("\t\t\t\t\t\t课程性质1:");
		scanf("%s" , ter[i].nature1);
		printf("\t\t\t\t\t\t教学效果1:");
		scanf("%s" , ter[i].effect1);
		
		printf("\t\t\t\t\t\t课程姓名2:");
		scanf("%s", ter[i].classname2);
		printf("\t\t\t\t\t\t开学学期2:");
		scanf("%s", ter[i].semester2);
		printf("\t\t\t\t\t\t课程性质2:");
		scanf("%s", ter[i].nature2);
		printf("\t\t\t\t\t\t教学效果2:");
		scanf("%s", ter[i].effect2);
		
		printf("\t\t\t\t\t\t课程姓名3:");
		scanf("%s", ter[i].classname3);
		printf("\t\t\t\t\t\t开学学期3:");
		scanf("%s", ter[i].semester3);
		printf("\t\t\t\t\t\t课程性质3:");
		scanf("%s", ter[i].nature3);
		printf("\t\t\t\t\t\t教学效果3:");
		scanf("%s", ter[i].effect3);
		
		printf("\t\t\t\t\t\t综合评分:");
		scanf("%d", &ter[i].score);
		while (ter[i].score < 0 || ter[i].score>100)
		{
			printf("评分只能为0-100\n");
			printf("\t\t\t\t\t\t综合评分:");
			scanf("%d", &ter[i].score);
		}


		
		printf("\t\t\t\t\t\t是否继续添加?(y/n)");
		scanf("\t\t\t\t\t\t%c", &sign);
		i=i+1;
		system("cls");
	}

	if ((fp = fopen("E:\\students\\teacher.txt", "a")) == NULL)			   
	{
		printf("cannot open the files\n");
		system("pause");
		return;                                         
	}

	for (i = 0; i < num; i++)				//写入文件
	{
		fprintf(fp, "%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %d\n", ter[i].id, ter[i].name, ter[i].position, ter[i].sex, ter[i].classname1, ter[i].semester1, ter[i].nature1, ter[i].effect1, ter[i].classname2, ter[i].semester2, ter[i].nature2, ter[i].effect2, ter[i].classname3, ter[i].semester3, ter[i].nature3, ter[i].effect3, ter[i].score);
	}
	fclose(fp);
	printf("\t\t\t\t\t\t写入成功(输入任何返回菜单)");
	getchar();
	menu();
}


//查看全部教师记录
void checkall()
{
	FILE *fp;
	int i = 0, num = 0;
	
	if ((fp = fopen("E:\\students\\teacher.txt", "r")) == NULL)
	{
		printf("cannot open the files\n");
		system("pause");
		return;
	}


	while (fscanf(fp, "%d%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%d", &teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1,  teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2, teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3, &teacher[i].score) != EOF)
	{
		i++;
		num = num + 1;
	}

	system("cls");
	
	
	printf("************************************************所有教师信息*****************************************\n");
	for (i = 0; i < num; i++)
	{
		printf("-------------------------------------------------------------------------------------\n");

		printf("\t\t\t工号\t\t姓名\t\t职位\t\t性别\t\t综合评分\n ");
		printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%d\n", teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex,teacher[i].score);
		printf("\t\t\t课程名称\t开学学期\t课程性质\t教学效果 \n");
		printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1);
		printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2);
		printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3);


	}
	printf("---------------------------------------------------------------------------------------\n");

	printf("输入任意键返回菜单\n");
	system("pause");
	menu();


}




//查找教师
void query()
{
	FILE *fp;
	int m, checkid;
	int i = 0, num = 0, a = 0;
	char sign = 'n';
	char checkname[10];						//查找名称
	char checkclass[20];					//查找课程名称

	system("cls");
	printf("\t\t\t\t请选择查询方式:\n");
	printf("\t\t\t\t\t 1.姓名查询 \n");
	printf("\t\t\t\t\t 2.工号查询 \n");
	printf("\t\t\t\t\t 3.课程查询 \n");
	scanf("\t\t\t\t\t%d", &m);

	if ((fp = fopen("E:\\students\\teacher.txt", "r")) == NULL)			//判断文件情况
	{
		printf("cannot open the files\n");
		system("pause");
		return;
	}


	while (fscanf(fp, "%d%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%d", &teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1, teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2, teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3, &teacher[i].score) != EOF)
	{
		i++;
		num = num + 1;
	}

	if (m == 1)															//用姓名查找
	{
		printf("\t\t\t\t你要查找老师的姓名:");
		scanf("\t\t\t\t%s", checkname);
		for (a = 0; a< num; a++)
		{
			if (strcmp(checkname, teacher[a].name) == 0 )
			{
				i=a;
			}
		}
		if (i != num)
		{
			printf("---------------------------------------------------------------------------------------\n");
			printf("\t\t\t工号\t\t姓名\t\t职位\t\t性别\t\t综合评分\n ");
			printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%d\n", teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].score);
			printf("\t\t\t课程名称\t开学学期\t课程性质\t教学效果 \n");
			printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1);
			printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2);
			printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3);
			printf("---------------------------------------------------------------------------------------\n");
		}
		else
		{
			printf("\n\t\t\t\t没有此教师\n");
			
		}

	}


	if (m == 2)															//用工号查找
	{
		printf("\t\t\t\t你要查找老师的工号:");
		scanf("\t\t\t\t%d", &checkid);
		
		for (a = 0; a< num; a++)
		{
			if (teacher[a].id == checkid)
			{
				i = a;
			}
		}
		if (i != num)
		{
			printf("---------------------------------------------------------------------------------------\n");
			printf("\t\t\t工号\t\t姓名\t\t职位\t\t性别\t\t综合评分\n ");
			printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%d\n", teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].score);
			printf("\t\t\t课程名称\t开学学期\t课程性质\t教学效果 \n");
			printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1);
			printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2);
			printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3);
			printf("---------------------------------------------------------------------------------------\n");
		}
		else
		{
			printf("\n\t\t\t\t没有此教师\n");

		}


	}

	if (m == 3)															//用课程名称进行查找
	{
		printf("\t\t\t\t你要查找老师的课程名称:");
		scanf("\t\t\t\t%s", checkclass);
		for (a = 0; a< num; a++)
		{
			if (strcmp(teacher[a].classname1,checkclass)==0)
			{
				i = a;
				printf("---------------------------------------------------------------------------------------\n");
				printf("\t\t\t工号\t\t姓名\t\t职位\t\t性别\t\t综合评分\n ");
				printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%d\n", teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].score);
				printf("\t\t\t课程名称\t开学学期\t课程性质\t教学效果 \n");
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1);
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2);
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3);
				printf("---------------------------------------------------------------------------------------\n");
			}
		}
		if (i == num)
		{
			printf("\n\t\t\t\t没有此教师\n");
		}

	}

	fclose(fp);
	printf("\n1.添加教师信息\t\t");
	printf("2.修改教师信息\t\t");
	printf("3.删除教师信息\t\t");
	printf("4.查看所有教师信息\t\t");

	printf("5.返回菜单");
	scanf("%d", &a);
	switch (a)				
	{
	case 1:
		add();
		break;
	case 2:
		amend(i);
		break;
	case 3:
		del(i);
		break;
	case 4:
		checkall();
		break;
	case 5:
		menu();
		break;
	}
}



//修改教师信息
void amend(int a )
{
	FILE *fp , *fp2;
	Teacher amendt;
	int num = 0,i=0;
	
	if ((fp = fopen("E:\\students\\teacher.txt", "r")) == NULL)
	{
		printf("cannot open the files\n");
		system("pause");
		return;
	}
	if ((fp2 = fopen("E:\\students\\teacher1.txt", "w")) == NULL)					//创建teacher1  最后替换teacher.txt
	{
		printf("cannot open the files\n");
		system("pause");
		return;
	}

	while (fscanf(fp, "%d%s%s%s%s%s%s%s%d", &teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1, &teacher[i].score) != EOF)
	{
		num = num + 1;
		i = i + 1;
	}


	printf("---------------------------------------------------------------------------------------\n");
	printf("\t\t\t工号\t\t姓名\t\t职位\t\t性别\t\t综合评分\n ");
	printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%d\n", teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].score);
	printf("\t\t\t课程名称\t开学学期\t课程性质\t教学效果 \n");
	printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1);
	printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2);
	printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3);
	printf("---------------------------------------------------------------------------------------\n");

	printf("\t\t\t\t\t\t请填入修改的信息\n");
	printf("\t\t\t\t\t\t工号:");
	scanf("\t\t\t\t\t\t%d", &amendt.id);
	printf("\t\t\t\t\t\t姓名");
	scanf("\t\t\t\t\t\t%s", amendt.name);
	printf("\t\t\t\t\t\t职位");
	scanf("\t\t\t\t\t\t%s", amendt.position);
	printf("\t\t\t\t\t\t性别");
	scanf("\t\t\t\t\t\t%s", amendt.sex);
	printf("\t\t\t\t\t\t课程姓名1");
	scanf("\t\t\t\t\t\t%s", amendt.classname1);
	printf("\t\t\t\t\t\t开学学期1");
	scanf("\t\t\t\t\t\t%s", amendt.semester1);
	printf("\t\t\t\t\t\t课程性质1");
	scanf("\t\t\t\t\t\t%s", amendt.nature1);
	printf("\t\t\t\t\t\t教学效果1");
	scanf("\t\t\t\t\t\t%s", amendt.effect1);
	
	printf("\t\t\t\t\t\t课程姓名2:");
	scanf("%s", amendt.classname2);
	printf("\t\t\t\t\t\t开学学期2:");
	scanf("%s", amendt.semester2);
	printf("\t\t\t\t\t\t课程性质2:");
	scanf("%s", amendt.nature2);
	printf("\t\t\t\t\t\t教学效果2:");
	scanf("%s", amendt.effect2);
	printf("\t\t\t\t\t\t课程姓名3:");
	scanf("%s", amendt.classname3);
	
	printf("\t\t\t\t\t\t开学学期3:");
	scanf("%s", amendt.semester3);
	printf("\t\t\t\t\t\t课程性质3:");
	scanf("%s", amendt.nature3);
	printf("\t\t\t\t\t\t教学效果3:");
	scanf("%s", amendt.effect3);
	
	printf("\t\t\t\t\t\t综合评分:");
	scanf("%d", &amendt.score);
	
	
	i = 0;
	while (i < num)
	{
		if (teacher[a].id != teacher[i].id)
		{
			fprintf(fp2, "%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %d", &teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1, teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2, teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3, &teacher[i].score);

		}
		i = i + 1;
	}

	fprintf(fp2, "%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %d", &teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1, teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2, teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3, &teacher[i].score);

	fclose(fp2);
	fclose(fp);
	remove("E:\\students\\teacher.txt");
	rename("E:\\students\\teacher1.txt", "E:\\students\\teacher.txt");		//替换为源文件

	printf("修改成功\n");
	system("pause");
	menu();
}




//删除教师信息
void del(int a)
{
	FILE *fp, *fp2;
	int i = 0,num=0;
	if ((fp = fopen("E:\\students\\teacher.txt", "r")) == NULL)
	{
		printf("cannot open the files\n");
		system("pause");
		return;
	}
	if ((fp2 = fopen("E:\\students\\teacher1.txt", "w")) == NULL)
	{
		printf("cannot open the files\n");
		system("pause");
		return;
	}

	while (fscanf(fp, "%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %d", &teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1, teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2, teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3, &teacher[i].score) != EOF)
	{
		num = num + 1;
		i = i + 1;
	}
	i = 0;
	while (i < num)
	{
		if (teacher[a].id != teacher[i].id)
		{
			fprintf(fp2, "%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %d", &teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1, teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2, teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3, &teacher[i].score);
		}
		i = i + 1;
	}

	fclose(fp2);
	fclose(fp);
	remove("E:\\students\\teacher.txt");
	rename("E:\\students\\teacher1.txt", "E:\\students\\teacher.txt");
	
	printf("删除成功\n");
	system("pause");
	menu();
}




//教师排序
void sort()
{
	FILE *fp;
	int num = 0, m,j;
	int i = 0;
	struct Teacher temp;
	system("cls");
	if ((fp = fopen("E:\\students\\teacher.txt", "r")) == NULL)
	{
		printf("cannot open the files\n");
		system("pause");
		return;
	}
	while (fscanf(fp, "%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %d", &teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1, teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2, teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3, &teacher[i].score) != EOF)
	{
		num = num + 1;
		i = i + 1;
	}


	printf("1.按工号降序来排\t 2.按工号升序来排\n");
	printf("3.按综合评分降序来排\t 4.按综合评分升序来排\n");
	scanf("%d", &m);



	if (m == 1||m==2)											//按工号查询
	{
		for (i = 0; i < num; i++)
		{
			for (j = 0; j < i; j++)
			{
				if (teacher[i].id > teacher[j].id)
				{
					temp = teacher[i];
					teacher[i] = teacher[j];
					teacher[j] = temp;
				}
			}
		}

		

		printf("---------------------------------------------------------------------------------------\n");
		printf("工号\t姓名\t职位\t性别\t课程名称\t开学学期\t课程性质\t教学效果\t教学成绩\n");

		if (m == 1)
		{
			for (i = 0; i < num; i++)
			{
				printf("---------------------------------------------------------------------------------------\n");
				printf("\t\t\t工号\t\t姓名\t\t职位\t\t性别\t\t综合评分\n ");
				printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%d\n", teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].score);
				printf("\t\t\t课程名称\t开学学期\t课程性质\t教学效果 \n");
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1);
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2);
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3);
				printf("---------------------------------------------------------------------------------------\n");
			}
		}
		if (m == 2)
		{
			for (i = num - 1; i >= 0; i--)
			{
				printf("---------------------------------------------------------------------------------------\n");
				printf("\t\t\t工号\t\t姓名\t\t职位\t\t性别\t\t综合评分\n ");
				printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%d\n", teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].score);
				printf("\t\t\t课程名称\t开学学期\t课程性质\t教学效果 \n");
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1);
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2);
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3);
				printf("---------------------------------------------------------------------------------------\n");
			}
		}

	}


	if (m == 3||m==4)												//按综合成绩查询
	{
		for (i = 0; i < num; i++)
		{
			for (j = 0; j < i; j++)
			{
				if (teacher[i].score > teacher[j].score)
				{
					temp = teacher[i];
					teacher[i] = teacher[j];
					teacher[j] = temp;
				}
			}
		}

		
	
		if (m == 3)
		{
			for (i = 0; i < num; i++)
			{
				printf("---------------------------------------------------------------------------------------\n");
				printf("\t\t\t工号\t\t姓名\t\t职位\t\t性别\t\t综合评分\n ");
				printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%d\n", teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].score);
				printf("\t\t\t课程名称\t开学学期\t课程性质\t教学效果 \n");
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1);
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2);
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3);
				printf("---------------------------------------------------------------------------------------\n");
			
			}
		}
		if (m == 4)
		{
			for (i = num - 1; i >= 0; i--)
			{
				printf("---------------------------------------------------------------------------------------\n");
				printf("\t\t\t工号\t\t姓名\t\t职位\t\t性别\t\t综合评分\n ");
				printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%d\n", teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].score);
				printf("\t\t\t课程名称\t开学学期\t课程性质\t教学效果 \n");
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1);
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2);
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3);
				printf("---------------------------------------------------------------------------------------\n");
			}
		}

	}


	printf("输入任意键返回菜单\n");
	system("pause");
	system("cls");
	menu();

}


int main()
{

	menu();

	return 0;
}