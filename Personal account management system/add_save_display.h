#include<stdio.h>
#include"struct.h"
#include<string.h>
int judge_input()//�ж�
{
    int j;
    char a;
    for(j=0;;j++)
    {
        a=getchar();
		if(a=='\n')
            break;
    }
    if(j>=1)
    {
        return 1;
    }
	return 0;
}

//��ʾ
void display(Data data[],int n)
{
	int i;
	printf("\n");
	printf("           ��     ��     ��     ��      ��     ϸ\n\n");
    printf("      ���  �¼�����        ��        ��        ��      ���\n");
	for(i=0;i<n;i++)
	{
		printf("%10d%10s%10d%10d%10d%10.2f\n",data[i].number,data[i].name,data[i].date.year,data[i].date.month,data[i].date.day,data[i].money);
	}
}
//�������
int add_data1(Data data[],int *m,int classify)
{
    int i,k;
	int group;
    printf("��������Ҫ��������������");
    scanf("%d",&group);
	if(group==0)
		return 1;
    printf("�밴�����µĸ�ʽ��������\n\n");
    printf("�¼����� �� �� �գ����ڣ� ������Ϊ����֧��Ϊ����\n");
    for(i=*m;i<*m+group;i++)
    {
		printf("%d.",i-*m+1);
        scanf("%s%d%d%d%lf",data[i].name,&data[i].date.year,&data[i].date.month,&data[i].date.day,&data[i].money);
        data[i].number=i+1;
        data[i].classify=classify;
        for(k=0;;k++)
        {
            if(data[i].date.year<=0)
            {
                printf("������������\n");
                printf("�������������ڣ��ꡢ�¡��գ�:");
                scanf("%d%d%d",&data[i].date.year,&data[i].date.month,&data[i].date.day);
                continue;
            }
            if(data[i].date.month>12||data[i].date.month<1)
            {
                printf("������������\n");
                printf("�������������ڣ��ꡢ�¡��գ�:");
                scanf("%d%d%d",&data[i].date.year,&data[i].date.month,&data[i].date.day);
                continue;
            }
            if((data[i].date.month==1||data[i].date.month==3||data[i].date.month==5||data[i].date.month==7||data[i].date.month==8||data[i].date.month==10||data[i].date.month==12)&&data[i].date.day>31)
            {
                printf("������������\n");
                printf("�������������ڣ��ꡢ�¡��գ�:");
                scanf("%d%d%d",&data[i].date.year,&data[i].date.month,&data[i].date.day);
                continue;
            }
            if((data[i].date.month==4||data[i].date.month==6||data[i].date.month==9||data[i].date.month==11)&&data[i].date.day>30)
            {
                printf("������������\n");
                printf("�������������ڣ��ꡢ�¡��գ�:");
                scanf("%d%d%d",&data[i].date.year,&data[i].date.month,&data[i].date.day);
                continue;
            }
            if(data[i].date.year%4==0&&data[i].date.year%100==0||data[i].date.year%4==0)
            {
                if(data[i].date.month==2&&data[i].date.day>29)
                {
                    printf("������������\n");
                    printf("�������������ڣ��ꡢ�¡��գ�:");
                    scanf("%d%d%d",&data[i].date.year,&data[i].date.month,&data[i].date.day);
                    continue;
                }
            }
            if(data[i].date.year%4==0&&data[i].date.year%100!=0||data[i].date.year%4!=0)
            {
                if(data[i].date.month==2&&data[i].date.day>28)
                {
                    printf("������������\n");
                    printf("�������������ڣ��ꡢ�¡��գ�:");
                    scanf("%d%d%d",&data[i].date.year,&data[i].date.month,&data[i].date.day);
                    continue;
                }
            }
            break;
        }
    }
    *m+=group;
	return 0;
}
int add_data(Data data[200],int *m,int classify)
{
    int i,j;
	char choice;
	for(i=0;;j++)
    {
        classify_menu();
		printf("��������ѡ������: ");
		printf("\n");
        choice=getchar();
        if(judge_input())
            continue;
        j=0;
        if(choice>=49&&choice<=54)
		{
            switch(choice)
            {
            case 49:
                classify=1;
				if(add_data1(data,m,classify))
					return 1;
                break;
            case 50:
                classify=2;
                if(add_data1(data,m,classify))
					return 1;
                break;
            case 51:
                classify=3;
                if(add_data1(data,m,classify))
					return 1;
                break;
            case 52:
                classify=4;
                if(add_data1(data,m,classify))
					return 1;
                break;
            case 53:
                classify=5;
                if(add_data1(data,m,classify))
					return 1;
                break;
            case 54:
                j=1;
                break;
            }
            if(j==1)
            {
                return 1;
            }
            break;
		}
    }
    getchar();
	return 0;
}
//��������
void save_data(Data data[200],int n)
{
    int i;
    FILE*fp1,*fp2;
	fp1=fopen("D:\\account data.txt","w");
	fp2=fopen("D:\\account data.txt","a+");
	if(n>0)
	{
	    for(i=0;i<n;i++)
		{
			fprintf(fp2,"%10d%10d%10d%10s%10.2f%10d\n",data[i].date.year,data[i].date.month,data[i].date.day,data[i].name,data[i].money,data[i].classify);
		}
	}
	fclose(fp1);
	fclose(fp2);

}
//���ڽ���
void exchangedate(Data data[],int i,int j)
{
	int a,b,c;
	a=data[j].date.year;
	b=data[j].date.month;
	c=data[j].date.day;
	data[j].date.year=data[i].date.year;
	data[j].date.month=data[i].date.month;
	data[j].date.day=data[i].date.day;
	data[i].date.year=a;
	data[i].date.month=b;
	data[i].date.day=c;
}

