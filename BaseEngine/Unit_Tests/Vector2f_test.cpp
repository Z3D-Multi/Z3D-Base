#ifdef __BUILD_FOR_TEST

#include "../Vector2f.h"
#include "UnitHeader.h"
#include __CUTE_LIBRARY_PATH

#ifndef __VECTOR2F_TEST
#define __VECTOR2F_TEST
namespace Z3D_Test {
	class Vector2f_Test {
	private:
		static cute::suite *s;

		static void testConstructor() {
			float x=10.0,y=12.0;
			Z3D_Base::Vector2f temp(x,y);

			Z3D_Base::Vector2f temp2 = temp;

			ASSERT_EQUALM("Test failed for vector2f in constructor: x=x",x,temp.getX());
			ASSERT_EQUALM("Test failed for vector2f in constructor: y=y",y,temp.getY());

			ASSERT_EQUALM("Test failed for vector2f in copy constructor: x=x",temp2.getX(),temp.getX());
			ASSERT_EQUALM("Test failed for vector2f in copy constructor: y=y",temp2.getY(),temp.getY());
		}

		static void testOperators()
		{
			s->push_back(CUTE(testArithematicOperators));
			s->push_back(CUTE(testLogicOperators));
		}

		static void testLogicOperators()
		{
			float x=10.1,y=23.5;
			Z3D_Base::Vector2f temp(x,y), temp1(x,y);

			ASSERTM("Test failed for vector2f in operator arithematic(vector): x==y", (Z3D_Base::Vector2f)temp==(Z3D_Base::Vector2f)temp1);
		}

		static void testArithematicOperators()
		{
			float x=10.1,y=23.5;
			float x1=12.5,y1=13.2;

			Z3D_Base::Vector2f temp(x,y);
			Z3D_Base::Vector2f temp1(x1,y1);
			Z3D_Base::Vector2f temp2;

			//Test vector addition://
			//temp2 = temp1.operator+(temp);
			temp2=temp1+temp;
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic(vector): x=x1+x2",temp.getX()+temp1.getX(),temp2.getX());
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic(vector): y=y1+y2",temp.getY()+temp1.getY(),temp2.getY());

			//Test vector self addition://
			temp2 = temp;
			ASSERT(temp2.getX()==temp.getX());
			temp += temp1;
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic(vector): y+=y2",temp2.getX()+temp1.getX(),temp.getX());
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic(vector): x+=x2",temp2.getY()+temp1.getY(),temp.getY());

			//Test float addition://
			temp1 = temp + x;
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic: X1=X + x",temp.getX()+x,temp1.getX());
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic: Y1=Y + x",temp.getY()+x,temp1.getY());

			//Test float self addition://
			temp2 = temp;
			temp += x;
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic: X1+=x",temp2.getX()+x,temp.getX());
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic: Y1+=x",temp2.getY()+x,temp.getY());

			//Test vector subtraction://
			temp2 = temp-temp1;
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic(vector): x=x1-x2",temp.getX()-temp1.getX(),temp2.getX());
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic(vector): y=y1-y2",temp.getY()-temp1.getY(),temp2.getY());

			//Test vector self subtraction://
			temp2 = temp;
			temp -= temp1;
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic(vector): y-=y2",temp2.getX()-temp1.getX(),temp.getX());
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic(vector): x-=x2",temp2.getY()-temp1.getY(),temp.getY());

			//Test float subtraction://
			temp1 = temp - x;
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic: X1=X - x",temp.getX()-x,temp1.getX());
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic: Y1=Y - x",temp.getY()-x,temp1.getY());

			//Test float self subtraction://
			temp2 = temp;
			temp -= x;
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic: X1-=x",temp2.getX()-x,temp.getX());
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic: Y1-=x",temp2.getY()-x,temp.getY());

			//Test float division://
			temp1 = temp / x;
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic: X1=X / x",temp.getX()/x,temp1.getX());
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic: Y1=Y / x",temp.getY()/x,temp1.getY());

			//Test float self division://
			temp2 = temp;
			temp /= x;
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic: X1/=x",temp2.getX()/x,temp.getX());
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic: Y1/=x",temp2.getY()/x,temp.getY());

			//Test float multiplication://
			temp1 = temp * x;
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic: X1=X * x",temp.getX()*x,temp1.getX());
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic: Y1=Y * x",temp.getY()*x,temp1.getY());

			//Test float self multiplication://
			temp2 = temp;
			temp *= x;
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic: X1*=x",temp2.getX()*x,temp.getX());
			ASSERT_EQUALM("Test failed for vector2f in operator arithematic: Y1*=x",temp2.getY()*x,temp.getY());
		}

	public:
		static void testBegin(cute::suite *s) {
			Vector2f_Test::s = s;
			s->push_back(CUTE(testConstructor));
			testOperators();
		}

	};

	//Static variable storage allocation://
	cute::suite *Vector2f_Test::s;
}
#endif

#endif
