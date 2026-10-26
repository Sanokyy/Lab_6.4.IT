
#include <iostream>
#include <iomanip>
using namespace std;

void Print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

long long ProductEven(int a[], int n)
{
    long long product = 1;

    for (int i = 1; i < n; i = i + 2)
    {
        product = product * a[i];
    }

    return product;
}

int SumBetweenZeros(int a[], int n)
{
    int first = -1;
    int last = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            if (first == -1)
            {
                first = i;
            }

            last = i;
        }
    }

    int sum = 0;

    if (first == -1 || first == last)
    {
        return 0;
    }

    for (int i = first + 1; i < last; i++)
    {
        sum = sum + a[i];
    }

    return sum;
}

void Rearrange(int a[], int n)
{
    int* b = new int[n];
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            b[k] = a[i];
            k = k + 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            b[k] = a[i];
            k = k + 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }

    delete[] b;
}

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    if (n <= 0)
    {
        return 0;
    }

    int* a = new int[n];

    cout << "Enter elements:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Original array: ";
    Print(a, n);

    cout << "Product = " << ProductEven(a, n) << endl;
    cout << "Sum = " << SumBetweenZeros(a, n) << endl;

    Rearrange(a, n);

    cout << "Modified array: ";
    Print(a, n);

    delete[] a;

    return 0;
}
