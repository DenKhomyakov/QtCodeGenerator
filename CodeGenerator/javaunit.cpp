#include "javaunit.h"

string JavaClassUnit::compile(unsigned int level) const {
    string result = generateShift(level) + "class " + name + "{\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
        if (fields[i].empty()) {
            continue;
        }

        for (const auto& f : fields[i]) {
            result += f->compile(level + 1);
            result += "\n";
        }
    }

    result += generateShift(level) + "};\n";
    return result;
}

string JavaMethodUnit::compile(unsigned int level) const {
    string result = generateShift(level);

    if (flags & PUBLIC) {
        result += "public ";
    } else if (flags & PROTECTED) {
        result += "protected ";
    } else if (flags & PRIVATE) {
        result += "private ";
    }

    if (flags & STATIC) {
        result += "static ";
    } else if (flags & FINAL) {
        result += "final ";
    }

    result += returnType + " ";
    result += name + "()";
    result += "{\n";

    for (const auto& b : body) {
        result += b->compile(level + 1);
    }

    result += generateShift(level) + "}\n";
    return result;
}

string JavaPrintOperatorUnit::compile(unsigned int level) const {
    return generateShift(level) + "System.out.println(\"" + text + "\");\n";
}
