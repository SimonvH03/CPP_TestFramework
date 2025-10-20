#include "TestRunner.hpp"

int	main(void)
{
	TestRunner::get().runAllTests();
	return 0;
}

#include "TestCreation.hpp"
#include "ValidationTools.hpp"

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// Animal
TEST(Call_Animal_Default_Constructor) {
	Animal	animal;
}

TEST(Call_Animal_Copy_Constructor) {
	Animal	animal;
	Animal	copy(animal);
}

TEST(Call_Animal_Assignment_Operator) {
	Animal	animal1;
	Animal	animal2;
	animal2 = animal1;
}

TEST(Call_Animal_getType) {
	Animal	animal;
	animal.getType();
}

TEST(Call_Animal_makeSound) {
	Animal	animal;
	animal.makeSound();
}

TEST(Valid_Animal_Default_Type) {
	Animal	animal;
	EQUATE(animal.getType(), "Animal");
}

// Cat
TEST(Call_Cat_Default_Constructor) {
	Cat	cat;
}

TEST(Call_Cat_Copy_Constructor) {
	Cat	cat;
	Cat	copy(cat);
}

TEST(Call_Cat_Assignment_Operator) {
	Cat	cat1;
	Cat	cat2;
	cat2 = cat1;
}

TEST(Call_Cat_getType) {
	Cat	cat;
	cat.getType();
}

TEST(Call_Cat_makeSound) {
	Cat	cat;
	cat.makeSound();
}

TEST(Valid_Cat_Default_Type) {
	Cat	cat;
	EQUATE(cat.getType(), "Cat");
}

// Dog
TEST(Call_Dog_Default_Constructor) {
	Dog	dog;
}

TEST(Call_Dog_Copy_Constructor) {
	Dog	dog;
	Dog	copy(dog);
}

TEST(Call_Dog_Assignment_Operator) {
	Dog	dog1;
	Dog	dog2;
	dog2 = dog1;
}

TEST(Call_Dog_getType) {
	Dog	dog;
	dog.getType();
}

TEST(Call_Dog_makeSound) {
	Dog	dog;
	dog.makeSound();
}

TEST(Valid_Dog_Default_Type) {
	Dog	dog;
	EQUATE(dog.getType(), "Dog");
}

// Mix
TEST(Valid_Animal_Copy_Constructor) {
	{	Cat		cat;
		Animal	animal(cat);
		EQUATE(animal.getType(), cat.getType());
	}
	{	Dog		dog;
		Animal	animal(dog);
		EQUATE(animal.getType(), dog.getType());
	}
}

TEST(Valid_Animal_Assignment_Operator) {
	{	Animal	animal;
		Cat		cat;
		animal = cat;
		EQUATE(animal.getType(), cat.getType());
	}
	{	Animal	animal;
		Dog		dog;
		animal = dog;
		EQUATE(animal.getType(), dog.getType());
	}
}
