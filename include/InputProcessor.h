#ifndef __INPUT_PROCESSOR_H__
#define __INPUT_PROCESSOR_H__

#include <iostream>
#include <functional>

using namespace std;

namespace fe
{

class InputProcessor
{
private:
	string m_QuestionPrefix;
	string m_QuestionSuffix;

public:
	InputProcessor();
	InputProcessor(const InputProcessor& toCopy);
	InputProcessor& operator=(const InputProcessor& toCopy);
	virtual ~InputProcessor();

	void setQuestionPrefix(const string& prefix);
	void setQuestionSuffix(const string& suffix);

	template<typename T>
	void read(const string& question, T& toSave, const function<bool(const T&)>& isRejected = nullptr)
	{
		T input;

		do
		{
			cout << m_QuestionPrefix << question << m_QuestionSuffix;
			cin  >> input;

			if(isRejected == nullptr)
			{
				toSave = input;
				return;
			}
		}
		while(isRejected(input));

		toSave = input;
	}
};

}

#endif