/*******************************************************************************
* Cyclical Figurate Numbers
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include "figurate_numbers.h"

using namespace std;

int combine(int x, int y);
bool isFigurateNumber(int n);
/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	for (int n1 = 10; n1 < 100; ++n1)
	{
		for (int n2 = 10; n2 < 100; ++n2)
		{
			if (isFigurateNumber(combine(n1,n2)))
			{
				for (int n3 = 10; n3 < 100; ++n3)
				{
					if (isFigurateNumber(combine(n2,n3)))
					{
						for (int n4 = 10; n4 < 100; ++n4)
						{
							if (isFigurateNumber(combine(n3,n4)))
							{
								for (int n5 = 10; n5 < 100; ++n5)
								{
									if (isFigurateNumber(combine(n4,n5)))
									{
										for (int n6 = 10; n6 < 100; ++n6)
										{
											int numbers[6] = {
												combine(n1,n2),
												combine(n2,n3),
												combine(n3,n4),
												combine(n4,n5),
												combine(n5,n6),
												combine(n6,n1)
											};

											bool triangleNumberFound = false;
											bool squareNumberFound = false;
											bool pentagonalNumberFound = false;
											bool hexagonalNumberFound = false;
											bool heptagonalNumberFound = false;
											bool octagonalNumberFound = false;

											for (int i = 0; i < 6; i++)
											{
												if (isOctagonalNumber(numbers[i]))
												{
													octagonalNumberFound = true;
												}
												else if (isHeptagonalNumber(numbers[i]))
												{
													heptagonalNumberFound = true;
												}
												else if (isHexagonalNumber(numbers[i]))
												{
													hexagonalNumberFound = true;
												}
												else if (isPentagonalNumber(numbers[i]))
												{
													pentagonalNumberFound = true;
												}
												else if (isSquareNumber(numbers[i]))
												{
													squareNumberFound = true;
												}
												else if (isTriangleNumber(numbers[i]))
												{
													triangleNumberFound = true;
												}
											}

											if (triangleNumberFound && squareNumberFound && pentagonalNumberFound
												&& hexagonalNumberFound && heptagonalNumberFound && octagonalNumberFound)
											{
												int sum = 0;
												for (int i = 0; i < 6; i++)
												{
													sum += numbers[i];
												}

												cout << sum << endl;
												
												return 0;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}

bool isFigurateNumber(int n)
{
	if (isOctagonalNumber(n))
	{
		return true;
	}
	if (isHeptagonalNumber(n))
	{
		return true;
	}
	if (isHexagonalNumber(n))
	{
		return true;
	}
	if (isPentagonalNumber(n))
	{
		return true;
	}
	if (isSquareNumber(n))
	{
		return true;
	}
	if (isTriangleNumber(n))
	{
		return true;
	}

	return false;
}

int combine(int x, int y)
{
	return x * 100 + y;
}