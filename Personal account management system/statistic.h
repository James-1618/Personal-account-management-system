#include<stdio.h>
#include"struct.h"

//统计
void statisticyear(Data data[],int n,double budget)
{
	int i,j,m=0,a[100]={0};
	double k;
	double in[100]={0};
	double out[100]={0};
	double sum[100]={0};
	if(n>0)
    {
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                if(i!=j)
                {
                    if(data[j].date.year==data[i].date.year)
                    {
                        j=n+1;
                        break;
                    }
                }
            }
            if(j<n+1)
            {
                a[m]=data[i].date.year;
                m++;
            }
        }
        for(i=0;i<m-1;i++)
        {
            for(j=i+1;j<m;j++)
            {
                if(a[i]<a[j])
                {
                    a[n+1]=a[i];
                    a[i]=a[j];
                    a[j]=a[n+1];
                }
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(data[j].date.year==a[i])
                {
                    if(data[j].money>0)
                        in[i]+=data[j].money;
                    if(data[j].money<0)
                        out[i]+=data[j].money;
                    sum[i]+=data[j].money;
                }
            }

        }
        k=budget; //budget为预算函数返回值
        for(i=0;i<m;i++)
        {
            if(k!=0)
            {
                if(fabs(out[i])<12*k)
                {
					if(i==0)
						printf("       年份     收入      支出  总计金额  支出超出预算\n");
                    printf("%10d%10.2f%10.2f%10.2f\n",a[i],in[i],out[i],sum[i]);
                }
                if(fabs(out[i])>12*k)
                {
					if(i==0)
						 printf("       年份     收入      支出  总计金额  支出超出预算\n");
                    printf("%10d%10.2f%10.2f%10.2f%15.2f \n",a[i],in[i],out[i],sum[i],k*12-fabs(out[i]));
                }
            }
            else
            {
				if(i==0)
					printf("       年份     收入      支出  总计金额\n");
                printf("%10d%10.2f%10.2f%10.2f\n",a[i],in[i],out[i],sum[i]);
            }
        }
    }
    else
        printf("无记录\n");
}

