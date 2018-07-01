#include<stdio.h>
#include<io.h>
#include<stdlib.h>
#include<string.h>


void menu();					//�˵�
void add();						//�����Ϣ
void checkall();				//�鿴ȫ��
void query();					//���ҽ�ʦ
void amend(int a);				//�޸���Ϣ
void del(int a);				//ɾ����Ϣ
void sort();					//����


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
	printf("************************************************��ӭʹ�ý�ʦ����ϵͳ*****************************************\n");
	printf("\t\t\t\t 1.¼���ʦ��Ϣ\t\t 2.�鿴���н�ʦ��Ϣ \n\n");
	printf("\t\t\t\t 3.��ʦ��Ϣ����\t\t 4.�޸Ľ�ʦ��Ϣ \n\n");
	printf("\t\t\t\t 5.ɾ����ʦ��Ϣ\t\t 6.��ʦ���� \n\n");
	printf("\t\t\t\t\t 7.�˳����� \n");
	printf("**********************************************************************************************************\n");
	printf("\t\t\t\t\t\t��ѡ����Ҫ�ķ���\n");


	scanf("%d", &choose);
	switch (choose)				//ѡ�����񲢽�����ת
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
	char sign = 'y';			//�жϼ����ź�
	system("cls");
	Teacher ter[200];

	

	while (sign != 'n'&&sign != 'N')
	{
		printf("************************************************��ӽ�ʦ��Ϣ*****************************************\n");
		printf("\t\t\t\t\t\t����:");
		scanf("%d" , &ter[i].id);
		printf("\t\t\t\t\t\t����:");
		scanf("%s" , ter[i].name);
		printf("\t\t\t\t\t\tְλ:");
		scanf("%s" , ter[i].position);
		
		printf("\t\t\t\t\t\t�Ա�:");
		scanf("%s" ,ter[i].sex);
		while (strcmp(ter[i].sex, "��") != 0 && strcmp(ter[i].sex, "Ů") != 0)
		{
			printf("t\t\t\t\t�Ա�ֻ����Ů\n");
			printf("\t\t\t\t\t\t�Ա�:");
			scanf("%s", ter[i].sex);
		}
		printf("\t\t\t\t\t\t�γ�����1:");
		scanf("%s" , ter[i].classname1);
		printf("\t\t\t\t\t\t��ѧѧ��1:");
		scanf("%s" , ter[i].semester1);
		printf("\t\t\t\t\t\t�γ�����1:");
		scanf("%s" , ter[i].nature1);
		printf("\t\t\t\t\t\t��ѧЧ��1:");
		scanf("%s" , ter[i].effect1);
		
		printf("\t\t\t\t\t\t�γ�����2:");
		scanf("%s", ter[i].classname2);
		printf("\t\t\t\t\t\t��ѧѧ��2:");
		scanf("%s", ter[i].semester2);
		printf("\t\t\t\t\t\t�γ�����2:");
		scanf("%s", ter[i].nature2);
		printf("\t\t\t\t\t\t��ѧЧ��2:");
		scanf("%s", ter[i].effect2);
		
		printf("\t\t\t\t\t\t�γ�����3:");
		scanf("%s", ter[i].classname3);
		printf("\t\t\t\t\t\t��ѧѧ��3:");
		scanf("%s", ter[i].semester3);
		printf("\t\t\t\t\t\t�γ�����3:");
		scanf("%s", ter[i].nature3);
		printf("\t\t\t\t\t\t��ѧЧ��3:");
		scanf("%s", ter[i].effect3);
		
		printf("\t\t\t\t\t\t�ۺ�����:");
		scanf("%d", &ter[i].score);
		while (ter[i].score < 0 || ter[i].score>100)
		{
			printf("����ֻ��Ϊ0-100\n");
			printf("\t\t\t\t\t\t�ۺ�����:");
			scanf("%d", &ter[i].score);
		}


		
		printf("\t\t\t\t\t\t�Ƿ�������?(y/n)");
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

	for (i = 0; i < num; i++)				//д���ļ�
	{
		fprintf(fp, "%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %d\n", ter[i].id, ter[i].name, ter[i].position, ter[i].sex, ter[i].classname1, ter[i].semester1, ter[i].nature1, ter[i].effect1, ter[i].classname2, ter[i].semester2, ter[i].nature2, ter[i].effect2, ter[i].classname3, ter[i].semester3, ter[i].nature3, ter[i].effect3, ter[i].score);
	}
	fclose(fp);
	printf("\t\t\t\t\t\tд��ɹ�(�����κη��ز˵�)");
	getchar();
	menu();
}


