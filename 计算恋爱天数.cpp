#include "stdio.h"
struct count
{
	int day[12];
};


int main(void)
{
	
	int year,month,day;
	
	printf("请输入年份:");
	scanf("%d",&year);
	
	printf("请输入月份:");
	scanf("%d",&month);
	
	printf("请输入天数:");
	scanf("%d",&day);
	
	int i; //计数 
	int days=0; //总天数 
	
	
	//闰年 
	struct count days1=
	{
		{31,29,31,30,31,30,31,31,30,31,30,31}
	};

	//平年 
	struct count days2=
	{
		{31,28,31,30,31,30,31,31,30,31,30,31}
	};
	
	

	//在2015内的天数 
	if(year==2015)
	{
		for(i=0;i<=month-2;i++)
		{
			days+=days1.day[i]-28;
		}
		days+=day;
	}	


	//大于2015则加上2015中的天数 
	int days_2015=365-28; 
	if(year>2015)
	{
		days+=days_2015;
	}
	 
	 
	//中间满年的天数 
	for(i=1;i<=year-2015-1;i++)
	{
		//如果是闰年 
		if((2015+i)%4==0)
		{
			days+=366;
		}
		//如果是平年 
		else
		{
			days+=365;
		}
	}
	
	
	//最后一年的天数 
	//如果是闰年 
	if(year%4==0)
	{
		for(i=0;i<=month-2;i++)
		{
			days+=days2.day[i];
		}
		days+=day;
	}
	//如果是平年 
	else
	{
		for(i=0;i<=month-2;i++)
		{
			days+=days1.day[i];
		}
		days+=day;
	}
	//	printf("该日在本年中是第%d天\n",days); 
	
	printf("我们在一起%d天啦!~",days+1);

	
	 
	return 0;
 
}
