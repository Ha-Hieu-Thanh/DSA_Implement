#include <iostream>
using namespace std;

/*
- Tại bước k, đưa phần tử thứ k trong mảng đã cho vào vị trí thích hợp trong mảng đã sắp xếp
- Độ phức tạp: O(n^2)
*/
void insertion_sort(int *a, int n)
{
  int i, j, last;
  for (int i = 1; i < n; i++)
  {
    last = a[i];
    for (j = i; j > 0 && a[j - 1] > last; j--)
      a[j] = a[j - 1];
    a[j] = last;
  }
}

/*
Tại bước k, tìm phần tử nhỏ nhất trong dãy còn lại và đổi chỗ với phần tử đang xét
Độ phức tạp: O(n^2)
*/
void selection_sort(int *a, int n)
{
  int i, j, min;
  for (i = 0; i < n - 1; i++)
  {
    min = i;
    for (j = i + 1; j < n; j++)
      if (a[j] < a[min])
        min = j;
    if (min != i)
      swap(a[i], a[min]);
  }
}

/*
Đổi chỗ 2 phần tử liên tiếp
Độ phức tạp: O(n^2)
*/
void bubble_sort(int *a, int n)
{
  int i, j;
  for (i = (n - 1); i >= 0; i--)
    for (j = 1; j <= i; j++)
      if (a[j - 1] > a[j])
        swap(a[j - 1], a[j]);
}

/*
Merge sort
Độ phức tạp: O(nlogn)
*/
void merge(int *a, int first, int mid, int last)
{
  int i = first, j = mid + 1, k = 0;
  int *temp = new int[last - first + 1];
  while (i <= mid && j <= last)
  {
    if (a[i] < a[j])
      temp[k++] = a[i++];
    else
      temp[k++] = a[j++];
  }
  while (i <= mid)
    temp[k++] = a[i++];
  while (j <= last)
    temp[k++] = a[j++];
  for (int i = 0; i < k; i++)
    a[first + i] = temp[i];
  delete[] temp;
}
void merge_sort(int *a, int first, int last)
{
  if (first < last)
  {
    int mid = (first + last) / 2;
    merge_sort(a, first, mid);
    merge_sort(a, mid + 1, last);
    merge(a, first, mid, last);
  }
}

// Quick sort
// Độ phức tạp: O(nlogn)
int partition(int *a, int left, int right)
{
  int pivot = a[(left + right) / 2];
  while (left <= right)
  {
    while (a[left] < pivot)
      left++;
    while (a[right] > pivot)
      right--;
    if (left <= right)
    {
      swap(a[left], a[right]);
      left++;
      right--;
    }
  }
  return left;
}

void quick_sort(int *a, int left, int right)
{
  int index = partition(a, left, right);
  if (left < index - 1)
    quick_sort(a, left, index - 1);
  if (index < right)
    quick_sort(a, index, right);
}

void max_heapify(int *a, int i, int n)
{
  int left = 2 * i + 1, right = 2 * i + 2, largest = i;
  if (left <= n && a[left] > a[largest])
    largest = left;
  if (right <= n && a[right] > a[largest])
    largest = right;
  if (largest != i)
  {
    swap(a[i], a[largest]);
    max_heapify(a, largest, n);
  }
}

void build_max_heap(int *a, int n)
{
  for (int i = n / 2; i >= 0; i--)
    max_heapify(a, i, n);
}

void heap_sort(int *a, int n)
{
  build_max_heap(a, n);
  for (int i = n - 1; i >= 0; i--)
  {
    swap(a[0], a[i]);
    max_heapify(a, 0, i - 1);
  }
}

void print(int *a, int n)
{
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}

int main()
{
  int a[] = {1, 5, 2, 4, 3};
  int n = sizeof(a) / sizeof(int);
  cout << "The original array: ";
  print(a, n);
  cout << "insertion, selection, bubble, merge, quick, heap, print, random, exit" << endl;
  cout << "Enter the type of sort: ";
  string type;
  do
  {
    cin >> type;
    if (type == "exit")
      break;
    if (type == "insertion")
      insertion_sort(a, n);
    else if (type == "selection")
      selection_sort(a, n);
    else if (type == "bubble")
      bubble_sort(a, n);
    else if (type == "merge")
      merge_sort(a, 0, n - 1);
    else if (type == "quick")
      quick_sort(a, 0, n - 1);
    else if (type == "heap")
      heap_sort(a, n);
    else if (type == "print")
      print(a, n);
    else if (type == "random")
    {
      for (int i = 0; i < n; i++)
        a[i] = rand() % 100;
      print(a, n);
    }
    else
    {
      cout << "Invalid command" << endl;
    }
  } while (type != "exit");
}
