#include <QCoreApplication>
#include "unit.h"
#include "factory.h"

using std::cout;
using std::endl;

string generateProgram(IFactory* factory, const string& className, const string& text) {
    shared_ptr<ClassUnit> myClass = factory->buildClass(className);

    myClass->add(
        factory->buildMethod("testFunc1", "void", MethodUnit::PUBLIC),
        ClassUnit::PUBLIC
        );

    myClass->add(
        factory->buildMethod("testFunc2", "void", MethodUnit::STATIC | MethodUnit::PRIVATE),
        ClassUnit::PRIVATE
        );

    myClass->add(
        factory->buildMethod("testFunc3", "void", MethodUnit::CONST | MethodUnit::PROTECTED | MethodUnit::PRIVATE),
        ClassUnit::PROTECTED
        );

    shared_ptr<MethodUnit> method = factory->buildMethod("testFunc4", "void", MethodUnit::STATIC | MethodUnit::PROTECTED);
    method->add(factory->buildPrintOperator(text));
    myClass->add(method, ClassUnit::PROTECTED);

    return myClass->compile();
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    cout << "C++ program:" << endl;
    CPlusPlusFactory factory1;
    cout << generateProgram(&factory1, "CPlusPlusClass", "Hello C++") << endl;

    cout << "Java program:" << endl;
    JavaFactory factory2;
    cout << generateProgram(&factory2, "JavaClass", "Hello Java") << endl;

    cout << "C# program:" << endl;
    CSharpFactory factory3;
    cout << generateProgram(&factory3, "CSharpClass", "Hello C#") << endl;

    return a.exec();
}
