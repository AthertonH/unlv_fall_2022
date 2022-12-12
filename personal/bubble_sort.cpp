#include <iostream>
using namespace std;

const int ARRAY_SIZE = 20;
int main()
{
    

    int array[ARRAY_SIZE] = {1, 2, 4, 1, 2, 6, 4, 5, 1, 2, 5, 2, 4, 6, 0, 89, 76, 6, 5};

    int temp = array[1];
    array[1] = array[2];
    array[2] = temp;

    for(int i = 0; i < ARRAY_SIZE - 1; i++)
    {
        for(int j = 0; j < ARRAY_SIZE - i - 1; j++)
        {
            if(array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }


    return 0;
}