//���ݽ���
void exchangedata(Data data[],int i,int j)
{
	double n;
	char str[50];
	exchangedate(data,i,j);
	n=data[j].money;
	data[j].money=data[i].money;
	data[i].money=n;
	strcpy(str,data[j].name);
	strcpy(data[j].name,data[i].name);
	strcpy(data[i].name,str);
}


//���������(����)
void ordermoney_down(Data data[], int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(data[i].money<data[j].money)
            {
                exchangedata(data,i,j);
            }
		}
	}
}
//���������(����)
void ordermoney_up(Data data[], int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(data[i].money>data[j].money)
            {
                exchangedata(data,i,j);
            }
        }
    }
}
//���������򣨽���
void orderdate_down(Data data[], int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(data[i].date.year<data[j].date.year)
            {
                exchangedata(data,i,j);
            }
            if(data[i].date.year==data[j].date.year)
            {
                if(data[i].date.month<data[j].date.month)
                {
                    exchangedata(data,i,j);
                }
                if(data[i].date.month==data[j].date.month)
                {
                    if(data[i].date.day<data[j].date.day)
                    {
                        exchangedata(data,i,j);
                    }
                }
            }
        }
	}
}
//��������������
void orderdate_up(Data data[], int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(data[i].date.year>data[j].date.year)
            {
                exchangedata(data,i,j);
            }
            if(data[i].date.year==data[j].date.year)
            {
                if(data[i].date.month>data[j].date.month)
                {
                    exchangedata(data,i,j);
                }
                if(data[i].date.month==data[j].date.month)
                {
                    if(data[i].date.day>data[j].date.day)
                    {
                        exchangedata(data,i,j);
                    }
                }
            }
        }
	}
}
//���������򣨽���
void ordername_down(Data data[], int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(data[i].name,data[j].name)<0)
            {
                exchangedata(data,i,j);
            }
        }
	}
}
//��������������
void ordername_up(Data data[], int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(data[i].name,data[j].name)>0)
            {
                exchangedata(data,i,j);
            }
        }
	}
}