//�鿴ȫ����ʦ��¼
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
	
	
	printf("************************************************���н�ʦ��Ϣ*****************************************\n");
	for (i = 0; i < num; i++)
	{
		printf("-------------------------------------------------------------------------------------\n");

		printf("\t\t\t����\t\t����\t\tְλ\t\t�Ա�\t\t�ۺ�����\n ");
		printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%d\n", teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex,teacher[i].score);
		printf("\t\t\t�γ�����\t��ѧѧ��\t�γ�����\t��ѧЧ�� \n");
		printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1);
		printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2);
		printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3);


	}
	printf("---------------------------------------------------------------------------------------\n");

	printf("������������ز˵�\n");
	system("pause");
	menu();


}




//���ҽ�ʦ
void query()
{
	FILE *fp;
	int m, checkid;
	int i = 0, num = 0, a = 0;
	char sign = 'n';
	char checkname[10];						//��������
	char checkclass[20];					//���ҿγ�����

	system("cls");
	printf("\t\t\t\t��ѡ���ѯ��ʽ:\n");
	printf("\t\t\t\t\t 1.������ѯ \n");
	printf("\t\t\t\t\t 2.���Ų�ѯ \n");
	printf("\t\t\t\t\t 3.�γ̲�ѯ \n");
	scanf("\t\t\t\t\t%d", &m);

	if ((fp = fopen("E:\\students\\teacher.txt", "r")) == NULL)			//�ж��ļ����
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

	if (m == 1)															//����������
	{
		printf("\t\t\t\t��Ҫ������ʦ������:");
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
			printf("\t\t\t����\t\t����\t\tְλ\t\t�Ա�\t\t�ۺ�����\n ");
			printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%d\n", teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].score);
			printf("\t\t\t�γ�����\t��ѧѧ��\t�γ�����\t��ѧЧ�� \n");
			printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1);
			printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2);
			printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3);
			printf("---------------------------------------------------------------------------------------\n");
		}
		else
		{
			printf("\n\t\t\t\tû�д˽�ʦ\n");
			
		}

	}


	if (m == 2)															//�ù��Ų���
	{
		printf("\t\t\t\t��Ҫ������ʦ�Ĺ���:");
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
			printf("\t\t\t����\t\t����\t\tְλ\t\t�Ա�\t\t�ۺ�����\n ");
			printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%d\n", teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].score);
			printf("\t\t\t�γ�����\t��ѧѧ��\t�γ�����\t��ѧЧ�� \n");
			printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1);
			printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2);
			printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3);
			printf("---------------------------------------------------------------------------------------\n");
		}
		else
		{
			printf("\n\t\t\t\tû�д˽�ʦ\n");

		}


	}

	if (m == 3)															//�ÿγ����ƽ��в���
	{
		printf("\t\t\t\t��Ҫ������ʦ�Ŀγ�����:");
		scanf("\t\t\t\t%s", checkclass);
		for (a = 0; a< num; a++)
		{
			if (strcmp(teacher[a].classname1,checkclass)==0)
			{
				i = a;
				printf("---------------------------------------------------------------------------------------\n");
				printf("\t\t\t����\t\t����\t\tְλ\t\t�Ա�\t\t�ۺ�����\n ");
				printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%d\n", teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].score);
				printf("\t\t\t�γ�����\t��ѧѧ��\t�γ�����\t��ѧЧ�� \n");
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1);
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2);
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3);
				printf("---------------------------------------------------------------------------------------\n");
			}
		}
		if (i == num)
		{
			printf("\n\t\t\t\tû�д˽�ʦ\n");
		}

	}

	fclose(fp);
	printf("\n1.��ӽ�ʦ��Ϣ\t\t");
	printf("2.�޸Ľ�ʦ��Ϣ\t\t");
	printf("3.ɾ����ʦ��Ϣ\t\t");
	printf("4.�鿴���н�ʦ��Ϣ\t\t");

	printf("5.���ز˵�");
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



