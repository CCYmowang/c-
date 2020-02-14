//文件摘要：定义了基类animal和其基类的派生类，并实现
//17130130312 曹晨瑶
//2019.6.18
#ifndef ANIMAL_CLASS
#define ANIMAL_CLASS
using namespace std;
class Animal
{
protected:
    std::string name;
public:
    Animal(const char* nm ="A") : name("A") { if(nm != NULL) name=nm; }
    Animal(const std::string& nm) : name(nm) { }
    virtual void iam () { cout << "Animal " << name <<"  \n"; }
    void  hello () { cout << "Animal::hello from " << name << std::endl; }
    void  common() { cout << "Animal::common\n"; }
};

class Cat :public Animal{
public:
	Cat(const char * nm = "A") :Animal("A") { if (nm != NULL) name = nm; }
	Cat(const std::string& nm) :Animal(nm) { }
	void iam() { std::cout << "Cat " << name << "  \n"; }
	void hello() { std::cout << "Cat::hello from " << name << std::endl;}

};

class Dog :public Animal {
public:
	Dog(const char * nm = "A") :Animal("A") { if (nm != NULL) name = nm; }
	Dog(const std::string& nm) :Animal(nm) { }
	void iam() { std::cout << "Dog " << name << "  \n"; }
	void hello() { std::cout << "Dog::hello from " << name << std::endl; }
};

#endif // ANIMAL_CLASS

