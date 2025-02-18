#ifndef FACTORY_H
#define FACTORY_H

#include "unit.h"

class IFactory {
public:
    virtual shared_ptr<ClassUnit> buildClass(const string& name) = 0;
    virtual shared_ptr<MethodUnit> buildMethod(const string& name, const string& returnType, Unit::Flags flags) = 0;
    virtual shared_ptr<PrintOperatorUnit> buildPrintOperator(const string& text) = 0;
};

class CPlusPlusFactory : public IFactory {
public:
    shared_ptr<ClassUnit> buildClass(const string& name) override;
    shared_ptr<MethodUnit> buildMethod(const string& name, const string& returnType, Unit::Flags flags) override;
    shared_ptr<PrintOperatorUnit> buildPrintOperator(const string& text) override;
};

class JavaFactory : public IFactory {
public:
    shared_ptr<ClassUnit> buildClass(const string& name) override;
    shared_ptr<MethodUnit> buildMethod(const string& name, const string& returnType, Unit::Flags flags) override;
    shared_ptr<PrintOperatorUnit> buildPrintOperator(const string& text) override;
};

class CSharpFactory : public IFactory {
public:
    shared_ptr<ClassUnit> buildClass(const string& name) override;
    shared_ptr<MethodUnit> buildMethod(const string& name, const string& returnType, Unit::Flags flags) override;
    shared_ptr<PrintOperatorUnit> buildPrintOperator(const string& text) override;
};

#endif // FACTORY_H
