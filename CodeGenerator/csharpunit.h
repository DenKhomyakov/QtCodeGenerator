#ifndef CSHARPUNIT_H
#define CSHARPUNIT_H

#include "unit.h"

class CSharpClassUnit : public ClassUnit {
public:
    CSharpClassUnit(const string& name) : ClassUnit(name) {}

    string compile(unsigned int level = 0) const override;
};

class CSharpMethodUnit : public MethodUnit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        PUBLIC = 1 << 5,
        PROTECTED = 1 << 6,
        PRIVATE = 1 << 7,
        INTERNAL = 1 << 8
    };

public:
    CSharpMethodUnit(const string& name, const string& returnType, Flags flags) : MethodUnit(name, returnType, flags) {}

    string compile(unsigned int level = 0) const override;
};

class CSharpPrintOperatorUnit : public PrintOperatorUnit {
public:
    CSharpPrintOperatorUnit(const string& text) : PrintOperatorUnit(text) {}

    string compile(unsigned int level = 0) const override;
};

#endif // CSHARPUNIT_H
