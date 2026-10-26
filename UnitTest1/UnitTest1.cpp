
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64IT
{
    TEST_CLASS(UnitTest64IT)
    {
    public:

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
                        first = i;

                    last = i;
                }
            }

            if (first == -1 || first == last)
                return 0;

            int sum = 0;

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
                    k++;
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (a[i] < 0)
                {
                    b[k] = a[i];
                    k++;
                }
            }

            for (int i = 0; i < n; i++)
            {
                a[i] = b[i];
            }

            delete[] b;
        }

        TEST_METHOD(Test1)
        {
            int a[4] = { 3, 2, 5, 4 };
            Assert::AreEqual(8LL, ProductEven(a, 4));
        }

        TEST_METHOD(Test2)
        {
            int a[6] = { 0, 5, -2, 3, 0, 7 };
            Assert::AreEqual(6, SumBetweenZeros(a, 6));
        }

        TEST_METHOD(Test3)
        {
            int a[5] = { 1, 2, 3, 4, 5 };
            Assert::AreEqual(0, SumBetweenZeros(a, 5));
        }

        TEST_METHOD(Test4)
        {
            int a[6] = { -3, 2, -1, 0, 5, -4 };
            int expected[6] = { 2, 0, 5, -3, -1, -4 };

            Rearrange(a, 6);

            for (int i = 0; i < 6; i++)
            {
                Assert::AreEqual(expected[i], a[i]);
            }
        }
    };
}
