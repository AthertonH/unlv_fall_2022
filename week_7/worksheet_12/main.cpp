#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ARRAY_SIZE = 10000;
const int MINIMUM_VALUE = 50;
const int MAXIMUM_VALUE = 1000;

int main()
{
	int numbers[ARRAY_SIZE];
	//optionally seed generator
	srand(time(0));
	
	//Generate random numbers
	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		numbers[i] = rand() % (MAXIMUM_VALUE - MINIMUM_VALUE + 1) + MINIMUM_VALUE;
	}
	
	bool oddFound = false;
	int oddMinimum = 0;
	int oddMaximum = 0;
	int oddSum = 0;
	int oddCount = 0;
	bool evenFound = false;
	int evenMinimum = 0;
	int evenMaximum = 0;
	int evenSum = 0;
	int evenCount = 0;
	
	//Analyze numbers in array
	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		//EVEN
		if(numbers[i] % 2 == 0)
		{
			evenCount++;
			evenSum+=numbers[i];
			//Use first even number found as the initial guess for min/max
			if(evenFound == false)
			{
				evenMinimum = numbers[i];
				evenMaximum = numbers[i];
				evenFound = true;
			}
			else if(numbers[i] < evenMinimum)
			{
				evenMinimum = numbers[i];
			}
			else if(numbers[i] > evenMaximum)
			{
				evenMaximum = numbers[i];
			}
		}
		//ODD
		else
		{
			oddCount++;
			oddSum+=numbers[i];
			//Use first odd number found as the initial guess for min/max
			if(oddFound == false)
			{
				oddMinimum = numbers[i];
				oddMaximum = numbers[i];
				oddFound = true;
			}
			else if(numbers[i] < oddMinimum)
			{
				oddMinimum = numbers[i];
			}
			else if(numbers[i] > oddMaximum)
			{
				oddMaximum = numbers[i];
			}
		}
	}
		
	if(oddCount > 0)
	{
		cout << "Minimum Odd: " << oddMinimum << endl;
		cout << "Maximum Odd: " << oddMaximum << endl;
		cout << "Average Odd: " << static_cast<double>(oddSum) / oddCount << endl;
	}
	else
	{
		cout << "No odd numbers generated." << endl;
	}
	
	if(evenCount > 0)
	{
		cout << "Minimum Even: " << evenMinimum << endl;
		cout << "Maximum Even: " << evenMaximum << endl;
		cout << "Average Even: " << static_cast<double>(evenSum) / evenCount << endl;
	}
	else
	{
		cout << "No even numbers generated." << endl;
	}
	
	return 0;
}