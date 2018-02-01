#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int num = 0;


struct student
{
	int id;//ѧ��
	char name[20];
	char sex[3];//�Ա�
	int age;
	char major[20];//רҵ
	struct student *next;
};
struct student students[1000];//ѧ������



void menu( );//�˵�
void write();//д���ļ�
void input();//����ѧ����Ϣ
void all();//�鿴����ѧ����Ϣ
void find();//Ѱ��ѧ��
void findid();//ͨ��ѧ����ѧ��
void findname();//ͨ��������ѧ��
void charge(int i );//�޸�ѧ����Ϣ
void out(int i);//ɾ��ѧ����Ϣ



int main()
{
	FILE *fp;
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
	switch(choose)				//ѡ�����񲢽�����ת
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
		printf("\n\nֱ���ҳ�ѧ��������޸�\n");
		find();
		break;
	case 5:
		printf("\n\nֱ���ҳ�ѧ�������ɾ��\n");
		find();
		break;
	}
}



//ѧ����Ϣ��д��
void write()
{
	FILE *fp;
	int i; 
	if ((fp = fopen("\E:\students.txt", "w+")) == NULL) //��ֹ�޷����ļ������
	{
		printf("���ܴ��ļ�!\n");

		return;
	}


	for (i = 0; i<num; i++) //д��ѧ����Ϣ

	{

		if (fwrite(&students[i], sizeof(struct student), 1, fp) != 1)
		{

			printf("д���ļ�����!\n");

		}

	}
	fclose(fp);

}





//����ȫ��ѧ��
void all()
{
	FILE *fp;
	
	if ((fp = fopen("\E:\students.txt", "r")) == NULL)
	{
		printf("�޷����ļ�\n");
		return;
	}


	
	printf("ѧ��\t����\t�Ա�\t����\tרҵ\n");
	for (int i = 0; i < 1000; i++)		//�������ѧ����Ϣ

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



//����ѧ����Ϣ
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
		
		
		
		printf("�Ƿ����?(y/n)");

		if (getchar() == 'n')

		{
			break;
			
		}

	}
	system("cls");
	menu();
}



//�ҳ�ѧ��
void find()
{
	int i = 1;
	
	FILE *fp;

	if ((fp = fopen("\E:\students.txt", "rb")) == NULL)
	{
		printf("�޷����ļ�\n");
		return;
	}


	//�ȴ��ļ������б���,��д���ڴ���
	for (int i = 0; i < 1000; i++)

	{

		fread(&students[i], sizeof(struct student), 1, fp);

		if (students[i].id == 0)
			break;

	}

	fclose(fp);




	printf("-------------------------------------------------------------\n\n");
	printf("1.ͨ��ѧ�Ų���\n");
	printf("2.ͨ����������\n");
	printf("3.���ز˵�\n");
	
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



//��ѧ������ѧ��
void findid()
{
	int i,s;
	int g = 0 ,number=0;
	FILE *fp;

	if ((fp = fopen("\E:\students.txt", "rb+")) == NULL)
	{
		printf("�޷����ļ�\n");
		return;
	}
	
	system("cls");
	printf("������ѧ�� : ");
	scanf("%d", &s);
	for ( i = 0; i < 1000; i++)
	{
		

		if (s == students[i].id)
		{
	
			printf("ѧ��\t����\t�Ա�\t����\tרҵ\n");
			printf("%d\t%s\t%s\t%d\t%s\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].major);
			g++;
			number = i;
		}
	}
	if (g == 0)
		printf("û�����ѧ��\n");
	
	fclose(fp);

	getchar();

	printf("\n1.��������?\n");
	printf("\n2.�޸�ѧ����Ϣ\n");
	printf("\n\n3.ɾ��ѧ����Ϣ\n");
	printf("\n\n4.���ز˵�\n");

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


//����������ѧ��
void findname()
{
	int i,g=0;
	int number=0;
	char s[20];
	FILE *fp;

	if ((fp = fopen("\E:\students.txt", "rb")) == NULL)
	{
		printf("�޷����ļ�\n");
		return;
	}

	system("cls");
	printf("���������� : ");
	scanf("%s", s);

	for (i = 0; i < 1000; i++)
	{


		if (strcmp(s,students[i].name)==0)
		{
			printf("ѧ��\t����\t�Ա�\t����\tרҵ\n");
			printf("%d\t%s\t%s\t%d\t%s\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].major);
			g++;
			number = i;
		}
		if (students[i].id == 0)
			break;

	}
	if (g == 0)
		printf("û�����ѧ��\n");

	fclose(fp);

	printf("\n\n1.��������?\n");
	printf("\n\n2.�޸�ѧ����Ϣ\n");
	printf("\n\n3.ɾ��ѧ����Ϣ\n");
	printf("\n\n4.���ز˵�\n");

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



//�޸�ѧ����Ϣ
void charge(int i)
{
	int w,g=0;

	FILE *fp;

	if ((fp = fopen("\E:\students.txt", "w+")) == NULL)
	{
		printf("�޷����ļ�\n");
		return;
	}

	system("cls");
	
	printf("-------------------------------------------------------------\n");
	printf("ѧ��\t����\t�Ա�\t����\tרҵ\n");
	printf("%d\t%s\t%s\t%d\t%s\n\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].major);
	printf("-------------------------------------------------------------\n");

	printf("\n1.�޸�ѧ��ѧ��\n");
	printf("2.�޸�ѧ������\n");
	printf("3.�޸�ѧ���Ա�\n");
	printf("4.�޸�ѧ������\n");
	printf("5.�޸�ѧ��רҵ\n");
	printf("�������������˳�\n");
	scanf("%d", &w);

	switch (w)
	{
	case 1 :
		printf("�������µ�ѧ�� : ");
		scanf("%d", &students[num+1].id);
		break;
	case 2:
		printf("�������µ����� : ");
		scanf("%s", students[num + 1].name);

		break;
	case 3:
		printf("�������µ��Ա� : ");
		scanf("%s", students[num + 1].sex);
		break;
	case 4:
		printf("�������µ����� : ");
		scanf("%d", &students[i].age);
		break;
	case 5:
		printf("�������µ�רҵ : ");
		scanf("%s", students[num + 1].major);
		break;
	default:
		break;
	}
	
	write();
	num++;
	printf("�޸ĳɹ�\n");

	printf("\n1.�����޸�\n");
	printf("\n2.���ز˵�\n");

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



//ɾ��ѧ��
void out(int i)
{

	FILE *fp;

	if ((fp = fopen("\E:\students.txt", "w+")) == NULL)
	{
		printf("�޷����ļ�\n");
		return;
	}
	
	for (i; i < 1000; i++)    //�ú�һ��ѧ������ǰһ��ѧ��,ʵ��ɾ��;
	{
		students[i] = students[i + 1];
		if (students[i + 1].id == 0)
			break;

	}
	fclose(fp);
	printf("seccesssssssssssssssssssss\n");
	menu();
}