#include "factory.h"
#include "cplusplusunit.h"
#include <javaunit.h>
#include <csharpunit.h>

using std::make_shared;

shared_ptr<ClassUnit> CPlusPlusFactory::buildClass(const string& name) {
    return make_shared<CPlusPlusClassUnit>(name);
}

shared_ptr<MethodUnit> CPlusPlusFactory::buildMethod(const string& name, const string& returnType, Unit::Flags flags) {
    return make_shared<CPlusPlusMethodUnit>(name, returnType, flags);
}

shared_ptr<PrintOperatorUnit> CPlusPlusFactory::buildPrintOperator(const string& text) {
    return make_shared<CPlusPlusPrintOperatorUnit>(text);
}

shared_ptr<ClassUnit> JavaFactory::buildClass(const string& name) {
    return make_shared<JavaClassUnit>(name);
}

shared_ptr<MethodUnit> JavaFactory::buildMethod(const string& name, const string& returnType, Unit::Flags flags) {
    return make_shared<JavaMethodUnit>(name, returnType, flags);
}

shared_ptr<PrintOperatorUnit> JavaFactory::buildPrintOperator(const string& text) {
    return make_shared<JavaPrintOperatorUnit>(text);
}

shared_ptr<ClassUnit> CSharpFactory::buildClass(const string& name) {
    return make_shared<CSharpClassUnit>(name);
}

shared_ptr<MethodUnit> CSharpFactory::buildMethod(const string& name, const string& returnType, Unit::Flags flags) {
    return make_shared<CSharpMethodUnit>(name, returnType, flags);
}

shared_ptr<PrintOperatorUnit> CSharpFactory::buildPrintOperator(const string& text) {
    return make_shared<CSharpPrintOperatorUnit>(text);
}
