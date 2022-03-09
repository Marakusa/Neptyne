//
// Created by Markus Kannisto on 09/03/2022.
//

#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = filesystem;

auto read_file(string_view path) -> string {
    constexpr auto read_size = size_t(4096);
    auto stream = ifstream(path.data());
    stream.exceptions(ios_base::badbit);

    auto out = string();
    auto buf = string(read_size, '\0');
    while (stream.read(& buf[0], read_size)) {
        out.append(buf, 0, stream.gcount());
    }
    out.append(buf, 0, stream.gcount());
    return out;
}