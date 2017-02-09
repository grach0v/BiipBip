#define EXC_PLACE __LINE__, __FILE__, __PRETTY_FUNCTION__

#include <iostream>
#include <cstring>
#include <string>

/* EXCEPTION_H */
# if !defined EXCEPTION_H
# define EXCEPTION_H

using namespace std; // i trust std

class myException: public std::exception
{
    private:
    string message;

    public:

    myException (const char* msg, int line, const char* file, const char* func);

    myException (const string & msg, int line, const char* file, const char* func);

    virtual ~myException () throw () {}

    virtual const char* what () const throw () { return message.c_str(); }

};

myException :: myException (const char* msg, int line, const char* file, const char* func):
message (msg)
{

    cout << "---EXCEPTION---"    << endl;
    cout << "file : "     << file << endl;
    cout << "function : " << func << endl;
    cout << "line : "     << line << endl;
    cout << "description: ";

}

myException :: myException (const string & msg, int line, const char* file, const char* func):
message (msg)
{

    cout << "---EXCEPTION---"    << endl;
    cout << "file = "    << file << endl;
    cout << "function = "<< func << endl;
    cout << "line = "    << line << endl;
    cout << "description: ";

}

# endif
