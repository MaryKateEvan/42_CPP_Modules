#include <iostream>

using std::string; //this so that i don't have to write 3 lines below
				   // std::string every time. Just for readability.

//! PART A :

// everything inside this class is private by default:
class Employee {
	string Name;
	string Company;
	int Age;
};

//which is exactly the same as this situation:
class Employee {
private:	
	string Name;
	string Company;
	int Age;
};

//? SCENARIO B:
//so in order to be able to access the members of the class i need to do:
class Employee {
public:	
	string Name;
	string Company;
	int Age;

	// a "class method" is moreover a function inside the class.
	void Intoduce_Yourself(){
		std::cout << "Name - " << Name << std::endl;
		std::cout << "Company - " << Company << std::endl;
		std::cout << "Age - " << Age << std::endl;
	}
	// the class method kinda represents a behavior of our object we can provoke whenever we want.
};

int main()
{
	int number;
	//and the same way that we create the normal variables, we do also the object of the class we want:
	Employee empl1; //a "variable" of type Employee -> this is going to be an object of the above class.
	//if the members of the struct are not public, i can not access them with empl1. 
	// but if the members are public (SCENARIO B) i can now access them and assign values:
	empl1.Name = "Mary Kate";
	empl1.Company = "42 Heilbronn";
	empl1.Age = 23;
	// ... to access the attributes of the struct, but this doesn't happen because in c++ by default all the "members" of the class are private.
	//how to provoke the "behavior" of our employee, meaning to make him introduce himself:
	empl1.Intoduce_Yourself();

	Employee emp2; //a constructor is invoked
	Employee emp3; //a constructor is invoked

}

//! PART B: CONSTRUCTORS
/*
In c++ we have 3 access modifiers:
-	private: it can not be accessible outside of the class
-	public: i can access the members of the class even outside of the class (for example in my main function)
-	protected: something between private and public, that has specific rules.
				the derived class can also accessthe protected attributes

A constructor is a special type of method that is invoked each time an object of the class is created. 

Default constructor: is automatically generated by the compiler. 
If I don't create a constructor of my own the compiler is going to give me one. this is the "default" constructor.

A constructor is like a "method", so like a function, but:
	RULES of a constructor:
	- it does not have a return type
	- a constructor has the same name as the class he belongs to
	- the constructor must be PUBLIC (there are exceptions)

The moment we create a constructor of our own, that means it destroys the default constructor.
*/

class Employee {
public:	
	string Name;
	string Company;
	int Age;

	// a "class method" is moreover a function inside the class.
	void Intoduce_Yourself(){
		std::cout << "Name - " << Name << std::endl;
		std::cout << "Company - " << Company << std::endl;
		std::cout << "Age - " << Age << std::endl;
	}

	//? how to create a constructor:
	Employee(string name, string company, int age) {
		//the constructor constructs the object here, assigning the given values:
		Name = name;
		Company = company;
		Age = age;
	}
};

int main()
{
	/*
	Now that i have the constructor, instead of doing:
	Employee empl1;
	empl1.Name = "Mary Kate";
	empl1.Company = "42 Heilbronn";
	empl1.Age = 23;
	empl1.Intoduce_Yourself();
	*/
	//I can just do:
	Employee empl1 = Employee("Mary Kate", "42 Heilbronn", 23); //the constructor receives the parameters here
	empl1.Intoduce_Yourself();

	// So that if I had multiple employees, I wouldn't have to repeat every time the 3 lines
	// for each one of them. So I can just say:
	Employee empl2 = Employee("John", "Amazon", 35);
	empl2.Intoduce_Yourself();

	//and same for employee3, 4, 5 and so on...

}


//! PART C: ENCAPSULATION

/*
	Encapsulation: budling or tying together data, and methods that operate on that data. SO that they are grouped together on a class.
	With the purpose of preventing anyone outside of my class to be able to directly access the data of the class, intereact with it or modify it.
	We don't want that to happen directly. We want to provide our own way for that interaction.
	for the we use SETTERS and GETTERS, which are just class methods (functions)
*/

class Employee {
private:
	// now these 3 variables are "encapsulated":
	string Name;
	string Company;
	int Age;
public:	
	
	// For every "encapsulated variable" we need a setter and a getter:

	// Setter for Name:
	void setName(string name) {
		Name = name;
	}
	// Getter for Name:
	string getName() {
		return Name;
	}

	// Setter for Company:
	void setCompany(string company) {
		Company = company;
	}
	// Getter for Company:
	string getCompany() {
		return Company;
	}
	
	// Setter for Age:
	void setAge(int age) {
		if (age >= 18)
			Age = age;
	}
	// Getter for Age:
	int getAge() {
		return Age;
	}
	
