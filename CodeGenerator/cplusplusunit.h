#ifndef CPLUSPLUSUNIT_H
#define CPLUSPLUSUNIT_H

#include "unit.h"

class CPlusPlusClassUnit : public ClassUnit {
public:
    CPlusPlusClassUnit(const string& name) : ClassUnit(name) {}

    string compile(unsigned int level = 0) const override;
};

class CPlusPlusMethodUnit : public MethodUnit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };

public:
    CPlusPlusMethodUnit(const string& name, const string& returnType, Flags flags) : MethodUnit(name, returnType, flags) {}

    string compile(unsigned int level = 0) const override;
};

class CPlusPlusPrintOperatorUnit : public PrintOperatorUnit {
public:
    CPlusPlusPrintOperatorUnit(const string& text) : PrintOperatorUnit(text) {}

    string compile(unsigned int level = 0) const override;
};

#endif // CPLUSPLUSUNIT_H
