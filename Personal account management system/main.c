#include<stdio.h>
#include<string.h>
#include"read.h"
#include"menu.h"
#include"struct.h"
#include"add_save_display.h"
#include"search.h"
#include"del_change.h"
#include"statistic.h"

void save_change(Data data[200],int n)
{
	int i[3];
	char choice[3];
	for(i[2]=0;;i[2]++)
    {
         save_menu();
         printf("��������ѡ������: ");
	   	 printf("\n");
         choice[2]=getchar();
		 if(judge_input())
			 continue;
		 if(choice[2]>=49&&choice[2]<=53)
		 {
			 switch(choice[2])
			 {
			 case 49:
                   save_data(data,n);
                   break;
             case 50:
                   break;
             }
			 break;
         }
     }
}
void budget1_(double *budget)
{

    char choice;
    int i,j=0,k;
	FILE *fp;
    if(*budget==0)
    {
        printf("������������Ԥ�㣺");
        for(i=0;;i++)
        {
            scanf("%lf",budget);
            if(budget>0)
                break;
            else
                printf("����������ȷ����Ԥ�㣺");
        }
        getchar();
		fp=fopen("D:\\budget data.txt","w");
		fprintf(fp,"%f",*budget);
		fclose(fp);
    }
    else
    {
		printf("�������Ƿ��޸���Ԥ��\n");
        for(i=0;;i++)
        {
            modify1_menu();
			printf("��������ѡ������: ");
			printf("\n");
            choice=getchar();
            if(judge_input())
                continue;
            if(choice>=49&&choice<=50)
            {
                j=0;
                switch(choice)
                {
                case 49:
                    printf("������������Ԥ�㣺");
                    for(k=0;;k++)
                    {
                        scanf("%lf",budget);
                        if(*budget>0)
                            break;
                        else
                            printf("����������ȷ����Ԥ�㣺");
                    }
                    getchar();
                    printf("�޸ĳɹ�\n");
					fp=fopen("D:\\budget data.txt","w");
					fprintf(fp,"%f",*budget);
					fclose(fp);
                    break;
                case 50:
                    j=1;
                    break;
                }
                if(j==1)
                    return;
                break;
            }
        }
    }
}
int del_change1(Data data[] ,int n,int a[])
{
    int i[5],j[2],number;
    char choice[6];
    for(i[0]=0;;i[0]++)
    {
        del_change_menu();
		printf("��������ѡ������: ");
		printf("\n");
        choice[0]=getchar();
        if(judge_input())
            continue;
        if(choice[0]>=49&&choice[0]<=51)
        {
            j[0]=0;
            switch(choice[0])
            {
            case 49://�޸�
				number=choose_number(a,n);
                for(i[1]=0;;i[1]++)
                {
                    modify_menu();
					printf("��������ѡ������: ");
					printf("\n");
                    choice[1]=getchar();
                    if(judge_input())
                        continue;
                    j[1]=0;
                    if(choice[1]>=49&&choice[1]<=52)
                    {
                        switch(choice[1])
                        {
                        case 49://�޸�����
                            modifydate(data,number);
                            display(data,n);
							save_change(data,n);
                            return 1;
                        case 50://�޸�����
                            modifyname(data,number);
                            display(data,n);
                            save_change(data,n);
                            return 1;
                        case 51://�޸Ľ��
                            modifymoney(data,number);
                            display(data,n);
                            save_change(data,n);
                            return 1;
                        case 52://������һ���˵�
                            j[1]=1;
                            break;
                        }
                        if(j[1]==1)
                        {
                            break;
                        }
                    }
                }
                break;
            case 50://ɾ��
                delete_data(data,a,&n);
                display(data,n);
                save_change(data,n);
                return 1;
            case 51://������һ���˵�
                j[0]=1;
                break;
            }
            if(j[0]==1)
                break;
        }
    }
    return 0;
}
void main()
{
	Data data[200];
	int classify=0;
	int i[20],j[20],n=0,a[200],b[200],c[200],d[200];
	char choice[20];
	double budget=0;
	printf("\n       ��        ��  \n\n");
	read(&n,data,&budget);
	for(i[0]=0;;i[0]++)  //��һ��˵�
	{
		menu();
		printf("��������ѡ������: ");
		printf("\n");
		choice[0]=getchar();
		if(judge_input())
            continue;
		j[0]=0;
        if(choice[0]>=49&&choice[0]<=54)
		{
			switch(choice[0])
			{
            case 49://�������
                if(add_data(data,&n,classify))
					break;
                for(i[1]=0;;i[1]++)
                {
                    save_menu();
                    printf("��������ѡ������: ");
					printf("\n");
                    choice[1]=getchar();
					if(judge_input())
                        continue;
					if(choice[1]>=49&&choice[1]<=50)
					{
						switch(choice[1])
						{
                        case 49://��������
							save_data(data,n);
							break;
						case 50:
							break;
						}
						break;
					}
				}
				break;
			case 50://����,�޸ģ�ɾ������
			    for(i[6]=0;;i[6]++)
                {
                    search_menu();
                    printf("��������ѡ������: ");
					printf("\n");
                    choice[6]=getchar();
					if(judge_input())
                        continue;
					if(choice[6]>=49&&choice[6]<=54)
					{
						switch(choice[6])
						{
                        case 49://�����ڲ���
                            searchdatadate(data,n,b);
							if(b[0]==0)
								continue;
                            if(del_change1(data,n,b))
								j[0]=1;
							break;
                        case 50://�����Ʋ���
                            searchdataname(data,n,c);
							if(c[0]==0)
								continue;
                            if(del_change1(data,n,c))
								j[0]=1;
                            break;
                        case 51:///��������
                            searchdatamoney(data,n,d);
							if(d[0]==0)
								continue;
                            if(del_change1(data,n,d))
								j[0]=1;
                            break;
                        case 52://����Ų���
                            searchdatanumber(data,n,a);
							if(a[0]==0)
								continue;
                            if(del_change1(data,n,a))
								j[0]=1;
                            break;
                        case 53://������һ���˵�
                            j[0]=1;
                            break;
                        case 54://�˳�
                            return;
						}
						if(j[0]==1)
                            break;
					}
                }
                break;
            case 51://��ʾ����
			    for(i[2]=0;;i[2]++)
                {
                    order_menu();
                    printf("��������ѡ������: ");
					printf("\n");
                    choice[2]=getchar();
					if(judge_input())
                        continue;
                    if(choice[2]>=49&&choice[2]<=53)
					{
						switch(choice[2])
						{
                        case 49://����������
							for(i[3]=0;;i[3]++)
						    {
							   	up_down_menu();
							    printf("��������ѡ������: ");
								printf("\n");
						        choice[3]=getchar();
								if(judge_input())
									 continue;
								j[1]=0;
								if(choice[3]>=49&&choice[3]<=52)
								{
									switch(choice[3])
									{
									case 49://����������
										orderdate_up(data,n);
										display(data,n);
										break;
									case 50://�����ڽ���
										orderdate_down(data,n);
										display(data,n);
										break;
									case 51://������һ���˵�
										j[1]=1;
										break;
									case 52://�˳�
										return;
									}
								}
								if(j[1]==1)
									break;
							}
							break;
						case 50://����������
							for(i[4]=0;;i[4]++)
							{
								up_down_menu();
						        printf("��������ѡ������: ");
								printf("\n");
								choice[4]=getchar();
								if(judge_input())
									 continue;
								j[1]=0;
								if(choice[4]>=49&&choice[4]<=52)
								{
									switch(choice[4])
									{
									case 49://����������
										ordername_up(data,n);
										display(data,n);
										break;
									case 50://�����ƽ���
										ordername_down(data,n);
										display(data,n);
										break;
									case 51://������һ���˵�
										j[1]=1;
										break;
									case 52://�˳�
										return;
									}
								}
								if(j[1]==1)
									break;
							}
                                    break;
                        case 51://���������
							for(i[5]=0;;i[5]++)
							{
								up_down_menu();
								printf("��������ѡ������: ");
								printf("\n");
						        choice[5]=getchar();
								if(judge_input())
									 continue;
								j[1]=0;
								if(choice[5]>=49&&choice[5]<=52)
								{
									switch(choice[5])
									{
									case 49://����
										ordermoney_up(data,n);
										display(data,n);
										break;
									case 50://����
										ordermoney_down(data,n);
										display(data,n);
										break;
									case 51://������һ���˵�
										j[1]=1;
										break;
									case 52://�˳�
										return;
									}
								}
								if(j[1]==1)
									break;
							}
							break;
                        case 52://������һ���˵�
							j[0]=1;
							break;
                        case 53://�˳�
                            return;
                        }
                        if(j[0]==1)
                            break;
					}
                }
                break;
            case 52://ͳ��
                for(i[7]=0;;i[7]++)
                {
                    classify_statistial_menu();
					printf("��������ѡ������: ");
					printf("\n");
                    choice[7]=getchar();
                    if(judge_input())
                        continue;
                    if(choice[7]>=49&&choice[7]<=568)
                    {
                        j[2]=0;
                        switch(choice[7])
                        {
                        case 49:
                            statistical(data,n,budget);
                            break;
                        case 50:
                            classify_statistical(data,n,budget,1);
                            break;
                        case 51:
                            classify_statistical(data,n,budget,2);
                            break;
                        case 52:
                            classify_statistical(data,n,budget,3);
                            break;
                        case 53:
                            classify_statistical(data,n,budget,4);
                            break;
                        case 54:
                            classify_statistical(data,n,budget,5);
                        case 55:
                            j[2]=1;
                                break;
                        case 56:
                            return;
                        }
                        if(j[2]==1)
                            break;
                    }
                }
                break;
            case 53://Ԥ��
                budget1_(&budget);
                break;
			case 54://�˳�
				return;
			}
        }
	}

}