//�޸Ľ�ʦ��Ϣ
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
	if ((fp2 = fopen("E:\\students\\teacher1.txt", "w")) == NULL)					//����teacher1  ����滻teacher.txt
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
	printf("\t\t\t����\t\t����\t\tְλ\t\t�Ա�\t\t�ۺ�����\n ");
	printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%d\n", teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].score);
	printf("\t\t\t�γ�����\t��ѧѧ��\t�γ�����\t��ѧЧ�� \n");
	printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1);
	printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2);
	printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3);
	printf("---------------------------------------------------------------------------------------\n");

	printf("\t\t\t\t\t\t�������޸ĵ���Ϣ\n");
	printf("\t\t\t\t\t\t����:");
	scanf("\t\t\t\t\t\t%d", &amendt.id);
	printf("\t\t\t\t\t\t����");
	scanf("\t\t\t\t\t\t%s", amendt.name);
	printf("\t\t\t\t\t\tְλ");
	scanf("\t\t\t\t\t\t%s", amendt.position);
	printf("\t\t\t\t\t\t�Ա�");
	scanf("\t\t\t\t\t\t%s", amendt.sex);
	printf("\t\t\t\t\t\t�γ�����1");
	scanf("\t\t\t\t\t\t%s", amendt.classname1);
	printf("\t\t\t\t\t\t��ѧѧ��1");
	scanf("\t\t\t\t\t\t%s", amendt.semester1);
	printf("\t\t\t\t\t\t�γ�����1");
	scanf("\t\t\t\t\t\t%s", amendt.nature1);
	printf("\t\t\t\t\t\t��ѧЧ��1");
	scanf("\t\t\t\t\t\t%s", amendt.effect1);
	
	printf("\t\t\t\t\t\t�γ�����2:");
	scanf("%s", amendt.classname2);
	printf("\t\t\t\t\t\t��ѧѧ��2:");
	scanf("%s", amendt.semester2);
	printf("\t\t\t\t\t\t�γ�����2:");
	scanf("%s", amendt.nature2);
	printf("\t\t\t\t\t\t��ѧЧ��2:");
	scanf("%s", amendt.effect2);
	printf("\t\t\t\t\t\t�γ�����3:");
	scanf("%s", amendt.classname3);
	
	printf("\t\t\t\t\t\t��ѧѧ��3:");
	scanf("%s", amendt.semester3);
	printf("\t\t\t\t\t\t�γ�����3:");
	scanf("%s", amendt.nature3);
	printf("\t\t\t\t\t\t��ѧЧ��3:");
	scanf("%s", amendt.effect3);
	
	printf("\t\t\t\t\t\t�ۺ�����:");
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
	rename("E:\\students\\teacher1.txt", "E:\\students\\teacher.txt");		//�滻ΪԴ�ļ�

	printf("�޸ĳɹ�\n");
	system("pause");
	menu();
}




//ɾ����ʦ��Ϣ
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
	
	printf("ɾ���ɹ�\n");
	system("pause");
	menu();
}




//��ʦ����
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


	printf("1.�����Ž�������\t 2.��������������\n");
	printf("3.���ۺ����ֽ�������\t 4.���ۺ�������������\n");
	scanf("%d", &m);



	if (m == 1||m==2)											//�����Ų�ѯ
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
		printf("����\t����\tְλ\t�Ա�\t�γ�����\t��ѧѧ��\t�γ�����\t��ѧЧ��\t��ѧ�ɼ�\n");

		if (m == 1)
		{
			for (i = 0; i < num; i++)
			{
				printf("---------------------------------------------------------------------------------------\n");
				printf("\t\t\t����\t\t����\t\tְλ\t\t�Ա�\t\t�ۺ�����\n ");
				printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%d\n", teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].score);
				printf("\t\t\t�γ�����\t��ѧѧ��\t�γ�����\t��ѧЧ�� \n");
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
				printf("\t\t\t����\t\t����\t\tְλ\t\t�Ա�\t\t�ۺ�����\n ");
				printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%d\n", teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].score);
				printf("\t\t\t�γ�����\t��ѧѧ��\t�γ�����\t��ѧЧ�� \n");
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1);
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2);
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3);
				printf("---------------------------------------------------------------------------------------\n");
			}
		}

	}


	if (m == 3||m==4)												//���ۺϳɼ���ѯ
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
				printf("\t\t\t����\t\t����\t\tְλ\t\t�Ա�\t\t�ۺ�����\n ");
				printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%d\n", teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].score);
				printf("\t\t\t�γ�����\t��ѧѧ��\t�γ�����\t��ѧЧ�� \n");
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
				printf("\t\t\t����\t\t����\t\tְλ\t\t�Ա�\t\t�ۺ�����\n ");
				printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%d\n", teacher[i].id, teacher[i].name, teacher[i].position, teacher[i].sex, teacher[i].score);
				printf("\t\t\t�γ�����\t��ѧѧ��\t�γ�����\t��ѧЧ�� \n");
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname1, teacher[i].semester1, teacher[i].nature1, teacher[i].effect1);
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname2, teacher[i].semester2, teacher[i].nature2, teacher[i].effect2);
				printf("\t\t\t%s\t\t%s\t\t%s\t\t%s\n", teacher[i].classname3, teacher[i].semester3, teacher[i].nature3, teacher[i].effect3);
				printf("---------------------------------------------------------------------------------------\n");
			}
		}

	}


	printf("������������ز˵�\n");
	system("pause");
	system("cls");
	menu();

}


int main()
{

	menu();

	return 0;
}