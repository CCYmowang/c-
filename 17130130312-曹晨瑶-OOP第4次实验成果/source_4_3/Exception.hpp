#ifndef Exception_hpp_
#define Exception_hpp_
class Exception
{
public:
    char* Start;
    char* Error;

    Exception(char* aStart , char* aError)
    {
        Start=aStart;
        Error=aError;
    }
};
#endif // Exception_hpp_
