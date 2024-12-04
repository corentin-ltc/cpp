#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : 
    AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : 
    AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : 
    AForm(other), target(other.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	
	this->CanBeExecuted(executor);
    std::string filename = target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    if (!outfile) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    outfile << "     oxoxoo    ooxoo\n"
            << "  ooxoxo oo  oxoxooo\n"
            << " oooo xxoxoo ooo ooxx\n"
            << " oxo o oxoxo  xoxxoxo\n"
            << "  oxo xooxoooo o ooo\n"
            << "    ooo\\oo\\  /o/o\n"
            << "        \\  \\/ /\n"
            << "         |   /\n"
            << "         |  |\n"
            << "         | |\n"
            << "         | |\n"
            << "         | |\n"
            << "  ______/___\\____\n";

    outfile.close();
}
