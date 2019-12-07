#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>



//

int m=0;

using namespace std;
class hf
{
	private:
		char alp[100],arr[100],dup[100],dec[100];
		struct tree
		{
			char ch;
			int freq;
			struct tree *lptr=NULL;
			struct tree *rptr=NULL;
			
		}t[100];
		struct tree *hptr=NULL;
		struct code
		{
			char encodedchar;
			char encode[100];
			
		}co[100];
	public:
		void read();
		void build();
		void enc(struct tree *ptr,int top,char arr[100]);
		void print();
		void findelt(char x);
		void decode(int declen);

		
};

void hf::read()
{
	cout<<"Enter the string:"<<endl;
	cin>>alp;
	int len;
	len=strlen(alp);
	strcpy(dup,alp);
	sort(alp,alp+len);
	cout<<endl<<alp;
	int c=0;
	for(int i=0;i<len;)
		{
			c=0;
			char s=alp[i];
			while(s==alp[i])
			{
				c++;
				i++;

			}
			int r=i-1;
			t[m].ch=alp[r];
			t[m].freq=c;
			m++;

		}

	for(int i=0;i<m;i++)
		cout<<t[i].ch<<t[i].freq<<endl;

	cout<<endl;
	
	cout<<endl;
	build();
	cout<<endl<<"--------printing encoded sequence for-------"<<endl;
	cout<<dup<<endl;
    for(int i=0;i<len;i++)
	{
		findelt(dup[i]);
	}
	cout<<endl<<"Enter the sequence u want to decode"<<endl;
	cin>>dec;
	
	//cout<<"hi";
	int declen;
	declen=strlen(dec);
	//cout<<"hi";
	//cout<<"hptr in read:"<<hptr;
	decode(declen);
	
}

void hf::decode(int declen)
{
struct tree *ptr1=hptr;

 
	int k=0;
	if(ptr1!=NULL)
  {
	//cout<<"sup";
	while(k<=declen)
	{     
			
		//cout<<"bro!!"<<endl;
			if(ptr1->lptr==NULL && ptr1->rptr==NULL)
			{
				
				cout<<ptr1->ch;
				ptr1=hptr;
			}
			
				if(dec[k]=='0')
					{ 
					ptr1=ptr1->lptr;k++;}
				else
					{ptr1=ptr1->rptr;
				k++;}
			
		
	
			
	}
}
else
cout<<"wrong";

}



void hf::build()
{
	int beg=0,end=m;int sw1;char sw2; struct tree *sw3=NULL;struct tree *sw4=NULL;
	while(beg<end-1)
		{
            cout<<"Beg:"<<beg<<"End:"<<end<<endl;
 			//int sw1;char sw2; struct tree *sw3=NULL;struct tree *sw4=NULL;
			for(int i=beg;i<end;i++)
			{
				for(int j=beg;j<end-1;j++)
				{
					if(t[j].freq>t[j+1].freq)
					{
						sw1=t[j].freq;
						t[j].freq=t[j+1].freq;
						t[j+1].freq=sw1;
						
						sw2=t[j].ch;
						t[j].ch=t[j+1].ch;
						t[j+1].ch=sw2;
						
						sw3=t[j].lptr;
						t[j].lptr=t[j+1].lptr;
						t[j+1].lptr=sw3;
						
						sw4=t[j].rptr;
						t[j].rptr=t[j+1].rptr;
						t[j+1].rptr=sw4;
						
					}
				}
			}

 
        
		t[end].freq=t[beg].freq+t[beg+1].freq;
		t[end].ch=' ';
		t[end].lptr=&t[beg];
		t[end].rptr=&t[beg+1];
		//beg=beg+2;
		cout<<endl;
		for(int y=beg;y<=end;y++)
		cout<<t[y].ch<<" : "<<t[y].freq<<endl;
		cout<<"--------------------------------------------------";
		end++;
		beg=beg+2;
	cout<<endl<<endl;
		for(int y=beg;y<end;y++)
		cout<<t[y].ch<<" : "<<t[y].freq<<endl;
		}

      hptr=&t[beg];
		
      enc(hptr,0,arr);
	  cout<<endl;
	  print();
	cout<<"hptr"<<hptr<<endl;
		
}





int d=0;

void hf::enc(struct tree *ptr,int top,char arr[100])
{
	if(ptr->lptr!=NULL)
	{
		
		arr[top]='0';
		enc(ptr->lptr,top+1,arr);
	}
	 if(ptr->rptr!=NULL)
	{
		arr[top]='1';
		enc(ptr->rptr,top+1,arr);
	}
	if(ptr->lptr==NULL && ptr->rptr==NULL)
	{
		co[d].encodedchar=ptr->ch;
		for(int  i=0;i<top;i++)
		{
			co[d].encode[i]=arr[i];
		}
		d++;
	}
}





void hf::print()
{
	cout<<"d:"<<d<<endl;
 for(int i=0;i<d;i++)
 {
  cout<<co[i].encodedchar<<" "<<co[i].encode;
  cout<<endl;
 }
}


 
char z;

void hf::findelt(char x)
{

    
	for(int i=0;i<d;i++)
	{
		if(co[i].encodedchar==x)
		{
			cout<<co[i].encode<<" ";
		}
	}
}














/*void hf::print(struct tree *ptr)
{
 if(ptr!=NULL)
 {
  print(ptr->lptr);
  cout<<ptr->ch<<"---"<<ptr->freq<<"-------"<<ptr->str<<endl;
  print(ptr->rptr);
 }
}*/


int main()
{
	hf h;
	h.read();
	
 return 0;
}
