#if !defined BEEP_BEEP_MF
# define BEEP_BEEP_MF

#include <Windows.h>
#include <cstring>
#include "exception.hpp"

class MSymbol
{
    //char symbol_;
    size_t length_;
    bool* code_;

    MSymbol (const MSymbol& my);
    MSymbol (MSymbol && my);
    MSymbol& operator= (const MSymbol& that);


    public:
    MSymbol (/*char symbol,*/ char* code);
    ~MSymbol ();
    void play();

};

MSymbol :: MSymbol (/*char symbol,*/ char* code):
    //symbol_ (symbol),
    length_ (strlen (code)),
    code_ (new bool [length_])
{
    for (size_t i = 0; i < length_; i++)
    {
        switch (code [i])
        {
            case '.':
                code_[i] = 0;
                break;

            case '-':
                code_[i] = 1;
                break;

            default:
                throw myException ("wrong code for a letter", EXC_PLACE);
        }
    }
}

MSymbol :: ~MSymbol ()
{
    delete code_;
    code_ = nullptr;
}

void MSymbol :: play ()
{
    for (size_t i = 0; i < length_; i++) Beep (750, 500* (1 + code_ [i]));
}

# endif
