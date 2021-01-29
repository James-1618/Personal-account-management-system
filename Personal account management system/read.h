#include<stdio.h>
#include"struct.h"
void read (int *m,Data data[],double *budget)
{
	int i=-1;
	FILE *fp,*fp1;
	fp=fopen("D:\\Account data.txt","r");
	fp1=fopen("D:\\budget data.txt","r");
	if(!fp)
	{
		fp=fopen("D:\\Account data.txt","w");
		return;
	}
	if(!fp1)
	{
		fp1=fopen("D:\\budget data.txt","w");
		return;
	}
	while(!feof(fp))
	{
		*m+=1;
		i+=1;
		fscanf(fp,"%d%d%d%s%lf%d",&data[i].date.year,&data[i].date.month,&data[i].date.day,data[i].name,&data[i].money,&data[i].classify);
		data[i].number=i+1;
	}
	fscanf(fp1,"%lf",budget);
	*m=*m-1;
	fclose(fp);
	fclose(fp1);
	return;
}
