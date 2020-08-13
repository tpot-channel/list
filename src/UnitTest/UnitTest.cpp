#include "pch.h"
#include "CppUnitTest.h"

#include "../include/list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestList
{
	TEST_CLASS(List)
	{
	public:
		
		TEST_METHOD(TestAdd)
		{
			LIST *p = NULL;
			
			p = list_add(p, 1);
			Assert::AreEqual(1, list_get_data(p));

			delete_list_all(p);
		}

		TEST_METHOD(TestAddTwoNode)
		{
			LIST* p = NULL;
			p = list_add(p, 1);
			p = list_add(p, 2);

			LIST* n = p;
			int expected[] = {2, 1};
			int number = sizeof(expected) / sizeof(int);
			for (int i = 0; i < number; i++) {
				Assert::AreEqual(expected[i], list_get_data(n));
				n = n->next;
			}

			delete_list_all(p);
		}

		TEST_METHOD(TestDelete)
		{
			LIST* p = NULL;
			p = list_add(p, 1);
			p = list_add(p, 2);

			p = list_delete(p);

			Assert::AreEqual(1, list_length(p));

			delete_list_all(p);
		}

		TEST_METHOD(TestDeleteNull)
		{
			LIST* p = NULL;
			p = list_delete(p);

			Assert::AreEqual(0, list_length(p));

			delete_list_all(p);
		}

		TEST_METHOD(TestDeleteIntermediate)
		{
			LIST* p = NULL;
			p = list_add(p, 1);
			p = list_add(p, 2);
			LIST* p2 = p;
			p = list_add(p, 3);

			list_delete_next(p2);

			Assert::AreEqual(2, list_length(p));

			LIST* n = p;
			int expected[] = { 3, 2 };
			int number = sizeof(expected) / sizeof(int);
			for (int i = 0; i < number; i++) {
				Assert::AreEqual(expected[i], list_get_data(n));
				n = n->next;
			}

			delete_list_all(p);
		}


		TEST_METHOD(TestGetNull)
		{
			Assert::AreEqual(0, list_get_data(NULL));
		}

		TEST_METHOD(TestLength)
		{
			LIST* p = NULL;
			p = list_add(p, 1);
			p = list_add(p, 2);

			Assert::AreEqual(2, list_length(p));

			delete_list_all(p);
		}


	};
}
