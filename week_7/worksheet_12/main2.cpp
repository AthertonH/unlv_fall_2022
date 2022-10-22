#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ARRAY_SIZE = 10000;
const int MINIMUM_VALUE = 50;
const int MAXIMUM_VALUE = 1000;
const int ODD = 1;
const int EVEN = 0;
const string LABEL[2] = {"Even", "Odd"};

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
	
	bool found[2] = {false, false};
	int minimum[2] = {0, 0};
	int maximum[2] = {0, 0};
	int sum[2] = {0, 0};
	int count[2] = {0, 0};
	
	//Analyze numbers in array
	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		int sign = numbers[i] % 2;
		count[sign]++;
		sum[sign]+=numbers[i];
			
		if(found[sign] == false)
		{
			minimum[sign] = numbers[i];
			maximum[sign] = numbers[i];
			found[sign] = true;
		}
		else if(numbers[i] < minimum[sign])
		{
			minimum[sign] = numbers[i];
		}
		else if(numbers[i] > maximum[sign])
		{
			maximum[sign] = numbers[i];
		}
	}
		
	for(int sign = 0; sign < 2; sign++)
	{
		if(count[sign] > 0)
		{
			cout << "Minimum " << LABEL[sign] << ": " << minimum[sign] << endl;
			cout << "Maximum " << LABEL[sign] << ": " << maximum[sign] << endl;
			cout << "Average " << LABEL[sign] << ": " 
				 << static_cast<double>(sum[sign]) / count[sign] << endl;
		}
		else
		{
			cout << LABEL[sign] << " values were not generated." << endl;
		}
	}
		
	return 0;
}