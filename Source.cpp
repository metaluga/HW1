#include <iostream>
#include <vector>
#include "UniquePtr.h"
#include <memory>

class DummyLogClass
{
public:
    DummyLogClass()
    {
        std::cout << "DummyLogClass()\n";
    }
    DummyLogClass(const DummyLogClass&)
    {
        std::cout << "DummyLogClass(const DummyLogClass&)\n";
    }
    ~DummyLogClass()
    {
        std::cout << "~DummyLogClass\n";
    }
};


UniquePtr<DummyLogClass> getObject()
{
    UniquePtr<DummyLogClass> ptr{ new DummyLogClass() };
    return ptr; //OK if NRVO works. Compile error otherwise.
}


int main() {


    {
        UniquePtr<DummyLogClass> ptr{ new DummyLogClass() }; // DummyLogClass()
    } // ~DummyLogClass()

    {
        UniquePtr<DummyLogClass> ptr{ new DummyLogClass() };
        //  UniquePtr<DummyLogClass> ptr1{ ptr }; //Compile error;
        //  UniquePtr<DummyLogClass> ptr1 = ptr;  //Compile error;
    }

    {
        //   auto ptr = getObject();//OK
    }

    {
        std::vector<UniquePtr<DummyLogClass>> vec; // OK
        for (int i = 0; i < 10; ++i)
        {

            vec.push_back(UniquePtr<DummyLogClass>{new DummyLogClass()}); // OK
        }
    }

    return 0;
}