//功能:菜单,读取,添加,查询,显示,修改,删除,保存
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define N 15 //最多保存15位学生的信息 

/*菜单*/void menu();
/*读取*/void read();
/*添加*/void add();
/*查询*/void search();
/*显示*/void show();
/*修改*/void modify();
/*删除*/void del();
/*保存*/void save();
int now=0; //now为现有学生人数 

struct student //学生信息包括学号,姓名,成绩 
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
	printf("%c%c 读取data.txt之前请先添加学生信息并保存data.txt %c%c\n",3,3,3,3);
	printf("\n");
	puts("1.读取data.txt");
	puts("2.添加学生信息");
	puts("3.查询学生信息");
	puts("4.显示所有学生信息");
	puts("5.修改学生信息");
	puts("6.删除学生信息"); //1.删除指定学生信息 2.删除所有学生信息 
	puts("7.保存data.txt");
	puts("0.退出系统");
	puts("\n");
	puts("请操作系统:");
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
		default:printf("请输入正确的数字");break;
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
		puts("找不到文件data.txt");
		system("pause");
		return; 
	}
	

	while(fscanf(fp,"%d %s %d",&stu[i].code, stu[i].name, &stu[i].mark)==3)
	{
		i++;
	}
	now=i;
	fclose(fp);
	puts("读取文件成功");
	printf("已读取%d个学生信息\n",i);
	system("pause");
}


void add()
{
	char ch[5]; //用于判断是否继续 
do
{
	puts("请输入要添加的学生的学号:");
	int i=0,num;
	scanf("%d",&num);
	for(i=0;i<=now-1;i++) //查询是否重复 
	{
		if(stu[i].code==num)
		{
			puts("已存在该学生的信息");
			system("pause");
			return;
		}
	}
	
	stu[now].code=num;
	puts("请输入该学生姓名");
	scanf("%s",stu[now].name);
	puts("请输入该学生成绩");
	scanf("%d",&stu[now].mark);
	now++;
	
	puts("是否继续添加? 是(Y) 否(N) :");
	scanf("%s",ch); 
}while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0);
system("pause");
}


void search()
{
	char ch[5]; //用于判断是否继续 
do
{
	puts("请输入要查询的学生的学号:");
	int i=0,num;
	scanf("%d",&num);
	int flag=0; //flag用来标记是否查询成功 
	for(i=0;i<=now-1;i++)
	{
		if(stu[i].code==num)
		{
			printf("学号:%d\n",stu[i].code);
			printf("姓名:%s\n",stu[i].name);
			printf("成绩:%d\n",stu[i].mark);
			flag=1;
		}
	}
	if(flag==0) puts("无法查询该学生的信息"); 
	puts("是否继续查询? 是(Y) 否(N) :");
	scanf("%s",ch); 
}while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0);

}


void show()
{
	int i=0;
	for(i=0;i<=now-1;i++)
	{
		printf("学号:%d\n",stu[i].code);
		printf("姓名:%s\n",stu[i].name);
		printf("成绩:%d\n",stu[i].mark);
		puts("\n");
	}
	system("pause");
}


void modify()
{
	char ch[5]; //用于判断是否继续 
do
{
	puts("请输入要修改的学生的学号:");
	int i=0,num;
	scanf("%d",&num);
	int flag=0; //flag用来标记是否查询成功 
	for(i=0;i<=now-1;i++)
	{
		if(stu[i].code==num)
		{
			puts("请选择修改项目 学号(1) 姓名(2) 成绩(3):");
			int x;
			scanf("%d",&x);
			switch(x)
			{
				case 1:
					{
						puts("请输入新的学号:");
						scanf("%d",&stu[i].code); 
					}break;
				case 2:
					{
						puts("请输入新的姓名:");
						scanf("%s",stu[i].name);
					}break;
				case 3:
					{
						puts("请输入新的成绩:");
						scanf("%d",&stu[i].mark); 
					}break;
				default:
					{
						puts("输入的数字错误");
					}break;
			}puts("修改成功!");
			flag=1;
		}
	}
	if(flag==0) puts("无法查询该学生的信息");
	puts("是否继续修改? 是(Y) 否(N) :");
	scanf("%s",ch); 
}while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0);

}


void del()
{
	char ch[5]; //用于判断是否继续 
do
{
	puts("请输入要删除的学生的学号:");
	int i=0,num;
	scanf("%d",&num);
	int flag=0; //flag用于标记是否查询成功 
	for(i=0;i<=now-1;i++)
	{
		if(stu[i].code==num)
		{
			int k=0;
			for(k=i;k<=now-2;k++)
			stu[k]=stu[k+1];
			puts("删除成功"); 
			now--;
			flag=1;
		}
	}
	if(flag==1) puts("无法查询该学生的信息");
	puts("是否继续删除? 是(Y) 否(N) :");
	scanf("%s",ch); 
}while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0);

}


void save()
{
	FILE *fp;
	int i=0;
	
	if((fp=fopen("data.txt","w"))==NULL)
	{
		puts("无法打开data.txt");
		return; 
	}
	
	for(i=0;i<=now-1;i++)
	{
		if(fprintf(fp,"%d %s %d\n",stu[i].code,stu[i].name,stu[i].mark)==1); 
	}
	fclose(fp);
	puts("保存data.txt成功");
	printf("已保存%d个学生信息\n",i);
	system("pause");
}
