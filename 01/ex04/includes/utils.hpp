#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <fstream>

void exit_error(std::string message);
void check_arguments(int argc, char **argv);
std::string copy_infile(char *infile_name);
void replace_strings(char **argv, std::string &content);
void copy_in_outfile(char **argv, std::string content);

#endif

