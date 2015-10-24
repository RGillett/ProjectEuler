/*******************************************************************************
* Palindrome Product
* Authors: Ryan Gillett, Brandon Gillett
*
* This program will find the largest palindrome which is a
* product of two 3-digit integers.
*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

//Prototypes
long int findLargestPalindrome();
bool isPalindrome(long int);
string to_string(long int number);

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	cout << "The largest palindrome that is a product of two 3-digit numbers is: "
		 << findLargestPalindrome() << endl;
}

/*******************************************************************************
* findLargestPalindrome
*******************************************************************************/
long int findLargestPalindrome()
{
	// Container for the largest palindrome found so far.
	long int largestPalindrome = 0;

	// Nested for loops. The indexes are multiplied together to find every possible
	// product of two 3-digit numbers.
	for (long int i = 100; i < 1000; i++)
	{
		for (long int j = i; j < 1000; j++)
		{
			if (isPalindrome(i*j))
			{
				// If the product of i and j is a palindrome, determine whether it is larger
				// than the previous largest palindrome and store the larger of the two.
				largestPalindrome = (largestPalindrome < (i * j) ? (i * j) : largestPalindrome);
			}
		}
	}

	return largestPalindrome;
}

/*******************************************************************************
* isPalindrome
* Determines whether a given value is a palindrome.
* @param checkValue - The value to be checked
* @return true if checkValue is a palindrome, otherwise false.
*******************************************************************************/
bool isPalindrome(long int checkValue)
{
	string stringValue = to_string(checkValue);

	for (int i = 0; i < stringValue.size() / 2; i++)
	{
		if (stringValue[i] != stringValue[stringValue.size() - i - 1])
			return false;
	}

	return true;
}

string to_string(long int number){
    string number_string = "";
    char ones_char;
    int ones = 0;
    while(true){
        ones = number % 10;
        switch(ones){
            case 0: ones_char = '0'; break;
            case 1: ones_char = '1'; break;
            case 2: ones_char = '2'; break;
            case 3: ones_char = '3'; break;
            case 4: ones_char = '4'; break;
            case 5: ones_char = '5'; break;
            case 6: ones_char = '6'; break;
            case 7: ones_char = '7'; break;
            case 8: ones_char = '8'; break;
            case 9: ones_char = '9'; break;
            default : cout << "Trouble converting number to string.\n";
        }
        number -= ones;
        number_string = ones_char + number_string;
        if(number == 0){
            break;
        }
        number = number/10;
    }
    return number_string;
}
