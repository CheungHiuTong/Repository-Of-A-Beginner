//����:�˵�,��ȡ,���,��ѯ,��ʾ,�޸�,ɾ��,����
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define N 15 //��ౣ��15λѧ������Ϣ 

/*�˵�*/void menu();
/*��ȡ*/void read();
/*���*/void add();
/*��ѯ*/void search();
/*��ʾ*/void show();
/*�޸�*/void modify();
/*ɾ��*/void del();
/*����*/void save();
int now=0; //nowΪ����ѧ������ 

struct student //ѧ����Ϣ����ѧ��,����,�ɼ� 
{
	int code;
	char name[15];
	int mark;
}stu[N];


int main()
{
	menu();
	return 0;
}


void menu()
{
while(1)
{
	printf("%c%c ��ȡdata.txt֮ǰ�������ѧ����Ϣ������data.txt %c%c\n",3,3,3,3);
	printf("\n");
	puts("1.��ȡdata.txt");
	puts("2.���ѧ����Ϣ");
	puts("3.��ѯѧ����Ϣ");
	puts("4.��ʾ����ѧ����Ϣ");
	puts("5.�޸�ѧ����Ϣ");
	puts("6.ɾ��ѧ����Ϣ"); //1.ɾ��ָ��ѧ����Ϣ 2.ɾ������ѧ����Ϣ 
	puts("7.����data.txt");
	puts("0.�˳�ϵͳ");
	puts("\n");
	puts("�����ϵͳ:");
	int x;
	scanf("%d",&x);
	if(x==0) return;
	switch(x)
	{
		case 1:read();break;
		case 2:add();break;
		case 3:search();break;
		case 4:show();break;
		case 5:modify();break;
		case 6:del();break;
		case 7:save();break;
		default:printf("��������ȷ������");break;
	}
	system("cls");
}
}


void read()
{
	FILE *fp;
	int i=0;
	
	if((fp=fopen("data.txt","r"))==NULL)
	{
		puts("�Ҳ����ļ�data.txt");
		system("pause");
		return; 
	}
	

	while(fscanf(fp,"%d %s %d",&stu[i].code, stu[i].name, &stu[i].mark)==3)
	{
		i++;
	}
	now=i;
	fclose(fp);
	puts("��ȡ�ļ��ɹ�");
	printf("�Ѷ�ȡ%d��ѧ����Ϣ\n",i);
	system("pause");
}


void add()
{
	char ch[5]; //�����ж��Ƿ���� 
do
{
	puts("������Ҫ��ӵ�ѧ����ѧ��:");
	int i=0,num;
	scanf("%d",&num);
	for(i=0;i<=now-1;i++) //��ѯ�Ƿ��ظ� 
	{
		if(stu[i].code==num)
		{
			puts("�Ѵ��ڸ�ѧ������Ϣ");
			system("pause");
			return;
		}
	}
	
	stu[now].code=num;
	puts("�������ѧ������");
	scanf("%s",stu[now].name);
	puts("�������ѧ���ɼ�");
	scanf("%d",&stu[now].mark);
	now++;
	
	puts("�Ƿ�������? ��(Y) ��(N) :");
	scanf("%s",ch); 
}while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0);
system("pause");
}


void search()
{
	char ch[5]; //�����ж��Ƿ���� 
do
{
	puts("������Ҫ��ѯ��ѧ����ѧ��:");
	int i=0,num;
	scanf("%d",&num);
	int flag=0; //flag��������Ƿ��ѯ�ɹ� 
	for(i=0;i<=now-1;i++)
	{
		if(stu[i].code==num)
		{
			printf("ѧ��:%d\n",stu[i].code);
			printf("����:%s\n",stu[i].name);
			printf("�ɼ�:%d\n",stu[i].mark);
			flag=1;
		}
	}
	if(flag==0) puts("�޷���ѯ��ѧ������Ϣ"); 
	puts("�Ƿ������ѯ? ��(Y) ��(N) :");
	scanf("%s",ch); 
}while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0);

}


void show()
{
	int i=0;
	for(i=0;i<=now-1;i++)
	{
		printf("ѧ��:%d\n",stu[i].code);
		printf("����:%s\n",stu[i].name);
		printf("�ɼ�:%d\n",stu[i].mark);
		puts("\n");
	}
	system("pause");
}


void modify()
{
	char ch[5]; //�����ж��Ƿ���� 
do
{
	puts("������Ҫ�޸ĵ�ѧ����ѧ��:");
	int i=0,num;
	scanf("%d",&num);
	int flag=0; //flag��������Ƿ��ѯ�ɹ� 
	for(i=0;i<=now-1;i++)
	{
		if(stu[i].code==num)
		{
			puts("��ѡ���޸���Ŀ ѧ��(1) ����(2) �ɼ�(3):");
			int x;
			scanf("%d",&x);
			switch(x)
			{
				case 1:
					{
						puts("�������µ�ѧ��:");
						scanf("%d",&stu[i].code); 
					}break;
				case 2:
					{
						puts("�������µ�����:");
						scanf("%s",stu[i].name);
					}break;
				case 3:
					{
						puts("�������µĳɼ�:");
						scanf("%d",&stu[i].mark); 
					}break;
				default:
					{
						puts("��������ִ���");
					}break;
			}puts("�޸ĳɹ�!");
			flag=1;
		}
	}
	if(flag==0) puts("�޷���ѯ��ѧ������Ϣ");
	puts("�Ƿ�����޸�? ��(Y) ��(N) :");
	scanf("%s",ch); 
}while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0);

}


void del()
{
	char ch[5]; //�����ж��Ƿ���� 
do
{
	puts("������Ҫɾ����ѧ����ѧ��:");
	int i=0,num;
	scanf("%d",&num);
	int flag=0; //flag���ڱ���Ƿ��ѯ�ɹ� 
	for(i=0;i<=now-1;i++)
	{
		if(stu[i].code==num)
		{
			int k=0;
			for(k=i;k<=now-2;k++)
			stu[k]=stu[k+1];
			puts("ɾ���ɹ�"); 
			now--;
			flag=1;
		}
	}
	if(flag==1) puts("�޷���ѯ��ѧ������Ϣ");
	puts("�Ƿ����ɾ��? ��(Y) ��(N) :");
	scanf("%s",ch); 
}while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0);

}


void save()
{
	FILE *fp;
	int i=0;
	
	if((fp=fopen("data.txt","w"))==NULL)
	{
		puts("�޷���data.txt");
		return; 
	}
	
	for(i=0;i<=now-1;i++)
	{
		if(fprintf(fp,"%d %s %d\n",stu[i].code,stu[i].name,stu[i].mark)==1); 
	}
	fclose(fp);
	puts("����data.txt�ɹ�");
	printf("�ѱ���%d��ѧ����Ϣ\n",i);
	system("pause");
}
