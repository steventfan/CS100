#!/bin/sh

echo "#ifndef MyClass_hh
#define MyClass_hh

class MyClass
{
   public:
      MyClass();
      ~MyClass();

   private:
};
#endif" > $1.hh
echo "#include \"./MyClass.hh\"

MyClass::MyClass()
{}

MyClass::~MyClass()
{}" > $1.cc
