#include "ArrayGen.h"
#include "RandMT.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

void ArrayGen::setArraySize(int n1)
{
	n=n1;
}

void ArrayGen::createArray()
{
	p = new int[n];
}

void ArrayGen::fill100()
{
	int i;
	RandMT random;
	
	RandMT (time(NULL));
	for(i=0;i<n;i++)
	{
		p[i]=random();
	}
}

void ArrayGen::fillASC()
{
	int i;
	for(i=0;i<n;i++)
	{
		p[i]=i;
	}
}

void ArrayGen::fillDESC()
{
	int i;
	for(i=n;i>0;i--)
	{
		p[n-i]=i;
	}
}

void ArrayGen::fill50()
{
	int i;
	RandMT random;
	int m=n/2;
	
	RandMT(time(NULL));
	for(i=0;i<m;i++)
	{
		p[i]=random();
	}
	for(i=m;i<n;i++)
	{
		p[i]=i;
	}
}

void ArrayGen::freeArrayMem()
{
	delete []p;
}

void ArrayGen::cpArray(ArrayGen ant)
{
	int i;
	for(i=0;i<n;i++)
		ant.p[i] = p[i];
}

void ArrayGen::bubbleSort()
{
	int i,j,temp;
	
	for(i=1; i<n; i++)
		for(j=n-1; j>=i; j--)
			if(p[j-1] > p[j])
				{
					temp = p[j-1];
					p[j-1] = p[j];
					p[j] = temp;
				}
}

void ArrayGen::selectSort()
{
	int i,j,k,min;
	
	for(i=0; i<n-1; i++)
		{
			k=i;
			min=p[i];
			for(j=i+1;j<n;j++)
			{
				if(p[j]<min)
				{
					k=j;
					min=p[j];
				}
			}
			p[k]=p[i];
			p[i]=min;
		}
}

void ArrayGen::insertSort()
{
	int i,j,x;
	for(i=1; i<n; i++) 
	{
		x = p[i];
		j = i-1;
		while( j>=0 && p[j]>x) 
		{
        	p[j+1] = p[j];
        	j = j-1;
		}
		p[j+1] = x;
	}
}

void ArrayGen::quickSort(int left, int right)
{
	int i,j,x,mid;
	if(left < right)
	{
		i = left;
		j = right;
		mid = (left+right)/2;
		x = p[mid];
		while(i < j)
		{
			while(p[i] < x) 
				i++;
            while(p[j] > x)
            	j--;
			if(i < j)
			{
           		if(p[i] == p[j])
				{
        			if(i < mid)
						i++;
                	if(j > mid)
						j--;
				}
                else 
				{
            	    swap(p[i],p[j]);
				}
			}
		}
    	quickSort(left,j-1);
    	quickSort(j+1,right);
	}
}
