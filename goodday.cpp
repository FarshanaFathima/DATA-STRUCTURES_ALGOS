#include<stdlib.h>
#include<iostream>
using namespace std;
float k=0,q=0,c=0,c1=0,z=0,c2=0;
class mcsss1
{
	 int a[100],n;
	public:
	void read();
	int msum1();
	int msum2();
	//int msum3();
	int msum4();
};



void mcsss1::read()
{
	cin>>n;
	cout<<"ARRAY"<<endl;

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	k=msum1();
	q=msum2();
	z=msum4();
}




int mcsss1::msum1()
{
	int max=0;
	int j,k,sum;
	for(int i=0;i<n;i++)  //0..........n-1
	{
		for(j=i;j<n;j++)//i,i.i+1.....,i................n-1-----generating subsequence
		{
			sum=0;
			for(k=i;k<=j;k++)     //finding the sum of the subsequence
			{
				sum=sum+a[k];  
				c++;
				if(sum>max)
				max=sum;
			
			}
			
			//cout<<sum<<endl;
			
		}
	}
return c;
}

int mcsss1::msum2()
{
	int max1=0;
	int j,k,sum;
	for(int i=0;i<n;i++)  
	{
		sum=0;
		for(j=i;j<n;j++)
		{
			sum=sum+a[j];
			c1++;
			if(sum>max1)
				max1=sum;
		}
	}
return c1;
}


/*int mcsss1::msum3()
{
	int max2=0;
	int j,k,sum;
	for(int i=0;i<5;i++)  
	{
		sum=0;
		for(j=i;j<5;j++)
		{
			sum=sum+a[j];
			c1++;
			if(sum>max1)
				max1=sum;
		}
	}
return max2;
}*/



int mcsss1::msum4()
{
	int max2=0;
	int j,k,csum=0,maxsum=0;
	for(int i=0;i<n;i++)  
	{
		csum=csum+a[i];
		c2++;
		if(csum<0)
			csum=0;
		else if(csum>maxsum)
			maxsum=csum;
		
	}
return c2;
}














int main()
{	k=0;
	mcsss1 m;
	//for(int i=0;i<100 ;i++)
	m.read();
	cout<<"K IS "<<k<<endl;
	cout<<"Q IS "<<q<<endl;
	cout<<"Z IS "<<z;
	return 0;
}
