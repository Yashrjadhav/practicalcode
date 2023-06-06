#include<iostream>
#define N 10
using namespace std;

class PriorityQue
{
	public:
		string Q[N];
		int Pr[N];
		int r,f;
		
		PriorityQue(){
			f=r=-1;
		}
		int isFull()
		{
			return (r>=9);
		}
		int isEmpty(){
			return(f=-1);
		}
		void enqueue(string data,int p)
		{
			int i;
			if((f==0)&&(r==N-1))
				cout<<"\nFull..";	
			else
			{
				if(f==-1)
				{
					f=r=0;
					Q[r]=data;
					Pr[r]=p;
				}
				else if(r==N-1)
				{
					for(i=f;i<=r;i++)
					{
						Q[i-f]=Q[i];
						Pr[i-f]=Pr[i];
						r=r-f;
						f=0;
						for(i=r;i>f;i--)
						{
							if(p<Pr[i])
							{
								Q[i+1]=Q[i];
								Pr[i+1]=Pr[i];
							}
							else
								break;
							Q[i+1]=data;
							Pr[i+1]=p;
							r++;
						}
					}
				}
				else
				{
					for(i=r;i>=f;i--)
					{
						if(p<Pr[i])
						{
							Q[i+1]=Q[i];
							Pr[i+1]=Pr[i];
						}
						else
							break;
					}
					Q[i+1]=data;
					Pr[i+1]=p;
					r++;
				}
			}
		}
		void dequeue()
		{
			if(f==-1)
				cout<<"\nEmpty..";
			else
			{
				cout<<"\nPatient "<<Q[f]<<" with priority "<<Pr[f]<<" is deleted..";
				if(f==r)
					f=r=-1;
				else
					f++;
			}
		}
		void display()
		{
			int i;
			for(i=f;i<=r;i++)
			{
				cout<<"\nPatient's Name : "<<Q[i];
				switch(Pr[i])
				{
					case 0:
						cout<<"\nPriority - 'Serious' ";
					break;
	
					case 1:
						cout<<"\nPriority - 'Non-serious' ";
					break;
									
					case 2:
						cout<<"\nPriority - 'CheckUp' ";
					break;
					
					default:
						cout<<"\nPriority not found ";
					break;
				}
			}
		}
		
};

int main()
{
	PriorityQue p;
	string nm;
	int ch,pr,n,i;
	do
 	{
		cout<<"\n______________________________________________\n";
		cout<<"\n\t [1] Add Patients \n\t [2] Display Patient Records\n\t [3] Delete Patient";
		cout<<"\n______________________________________________\n";
  		cout<<"\n Enter your choice: ";
  		cin>>ch;
  		switch(ch)
  		{
  			case 1:	
			  	cout<<"\nEnter number of patients : ";
				cin>>n;
				i=0;
				while(i<n)
				{
					cout<<"\nEnter name of patient : ";
					cin>>nm;
					doagain:
					cout<<"\nEnter priority (0-Serious, 1-Non-serious, 2-General checkup): ";
					cin>>pr;
					switch(pr)
					{
						case 0:
							p.enqueue(nm,0);
						break;
						
						case 1:
							p.enqueue(nm,1);
						break;
						
						case 2:
							p.enqueue(nm,2);
						break;
						
						default: goto doagain;
					}
					i++;
				}
			break;
			
			case 2:
				p.display();
			break;
			
			case 3:
				p.dequeue();
			break;
		}
		cout<<"\n______________________________________________\n";
 		cout<<" Press 1 to continue : ";
 		cin>>ch;
 	}while(ch==1);
 	return 0;
}
