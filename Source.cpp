#include <iostream>
#include <fstream>
using namespace std;
#define size 8
int linearSearch(int array[size], int& target)
{
    int position = 0;                         // Starting index of array
    int result = -1;                          // Position before it is found set to a negative 1
    bool Found = 0;                           // A flag that set the condition to a true 
    while (!Found && position < size)         // Complex condition two case must happen 
    {
        if (array[position] == target)
        {
            result = position + 1;             // target position
            Found = 1;                      // to break loop
        }
        position++;
    }
    return result;
}
//=====================================================================
void main()
{
    int list[size] = { 0 };        //set an argument same type as array
    int target;                    //Local variable target to set waht user is looking for

    ifstream    input;
    input.open("sum.txt");
    for (int i = 0; i < size; i++)    //reading input and storing that to the array of list
        input >> list[i];

    cout << "These are the list of elements in the array" << endl;  //==== Validating your input file
    for (int i = 0; i < size; i++)
        cout << list[i] << "  ";
    cout << endl;

    cout << "Please enter a positive integer that you look for " << endl;  //Propmt user to input the targer
    cin >> target;                                                         //extract target
    if (target < 0)                                                        //Checking if target was inputted corecty 
        cout << "You entered a negative number" << endl;
    else
        if (linearSearch(list, target) < 0)
            cout << " Your target is not in the list" << endl;
        else
            cout << "It is element # " << linearSearch(list, target) << " in the list " << endl;
    system("pause");
}