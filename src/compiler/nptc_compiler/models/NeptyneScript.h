//
// Created by Markus Kannisto on 10/03/2022.
//

#pragma once

#include "../../../common/common.h"

class NeptyneScript {
 public:
  fs::path full_path_;
  string filename_;
  string extension_;
  string name_;
  string directory_path_;
  string obj_directory_path_;
  string output_executable_path_;
  string output_assembly_path_;
  string output_obj_path_;
  
  string code_;
  vector<string> code_lines_;
  
  explicit NeptyneScript(const string &file) {
	  if (!file.empty()) {
		  full_path_ = fs::canonical(file);
		  filename_ = full_path_.string().substr(full_path_.string().find_last_of("/\\") + 1);
		  extension_ = filename_.substr(filename_.find_last_of('.'));
		  name_ = filename_.substr(0, filename_.length() - extension_.length());
		  directory_path_ = full_path_.string().substr(0, full_path_.string().find_last_of("/\\") + 1);
		  obj_directory_path_ = directory_path_;
		  output_executable_path_ = directory_path_ + name_;
		  output_assembly_path_ = obj_directory_path_ + name_ + ".asm";
		  output_obj_path_ = obj_directory_path_ + name_ + ".o";
	  }
  }
  
  NeptyneScript() = default;
};

static NeptyneScript kNullScript = *new NeptyneScript("");
