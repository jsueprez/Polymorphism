# Polymorphism

This project shows off concepts about one fundamental principle of the OOP, the polymorphism.

## Table of Contents

- [Polymorphism](#polymorphism)
  - [Table of Contents](#table-of-contents)
  - [About the Project](#about-the-project)
    - [Polymorphism](#polymorphism-1)
      - [Virtual functions](#virtual-functions)
      - [Static Polymorphism](#static-polymorphism)
      - [Dynamic Polymorphism](#dynamic-polymorphism)
    - [Function overloading](#function-overloading)
    - [Function overriding](#function-overriding)
      - [Pure virtual (abstract) functions](#pure-virtual-abstract-functions)
      - [Interface class](#interface-class)
  - [Getting Started](#getting-started)
    - [Dependencies](#dependencies)
    - [Getting the Source](#getting-the-source)
    - [Building](#building)
    - [Running Tests](#running-tests)
      - [Other Tests](#other-tests)
    - [Installation](#installation)
    - [Usage](#usage)
  - [Further Reading](#further-reading)
  - [License](#license)
  - [Authors](#authors)

## About the Project

### Polymorphism 
This is one of the main features of OOP and it refers to the ability to exist in multiple forms. Multiple definitions can be given to a single interface. ```virtual``` functions are key to polymorphism.

#### Virtual functions
These are special type of functions that, when called, resolves to the most-derived version of the function that exists between the base and derived class. This capability is known as polymorphism. A derived function is considered a match if it has the same signature (name, parameter types, and whether it is const) and return type as the base version of the function. Such functions are called overrides.

When a derived class is assigned to a base class object, the base class only receives a copy of the base portion of the derived class. This is called object slicing.
``` c++
class Base
{
  public: 
    std::string_view get_name() const { return "Base"; }
}
class Derived : public Base
{
  public:
    std::string_view get_name() const { return "Derived"; }
}
int main()
{
  Base base{ derived };
  std::cout << base.get_name() << "\n";  // base.get_name() resolves to Base::get_name() and not to Derived::get_name()
}
```
In the example above, base receives a copy of the Base portion of derived, but not the Derived portion. That Derived portion has effectively been “sliced off”. Because variable base does not have a Derived part, base.getName() resolves to Base::getName().

To avoid object slicing we can use virtual functions and that way acces to the most-derived version of a function. Also worth mention that without virtual functions, base class pointers and references to a derived class will only have access to base class member variables and versions of functions.
``` c++
class Base
{
  public: 
    virtual std::string_view get_name() const { return "Base"; }
}
class Derived : public Base
{
  public:
    std::string_view get_name() const override { return "Derived"; }
}
int main()
{
  Base& ref{ derived };
  std::cout << ref.get_name() << "\n"; // resolves to Derived::get_name()

  Base* ptr{ &derived };
  std::cout << ptr->get_name() << "\n"; // resolves to Derived::get_name()
}
```

Note: *Using virtual functions has a cost: virtual functions take longer to call, and the necessity of the virtual table increases the size of every object containing a virtual function by one pointer.*

There are 2 types of polymorphism, the static and the dynamic.

#### Static Polymorphism
Also knows as static binding, it is resolved at compile time, an example could be the method overloading.

#### Dynamic Polymorphism
Also knows as dynamic binding, it is resolved at occurs at runtime, an example could be the method overriding.

### Function overloading
It is a feature of the OPP which allows you to give the same name to more than one function within a class if the arguments passed differs.
``` c++
  int calculate_area(const int base, const int height) // Area of a triangle
  {
    return ( base * height ) / 2;
  }
  int calculate_area(const int lenght, const int width) // Area of a rectangle
  {
    return lenght * width ;
  }
  int calculate_area(const int side_lenght)  // Area of a square
  {
    return side_lenght * sid_lenght;
  }
```

### Function overriding
It is a feature of the OPP which allows the derived class or child class to implement its own version of a member function inherited from the base class. The funcion to be overriden must be declared using the  ```virtual```  specifier in the base class. To help address the issue of functions that are meant to be overrides but aren’t, the ```override``` specifier can be applied to any virtual function by placing the specifier in the same place const would go. If the function does not override a base class function (or is applied to a non-virtual function), the compiler will flag the function as an error.

``` c++
class Shape 
{
  public:
    // Area of a 
    virtual void calculate_area(const int base, const int height) 
    {
      std::cout << "The area is: ???" << ".\n";
    }
}

class Triangle : public Shape
{
  public:
    void calculate_area(const int base, const int height) override
    {
      std::cout << "The area  of a triangle is: " <<  ( base * height ) / 2 << ".\n";
    }
}
```
#### Pure virtual (abstract) functions
These are functions that has no body at all(no implementation), they simply acts as a paceholder that is meant to be redefined by the derived classes. A virtual function can be made pure virtual/abstract by adding “= 0” to the end of the virtual function prototype. A class containing a pure virtual function is called an abstract class, and can not be instantiated. A class that inherits pure virtual functions must concretely define them or it will also be considered abstract.

``` c++
class Base
{
public:
    int get_number() const { return 1; } // a normal non-virtual function
    virtual const char* get_name() const { return "Base"; } // a normal virtual function
    virtual int get_value() const = 0; // a pure virtual function
    int dummy_function() = 0; // Compile error: can not set non-virtual functions to 0
};
```

#### Interface class
An interface class is a class that has no member variables, and where all of the functions are pure virtual! In other words, the class is purely a definition, and has no actual implementation. Interfaces are useful when you want to define the functionality that derived classes must implement, but leave the details of how the derived class implements that functionality entirely up to the derived class.

Interface classes are often named beginning with an I.

**[Back to top](#table-of-contents)**

// TODO:
## Getting Started

// TODO:
### Dependencies

// TODO:
### Getting the Source

// TODO:
### Building

// TODO:
### Running Tests


// TODO:
#### Other Tests


// TODO:
### Installation


// TODO:
### Usage

**[Back to top](#table-of-contents)**


// TODO:
## Further Reading

// TODO:
## License


## Authors

**[Antonio Perez](https://github.com/jsueprez)** - *Initial work* -

**[Back to top](#table-of-contents)**
