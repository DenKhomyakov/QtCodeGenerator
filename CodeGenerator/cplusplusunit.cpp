#include "cplusplusunit.h"

string CPlusPlusClassUnit::compile(unsigned int level) const {
    string result = generateShift(level) + "class " + name + "{\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
        if (fields[i].empty()) {
            continue;
        }

        result += ACCESS_MODIFIERS[i] + ":\n";

        for (const auto& f : fields[i]) {
            result += f->compile(level + 1);
            result += "\n";
        }
    }

    result += generateShift(level) + "};\n";
    return result;
}

string CPlusPlusMethodUnit::compile(unsigned int level) const {
    string result = generateShift(level);

    if (flags & STATIC) {
        result += "static ";
    } else if (flags & VIRTUAL) {
        result += "virtual ";
    }

    result += returnType + " ";
    result += name + "()";

    if (flags & CONST) {
        result += " const";
    }

    result += "{\n";

    for (const auto& b : body) {
        result += b->compile(level + 1);
    }

    result += generateShift(level) + "}\n";
    return result;
}

string CPlusPlusPrintOperatorUnit::compile(unsigned int level) const {
    return generateShift(level) + "printf(\"" + text + "\");\n";
}
