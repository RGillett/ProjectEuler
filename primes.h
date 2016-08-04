/*******************************************************************************
* Author: Ryan Gillett
*******************************************************************************/
#ifndef PRIMES
#define PRIMES

/*******************************************************************************
* sieveOfEratosthenes()
* Sets an array of booleans to true for prime indexes for quick prime checking.
*******************************************************************************/
void sieveOfEratosthenes(bool* sieve, const int& size)
{
	sieve[0] = false;
	sieve[1] = false;
	for (int i = 2; i < size; i++)
	{
		sieve[i] = true;
	}

	for (int i = 2; i*i < size; i++)
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

/*******************************************************************************
* isPrime()
* Determines whether a number is prime
*******************************************************************************/
bool isPrime(const unsigned long long int& number)
{
	const int SIEVE_MAX = 100000;
	static bool sieve[SIEVE_MAX];
	static bool initialized = false;

	if (!initialized)
	{
		sieveOfEratosthenes(sieve, SIEVE_MAX);
		initialized = true;
	}

	if (number >= SIEVE_MAX)
	{
		if (!(number % 2 == 0 || number % 3 == 0))
		{
			for (unsigned long long int i = 5; i*i <= number; i += 6)
			{
				if (number % i == 0 || number % (i + 2) == 0)
					return false;
			}
			
			return true;
		}
		
		return false;
	}
	else
	{
		return sieve[number];
	}
}

/*******************************************************************************
* nextPrime()
* Takes an int and returns the closest consecutive prime
*******************************************************************************/
void nextPrime(long long int& number)
{
	while (!isPrime(++number))
		;
		
	return;
}

#endif