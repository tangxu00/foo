/*************************************************************************
    > File Name: mywork.c
    > Author: dooon
    > Mail: tangxu314@163.com 
    > Created Time: 2016年10月19日 星期三 15时33分25秒
 ************************************************************************/

#include<stdio.h>
#define MAXSIZE 100
typedef struct
{
	char name[16];//student name
	float grade[3];
	float average;
} student;
int main(void)
	{
		int i,j,num,s,b;
		FILE *fp;
		int a;
		float max;
		student stu[MAXSIZE];
		printf ("enter number of students:");
		scanf("%d",&num);
		for(i=0;i<num;i++)
		{
			printf("enter students name:");
			scanf("%s",stu[i].name);
			printf("enter the three score of student:");
			for (j=0,s=0;j<3;j++)
			{
				scanf("%f",&stu[i].grade[j]);
				s=s+stu[i].grade[j];
			}
			stu[i].average=s/3;
		}
		max=stu[0].average;
		b=0;
		for (i=1;i<num+1;i++)
		{
			if(max < stu[i].average)
			{
				max=stu[i].average;
				b=i;
			}
		}
		if((fp=fopen("stu.dat","wb"))==NULL)
		{
			printf("cant open file\n");
			return;
		}
		for(a=0;a<num;a++)
		{
			if(fwrite(&stu[a],sizeof(student),1,fp)!=1)
				{
					fclose(fp);
				}
		}
		printf("\nThe Highest is %10s\nscore1=%.2f  score2=%.2f  score3=%.2f  aver=%.2f\n",stu[b].name,stu[b].grade[1],stu[b].grade[2],stu[b].grade[3],stu[1].average);
		//for(i=0;i<num;i++)
		//	printf("%10s,%4d\n",stu[i].name,stu[i].average);
		
	}
