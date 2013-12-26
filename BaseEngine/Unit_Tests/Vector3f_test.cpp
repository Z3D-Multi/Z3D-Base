#ifdef __BUILD_FOR_TEST

#include "../Vector3f.h"
#include "UnitHeader.h"
#include __CUTE_LIBRARY_PATH
#include <cmath>

#ifndef __VECTOR3F_TEST
#define __VECTOR3F_TEST
namespace Z3D_Test {
	class Vector3f_Test {
	private:
		static cute::suite *s;

		static void testConstructor() {
			float x=10.0,y=12.0,z=13.54;
			Z3D_Base::Vector3f temp(x,y,z);

			Z3D_Base::Vector3f temp2 = temp;

			ASSERT_EQUALM("Test failed for vector3f in constructor: x=x",x,temp.getX());
			ASSERT_EQUALM("Test failed for vector3f in constructor: y=y",y,temp.getY());
			ASSERT_EQUALM("Test failed for vector3f in constructor: z=z",z,temp.getZ());

			ASSERT_EQUALM("Test failed for vector3f in copy constructor: x=x",temp2.getX(),temp.getX());
			ASSERT_EQUALM("Test failed for vector3f in copy constructor: y=y",temp2.getY(),temp.getY());
			ASSERT_EQUALM("Test failed for vector3f in copy constructor: z=z",temp2.getZ(),temp.getZ());
		}

		static void testOperators()
		{
			s->push_back(CUTE(testArithematicOperators));
			s->push_back(CUTE(testLogicOperators));
		}

		static void testLogicOperators()
		{
			float x=10.1,y=23.5,z=13.54;
			Z3D_Base::Vector3f temp(x,y,z), temp1(x,y,z);

			ASSERTM("Test failed for vector3f in operator arithematic(vector): x==y", (Z3D_Base::Vector3f)temp==(Z3D_Base::Vector3f)temp1);
		}

		static void testArithematicOperators()
		{
			float x=10.1,y=23.5,z=13.54;
			float x1=12.5,y1=13.2,z1=13.154;

			Z3D_Base::Vector3f temp(x,y,z);
			Z3D_Base::Vector3f temp1(x1,y1,z1);
			Z3D_Base::Vector3f temp2;

			//Test vector addition://
			//temp2 = temp1.operator+(temp);
			temp2=temp1+temp;
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic(vector): x=x1+x2",temp.getX()+temp1.getX(),temp2.getX());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic(vector): y=y1+y2",temp.getY()+temp1.getY(),temp2.getY());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic(vector): z=z1+z2",temp.getZ()+temp1.getZ(),temp2.getZ());

			//Test vector self addition://
			temp2 = temp;
			temp += temp1;
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic(vector): y+=y2",temp2.getX()+temp1.getX(),temp.getX());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic(vector): x+=x2",temp2.getY()+temp1.getY(),temp.getY());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic(vector): z+=z2",temp2.getZ()+temp1.getZ(),temp.getZ());

			//Test float addition://
			temp1 = temp + x;
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: X1=X + x",temp.getX()+x,temp1.getX());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: Y1=Y + x",temp.getY()+x,temp1.getY());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: Z1=Z + x",temp.getZ()+x,temp1.getZ());

			//Test float self addition://
			temp2 = temp;
			temp += x;
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: X1+=x",temp2.getX()+x,temp.getX());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: Y1+=x",temp2.getY()+x,temp.getY());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: Z1+=x",temp2.getZ()+x,temp.getZ());

			//Test vector subtraction://
			temp2 = temp-temp1;
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic(vector): x=x1-x2",temp.getX()-temp1.getX(),temp2.getX());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic(vector): y=y1-y2",temp.getY()-temp1.getY(),temp2.getY());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic(vector): z=z1-z2",temp.getZ()-temp1.getZ(),temp2.getZ());

			//Test vector self subtraction://
			temp2 = temp;
			temp -= temp1;
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic(vector): y-=y2",temp2.getX()-temp1.getX(),temp.getX());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic(vector): x-=x2",temp2.getY()-temp1.getY(),temp.getY());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic(vector): z-=z2",temp2.getZ()-temp1.getZ(),temp.getZ());

			//Test float subtraction://
			temp1 = temp - x;
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: X1=X - x",temp.getX()-x,temp1.getX());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: Y1=Y - x",temp.getY()-x,temp1.getY());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: Z1=Z - z",temp.getZ()-x,temp1.getZ());

			//Test float self subtraction://
			temp2 = temp;
			temp -= x;
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: X1-=x",temp2.getX()-x,temp.getX());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: Y1-=x",temp2.getY()-x,temp.getY());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: Z1-=x",temp2.getZ()-x,temp.getZ());

			//Test float division://
			temp1 = temp / x;
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: X1=X / x",temp.getX()/x,temp1.getX());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: Y1=Y / x",temp.getY()/x,temp1.getY());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: Z1=Z / x",temp.getZ()/x,temp1.getZ());

			//Test float self division://
			temp2 = temp;
			temp /= x;
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: X1/=x",temp2.getX()/x,temp.getX());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: Y1/=x",temp2.getY()/x,temp.getY());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: Z1/=x",temp2.getZ()/x,temp.getZ());

			//Test float multiplication://
			temp1 = temp * x;
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: X1=X * x",temp.getX()*x,temp1.getX());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: Y1=Y * x",temp.getY()*x,temp1.getY());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: Z1=Z * x",temp.getZ()*x,temp1.getZ());

			//Test float self multiplication://
			temp2 = temp;
			temp *= x;
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: X1*=x",temp2.getX()*x,temp.getX());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: Y1*=x",temp2.getY()*x,temp.getY());
			ASSERT_EQUALM("Test failed for vector3f in operator arithematic: Z1*=x",temp2.getZ()*x,temp.getZ());

			//Test Cross Product://
			temp.setXYZ(1.0f,0.0f,0.0f);
			temp1.setXYZ(0.0f,1.0f,0.0f);
			temp2.setXYZ(0.0f,0.0f,1.0f);

			ASSERTM("Test failed for vector3f in operator arithematic(vector): k=i*j",(Z3D_Base::Vector3f)temp2==(Z3D_Base::Vector3f)(temp*temp1));
			ASSERTM("Test failed for vector3f in operator arithematic(vector): i=j*k",(Z3D_Base::Vector3f)temp==(Z3D_Base::Vector3f)(temp1*temp2));
			ASSERTM("Test failed for vector3f in operator arithematic(vector): j=k*i",(Z3D_Base::Vector3f)temp1==(Z3D_Base::Vector3f)(temp2*temp));

		}


		static void testRotation() {
			Z3D_Base::Vector3f temp(1.0f,0.0f,0.0f), temp1(0.0f,1.0f,0.0f), temp2(0.0f,0.0f,1.0f);

			ASSERT_EQUALM("Test failed for vector3f in rotation-1(vector)",temp1,temp.rotate(90.0f,temp2));

		}

	public:
		static void testBegin(cute::suite *s) {
			Vector3f_Test::s = s;
			s->push_back(CUTE(testConstructor));
			s->push_back(CUTE(testRotation));
			testOperators();
		}

	};

	//Static variable storage allocation://
	cute::suite *Vector3f_Test::s;
}
#endif

#endif
