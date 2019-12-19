#include <iostream>
#include "GPM/GPM.h"

int main(const int p_argc, char** p_argv)
{
	try
	{
		// Your tests here
		Matrix4F test = Matrix4F::identity;
		std::cout << "[]=" << test[4] << " (,)=" << test(1,4);

		
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception thrown: " << e.what() << '\n';
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}