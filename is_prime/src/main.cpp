#include <stdio.h>
using namespace std;

const int MAX_N = 1e8;

// checked   => not prime
// unchecked => prime
bool sieve[MAX_N];

bool gen_sieve(size_t limit = MAX_N)
{
    if (limit > sizeof(sieve)) return false;

    // there is no need to go beyond sqrt(limit)
    for (size_t i = 2; i*i < limit; i++)
    {
        // if still unchecked
        if(!sieve[i])
        {
            // check all multiples
            for (size_t j = i*i; j < limit; j += i)
            {
                sieve[j] = true;
            }
        }

        printf("[DEBUG] Removed all multiples of %li\n", i);
    }

    return true;
}

bool is_prime(int number)
{
    // unchecked => prime
    return !sieve[number];
}

int main()
{
    int n;

    user_input:

    printf("[INFO] Enter number: ");
    scanf("%i", &n);

    if (n <= 1) goto user_input;

    gen_sieve();

    printf(is_prime(n) ? "[INFO] %i is a prime!" : "[INFO] %i is not a prime.", n);
    printf("\n");
}