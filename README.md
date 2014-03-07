cbuilder
========

A tiny shell utility tool for rapid class creation based on templates.

With cbuilder you can create C++ clases from terminal in just no time.
If you don't like the default output format you can customize the
templates that came with cbuilder or create them from scratch.

BUILD AND INSTALL
=================

1 - Download source code
2 - Extract it to a folder
3 - In a shell, go to the folder where you extracted the source code and run:
  $ make

It is recommended that after step 3 you run:
  $ make install

This will install cbuilder on /usr/local/bin to make it available from
anywhere if /usr/local/bin is in your $PATH environment variable.

USAGE
=====

With default templates:
  $ cbuilder

With custom templates:
  $ cbuilder custom_header.tpl custom_cpp.tpl

The default templates are located in:
  $HOME/$USER/.cbuilder/templates

Cbuilder will ask you the name of the class,
followed by the namespace of the class and the
header guard.

Example:

  Class Name: MyClass
  Namespace: fe
  Header Guard: MY_CLASS 

This will produce the following header (MyClass.h):

#ifndef __MY_CLASS_H__
#define __MY_CLASS_H__

namespace fe
{

class MyClass
{
public:
	MyClass();
	MyClass(const MyClass& toCopy);
	MyClass& operator=(const MyClass& toCopy);
	~MyClass();
};

}

#endif

And the following source (MyClass.cpp):

#include "MyClass.h"

namespace fe
{

// =============================================================================
//	CONSTRUCTORS, COPY CONSTRUCTOR, DESTRUCTOR, ASSIGNMENT OPERATOR
// =============================================================================
MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

}
