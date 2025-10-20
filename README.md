# CPP_TestFramework
A compact C++ Test framework to simplify writing tests for the 42 CPP Modules.

### Goal
This tool aids fast test creation, execution and logging. The main focus is to save time, and simplify writing tests.

### Compliance
To comply with 42 CPP Module requirements, each exercise must compile with a Makefile and main.cpp inside the Turn-in directory, and "there must be at least a main.cpp file with tests provided". Make sure you do not overlook this.

# Usage
```
#include "TestRunner.hpp"

int	main(void)
{
	TestRunner::get().runAllTests();
	return 0;
}
```
```
#include "TestCreation.hpp"
#include "ValidationTools.hpp" (optional)

#include "YourClass.hpp" (optional)

TEST(<test name>)
{
	// test body
}
```

### Compilation
The included Makefile will compile the TestRunner into an archive (library) of c++ object files.
Per the 42 Norm about Makefiles (yes, it still applies to C++) you must compile libraries by calling their respective Makefile in your Makefile. I suggest using '$(MAKE) -C <lib_directory>'. You can then simply add the archive to your Executable rule's dependencies and compilation as if it were an object file (because it is a bunch of object files).

Tests will only compile with std=c++20 and up. You can opt to compile your subject as an archive in an earlier c++ standard.

# ValidationTools
I'm still discovering what tools could be helpful for validating most of the exercises. I noticed a lot of Modules require validation by printing to stdout, I haven't looked into how to cleanly validate behaviour of this kind yet. If you have any ideas for useful validation tools, please do not hesitate to contribute to this repository.

Currently the available tools are:
- CHECK(expression)
	- can take any boolean expression
	- fails when the expression evaluates to false
	- will log expression as a string
- EQUATE(object A, object B)
	- can take any std::two equality_comparible_with<> object types
	- fails when object A and B are not equal according to A::operator==(B const&)
 	- will log each parameter as a string
    - will attempt to log the _value_ of each parameter as a string


A working example of the Compilation, File tree, and Test writing is provided.
