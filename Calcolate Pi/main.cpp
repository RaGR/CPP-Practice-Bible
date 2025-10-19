#include <iostream>
#include <conio.h>
#include <random>
#include <stdlib.h>
#include <ctime>
#include <math.h>

using namespace std;

double
randMToN (double M, double N)
{
  return M + (rand () / (RAND_MAX / (N - M)));
}

double
calculate_pi (int n)
{
  double x, y, num_of_c = 0, num_of_r = 0;
  for (int i = 0; i < n; i++)
    {
      x = randMToN (0, 1);
      y = randMToN (0, 1);
      cout << x << " , " << y << endl << x * x << " <- X2,Y2 -> " << y *
	y << endl << x * x + y * y << endl << endl;

      if (sqrt (x * x + y * y) <= 1.0f)
	num_of_c++;
      num_of_r++;
    }
  cout << num_of_c << endl << num_of_r << endl;
  cout << num_of_c / num_of_r << endl;
  return 4 * (num_of_c / num_of_r);
}


int
main ()
{
  int n = 1;
  while (n != 0)
    {
      cin >> n;
      cout << calculate_pi (n) << endl;
    }
  return 0;
}
