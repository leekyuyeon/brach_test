#include "..\Header\DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "..\Header\DSP2833x_Examples.h"   // DSP2833x Examples Include File


void Exchange(float *Data, int x, int y)
{
	float Temp = 0;

	Temp = Data[x];
	Data[x] = Data[y];
	Data[y] = Temp;
}

int Partition(float *Data, int Left, int Right)
{
	int Count = 0;
	int Last = 0;

	Last = Left - 1;
	for(Count = Left; Count < Right; Count++)
	{
		if(Data[Count] < Data[Right])Exchange(Data, ++Last, Count);
	}
	Exchange(Data, Last + 1, Right);

	return Last + 1;
}

void QuickSort(float *Data, int Left, int Right)
{
	int Last = 0;

	if(Left < Right)
	{
		Last = Partition(Data, Left, Right);
		QuickSort(Data, Left, Last - 1);
		QuickSort(Data, Last + 1, Right);
	}
}

void InsertionSort(float *Data, int Number)
{
	int i,j;
	float Key;

	for(i = 1; i <= Number; i++)
	{
		Key = Data[i];
		j = i - 1;
		while((j >= 0) && (Data[j] > Key))
		{
			Data[j + 1] = Data[j];
			j--;
		}
		Data[j + 1] = Key;
	}
}

//===========================================================================
// End of file.
//===========================================================================
