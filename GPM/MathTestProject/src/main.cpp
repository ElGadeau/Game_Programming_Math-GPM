#include <iostream>
#include "GPM/GPM.h"

int main(const int p_argc, char** p_argv)
{
	try
	{
		// Your tests here
		Matrix4F test = Matrix4F::identity;
		std::cout << "[]=" << test[4] << " (,)=" << test(1,3);

		Quaternion quat(1.0f, 2.0f, 30.0, 1.0f);
		Quaternion quat2(1.0f, 2.0f, 30.0, 1.0f);
		quat.Normalize();
		quat *= quat2;

		std::cout << quat[0];

		Vector4F tmp = Vector4F::one;
		std::cout << tmp[0];
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception thrown: " << e.what() << '\n';
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}