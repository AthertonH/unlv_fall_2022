#include <iostream>
#include <cstdlib>
using namespace std;

double getCircleArea(double radius)
{
	return 0.5 * radius * radius * 3.14159;
}

int main(int argc, char* argv[])
{
	if(argc>1)
	{
		cout << "Circle Area: " << getCircleArea(atof(argv[1]));
	}	
	else
	{
		cout << "Program requires a radius value." << endl;
		return 0;
	}
	
	return 0;
}