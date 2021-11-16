#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Misha\source\repos\lab 7.1\lab 7.1\lab 7.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rowCount = 1;
			int colCount = 3;
			int** Z = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				Z[i] = new int[colCount];

			int S;
			int k;
			int i = Calc(Z, 1, 3, S, k);

			Assert::AreEqual(i, S);
		}
	};
}
