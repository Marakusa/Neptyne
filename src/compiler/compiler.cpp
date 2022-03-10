//
// Created by Markus Kannisto on 09/03/2022.
//

#include "../common_includes.h"
#include "../utils/file_utils.h"
#include "compiler.h"
#include "NeptyneScript.h"
#include "tokenizer.h"

void compile(const NeptyneScript &script) {
    string code = readFile(script.full_path);
    NeptyneScript s = script;
    s.code = code;
    vector<string> lines;
    split(lines, code, "\n");
    s.code_lines = lines;
    vector<Token> tokens = tokenize(s);
}
