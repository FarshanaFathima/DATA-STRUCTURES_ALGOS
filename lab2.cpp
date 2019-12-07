#include<stdlib.h>
#include<iostream>
using  namespace std;

class data
{
	int array[100];int size;
	public:
		void input();
		void bsearch(int x);
};
void data::input()
{
    cout<<"Enter the size"<<endl;
	cin>>size;

	for(int i=0;i<size;i++)
		{
			cin>>array[i];
		}
}
void data::bsearch(int x)
{
	int beg=0;int end=size-1;int mid,pos,flag=0;
	while(beg<=end)
		{
			mid=(beg+end)/2;
			if(array[mid]==x)
				{
					pos=mid;
					flag=1;
					break;
				}
			else if(x>array[mid])
				{
					beg=mid+1;
				}
			else if(x<array[mid])
				{
					end=mid-1;
				}
		}
if(flag==0)
cout<<"elt not found";
else
cout<<"elt found at pos"<<pos;
}
int  main()
{
	int no,c;
	data d;
	cout<<"Enter the number u wish to  search";
	cin>>no;
	d.input();
	d.bsearch(no);
 
return 0;
}

