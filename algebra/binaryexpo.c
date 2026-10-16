/* Binary Exponentiation:
 * Allows us to find the value of a^n in O(logn) multiplication, rather than
 * O(n) n is a non-negative integer. Works for any operator whose associative:
 * (x*y)*z === x*(y*z)
 *
 * WORKING:
 * We express the exponent in base 2, and split the base.
 * Then we calculate the individual powers, each of them is used to calculate
 * the next.
 *
 * Ex: 3^(13) = 3^(1101_2) = 3^(1*8) * 3^(1*4) * 3^(0*2) * 3^(1*1)
 * = 3^8 + 3^4 + 3^1
 * Now, 3^1 = 3
 *      3^2 = (3^1)^2 = 9
 *      3^4 = (3^2)^2 = 81
 *      3^8 = (3^4)^2 = 6561
 *
 * Answer = 8 * 81 * 6561 = 4251528
 */

// Recursive approach
long long binpow_recursive(long long base, long long exp) {
  if (exp == 0) {
    return 1;
  }
  long long res = binpow_recursive(base, exp / 2);
  if (exp % 2 == 0) {
    return res * res;
  } else {
    return res * res * base;
  }
}

// Iterative approach, this one actually uses the working idea
long long binpow_iterative(long long base, long long exp) {
  long long res = 1;
  while (exp > 0) {
    if (exp & 1) { // if lsb of exp is 1
      res = res * base;
    }
    base = base * base;
    exp >>= 1;
  }
  return res;
}