//按月份统计
void statisticmonth(Data data[],int n,double budget)
{
	int i,j,m=0,a[100]={0},b[100]={0};
	double k;
	double in[100]={0};
	double out[100]={0};
	double sum[100]={0};
	if(n>0)
    {
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
				if(i!=j)
				{
					if(data[j].date.year==data[i].date.year)
					{
						if(data[j].date.month==data[i].date.month)
                        {
                            j=n+1;
							break;
                        }
					}
				}
            }
            if(j<n+1)
            {
                a[m]=data[i].date.year;
                b[m]=data[i].date.month;
                m++;
            }
        }
        for(i=0;i<m-1;i++)
        {
            for(j=i+1;j<m;j++)
            {
                if(a[i]<a[j])
                {
                    a[n+1]=a[i];
                    a[i]=a[j];
                    a[j]=a[n+1];
                    b[n+1]=b[i];
                    b[i]=b[j];
                    b[j]=b[n+1];
                }
                if(a[i]==a[j])
                {
                    if(b[i]<b[j])
                    {
                        b[n+1]=b[i];
                        b[i]=b[j];
                        b[j]=b[n+1];
                    }
                }
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(data[j].date.year==a[i])
                {
                    if(data[j].date.month==b[i])
                    {
                        if(data[j].money>0)
                            in[i]+=data[j].money;
                        if(data[j].money<0)
                            out[i]+=data[j].money;
                        sum[i]+=data[j].money;
                    }
                }
            }

        }
        k=budget; //budget为预算函数返回值
        for(i=0;i<m;i++)
        {
            if(k!=0)
            {
                if(fabs(out[i])<k)
                {
					if(i==0)
						 printf("        年        月      收入      支出  总计金额   支出超出预算\n");
                    printf("%10d%10d%10.2f%10.2f%10.2f\n",a[i],b[i],in[i],out[i],sum[i]);
                }
                if(fabs(out[i])>k)
                {
					if(i==0)
						 printf("        年        月      收入      支出  总计金额   支出超出预算\n");
                    printf("%10d%10d%10.2f%10.2f%10.2f%15.2f \n",a[i],b[i],in[i],out[i],sum[i],k-fabs(out[i]));
                }
            }
            else
            {
				if(i==0)
					printf("        年        月      收入      支出  总计金额\n");
                printf("%10d%10d%10.2f%10.2f%10.2f\n",a[i],b[i],in[i],out[i],sum[i]);
            }
        }
    }
    else
        printf("无记录\n");
}
//按日统计
void statisticday(Data data[],int n,double budget)
{
	int i,j,m=0,a[100]={0},b[100]={0},c[100]={0};
	double k;
	double in[100]={0};
	double out[100]={0};
	double sum[100]={0};
	if(n>0)
    {
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
				if(i!=j)
				{
				    if(data[j].date.year==data[i].date.year)
					{
						if(data[j].date.month==data[i].date.month)
                        {
                            if(data[j].date.day==data[i].date.day)
                                j=n+1;
                                break;
                        }
					}
				}

            }
            if(j<n+1)
            {
                a[m]=data[i].date.year;
                b[m]=data[i].date.month;
                c[m]=data[i].date.day;
                m++;
            }
        }
        for(i=0;i<m-1;i++)
        {
            for(j=i+1;j<m;j++)
            {
                if(a[i]<a[j])
                {
                    a[n+1]=a[i];
                    a[i]=a[j];
                    a[j]=a[n+1];
                    b[n+1]=b[i];
                    b[i]=b[j];
                    b[j]=b[n+1];
                    c[n+1]=c[i];
                    c[i]=c[j];
                    c[j]=c[n+1];
                }
                if(a[i]==a[j])
                {
                    if(b[i]<b[j])
                    {
                        b[n+1]=b[i];
                        b[i]=b[j];
                        b[j]=b[n+1];
                        c[n+1]=c[i];
                        c[i]=c[j];
                        c[j]=c[n+1];
                    }
                    if(b[i]==b[j])
                    {
                        if(c[i]<c[j])
                        {
                            c[n+1]=c[i];
                            c[i]=c[j];
                            c[j]=c[n+1];
                        }
                    }
                }
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(data[j].date.year==a[i])
                {
                    if(data[j].date.month==b[i])
                    {
                        if(data[j].date.day==c[i])
                        {
                            if(data[j].money>0)
                                in[i]+=data[j].money;
                            if(data[j].money<0)
                                out[i]+=data[j].money;
                            sum[i]+=data[j].money;
                        }
                    }
                }
            }
        }
        k=budget; //budget为预算函数返回值
        for(i=0;i<m;i++)
        {
            if(k!=0)
            {
                if(fabs(out[i])<k/30)
                {
					if(i==0)
						printf("        年        月        日      收入      支出  总计金额   支出超出预算\n");
                    printf("%10d%10d%10d%10.2f%10.2f%10.2f\n",a[i],b[i],c[i],in[i],out[i],sum[i]);
                }
                if(fabs(out[i])>k/30)
                {
					if(i==0)
						printf("        年        月        日      收入      支出  总计金额   支出超出预算\n");
                    printf("%10d%10d%10d%10.2f%10.2f%10.2f%15.2f \n",a[i],b[i],c[i],in[i],out[i],sum[i],k/30-fabs(out[i]));
                }
            }
            else
            {
				if(i==0)
					printf("        年        月        日      收入      支出  总计金额\n");
                printf("%10d%10d%10d%10.2f%10.2f%10.2f\n",a[i],b[i],c[i],in[i],out[i],sum[i]);
            }
        }
    }
    else
        printf("无记录\n");
}
int statistical(Data data[],int n,double budget)
{
    int i,j;
	char choice;
    for(i=0;;i++)
    {
        statistial_menu();
		printf("请输入您选择的序号: ");
		printf("\n");
        choice=getchar();
        if(judge_input())
            continue;
        if(choice>=49&&choice<=53)
        {
            j=0;
            switch(choice)
            {
            case 49://按年统计
                statisticyear(data,n,budget);
                break;
            case 50://按月统计
                statisticmonth(data,n,budget);
                break;
            case 51://按日统计
                statisticday(data,n,budget);
                break;
            case 52://返回上一级菜单
                j=1;
                break;
            }
            if(j==1)
                return 1;
        }
    }
    return 0;
}
void classify_statistical(Data data[],int n,double budget,int classify)
{
    int i[2];
    Data classify_data[200];
    i[0]=0;
    for(i[1]=0;i[1]<n;i[1]++)
    {
        if(data[i[1]].classify==classify)
        {
            classify_data[i[0]].classify=data[i[1]].classify;
            classify_data[i[0]].number=data[i[1]].number;
            strcpy(classify_data[i[0]].name,data[i[1]].name);
            classify_data[i[0]].date.year=data[i[1]].date.year;
            classify_data[i[0]].date.month=data[i[1]].date.month;
            classify_data[i[0]].date.day=data[i[1]].date.day;
            classify_data[i[0]].money=data[i[1]].money;
            i[0]++;
        }
    }
    statistical(classify_data,i[0],budget);
}
