#include <bits/stdc++.h>
using namespace std;

int res[100000];
int n;
void Try(int i)
{
  for (int j = 1; j <= n; j++)
  {
    // Check dieu kien khong an nhau
    bool ok = true;
    for (int k = 1; k < i; k++)
    {
      if (res[k] == j || abs(res[k] - j) == abs(k - i))
      {
        ok = false;
        break;
      }
    }
    if (ok)
    {
      // Gan bien trang thai cho trang thai i
      res[i] = j;
      if (i == n)
      {
        for (int k = 1; k <= n; k++)
        {
          cout << res[k] << " ";
        }
        cout << endl;
      }
      else
      {
        Try(i + 1);
      }
      // Tra lai bien trang thai
    }
  }
}

int main()
{
  cin >> n;
  Try(1);
  return 0;
}