#include <iostream>
#include <cstdarg>

using namespace std;

void error(const char* format, ...);

int main(){
    char* a="Rainman";
    char b='a';
    char* c="super";
    int d=2016;
    error("Hello, %s is %c %s man. %d.\n",a, b, c,d);
    error("We are netter.\n");
    error("Hey, everyone. %c am %s , I am %d .\n", 'I', "spiderman", 20);
    return 0;
}

void error(const char* format, ...){
         const char *ptr = format;
         va_list ap;
         va_start(ap, format);
         while (*ptr){
             switch (*ptr) {
                 case '%':
                 ptr++;
             switch (*ptr) {
                 case 'c':
                     cout << (char) va_arg(ap,int);
                     break;
                 case 'd':
                     cout << va_arg(ap,int);
                     break;
                 case 's':
                     cout << va_arg(ap,char*);
                     break;
                 default :
                     cout << "%" << *ptr;
            }
            ptr++;
            break;
        default :
            cout << *ptr;
            ptr++;
            break;
        }
      }
    va_end(ap);

}
