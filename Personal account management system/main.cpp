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
         printf("请输入您选择的序号: ");
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
        printf("请输入您的月预算：");
        for(i=0;;i++)
        {
            scanf("%lf",budget);
            if(budget>0)
                break;
            else
                printf("请输入您正确的月预算：");
        }
        getchar();
		fp=fopen("D:\\budget data.txt","w");
		fprintf(fp,"%f",*budget);
		fclose(fp);
    }
    else
    {
		printf("请问您是否修改月预算\n");
        for(i=0;;i++)
        {
            modify1_menu();
			printf("请输入您选择的序号: ");
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
                    printf("请输入您的月预算：");
                    for(k=0;;k++)
                    {
                        scanf("%lf",budget);
                        if(*budget>0)
                            break;
                        else
                            printf("请输入您正确的月预算：");
                    }
                    getchar();
                    printf("修改成功\n");
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
		printf("请输入您选择的序号: ");
		printf("\n");
        choice[0]=getchar();
        if(judge_input())
            continue;
        if(choice[0]>=49&&choice[0]<=51)
        {
            j[0]=0;
            switch(choice[0])
            {
            case 49://修改
				number=choose_number(a,n);
                for(i[1]=0;;i[1]++)
                {
                    modify_menu();
					printf("请输入您选择的序号: ");
					printf("\n");
                    choice[1]=getchar();
                    if(judge_input())
                        continue;
                    j[1]=0;
                    if(choice[1]>=49&&choice[1]<=52)
                    {
                        switch(choice[1])
                        {
                        case 49://修改日期
                            modifydate(data,number);
                            display(data,n);
							save_change(data,n);
                            return 1;
                        case 50://修改名称
                            modifyname(data,number);
                            display(data,n);
                            save_change(data,n);
                            return 1;
                        case 51://修改金额
                            modifymoney(data,number);
                            display(data,n);
                            save_change(data,n);
                            return 1;
                        case 52://返回上一级菜单
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
            case 50://删除
                delete_data(data,a,&n);
                display(data,n);
                save_change(data,n);
                return 1;
            case 51://返回上一级菜单
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
	printf("\n       账        本  \n\n");
	read(&n,data,&budget);
	for(i[0]=0;;i[0]++)  //第一层菜单
	{
		menu();
		printf("请输入您选择的序号: ");
		printf("\n");
		choice[0]=getchar();
		if(judge_input())
            continue;
		j[0]=0;
        if(choice[0]>=49&&choice[0]<=54)
		{
			switch(choice[0])
			{
            case 49://添加数据
                if(add_data(data,&n,classify))
					break;
                for(i[1]=0;;i[1]++)
                {
                    save_menu();
                    printf("请输入您选择的序号: ");
					printf("\n");
                    choice[1]=getchar();
					if(judge_input())
                        continue;
					if(choice[1]>=49&&choice[1]<=50)
					{
						switch(choice[1])
						{
                        case 49://保存数据
							save_data(data,n);
							break;
						case 50:
							break;
						}
						break;
					}
				}
				break;
			case 50://查找,修改，删除数据
			    for(i[6]=0;;i[6]++)
                {
                    search_menu();
                    printf("请输入您选择的序号: ");
					printf("\n");
                    choice[6]=getchar();
					if(judge_input())
                        continue;
					if(choice[6]>=49&&choice[6]<=54)
					{
						switch(choice[6])
						{
                        case 49://按日期查找
                            searchdatadate(data,n,b);
							if(b[0]==0)
								continue;
                            if(del_change1(data,n,b))
								j[0]=1;
							break;
                        case 50://按名称查找
                            searchdataname(data,n,c);
							if(c[0]==0)
								continue;
                            if(del_change1(data,n,c))
								j[0]=1;
                            break;
                        case 51:///按金额查找
                            searchdatamoney(data,n,d);
							if(d[0]==0)
								continue;
                            if(del_change1(data,n,d))
								j[0]=1;
                            break;
                        case 52://按序号查找
                            searchdatanumber(data,n,a);
							if(a[0]==0)
								continue;
                            if(del_change1(data,n,a))
								j[0]=1;
                            break;
                        case 53://返回上一级菜单
                            j[0]=1;
                            break;
                        case 54://退出
                            return;
						}
						if(j[0]==1)
                            break;
					}
                }
                break;
            case 51://显示数据
			    for(i[2]=0;;i[2]++)
                {
                    order_menu();
                    printf("请输入您选择的序号: ");
					printf("\n");
                    choice[2]=getchar();
					if(judge_input())
                        continue;
                    if(choice[2]>=49&&choice[2]<=53)
					{
						switch(choice[2])
						{
                        case 49://按日期排序
							for(i[3]=0;;i[3]++)
						    {
							   	up_down_menu();
							    printf("请输入您选择的序号: ");
								printf("\n");
						        choice[3]=getchar();
								if(judge_input())
									 continue;
								j[1]=0;
								if(choice[3]>=49&&choice[3]<=52)
								{
									switch(choice[3])
									{
									case 49://按日期升序
										orderdate_up(data,n);
										display(data,n);
										break;
									case 50://按日期降序
										orderdate_down(data,n);
										display(data,n);
										break;
									case 51://返回上一级菜单
										j[1]=1;
										break;
									case 52://退出
										return;
									}
								}
								if(j[1]==1)
									break;
							}
							break;
						case 50://按名称排序
							for(i[4]=0;;i[4]++)
							{
								up_down_menu();
						        printf("请输入您选择的序号: ");
								printf("\n");
								choice[4]=getchar();
								if(judge_input())
									 continue;
								j[1]=0;
								if(choice[4]>=49&&choice[4]<=52)
								{
									switch(choice[4])
									{
									case 49://按名称升序
										ordername_up(data,n);
										display(data,n);
										break;
									case 50://按名称降序
										ordername_down(data,n);
										display(data,n);
										break;
									case 51://返回上一级菜单
										j[1]=1;
										break;
									case 52://退出
										return;
									}
								}
								if(j[1]==1)
									break;
							}
                                    break;
                        case 51://按金额排序
							for(i[5]=0;;i[5]++)
							{
								up_down_menu();
								printf("请输入您选择的序号: ");
								printf("\n");
						        choice[5]=getchar();
								if(judge_input())
									 continue;
								j[1]=0;
								if(choice[5]>=49&&choice[5]<=52)
								{
									switch(choice[5])
									{
									case 49://升序
										ordermoney_up(data,n);
										display(data,n);
										break;
									case 50://降序
										ordermoney_down(data,n);
										display(data,n);
										break;
									case 51://返回上一级菜单
										j[1]=1;
										break;
									case 52://退出
										return;
									}
								}
								if(j[1]==1)
									break;
							}
							break;
                        case 52://返回上一级菜单
							j[0]=1;
							break;
                        case 53://退出
                            return;
                        }
                        if(j[0]==1)
                            break;
					}
                }
                break;
            case 52://统计
                for(i[7]=0;;i[7]++)
                {
                    classify_statistial_menu();
					printf("请输入您选择的序号: ");
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
            case 53://预算
                budget1_(&budget);
                break;
			case 54://退出
				return;
			}
        }
	}

}




