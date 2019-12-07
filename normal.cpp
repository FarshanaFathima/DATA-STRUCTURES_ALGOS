#include<iostream>
#include<stdio.h>

using namespace std;
class ihts
{
	private:
	int n,num;
	char Array[100];
	struct node
	{
		char f1[100];
		char f2[100];
	}n1[100];

	public:
	void input();
	void candidate();
};


void ihts::input()
{
	
	cout<<"Enter the number of elements in the relation"<<endl;
	cin>>n;
	cout<<"Enter the Array";
	cin>>Array;
	
	cout<<"Enter the number of FD's"<<endl;
	cin>>num;
	cout<<"Enter the functional dependancies";
	for(int i=0;i<num;i++)
	{
		
		cin>>n1[i].f1;
		cout<<"->";
		cin>>n1[i].f2;
		cout<<endl;
		
	}
}

void ihts::candidate()
{
		int carray[n];
		for(i=0;i<n;i++)
		{
			carray[i]=0;
		}
		for(i=0;i<n;i++)
		{
			
		}
}


void ihts::
int main()
{
	ihts h;
	h.input();
	h.candidate();
	return 0;

}
