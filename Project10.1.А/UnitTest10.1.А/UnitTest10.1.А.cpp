#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../Project10.1.А/Source.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest101А
{
	TEST_CLASS(UnitTest101А)
	{
	public:

		TEST_METHOD(Test_PercentHighAverage)
		{
			Student students[] = {
				{"Ivanenko", 2, PHYSICS, 5, 5, 5},  
				{"Petrenko", 3, MATHEMATICS, 4, 4, 4},  
				{"Shevchenko", 1, ENGINEERING, 3, 5, 5},  
				{"Bondarenko", 4, PHYSICS, 5, 5, 5}  
			};

			int N = 4;

			double percent = PercentHighAverage(students, N);
			Assert::AreEqual(50.0, percent, 0.01);
		}

		TEST_METHOD(Test_PrintExcellentStudents)
		{
			Student students[] = {
				{"Ivanenko", 2, PHYSICS, 5, 5, 5},  
				{"Petrenko", 3, MATHEMATICS, 4, 4, 4}, 
				{"Shevchenko", 1, ENGINEERING, 3, 5, 5}, 
				{"Bondarenko", 4, PHYSICS, 5, 5, 5}  
			};

			int N = 4;

			int excellentCount = 0;
			for (int i = 0; i < N; i++) {
				double avg = (students[i].fizyka + students[i].matematika + students[i].informatyka) / 3.0;
				if (avg >= 4.5) {
					excellentCount++;
				}
			}

			Assert::AreEqual(2, excellentCount);
		}

		
	};
}