	void Intoduce_Yourself() {
		std::cout << "Name - " << Name << std::endl;
		std::cout << "Company - " << Company << std::endl;
		std::cout << "Age - " << Age << std::endl;
	}

	//constructor:
	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}

};

int main()
{
	Employee empl1 = Employee("Mary Kate", "42 Heilbronn", 23); 
	empl1.Intoduce_Yourself();

	Employee empl2 = Employee("John", "Amazon", 35);
	empl2.Intoduce_Yourself();

	/* So now although the Name, Company and Age are private attributes, and I wouldn't be able to 
		modify them doing 
			empl1.Name = "Mary Kate";
			empl1.Company = "42 Heilbronn";
			empl1.Age = 23;
		I can now call the getters and setters:
	*/
	// So if i do: 
	empl1.setAge(30); // then the attribute Age of empl1 will be indeed changed.
	// But if I do:
	empl1.setAge(15); //it will not work, because I'm checkind if >= 18 in the setter.

}
/*
	so now with the encapsulation, whoever wants to have access to my class' variables 
	(name, Company, Age)	the need to use the methods of the class that i "expose", 
	meaning the setters and getters.
*/


//! PART D: ABSTRACTION

/*
	Abstraction:
	"Hiding complex things behind a procedure that makes those things look simple"
	In OPP We simulate the behavior of interface using abstract classes
*/

//! We use an "abstract class":
class AbstractEmployee {
	// pure virtual function:
	virtual void AskForPromotion() = 0;
	// that means that whichever class calls this contract (abstract class), needs 
	// to provide implemetation for the method AskForPromotion. Like the class above:
	//? we use the "virtual .... = 0;" to make the function AskForPromotion obgigatory
	//? so that any class that calls this abstract class MUST provide implementation
	//? for the AskForPromotion method.
};

// So now, instead of starting the class as:
// class Employee {
// we do:
class Employee:AbstractEmployee { //which means that this class is bound to "AskForPromotion"
//	so in this case, our Employee is "inheriting" from our AbstractEmployee
// so now it means that if I create an "Employee" object, I can invoke the method AskForPromotion.
// doing in my main for example: empl1.AskForPromotion();
private:
	string Name;
	string Company;
	int Age;
public:	
	void setName(string name) {
		Name = name;
	}
	string getName() {
		return Name;
	}
	void setCompany(string company) {
		Company = company;
	}
	string getCompany() {
		return Company;
	}
	void setAge(int age) {
		if (age >= 18)
			Age = age;
	}
	int getAge() {
		return Age;
	}
	
	void Intoduce_Yourself() {
		std::cout << "Name - " << Name << std::endl;
		std::cout << "Company - " << Company << std::endl;
		std::cout << "Age - " << Age << std::endl;
	}

	//constructor:
	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}

	//! the method that the abstract class needs:
	void AskForPromotion() {
		if (Age > 30)
			std::cout << Name << " got promoted!" << std::endl;
		else
			std::cout << Name << " sorry no Promotion for you!" << std::endl;
	}
};

int main()
{
	Employee empl1 = Employee("Mary Kate", "42 Heilbronn", 23); 
	Employee empl2 = Employee("John", "Amazon", 35);

	// So now I can do: 
	empl1.AskForPromotion();
	empl2.AskForPromotion();
	// and indeed for me it will print "sorry no promotion" but for John it will say
	// "got promoted"
}


//! PART E: INHERITANCE
/*
	A derived/child class inherits all the attributes and methods of the parent class, 
	and it can have additional attributes and/or methods of each own, that the parent
	class doesn't have.
	"subclass" or "derived class"
	"base class" or "parent class" or "super class";
*/

// the "abstract class":
class AbstractEmployee {
	// pure virtual function:
	virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee { //which means that this class is bound to "AskForPromotion"
//	so in this case, our Employee is "inheriting" from our AbstractEmployee
// so now it means that if I create an "Employee" object, I can invoke the method AskForPromotion.
// doing in my main for example: empl1.AskForPromotion();
private:
	string Name;
	string Company;
	int Age;
public:	
	void setName(string name) {
		Name = name;
	}
	string getName() {
		return Name;
	}
	void setCompany(string company) {
		Company = company;
	}
	string getCompany() {
		return Company;
	}
	void setAge(int age) {
		if (age >= 18)
			Age = age;
	}
	int getAge() {
		return Age;
	}
	
	void Intoduce_Yourself() {
		std::cout << "Name - " << Name << std::endl;
		std::cout << "Company - " << Company << std::endl;
		std::cout << "Age - " << Age << std::endl;
	}

	//constructor:
	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}

	// the method that the abstract class needs:
	void AskForPromotion() {
		if (Age > 30)
			std::cout << Name << " got promoted!" << std::endl;
		else
			std::cout << Name << " sorry no Promotion for you!" << std::endl;
	}
};

