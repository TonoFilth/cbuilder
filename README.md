cbuilder
========

A tiny shell utility tool for rapid class creation based on templates.

With cbuilder you can create C++ clases from terminal in just no time.  
If you don't like the default output format you can customize the
templates that came with cbuilder or create them from scratch.

## BUILD AND INSTALL
1. Download source code
2. Extract it to a folder

3. In a shell, go to the folder where you extracted the source code and run:

```
$ make
```

It's recommended that after step 3 you run:
```
$ sudo make install
```

This will install cbuilder on **/usr/local/bin** to make it available from
anywhere if /usr/local/bin is in your **$PATH** environment variable.

## USAGE
With default templates:
```
$ cbuilder
```

With custom templates:
```
$ cbuilder custom_header.tpl custom_cpp.tpl
```

The default templates are located in:
```
$ ~/.cbuilder/templates
```

Cbuilder will ask you the name of the class,
followed by the namespace of the class and the
header guard.

**Example:**

```
Class Name: MyClass
Namespace: fe
Header Guard: MY_CLASS 
```

This will produce the following header  
**MyClass.h**
```cpp
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
```

And the following source  
**MyClass.cpp**
```cpp
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
```
## CUSTOM TEMPLATES

Copy the default templates in your working directory or in another directory of your choice.
```
$ cp ~/.cbuilder/templates/Def* ./
```
Open the templates in your favourite text editor  
They will look like this:  

**DefHeader.tpl**
```cpp
#ifndef __GUARD
#define __GUARD

__NAMESPACE-START

class __CLASS
{
public:
	__CLASS();
	__CLASS(const __CLASS& toCopy);
	__CLASS& operator=(const __CLASS& toCopy);
	~__CLASS();
};

__NAMESPACE-END

#endif
```
**DefSource.tpl**
```cpp
#include "__CLASS.h"

__NAMESPACE-START

// =============================================================================
//	CONSTRUCTORS, COPY CONSTRUCTOR, DESTRUCTOR, ASSIGNMENT OPERATOR
// =============================================================================
__CLASS::__CLASS()
{
}

__CLASS::~__CLASS()
{
}

__NAMESPACE-END
```
At the moment, there are four markers that cbuilder will replace during parsing with your input:

1. **__CLASS** will be replaced with the class name
2. **__NAMESPACE-START** will be replaced with the namespace name
3. **__NAMESPACE-END** will be replaced with **'}'**
4. **__GUARD** will be replaced with the header guard  

