#include "Robot.h"

Robot::Robot(int initialEnergy) : Item("Robot")
{
	energy = initialEnergy;
}

void Robot::walk() 
{
	energy--;
}

void Robot::eat(Food *food)
{
	energy += food->getValue();
}

void Robot::collect(Jewel *jewel) 
{
	bag.push_back(*jewel);
}