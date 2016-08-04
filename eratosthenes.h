/*******************************************************************************
* Sieve of Eratosthenes
* Author: Ryan Gillett
*******************************************************************************/
#ifndef ERATOSTHENES
#define ERATOSTHENES

/*******************************************************************************
* sieveOfEratosthenes()
* Sets an array of booleans to true for prime indexes for quick prime checking.
*******************************************************************************/
void sieveOfEratosthenes(bool* sieve, int size)
{
	sieve[0] = false;
	sieve[1] = false;
	sieve[2] = true;
	sieve[3] = true;
	for (int i = 4; i < size; i++)
	{
		if (sieve[i] % 2 == 0 || sieve[i] % 3 == 0)
		{
			sieve[i] = false;
		}
		else
		{
			sieve[i] = true;
		}
	}

	for (int i = 5; i*i < size; i++)
	{
		if (sieve[i] == true)
		{
			for (int j = i + i; j < size; j += i)
			{
				sieve[j] = false;
			}
		}
	}
}

#endif