#include<stdio.h>
int choose_number(int a[],int n)         //�޸�����
{
    int i,j,number;
	printf("�����������޸ĵ��������:");
    for(j=0;;j++)
    {
        scanf("%d",&number);
        for(i=1;i<=a[0];i++)
        {
            if(number==a[i]+1)
			{
				getchar();
                return number;
			}
        }
        printf("��������ȷ����ţ�");
    }
    return 0;
}

void modifydate(Data s[],int number)
{
    int year,month,day,i;
    for(i=0;;i++)
    {
		printf("�������޸ĺ�����ڣ�");					//�޸�����
        scanf("%d%d%d",&year,&month,&day);
        s[number-1].date.year=year;
        s[number-1].date.month=month;
        s[number-1].date.day=day;
        if(year<=0)
        {
            printf("������������\n");
            continue;
        }
        if(month>12||month<1)
        {
            printf("������������\n");
            continue;
        }
        if(year%4==0&&year%100!=0)
        {
            if(((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&(day>31||day<1))||((month==4||month==6||month==9||month==11)&&(day>30||day<1))||(month==2&&(day>29||day<1)))
            {
                if((year<=0)||(month>12||month<1)||((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&(day>31||day<1))||((month==4||month==6||month==9||month==11)&&(day>30||day<1))||(month==2&&(year%4==0&&year%100!=0)&&(day>29||day<1))||(month==2&&(year%4!=0)&&(day>28||day<1)));
                {
                    printf("������������\n");
                    continue;
                }
            }
        }
        if(((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&(day>31||day<1))||((month==4||month==6||month==9||month==11)&&(day>30||day<1))||(month==2&&(day>28||day<1)))
        {
            if((year<=0)||(month>12||month<1)||((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&(day>31||day<1))||((month==4||month==6||month==9||month==11)&&(day>30||day<1))||(month==2&&(year%4==0&&year%100!=0)&&(day>29||day<1))||(month==2&&(year%4!=0)&&(day>28||day<1)));
            {
                printf("������������\n");
                continue;
            }
        }
        else
            break;

    }
    getchar();

}
void modifyname(Data s[],int number)
{
    char name[100];
    printf("�������޸ĺ�����ƣ�");           //�޸�����
    scanf("%s",name);
    strcpy(s[number-1].name,name);
	getchar();
}
void modifymoney(Data s[],int number)
{
    double money;
    printf("�������޸ĺ�Ľ�");               //�޸Ľ��
    scanf("%lf",&money);
    getchar();
    s[number-1].money=money;
}


void delete_data(Data s[],int a[],int *n)     //ɾ��
{
	int i,j,number;
	printf("����������ɾ����������ţ�");
    for(j=0;;j++)
    {
        scanf("%d",&number);
        for(i=1;i<=a[0];i++)
        {
            if(number==a[i]+1)
			{
				j=-1;
				break;
			}
        }
		if(j==-1)
			break;
        printf("��������ȷ����ţ�");
    }
	getchar();
	for(i=0;i<*n;i++)
	{
		if(s[i].number==number)
		{
		    for(;i<*n-1;i++)
            {
                s[i].date.year=s[i+1].date.year;
                s[i].date.month=s[i+1].date.month;
                s[i].date.day=s[i+1].date.day;
                strcpy(s[i].name,s[i+1].name);
                s[i].money=s[i+1].money;
            }
		}
	}
	*n=*n-1;
}
