#include "stdio.h"
struct count
{
	int day[12];
};

struct count days1=
{
	{31,29,31,30,31,30,31,31,30,31,30,31}
};

struct count days2=
{
	{31,28,31,30,31,30,31,31,30,31,30,31}
};

int main(void)
{
	int year,month,day;
	
	printf("���������:");
	scanf("%d",&year);
	
	printf("�������·�:");
	scanf("%d",&month);
	
	printf("����������:");
	scanf("%d",&day);
	
	int i; //���� 
	
	if(year%4==0)
	{
		for(i=0;i<=month-2;i++)
		{
			day+=days2.day[i];
		}
	}
	
	else
	{
		for(i=0;i<=month-2;i++)
		{
			day+=days1.day[i];
		}
	}
	
	printf("�����ڱ������ǵ�%d��",day); 
}
