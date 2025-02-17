#include "csharpunit.h"

string CSharpClassUnit::compile(unsigned int level) const {
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

    result += generateShift(level) + "}\n";
    return result;
}

string CSharpMethodUnit::compile(unsigned int level) const {
    string result = generateShift(level);

    if (flags & PUBLIC) {
        result += "public ";
    } else if (flags & PROTECTED) {
        result += "protected ";
    } else if (flags & PRIVATE) {
        result += "private ";
    } else if (flags & INTERNAL) {
        result += "internal ";
    }

    if (flags & STATIC) {
        result += "static ";
    } else if (flags & CONST) {
        result += "const ";
    } else if (flags & VIRTUAL) {
        result += "virtual ";
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

string CSharpPrintOperatorUnit::compile(unsigned int level) const {
    return generateShift(level) + "Console.WriteLine(\"" + text + "\");\n";
}
