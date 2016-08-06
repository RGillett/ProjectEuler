/*******************************************************************************
* Author: Ryan Gillett
*******************************************************************************/
#ifndef PRIMES
#define PRIMES

static const int SIEVE_MAX = 100000;
static bool sieve[SIEVE_MAX];
static bool initialized = false;

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
void nextPrime(unsigned long long int& number)
{
	while (!isPrime(++number))
		;
		
	return;
}

/*******************************************************************************
* previousPrime()
* Takes an int and returns the previous consecutive prime
*******************************************************************************/
void previousPrime(unsigned long long int& number)
{
	while (!isPrime(--number))
		;
		
	return;
}

/*******************************************************************************
* factorize()
*******************************************************************************/
int* factorize()
{
	if (!initialized)
	{
		sieveOfEratosthenes(sieve, SIEVE_MAX);
		initialized = true;
	}

	return 1;
}

/*******************************************************************************
* countFactors()
*******************************************************************************/
long long int countPrimeFactors(long long int value)
{
	long long int primeFactor = 0;
	
	int factors = 1;
	
	while (value > 1)
	{
		int factorCounter = 1;
		
		nextPrime(primeFactor);
			
		while (value % primeFactor == 0)
		{
			value /= primeFactor;
			factorCounter++;
		}
		
		factors *= factorCounter;
	}
	
	return factors;
}



#endif // PRIMES