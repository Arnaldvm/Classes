#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Classes\Point2D.cpp"
#include "..\Classes\String.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(Tests){
	public:

		TEST_METHOD(setZero){ //We set to 0 and check if it is true.

			Point2D p;
			p.setZero();
			Assert::IsTrue(p.x == 0.0f);
			Assert::IsTrue(p.y == 0.0f);

		}

		TEST_METHOD(areZero){ //We make them 0 and then we check if x and y are actually 0.

			Point2D p;
			p.x = 0.0f;
			p.y = 0.0f;
			Assert::IsTrue(p.areZero());

		}

		TEST_METHOD(subtract){ //We create 2 Point2D and we subtract their x and y. Then we check if its equal to p (no need to create a 3rd object)

			Point2D p;
			p.x = 1.0f;
			p.y = 1.0f;
			Point2D q;
			q.x = 2.0f;
			q.y = 2.0f;
			Assert::IsTrue(q - p == p);

		}

		TEST_METHOD(add){ //We create 2 Point2D and we add their x and y. Then we check if its equal to q (no need to create a 3rd object)

			Point2D p;
			p.x = 1.0f;
			p.y = 1.0f;
			Point2D q;
			q.x = 2.0f;
			q.y = 2.0f;
			Assert::IsTrue(p + p == q);

		}

		TEST_METHOD(subtract_equal){ //We create 2 Point2D and we subtract the 1st to the 2nd. Then we check if its equal to p (no need to create a 3rd object)

			Point2D p;
			p.x = 1.0f;
			p.y = 1.0f;
			Point2D q;
			q.x = 2.0f;
			q.y = 2.0f;
			Assert::IsTrue((p -= q) == p);

		}

		TEST_METHOD(add_equal){ //We create 2 Point2D and we add the 1st to itself. Then we check if its equal to q (no need to create a 3rd object)

			Point2D p;
			p.x = 1.0f;
			p.y = 1.0f;
			Point2D q;
			q.x = 2.0f;
			q.y = 2.0f;
			Assert::IsTrue((p += p) == q);
		}

		TEST_METHOD(equal){ //We create 2 Point2D with the same values. Then we check if they are equal.

			Point2D p;
			p.x = 1.0f;
			p.y = 1.0f;
			Point2D q;
			q.x = 1.0f;
			q.y = 1.0f;
			Assert::IsTrue(p == q);
		}

		TEST_METHOD(not_equal){ //We create 2 Point2D with the different values. Then we check if they are different.

			Point2D p;
			p.x = 1.0f;
			p.y = 1.0f;
			Point2D q;
			q.x = 2.0f;
			q.y = 2.0f;
			Assert::IsTrue(p != q);
		}

		TEST_METHOD(adjudicate){  //We create 2 Point2D with the different values. Then we adjudicate the 1st to the 2nd. We compare if the 2nd and the 1st are the same.

			Point2D p;
			p.x = 1.0f;
			p.y = 1.0f;
			Point2D q;
			q.x = 2.0f;
			q.y = 2.0f;
			Assert::IsTrue((p = q) == p);
		}

		TEST_METHOD(distance){ ///We create 2 Point2D with the different values. Then we calculate the distance and check if it is true.

			Point2D p;
			p.x = 1.0f;
			p.y = 1.0f;
			Point2D q;
			q.x = 1.0f;
			q.y = 3.0f;
			Assert::IsTrue(p.distanceTo(q) == 2);
		}

// ----------------------------------------------------------------------------------
		
		TEST_METHOD(chain){

		String* a = new String(); //We create a new empty String and we check if it is actually empty.
		
		Assert::AreEqual(a->characters, "");
		Assert::IsTrue(a->length_string == 1);
		}
		
		TEST_METHOD(string_char_format){ //We create a new String with whatever arguments and we check if the length and the content are fine.

		String* a = new String("%s", "Hello");
		Assert::AreEqual(a->characters, "Hello");
		Assert::IsTrue(a->length_string == 6);
		}
		
		TEST_METHOD(string_reference){  //We create two new Strings (the 2nd with the 1st as argument) and we check if the length and the content are fine.

		String* a = new String("Hello");
		String* b = new String(*a);
		Assert::AreEqual(b->characters, "Hello");
		unsigned int c = 6;
		Assert::AreEqual(b->length_string, c);
		}
		
		TEST_METHOD(deletes){ //We create a new String and then check if the content was removed.

		String* a = new String("Hello");
		a->~String();
		Assert::IsTrue(a->characters != "Hello");
		Assert::IsTrue(a->length_string != 5);
		}
		
		TEST_METHOD(equal_s_char){ //We create a new String and check if the content associated is actually the same.

		String* a = new String("Hello World!");
		
		Assert::IsTrue(*a == "Hello World!");
		}
		
		TEST_METHOD(equal_s_s){ // We create 2 equal Strings and we check if they are the same.

		String* a = new String("Hello World!");
		String* b = new String("Hello World!");
		Assert::IsTrue(*a == *b);
		}
		
		TEST_METHOD(not_equal_s_char){ //We create a new String and check if the content associated is different.

			String* a = new String("Hello World!"); 

			Assert::IsTrue(*a != "HelloWorld!");
		}
		
		TEST_METHOD(not_equal_s_s){ // We create 2 equal Strings and we check if they are different.

		String* a = new String("Hello World!");
		String* b = new String("Hello");
		Assert::IsTrue(*a != *b);
		}
		
	
		TEST_METHOD(adjudicate_s_char){ //We create a String, then we associate a char to it, and we check if it is the same.

		String* a = new String();
		a->characters = "Hello World!";
		Assert::IsTrue(a->characters == "Hello World!");
		}
		
		TEST_METHOD(adjudicate_s_s){ //We create an empty String and a String with a char. We adjudicate the 2nd to the 1st and we check if they are the same.

		String* a;
		String* b = new String("Hello World");
		a = b;
		Assert::IsTrue(*a == *b);
		}
		
		TEST_METHOD(add_s_char){ //We create a String and we associate it "Hello", we create a new empty String and then we do the operation. Finally we check if they are the same.

		String* a = new String();
		a->characters = "Hello";
		String* b = new String();
		*b += *a;
		Assert::IsTrue(b->characters == "Hello");
		}

		TEST_METHOD(add_s_s){ //We create 2 Strings and then we add the 2nd to the 1st. Then we chack if they are the same.

		String* a = new String("Hel");
		String* b = new String("lo");
		*a += *b;
		String* c = new String("Hello");
		Assert::IsTrue(a->length_string == c->length_string);

		}

		TEST_METHOD(lenght){ //We create a new String and we check its lenght with the function.
		String* a= new String("Hello");
		Assert::IsTrue(a->length() == 5);
		}

		TEST_METHOD(capacity){
		String* a = new String("Hello"); //We create a new String and we check its capacity with the function.
		Assert::IsTrue(a->capacity() == 6);
		}

		TEST_METHOD(get_string){ //We create a new String and we check its content with the function.
		String* a = new String("Hello");
		Assert::AreEqual(a->getString() , "Hello");
		}

		TEST_METHOD(clear){ //We create a new String and we check if it is empty after the clear.
		String* a = new String("Hello");
		a->clear();
		Assert::AreEqual(a->characters, "");
		
		}

		
	};
}

