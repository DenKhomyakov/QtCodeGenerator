#ifndef JAVAUNIT_H
#define JAVAUNIT_H

#include "unit.h"

class JavaClassUnit : public ClassUnit {
public:
    JavaClassUnit(const string& name) : ClassUnit(name) {}

    string compile(unsigned int level = 0) const override;
};

class JavaMethodUnit : public MethodUnit {
public:
    enum Modifier {
        STAATIC = 1,
        FINAL = 1 << 3,
        ABSTRACT = 1 << 4,
        PUBLIC = 1 << 5,
        PROTECTED = 1 << 6,
        PRIVATE = 1 << 7
    };

public:
    JavaMethodUnit(const string& name, const string& returnType, Flags flags) : MethodUnit(name, returnType, flags) {}

    string compile(unsigned int level = 0) const override;
};

class JavaPrintOperatorUnit : public PrintOperatorUnit {
public:
    JavaPrintOperatorUnit(const string& text) : PrintOperatorUnit(text) {}

    string compile(unsigned int level = 0) const override;
};

#endif // JAVAUNIT_H