For example, let's modify the templates to create a class which represents a GameObject.  
**GameObjectHeader.tpl**
```cpp
#ifndef __GUARD
#define __GUARD

#include <iostream>

#include "Graphics.h"
#include "Vectors.h"

class __CLASS
{
private:
	Texture  m_Texture;
	Vector2F m_Position;
	Vector2F m_Scale;

	void Copy(const __CLASS& toCopy);

public:
	__CLASS(const Texture& tx,
			const Vector2F& position,
			const Vector2F& scale);
	__CLASS(const __CLASS& toCopy);
	__CLASS& operator=(const __CLASS& toCopy);
	virtual ~__CLASS();

	const Vector2F& GetPosition() const;
	const Vector2F& GetScale() const;

	void SetPosition(const Vector2F& newPosition);
	void SetScale(const Vector2F& newScale);

	virtual void Draw(RenderTarget& renderTarget) const;

	void PrintDebug() const;
};

#endif
```
**GameObjectSrc.tpl**
```cpp
#include "__CLASS.h"

using namespace std;

// =============================================================================
//	CONSTRUCTORS, COPY CONSTRUCTOR, DESTRUCTOR, ASSIGNMENT OPERATOR
// =============================================================================
__CLASS::__CLASS(const Texture& tx,
				 const Vector2F& position,
				 const Vector2F& scale) :
	m_Texture(tx),
	m_Position(position),
	m_Scale(scale)
{
}

__CLASS::__CLASS(const __CLASS& toCopy)
{
	Copy(toCopy);
}

__CLASS& __CLASS::operator=(const __CLASS& toCopy)
{
	if (this == &toCopy)
		return this;

	Copy(toCopy);
	return *this;
}

__CLASS::~__CLASS()
{
}

// =============================================================================
//	PRIVATE AND PROTECTED METHODS
// =============================================================================
void __CLASS::Copy(const __CLASS& toCopy)
{
	m_Texture  = toCopy.m_Texture;
	m_Position = toCopy.m_Position;
	m_Scale    = toCopy.m_Scale;
}

// =============================================================================
//	GETTERS & SETTERS
// =============================================================================
const Vector2F& __CLASS::GetPosition() const
{
	return m_Position;
}

const Vector2F& __CLASS::GetScale() const
{
	return m_Scale;
}

void __CLASS::SetPosition(const Vector2F& newPosition)
{
	m_Position = newPosition;
}

void __CLASS::SetScale(const Vector2F& newScale)
{
	m_Scale = newScale;
}

// =============================================================================
//	VIRTUAL METHODS
// =============================================================================
void __CLASS::Draw(RenderTarget& renderTarget) const
{
	renderTarget.Draw(m_Texture, m_Position, m_Scale);
}

// =============================================================================
//	DEBUG METHODS
// =============================================================================
void __CLASS::PrintDebug() const
{
	cout << "GAME-OBJECT" << endl;
	cout << "  Position: " << m_Position << endl;
	cout << "  Scale:    " << m_Scale << endl;
}
```
And run cbuilder with them:
```
$ cbuilder GameObjectHeader.tpl GameObjectSrc.tpl
  Using header template: GameObjectHeader.tpl
  Using source template: GameObjectSrc.tpl
  Class Name: MyCustomGO
  Namespace: ---
  Header Guard: MY_CUSTOM_GAME_OBJECT
```
This will produce MyCustomGO.h and MyCustomGO.cpp:  
**MyCustomGO.h**
```cpp
#ifndef __MY_CUSTOM_GAME_OBJECT_H__
#define __MY_CUSTOM_GAME_OBJECT_H__

#include <iostream>

#include "Graphics.h"
#include "Vectors.h"

class MyCustomGO
{
private:
	Texture  m_Texture;
	Vector2F m_Position;
	Vector2F m_Scale;

	void Copy(const MyCustomGO& toCopy);

public:
	MyCustomGO(const Texture& tx,
			const Vector2F& position,
			const Vector2F& scale);
	MyCustomGO(const MyCustomGO& toCopy);
	MyCustomGO& operator=(const MyCustomGO& toCopy);
	virtual ~MyCustomGO();

	const Vector2F& GetPosition() const;
	const Vector2F& GetScale() const;

	void SetPosition(const Vector2F& newPosition);
	void SetScale(const Vector2F& newScale);

	virtual void Draw(RenderTarget& renderTarget) const;

	void PrintDebug() const;
};

#endif
```
**MyCustomGO.cpp**
```cpp
#include "MyCustomGO.h"

using namespace std;

// =============================================================================
//	CONSTRUCTORS, COPY CONSTRUCTOR, DESTRUCTOR, ASSIGNMENT OPERATOR
// =============================================================================
MyCustomGO::MyCustomGO(const Texture& tx,
				 const Vector2F& position,
				 const Vector2F& scale) :
	m_Texture(tx),
	m_Position(position),
	m_Scale(scale)
{
}

MyCustomGO::MyCustomGO(const MyCustomGO& toCopy)
{
	Copy(toCopy);
}

MyCustomGO& MyCustomGO::operator=(const MyCustomGO& toCopy)
{
	if (this == &toCopy)
		return this;

	Copy(toCopy);
	return *this;
}

MyCustomGO::~MyCustomGO()
{
}

// =============================================================================
//	PRIVATE AND PROTECTED METHODS
// =============================================================================
void MyCustomGO::Copy(const MyCustomGO& toCopy)
{
	m_Texture  = toCopy.m_Texture;
	m_Position = toCopy.m_Position;
	m_Scale    = toCopy.m_Scale;
}

// =============================================================================
//	GETTERS & SETTERS
// =============================================================================
const Vector2F& MyCustomGO::GetPosition() const
{
	return m_Position;
}

const Vector2F& MyCustomGO::GetScale() const
{
	return m_Scale;
}

void MyCustomGO::SetPosition(const Vector2F& newPosition)
{
	m_Position = newPosition;
}

void MyCustomGO::SetScale(const Vector2F& newScale)
{
	m_Scale = newScale;
}

// =============================================================================
//	VIRTUAL METHODS
// =============================================================================
void MyCustomGO::Draw(RenderTarget& renderTarget) const
{
	renderTarget.Draw(m_Texture, m_Position, m_Scale);
}

// =============================================================================
//	DEBUG METHODS
// =============================================================================
void MyCustomGO::PrintDebug() const
{
	cout << "GAME-OBJECT" << endl;
	cout << "  Position: " << m_Position << endl;
	cout << "  Scale:    " << m_Scale << endl;
}
```
And that's it!! You can customize the default templates to build classes that look like you want :)
