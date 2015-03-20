#include<iostream>
using namespace std;
const int N=100;
int s[2][N],top=-1,n;		//STACK
void push(int i,int j)	//PUSH FUNCTION
{
	if(top==N-1)
	{	}
	else
	{
		s[0][++top]=i;
		s[1][top]=j;
	}
}
int pop(int &i,int &j)	//POP FUNCTION
{
	if(top==-1)
		return 0;
	else
	{
		i=s[0][top];
		j=s[1][top--];
		return 1;
	}
}
int check(int a[][N],int i,int j)//TO CHECK WHETHER a[i][j] IS SUITABLE FOR PLACING THE QUEEN
{
	int x,y;
	for(x=0;x<n;x++)
	{
		if(a[x][j]==1)				//CHECK HORIZONTALLY
			return 0;
		if(a[i][x]==1)				//CHECK VERTICALLY
			return 0;
	}
	for(x=i,y=j;x<n&&y<n;x++,y++)	//CHECK TILL RIGHT DOWN CORNER
	{
		if(a[x][y]==1)
			return 0;
	}
	for(x=i,y=j;x>=0&&y>=0;x--,y--)	//CHECK TILL LEFT TOP CORNER
	{
		if(a[x][y]==1)
			return 0;
	}

	for(x=i,y=j;x>=0&&y<n;x--,y++)	//CHECK TILL LEFT DOWN CORNER
	{
		if(a[x][y]==1)
			return 0;
	}
	for(x=i,y=j;x<n&&y>=0;x++,y--)	//CHECK TILL RIGHT TOP CORNER
	{
		if(a[x][y]==1)
			return 0;
	}
	return 1;
}
int main()
{
	int a[N][N],i,j,k=0;
	cout<<"Enter the value of N:";
	cin>>n;
	for(i=0;i<n;i++)			//INTIALIZATION
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=0;
		}
	}
	int i1,j1;
	do
	{
		if(pop(i1,j1)==1)		//BACKTRACKING
		{
			k--;
			a[i1][j1]=0;
			j1++;
			if(j1==n)
			{
				i1++;
				j1=0;
			}
		}
		else
			i1=j1=0;
		for(i=i1;i<n;i++)
		{
			for(j=j1;j<n;j++)
			{
				if(check(a,i,j)==1)
				{
					a[i][j]=1;
					push(i,j);			//STORING VALUES  OF I AND J  
					k++;
				}
			}
			j1=0;
		}
	}while(k<n&&k>0);
	for(i=0;i<n;i++)					//DISPLAYING
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}cout<<endl;
	}
	cin.get();
	cin.get();
}
