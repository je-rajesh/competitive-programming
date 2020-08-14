#include <bits/stdc++.h>
using namespace std;

// type definitions
typedef long long ll;
ifstream yyy("input.txt");
ofstream zzz("output.txt");

int main()
{
  int n;
  yyy >> n;

  // first type of pattern.
  int half = n / 2;
  for (int i = 1; i <= half + 1; i++)
  {
    zzz << "*\t";
  }

  for (int i = 1; i < half; i++)
  {
    zzz << "\t";
  }

  zzz << "*";
  zzz << endl;
  // second type of pattern.
  for (int i = 1; i < half; i++)
  {
    for (int j = 1; j <= half; j++)
    {
      zzz << "\t";
    }
    zzz << "*";
    for (int j = 1; j <= half; j++)
    {
      zzz << "\t";
    }
    zzz << "*";
    zzz << endl;
  }
  // middle portion
  for (int i = 0; i < n; i++)
    zzz << "*\t";

  // third type of pattern.
  zzz << endl;
  for (int i = 1; i < half; i++)
  {
    zzz << "*";
    for (int j = 1; j <= half; j++)
    {
      zzz << "\t";
    }
    zzz << "*";
    for (int j = 1; j <= half; j++)
    {
      zzz << "\t";
    }
    zzz << endl;
  }

  zzz << "*" ;
  for (int i = 1; i <= half; i++)
  {
    zzz << "\t";
  }

  for (int i = 1; i <= half + 1; i++)
  {
    zzz << "*\t";
  }
}
