#include<stdio.h>
#include<string.h>
#include<math.h>
#include"struct.h"
void searchdatanumber(Data s[],int n,int a[])        //����Ų���
{
	int i,j=0,number;
	do
	{
	   printf("����������ҵ����:");
	   scanf("%d",&number);
	}while(number<=0);
	getchar();
	for(i=0;i<n;i++)
	{
		if(number==s[i].number)
		{
		    j++;
		    a[j]=i;
			printf("      ���  �¼�����        ��        ��        ��      ���\n");
		    printf("%10d%10s%10d%10d%10d%10.2f\n",s[i].number,s[i].name,s[i].date.year,s[i].date.month,s[i].date.day,s[i].money);
		}
	}
    if(j==0)
	    printf("δ�ҵ�����ŵļ�¼��\n\n");
	a[0]=j;
}




void searchdatadate(Data s[],int n,int b[])               //�����ڲ���
{
	int i,j=0,year,month,day;
	printf("����������ҵ�����:");
	scanf("%d%d%d",&year,&month,&day);
	if(year<=0)
	{
		printf("������������\n");
        printf("����������������ҵ�����:");
	    scanf("%d%d%d",&year,&month,&day);
	}
    if(month>12||month<1)
	{
		printf("������������\n");
        printf("����������������ҵ�����:");
	    scanf("%d%d%d",&year,&month,&day);
	}
	if(year%4==0&&year%100!=0)
	{
		if(((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&(day>31||day<1))||((month==4||month==6||month==9||month==11)&&(day>30||day<1))||(month==2&&(day>29||day<1)))
		{
			do
            {
                printf("������������\n");
                printf("����������������ҵ�����:");
	            scanf("%d%d%d",&year,&month,&day);
            }while((year<=0)||(month>12||month<1)||((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&(day>31||day<1))||((month==4||month==6||month==9||month==11)&&(day>30||day<1))||(month==2&&(year%4==0&&year%100!=0)&&(day>29||day<1))||(month==2&&(year%4!=0)&&(day>28||day<1)));
		}
	}
	else
	{
		if(((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&(day>31||day<1))||((month==4||month==6||month==9||month==11)&&(day>30||day<1))||(month==2&&(day>28||day<1)))
		{
			do
            {
			    printf("������������\n");
                printf("����������������ҵ�����:");
	            scanf("%d%d%d",&year,&month,&day);
            }while((year<=0)||(month>12||month<1)||((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&(day>31||day<1))||((month==4||month==6||month==9||month==11)&&(day>30||day<1))||(month==2&&(year%4==0&&year%100!=0)&&(day>29||day<1))||(month==2&&(year%4!=0)&&(day>28||day<1)));
		}
	}
    for(i=0;i<n;i++)
	{
		if((year==s[i].date.year)&&(month==s[i].date.month)&&(day==s[i].date.day))
		{
		    j++;
		    if(j==1)
                printf("      ���  �¼�����        ��        ��        ��      ���\n");
		    b[j]=i;
			printf("%10d%10s%10d%10d%10d%10.2f\n",s[i].number,s[i].name,s[i].date.year,s[i].date.month,s[i].date.day,s[i].money);
		}
	}
	getchar();
	 if(j==0)
    {
        printf("δ�ҵ������ڵļ�¼��\n\n");
    }
	 b[0]=j;
}


void searchdataname(Data s[],int n,int c[])          //�����Ʋ���
{
	int i,j=0;
    char name[20];
	printf("����������ҵ�����:");
	scanf("%s",name);
	for(i=0;i<n;i++)
	{
		if(strcmp(s[i].name,name)==0)
		{
		    j++;
		    if(j==1)
                printf("      ���  �¼�����        ��        ��        ��      ���\n");
		    c[j]=i;
		    printf("%10d%10s%10d%10d%10d%10.2f\n",s[i].number,s[i].name,s[i].date.year,s[i].date.month,s[i].date.day,s[i].money);
		}

	}
	getchar();
	if(j==0)
    {
        printf("δ�ҵ������Ƶļ�¼��\n\n");
    }
	c[0]=j;
}


void searchdatamoney(Data s[],int n,int d[])     //��������
{
	int i,j=0;
	double money;
	do
	{
	   printf("����������ҵĽ��:");
	   scanf("%lf",&money);
	}while(money<0);
	for(i=0;i<n;i++)
	{
		if(fabs(s[i].money-money)<1e-6)
		{
		    j++;
		    if(j==1)
                printf("      ���  �¼�����        ��        ��        ��      ���\n");
            d[j]=i;
            printf("%10d%10s%10d%10d%10d%10.2f\n",s[i].number,s[i].name,s[i].date.year,s[i].date.month,s[i].date.day,s[i].money);
		}
	}
	getchar();
	if(j==0)
    {
        printf("δ�ҵ��ý��ļ�¼��\n\n");
    }
	d[0]=j;
}







