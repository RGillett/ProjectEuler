/*******************************************************************************
* Author: Ryan Gillett
*******************************************************************************/
#ifndef PRIMES
#define PRIMES

#include <vector>

/*******************************************************************************
* sieveOfEratosthenes()
* Sets an array of booleans to true for prime indexes for quick prime checking
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
			for (int j = i * i; j < size; j += i)
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
	static const int SIEVE_MAX = 1000000;
	static bool sieve[SIEVE_MAX];
	static bool initialized = false;

	if (!initialized)
	{
		sieveOfEratosthenes(sieve, SIEVE_MAX);
		initialized = true;
	}

	if (number >= SIEVE_MAX)
	{
		if (!(number % 2 == 0 || number % 3 == 0 || number < 2))
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
	if (number < 2)
	{
		number = 2;
		return;
	}
	if (number % 2 != 1)
	{
		--number;
	}
	while (!isPrime(number+=2))
		;

	return;
}

/*******************************************************************************
* previousPrime()
* Takes an int and returns the previous consecutive prime
*******************************************************************************/
void previousPrime(long long int& number)
{
	while (number > 2 && !isPrime(--number))
		;

	return;
}

/*******************************************************************************
* getPrime()
* Takes an integer n and returns the nth prime number
*******************************************************************************/
long long int getPrime(int n)
{
	long long int prime = 0;

	for (int i = 0; i < n; ++i)
	{
		nextPrime(prime);
	}

	return prime;
}

/*******************************************************************************
* factorize()
* Returns a vector of the number of repetitions of each prime n
* e.g. 504 as the parameter will return 2*2*2*3*3*7 as {3,2,0,1}
* representing 3 factors of the 1st prime: 2, 2 factors of the 2nd prime: 3,
* 0 factors of the 3rd prime: 5, and 1 factor of the 4th prime: 7
* This format requires less memory and allows faster manipulation of the numbers
*******************************************************************************/
std::vector<int> factorize(long long int number)
{
	std::vector<int> factors;

	for (long long int i = 2; number > 1; nextPrime(i))
	{
		int count = 0;
		while (number % i == 0)
		{
			count++;
			number /= i;
		}
		factors.push_back(count);
	}

	return factors;
}

/*******************************************************************************
* countPrimeFactors()
*******************************************************************************/
long long int countPrimeFactors(long long int number)
{
	int primeFactorsCount = 0;

	for (long long int primeFactor = 2; number > 1; nextPrime(primeFactor))
	{
		while (number % primeFactor == 0)
		{
			number /= primeFactor;
			primeFactorsCount++;
		}
	}

	return primeFactorsCount;
}



#endif // PRIMES