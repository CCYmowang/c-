#include <iostream>

using namespace std;

int main(int argc,char *argv[])
{
    int i;
    for(i =0 ; i<argc ; i++)
        cout << "Hello," << argv[i] << "!" << endl;
    return 0;
}
