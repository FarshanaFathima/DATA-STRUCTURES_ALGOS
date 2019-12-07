#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	float at[6];
	float bt[6];
	//int pr[6];
	float wt[6];
	float rr[6];
	for(int i=0;i<6;i++)
	{
		cout<<"enter at and bt \n";
		cin>>at[i];
		cin>>bt[i];
		//cin>>pr[i];
	}
	//sorting..
	int temp,temp1,temp2,counter;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(at[j]>at[j+1])
			{
				temp=at[j];
				at[j]=at[j+1];
				at[j+1]=temp;

				temp1=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp1;

				/*temp2=pr[j];
				pr[j]=pr[j+1];
				pr[j+1]=tem p2;*/
				
				
			}
		}
	}
	cout<<endl;
	for(int i=0;i<6;i++)
	cout<<at[i]<<" "<<bt[i]<<"\n";
	
	int mark1[6];//to mark tje processes that have arrived
	int mark2[6];//to mark the processes that have been completed;
	
	int ct[6];

	for(int i=0;i<6;i++)
	{
		mark1[i]=0;
		mark2[i]=0;wt[i]=0;ct[i]=0;}
	ct[0]=at[0]+bt[0];
	counter=ct[0];
	cout<<counter;
	mark1[0]=1;
	mark2[0]=1;
	wt[0]=0;
	int z=1;
	int flag=0;
	float max;
	int pos,c;
	while(z<6)
	{       flag=0;
		if(at[z]>counter)
		{counter=at[z];}
		for(int i=1;i<6;i++)
		{
			if(at[i]<=counter )
				{mark1[i]=1;//flag=1;
				}
		}
		
		
		 //max=-1; pos=0;
		for(int i=0;i<6;i++)
		{
			if(mark1[i]==1 && mark2[i]!=1)
				{
					wt[i]=counter-at[i];
					rr[i]=(wt[i]+bt[i])/bt[i];
				}
	
		}
		cout<<endl;
		for(int i=0;i<6;i++)
		cout<<wt[i]<<" ";
		cout<<endl;
		max=-1.0;
		
		for(int i=0;i<6;i++)
		{
			if(mark1[i]==1 && mark2[i]!=1)
				{
					if(rr[i]>max)
					{
						max=rr[i];
						pos=i;
					}
					else if(rr[i]==max)
					{
						if(at[i]<at[pos])
						{
							pos=i;
							max=rr[i];
						}
						else
						{
							max=max;
							pos=pos;
						}
					}
				}
	
		}
		ct[pos]=counter+bt[pos];
		counter=ct[pos];
		mark2[pos]=1;
		z++;
		cout<<max;
		cout<<endl;
		for(int k=0;k<6;k++)
		cout<<ct[k]<<" ";
		cout<<endl;
		
		
	}
	cout<<"-----------------------------output--------------------\n";
	cout<<"at	 bt	 wt         ct\n";
	for(int k=0;k<6;k++)
	cout<<at[k]<<"	 "<<bt[k]<<" 	"<<wt[k]<<"		"<<ct[k]<<"\n";
	
return 1;

}


