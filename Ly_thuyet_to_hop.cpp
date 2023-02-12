#include <bits/stdc++.h>
using namespace std;

string next_bit_string(string s)
{
  int n = s.length();
  for (int i = n - 1; i >= 0; i--)
  {
    if (s[i] == '0')
    {
      s[i] = '1';
      for (int j = i + 1; j < n; j++)
      {
        s[j] = '0';
      }
      return s;
    }
  }
  return "";
}

void Generate_bit_string(int n)
{
  string s = "";
  for (int i = 0; i < n; i++)
  {
    s += '0';
  }
  while (s != "")
  {
    cout << s << endl;
    s = next_bit_string(s);
  }
}

string next_sub_set(int n, int m, string s)
{
  for (int i = m - 1; i >= 0; i--)
  {
    if (s[i] != (n - m + i + 1) + '0')
    {
      s[i]++;
      for (int j = i + 1; j < m; j++)
      {
        s[j] = s[j - 1] + 1;
      }
      return s;
    }
  }
  return "";
}

void Generate_sub_set(int n, int m)
{
  string s = "";
  for (int i = 0; i < m; i++)
  {
    s += to_string(i + 1);
  }
  while (s != "")
  {
    for (int i = 0; i < m; i++)
    {
      cout << s[i] << " ";
    }
    cout << endl;
    s = next_sub_set(n, m, s);
  }
}

int findSmallestGreaterThanX(int arr[], int n, int x)
{
  int min = INT_MAX;
  int minIndex = -1;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > x && arr[i] < min)
    {
      min = arr[i];
      minIndex = i;
    }
  }

  return (min != INT_MAX) ? minIndex : -1;
}

string next_permutation(int n, string s)
{
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    arr[i] = s[i] - '0';
  }
  for (int i = n - 2; i >= 0; i--)
  {
    if (arr[i] < arr[i + 1])
    {
      int min = INT_MAX;
      int minIndex = -1;
      // find smallest greater than s[i] after s[i]
      for (int j = i + 1; j < n; j++)
      {
        if (arr[j] > arr[i] && arr[j] < min)
        {
          min = arr[j];
          minIndex = j;
        }
      }
      swap(arr[i], arr[minIndex]);
      sort(arr + i + 1, arr + n);
      for (int i = 0; i < n; i++)
      {
        s[i] = arr[i] + '0';
      }
      return s;
    }
  }
  return "";
}

void Generate_permutation(int n)
{
  string s = "";
  for (int i = 0; i < n; i++)
  {
    s += to_string(i + 1);
  }
  while (s != "")
  {
    cout << s << endl;
    s = next_permutation(n, s);
  }
}

int main()
{
  Generate_bit_string(3);
  cout << "***************" << endl;
  Generate_sub_set(5, 3);
  cout << "***************" << endl;
  Generate_permutation(3);
  return 0;
}
