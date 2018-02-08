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
	int id;//ѧ��
	char name[20];
	char sex[3];//�Ա�
	int age;
	char major[20];//רҵ
}students[mm];



void menu();//�˵�
void write();//д���ļ�
void input();//����ѧ����Ϣ
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


//���˵�
void menu()
{
	int choose;
	printf("************************************************��ӭʹ��ѧ������ϵͳ*****************************************\n");
	printf("\t\t\t\t 1.¼��ѧ����Ϣ \n");
	printf("\t\t\t\t 2.�鿴����ѧ����Ϣ \n");
	printf("\t\t\t\t 3.ѧ����Ϣ���� \n");
	printf("\t\t\t\t 4.�޸�ѧ����Ϣ \n");
	printf("\t\t\t\t 5.ɾ��ѧ����Ϣ \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t2018.1.30.�汾1.0\n");
	printf("**********************************************************************************************************\n");
	printf("��ѡ����Ҫ�ķ���\n");

	scanf("%d", &choose);
	switch (choose)				//ѡ�����񲢽�����ת
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
		printf("������ѧ��:");

		scanf("%d", &students[num].id);

		getchar();



		printf("����������:");

		scanf("%s", &students[num].name);

		getchar();


		printf("����������:");

		scanf("%d", &students[num].age);

		getchar();



		printf("�������Ա�:");

		scanf("%s", &students[num].sex);

		getchar();


		printf("������רҵ:");

		scanf("%s", &students[num].major);

		getchar();

		num++;


		write(); //д���ļ�

		printf("д��ɹ�\n");

		printf("�Ƿ����?(y/n)");

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
		printf("���ܴ��ļ�!\n");

		return;
	}

	if (fwrite(&students[i], sizeof(struct student), 1, fp) != 1)
	{

		printf("д���ļ�����!\n");

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
		printf("���ڻ�û��ѧ��\n");
		menu();
	}
	else
	{
		printf("ѧ��\t����\t�Ա�\t����\tרҵ\n");
		do
		{
			sprintf(s, "E:\\students\\%s" ,fileinfo.name);
			if ((fp = fopen(s, "r+")) == NULL)
			{
				printf("�޷����ļ�\n");
				return;
			}
	
			fread(&students[i], sizeof(struct student), 1, fp);
			printf("%d\t%s\t%s\t%d\t%s\t\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].major);
		}while (_findnext(handle, &fileinfo) == 0);
	}

	printf("����������ز˵�\n");
	getchar();
	getchar();
	system("cls");
	menu();

}


void find()
{
	int s = 0;

	
	printf("1.ͨ��ѧ�Ų���\n");
	printf("2.ͨ����������\n");
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
	
	printf("������ѧ�� : ");
	scanf("%s", g);
	
	sprintf(s, "E:\\students\\%s.txt", g);

	if ((fp = fopen(s, "r+")) == NULL)
		{
			printf("û�����ѧ��\n");
			return;
		}
	
	fread(&students[i], sizeof(struct student), 1, fp);

	printf("ѧ��\t����\t�Ա�\t����\tרҵ\n");
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



	printf("����������\n");
	scanf("%s", a);

	if ((handle = _findfirst("E:\\students\\*.txt", &fileinfo)) == -1L)
	{
		printf("���ڻ�û��ѧ��\n");
		menu();
	}
	else
	{
		do
		{
			sprintf(s, "E:\\students\\%s", fileinfo.name);
			if ((fp = fopen(s, "r+")) == NULL)
			{
				printf("�޷����ļ�\n");
				return;
			}
			fread(&students[i], sizeof(struct student), 1, fp);
			if (strcmp(a, students[i].name) == 0)
			{
				printf("ѧ��\t����\t�Ա�\t����\tרҵ\n");
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
	printf("����������Ҫɾ��ѧ����ѧ��\n");
	scanf("%s", g);
	sprintf(s, "E:\\students\\%s.txt", g);
	if ((fp = fopen(s, "r+")) == NULL)
	{
		printf("û�����ѧ��\n");
		return;
	}
	fread(&students[i], sizeof(struct student), 1, fp);
	printf("ѧ��\t����\t�Ա�\t����\tרҵ\n");
	printf("%d\t%s\t%s\t%d\t%s\t\n\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].major);
	fclose(fp);
	
	printf("��ȷ��Ҫɾ����λѧ����:1.ȷ��,2.��\n");
	scanf("%d", &t);
	if (t == 2)
	{
		system("cls");
		return;
	}
	if (remove(s))
	{
		printf("ɾ���ļ�ʧ��\n");
		return;
	}
	else
		printf("ɾ���ɹ�\n");

}


void charge()
{
	int y;
	FILE *fp;
	system("cls");
	printf("������ѧ�� : ");
	scanf("%s", g);
	sprintf(s, "E:\\students\\%s.txt", g);
	if ((fp = fopen(s, "r+")) == NULL)
	{
		printf("û�����ѧ��\n");
		return;
	}
	fread(&students[i], sizeof(struct student), 1, fp);
	printf("ѧ��\t����\t�Ա�\t����\tרҵ\n");
	printf("%d\t%s\t%s\t%d\t%s\t\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].major);
	
	printf("�������Ҫ�޸ĵ�ֵ\n");
	
	printf("\n1.�޸�ѧ��ѧ��\n");
	printf("2.�޸�ѧ������\n");
	printf("3.�޸�ѧ���Ա�\n");
	printf("4.�޸�ѧ������\n");
	printf("5.�޸�ѧ��רҵ\n");
	printf("�������������˳�\n");
	scanf("%d", &y);
	switch (y)
	{
	case 1:
		printf("�������µ�ѧ�� : ");
		scanf("%d", &students[i].id);
		break;
	case 2:
		printf("�������µ����� : ");
		scanf("%s", students[i].name);

		break;
	case 3:
		printf("�������µ��Ա� : ");
		scanf("%s", students[i].sex);
		break;
	case 4:
		printf("�������µ����� : ");
		scanf("%d", &students[i].age);
		break;
	case 5:
		printf("�������µ�רҵ : ");
		scanf("%s", students[i].major);
		break;
	}
	write();
	menu();
}


