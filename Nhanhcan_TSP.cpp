#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N][N];
int res[N];
vector<int> vRes;
int ki_luc = INT_MAX;
int cmin = INT_MAX;
int n;
int can = 0;
bool di_qua[N];

void input()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> a[i][j];
    }
  }
}

void Try(int i)
{
  for (int j = 2; j <= n; j++)
  {
    if (!di_qua[j])
    {
      res[i] = j;
      di_qua[j] = true;
      can += a[res[i - 1]][res[i]];
      if (i == n)
      {
        if (can + a[res[n]][1] < ki_luc)
        {
          ki_luc = can + a[res[n]][1];
          vRes = vector<int>(res, res + n + 1);
        }
      }
      else
      {
        if (can + (n - i + 1) * cmin < ki_luc)
        {
          Try(i + 1);
        }
      }
      can -= a[res[i - 1]][res[i]];
      di_qua[j] = false;
    }
  }
}

int main()
{
  input();
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i != j && a[i][j] < cmin)
      {
        cmin = a[i][j];
      }
    }
  }
  memset(di_qua, false, sizeof di_qua);
  di_qua[1] = true;
  res[1] = 1;
  Try(2);
  cout << "Chi phi di chuyen: " << ki_luc << endl;
  cout << "Duong di: ";
  for (int i = 1; i < vRes.size(); i++)
  {
    cout << vRes[i] << "-->";
  }
  cout << 1 << endl;
  return 0;
}
