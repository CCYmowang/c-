#include"tool.hpp"
#include<cstdlib>
#include<cstring>
bool Is(char*& Stream ,  char* Text)
{
    size_t len=strlen(Text);
    /*�������*/
    char* Read=Stream;
    /*���˿ո�*/
    while(*Read==' ')Read++;
    if(strncmp(Read,Text,len)==0)
    {
        Stream=Read+len;
        return true;
    }
    else
    {
        return false;
    }
}
