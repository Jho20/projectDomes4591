#include "ArrayGen.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>

using namespace std;

void printData();
int arraySize();
int arrayChoice();
void createFile(float sec1,float sec2, float sec3, float sec4);

int main(int argc, char** argv) {
	
	int size,choice;
	float sec1,sec2,sec3,sec4;
	clock_t ct0,ct1;
	ArrayGen original,copy;
	
	printData();
	size=arraySize();
	original.setArraySize(size);
	original.createArray();
	choice=arrayChoice();
	
	switch(choice)
	{
		case(1):
			original.fill100();
		break;
		case(2):
			original.fill50();
		break;
		case(3):
			original.fillASC();
		break;
		case(4):
			original.fillDESC();
		break;
		default:
			cout << "Something went wrong, try again";
	}
	
			cout << "Sorting ==> ";
				
			copy.setArraySize(size);
			copy.createArray();
			original.cpArray(copy);
			//bubblesort
			cout << "Bubble Sort... ";
			ct0=clock();
			copy.bubbleSort();
			ct1=clock();
			sec1=(float)(ct1-ct0)/CLOCKS_PER_SEC;
			//selectsort
			cout << "Select Sort... ";
			original.cpArray(copy);
			ct0=clock();
			copy.selectSort();
			ct1=clock();
			sec2=(float)(ct1-ct0)/CLOCKS_PER_SEC;
			//insertsort
			cout << "Insert Sort... ";
			original.cpArray(copy);
			ct0=clock();
			copy.insertSort();
			ct1=clock();
			sec3=(float)(ct1-ct0)/CLOCKS_PER_SEC;
			//quicksort
			cout << "Quick Sort... ";
			original.cpArray(copy);
			ct0=clock();
			copy.quickSort(0,size);
			ct1=clock();
			sec4=(float)(ct1-ct0)/CLOCKS_PER_SEC;
			
			
	original.freeArrayMem();
	copy.freeArrayMem();
	
	createFile(sec1,sec2,sec3,sec4);
	
	return 0;
}

void printData()
{
	cout << "Student" << endl;
	cout << "=======" << endl;
	cout << "Name: Ioannis Allousi" << endl;
	cout << "AEM: 4591" << endl << endl;
	
	cout << "Computer Characteristics" << endl;
	cout << "========================" << endl;
	cout << "CPU: Intel" << endl;
	cout << "Intel i5 9600k 3.7Ghz" << endl;
	cout << "RAM: 12GB" << endl;
	cout << "Virtualized: Yes (KVM)" <<endl << endl;
}

int arraySize()
{
	int size;
	cout << "Array Size? ";
	cin >> size;
	cout << endl << endl;
	return(size);
}

int arrayChoice()
{
	int choice;
	cout << "Array Types" << endl;
	cout << "	1. Random 100%" << endl;
	cout << "	2. Sorted 50%, Random 50%" << endl;
	cout << "	3. Sorted ASC" << endl;
	cout << "	4. Sorted DESC" << endl;
	cout << "Choose array type: ";
	cin >> choice;
	return(choice);
}

void createFile(float sec1,float sec2,float sec3,float sec4)
{
	ofstream results;
	results.open("TIMES.txt",ios_base::app);
	results << setw(20)<<"EXECUTION TIMES(seconds)" << endl;
	results << "BubbleSort"<<setw(10)<<"SelectSort"<<setw(10)<<"InsertSort"<<setw(10)<<"QuickSort"<<endl;
	results << "=========="<<setw(10)<<"=========="<<setw(10)<<"=========="<<setw(10)<<"========="<<endl;
	results << setw(10) << setprecision(5) <<sec1 << setw(10) << setprecision(5) << sec2 << setw(10) << setprecision(5) << sec3 << setw(10) << setprecision(5) << sec4 <<endl;
	results.close();
}
