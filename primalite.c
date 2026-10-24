#include "primalite.h"

int est_premier_A1(long long n)
{
  if (n < 2)
  {
    return 0;
  }

  /* A1 : tester tous les diviseurs de 2 a n - 1. */
  for (long long i = 2; i < n; ++i)
  {
    if (n % i == 0)
    {
      return 0;
    }
  }

  return 1;
}

int est_premier_A2(long long n)
{
  if (n < 2)
  {
    return 0;
  }

  /* A2 : tester les diviseurs de 2 a n / 2. */
  for (long long i = 2; i <= n / 2; ++i)
  {
    if (n % i == 0)
    {
      return 0;
    }
  }

  return 1;
}

int est_premier_A3(long long n)
{
  if (n < 2)
  {
    return 0;
  }

  /*
   * A3 : un diviseur doit exister au plus jusqu'a sqrt(n).
   * Pour n positif, i <= n / i equivaut a i * i <= n,
   * sans risquer un debordement dans le calcul i * i.
   */
  for (long long i = 2; i <= n / i; ++i)
  {
    if (n % i == 0)
    {
      return 0;
    }
  }

  return 1;
}

int est_premier_A4(long long n)
{
  if (n < 2)
  {
    return 0;
  }

  /* Le seul nombre pair premier est 2. */
  if (n % 2 == 0)
  {
    return n == 2;
  }

  /*
   * A4 : apres le traitement des nombres pairs, tester uniquement
   * les diviseurs impairs 3, 5, 7, ... jusqu'a sqrt(n).
   * Cette interpretation prolonge l'amelioration de A3.
   */
  for (long long i = 3; i <= n / i; i += 2)
  {
    if (n % i == 0)
    {
      return 0;
    }
  }

  return 1;
}
