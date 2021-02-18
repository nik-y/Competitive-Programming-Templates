/*
Begin
   Create function to find all primes smaller than limit
   using simple sieve of eratosthenes.
   Finds all prime numbers in given range using
   segmented sieve
   A) Compute all primes smaller or equal to square root of high using simple sieve
   B) Count of elements in given range
   C) Declaring boolean only for [low, high]
   D) Find the minimum number in [low ... high] that is a multiple of prime[i] (divisible by prime[i])
   E) Mark multiples of prime[i] in [low … high]
   F) Numbers which are not marked in range, are prime
End
*/

#include <bits/stdc++.h>
using namespace std;
void simpleSieve(int lmt, vector<int>& prime) {
   bool mark[lmt + 1];
   memset(mark, false, sizeof(mark));
   for (int i = 2; i <= lmt; ++i) {
      if (mark[i] == false) {
         prime.push_back(i);
         for (int j = i; j <= lmt; j += i)
            mark[j] = true;
      }
   }
}
void PrimeInRange(int low, int high) {
   int lmt = floor(sqrt(high)) + 1;
   vector<int> prime;
   simpleSieve(lmt, prime);
   int n = high - low + 1;
   bool mark[n + 1];
   memset(mark, false, sizeof(mark));
   for (int i = 0; i < prime.size(); i++) {
      int lowLim = floor(low / prime[i]) * prime[i];
      if (lowLim < low)
         lowLim += prime[i];
      for (int j = lowLim; j <= high; j += prime[i])
         mark[j - low] = true;
   }
   for (int i = low; i <= high; i++)
      if (!mark[i - low])
         cout << i << " ";
}
int main() {
   int low = 10, high = 50;
   PrimeInRange(low, high);
   return 0;
}