#ifdef __BUILD_FOR_TEST

#include "../Matrix4f.h"
#include "UnitHeader.h"
#include __CUTE_LIBRARY_PATH

#ifndef __MATRIX4F_TEST
#define __MATRIX4F_TEST
namespace Z3D_Test {
	class Matrix4f_Test {
	private:
		static cute::suite *s;

		static void testConstructor()
		{
			Z3D_Base::Matrix4f temp;
			Z3D_Base::Matrix4f temp1 = temp;
			ASSERT_EQUALM("Test failed for matrix4f in copy constructor", (Z3D_Base::Matrix4f)temp,(Z3D_Base::Matrix4f)temp1);

		}

		static void testOperators()
		{
			s->push_back(CUTE(testArithematicOperators));
			s->push_back(CUTE(testLogicOperators));
		}

		static void testLogicOperators()
		{
			Z3D_Base::Matrix4f temp, temp1;
			temp.loadIdentity();
			temp1.loadIdentity();

			ASSERTM("Test failed for matrix4f in operator arithematic: x==y", (Z3D_Base::Matrix4f)temp==(Z3D_Base::Matrix4f)temp1);

			temp1=temp;
			ASSERTM("Test failed for matrix4f in operator arithematic-2: x==y", (Z3D_Base::Matrix4f)temp==(Z3D_Base::Matrix4f)temp1);
		}

		static void testArithematicOperators()
		{
			Z3D_Base::Matrix4f temp,temp1,temp2;

			temp1.set(0,2,0.0f);
			temp.loadIdentity();
			temp2 = temp1*temp;

			//Test matrix multiplication://
			ASSERT_EQUALM("Test failed for matrix4f in operator arithematic: x=x1*x2",temp1,temp2);

			//Test vector multiplication://
			Z3D_Base::Vector3f temp3(1.0f,2.0f,3.0f);
			Z3D_Base::Vector3f temp4 = temp*temp3;
			ASSERT_EQUALM("Test failed for matrix4f in operator arithematic(vector): x=y*z",temp3,temp4);
		}

	public:
		static void testBegin(cute::suite *s) {
			Matrix4f_Test::s = s;
			s->push_back(CUTE(testConstructor));
			testOperators();
		}

	};

	//Static variable storage allocation://
	cute::suite *Matrix4f_Test::s;
}
#endif

#endif
