#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <memory>
#include <vector>

using std::string;
using std::vector;
using std::shared_ptr;

class Unit {
public:
    using Flags = unsigned int;

public:
    virtual ~Unit() = default;

    virtual void add(const shared_ptr<Unit>&, Flags) {
        throw std::runtime_error("Not supported");
    }

    virtual string compile(unsigned int level = 0) const = 0;

protected:
    virtual string generateShift(unsigned int level) const {
        static const auto defaultShift = " ";
        string result;

        for (unsigned int i = 0; i < level; ++i) {
            result += defaultShift;
        }

        return result;
    }
};

class ClassUnit : public Unit {
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };

    static const vector<string> ACCESS_MODIFIERS;

public:
    explicit ClassUnit(const string& name) : name(name) {
        fields.resize(ACCESS_MODIFIERS.size());
    }

    void add(const shared_ptr<Unit>& unit, Flags flags) override {
        int accessModifier = PRIVATE;

        if (flags < ACCESS_MODIFIERS.size()) {
            accessModifier = flags;
        }

        fields[accessModifier].push_back(unit);
    }

protected:
    string name;
    using Fields = vector<shared_ptr<Unit>>;
    vector<Fields> fields;
};

class MethodUnit : public Unit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        FINAL = 1 << 3,
        ABSTRACT = 1 << 4,
        PUBLIC = 1 << 5,
        PROTECTED = 1 << 6,
        PRIVATE = 1 << 7,
        INTERNAL = 1 << 8
    };

public:
    MethodUnit(const string& name, const string& returnType, Flags flags) : name(name), returnType(returnType), flags(flags) {}

    void add(const shared_ptr<Unit>& unit, Flags /* flags */ = 0) override {
        body.push_back(unit);
    }

protected:
    string name;
    string returnType;
    Flags flags;
    vector<shared_ptr<Unit>> body;
};

class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit(const string& text) : text(text) {}

protected:
    string text;
};

#endif // UNIT_H
