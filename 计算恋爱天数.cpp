#include "stdio.h"
struct count
{
	int day[12];
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
	int days=0; //������ 
	
	
	//���� 
	struct count days1=
	{
		{31,29,31,30,31,30,31,31,30,31,30,31}
	};

	//ƽ�� 
	struct count days2=
	{
		{31,28,31,30,31,30,31,31,30,31,30,31}
	};
	
	

	//��2015�ڵ����� 
	if(year==2015)
	{
		for(i=0;i<=month-2;i++)
		{
			days+=days1.day[i]-28;
		}
		days+=day;
	}	


	//����2015�����2015�е����� 
	int days_2015=365-28; 
	if(year>2015)
	{
		days+=days_2015;
	}
	 
	 
	//�м���������� 
	for(i=1;i<=year-2015-1;i++)
	{
		//��������� 
		if((2015+i)%4==0)
		{
			days+=366;
		}
		//�����ƽ�� 
		else
		{
			days+=365;
		}
	}
	
	
	//���һ������� 
	//��������� 
	if(year%4==0)
	{
		for(i=0;i<=month-2;i++)
		{
			days+=days2.day[i];
		}
		days+=day;
	}
	//�����ƽ�� 
	else
	{
		for(i=0;i<=month-2;i++)
		{
			days+=days1.day[i];
		}
		days+=day;
	}
	//	printf("�����ڱ������ǵ�%d��\n",days); 
	
	printf("������һ��%d����!~",days+1);

	
	 
	return 0;
 
}
