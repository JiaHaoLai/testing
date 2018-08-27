 ///
 /// @file    string.cc
 /// @author  hasee(neo@Gmail.com)
 /// @date    2018-04-12 06:44:12
 ///
#include <string.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
	String()
	:_pstr(NULL)
	{
		cout << "String()" << endl;
	}

	String(const char *pstr)
	:_pstr(new char[strlen(pstr)+1]())
	{
		strcpy(_pstr, pstr);
		cout << "String(const char *)" << endl;
	}

	String(const String & rhs)
	:_pstr(new char[strlen(rhs._pstr)+1]())
	{
		strcpy(_pstr, rhs._pstr);
		cout << "String(const Sting &)" << endl;
	}

	String & operator=(const String & rhs)
	{
		cout << "String & operator=(const Sting &)" << endl;
		if(this != &rhs)
		{
			delete [] _pstr;

			_pstr = new char[strlen(rhs._pstr) + 1]();
			strcpy(_pstr, rhs._pstr);
		}

		return *this;
	}

	void print()
	{
		if(_pstr==NULL)
		{
			cout << "_pstr = NULL" << endl;
		}else{
			cout << "_pstr = " << _pstr << endl;
		}
	}

	~String()
	{
		delete [] _pstr;
		cout << "~String()" << endl;
	}

private:
	char * _pstr;
};
 
int main(void)
{
	String str1;
	str1.print();

	String str2 = "Hello,world";
	String str3("wangdao");

	str2.print();
	str3.print();

	String str4 = str3;
	str4.print();

	str4 = str2;
	str4.print();

	return 0;
}
