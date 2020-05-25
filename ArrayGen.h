#ifndef ARRAYGEN_H
#define ARRAYGEN_H

class ArrayGen
{
	private:
		int *p;
		int n;
	public:
		void setArraySize(int n1);
		void createArray();
		void fill100();
		void fill50();
		void fillASC();
		void fillDESC();
		void freeArrayMem();
		
		void cpArray(ArrayGen ant);
		
		void bubbleSort();
		void selectSort();
		void insertSort();
		void quickSort(int left, int right);
};

#endif

