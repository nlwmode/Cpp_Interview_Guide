/**
*
*   create by nlwmode. 09/15/2020
*   虚函数、 虚函数表、 纯虚函数、 虚析构函数 相关原理解析
*/
#include<iostream>
using namespace std;

class Animal
{
public:
    int months;
    int weight;
public:
    Animal();
    virtual ~Animal(){                      
        cout << "delete class Animal" << endl;
    }
    virtual void eat(){
        cout << "Animal eat" << endl;
    }
};

class Dog : public Animal       // 此时 Dog 派生类会有自己的虚函数表, 还有一个隐式的指向父类的虚函数表指针成员变量
{
public:
    Dog();
    ~Dog(){
        cout << "delete class Dog" << endl;
    }
    virtual void eat(){         // 子类覆盖父类的 eat 方法， 
        cout << "Dog eat" << endl;
    }
};

int main()
{
    Animal* animal = new Dog();
    // 当有派生类指向父类的时候，派生类会调用自己的析构函数，而不会调用父类的虚析构函数
    animal->eat();      // 因为时 new 的 Dog 对象 ， 所以执行的是 Dog 虚函数表里面的 eat 方法
    delete animal;      // 因为父类是虚析构函数，此时删除 animal 是 安全的，会在堆中删除 Dog 的实例
    return 0;
}