//! the subclass that inherits from the parent class "Employee":
class Developer:Employee {
public:
	string FavProgrLang;
	//now this subclass needs a constructor of its own:
	Developer(string name, string company, int age, string fpl)
		:Employee(name, company, age) //we do this because there is already a constructor for these 3 attributes, on the parent class "Employee"
	{
		FavProgrLang = fpl;
	}
	// let's create a new method on the subclass:
	void FixBug() {
		std::cout << getName() << " fixed bug using " << FavProgrLang << std::endl;
	}
	//? but if the "Name" attribute of the Employee class was "protected" instead of
	//? "private" we could access directly the Name value from the subclass and do:
	// void FixBug() {
	// 	std::cout << Name << " fixed bug using " << FavProgrLang << std::endl;
	// }
	//now is red, but if it was "protected" it wouldn't be
};

int main()
{
	Employee empl1 = Employee("Mary Kate", "42 Heilbronn", 23); 
	Employee empl2 = Employee("John", "Amazon", 35);

	// and now we can create an object of the subclass Developer:
	Developer d = Developer("Saldina", "Youtube", 25, "C++");
	//and we can call the method of the class like:
	d.FixBug(); //which prints: Saldina fixed bug using C++
}

// when the class is initialized as:
class Developer: Employee {};
// the inheritance is by default private. 
// and the the Developer Class can not access the methods or attributes of the parent class (Employee)
// in order to do:
d.AskForPromotion();
// But if we change the inheritance to public, initializing the class as:
class Developer: public Employee {};
// now we can call actually the methods or attributes of the parent class and do:
d.AskForPromotion();




//! PART F: POLYMORPHISM
/*
	= "The ability of an object or a method to have many forms"

	the most common use of polymorphism is when a parent class 
	reference is used to refer to a child class object
*/


class AbstractEmployee {
	// pure virtual function:
	virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee {
protected:
	string Name;
private:
	string Company;
	int Age;
public:	
	void setName(string name) {
		Name = name;
	}
	string getName() {
		return Name;
	}
	void setCompany(string company) {
		Company = company;
	}
	string getCompany() {
		return Company;
	}
	void setAge(int age) {
		if (age >= 18)
			Age = age;
	}
	int getAge() {
		return Age;
	}

	//constructor:
	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}

	// the method that the abstract class needs:
	void AskForPromotion() {
		if (Age > 30)
			std::cout << Name << " got promoted!" << std::endl;
		else
			std::cout << Name << " sorry no Promotion for you!" << std::endl;
	}

	//! new method here to show polymorphism:
	virtual void Work() { //! the virtual practically says: can you please check if there is implemetantion of this function in my derived classes? If yes, please execute that, and not this here:
	std::cout << Name << " is checking emails" << std::endl;
	}
};

// first subclass that inherits from the parent class "Employee":
class Developer: public Employee {
public:
	string FavProgrLang;
	//now this subclass needs a constructor of its own:
	Developer(string name, string company, int age, string fpl)
		:Employee(name, company, age) //we do this because there is already a constructor for these 3 attributes, on the parent class "Employee"
	{
		FavProgrLang = fpl;
	}
	void FixBug() {
		std::cout << Name << " fixed bug using " << FavProgrLang << std::endl;
	}
	//! same name of method, as the one in the parent class, but different implementation:
	void Work() {
	std::cout << Name << " is writing code in " << FavProgrLang << std::endl;
	}
};

// second subclass that inherits from the parent class "Employee":
class Teacher: public Employee {
public:
	string Subject;
	//now this subclass needs a constructor of its own:
	Teacher(string name, string company, int age, string subject)
		:Employee(name, company, age) //we do this because there is already a constructor for these 3 attributes, on the parent class "Employee"
	{
		Subject = subject;
	}
	//! same name of method, as the one in the parent class, but different implementation:
	void Work() {
	std::cout << Name << " is preparing " << Subject << "lesson" << std::endl;
	}
};

int main()
{
	Developer d = Developer("Saldina", "Youtube", 25, "C++");
	Teacher t = Teacher("John", "School", 40, "History");
	
	//and now although there is a method "work" on the parent class Employee, 
	// the next two, will have indeed different result:
	d.Work(); //output: Saldina is writing code in C++
	t.Work(); //output: John is preparing History lesson

	//? :	 the most common use of polymorphism is when a parent class 
	//?   	 reference is used to refer to a child class object
	Employee *e1 = &d; 
	Employee *e2 = &t;
	// so a pointer of a base class can hold reference to derived class object.

	// And this way, we can now call:
	e1->Work(); //output: Saldina is writing code in C++
	e2->Work();//output: John is preparing History lesson
	// But if the Work method in the base class Employee was not virtual (line 473)
	// Then the output for both Saldina and John would be: is checking emails
}
