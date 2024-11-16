#include "utils.hpp"

void copy_in_outfile(char **argv, std::string content)
{
	std::string outfile_name;

	outfile_name = ((std::string)argv[1]).append(".replace");
	std::ofstream outfile(outfile_name);
	if (!outfile)
	{
		std::cerr << "Could not open \"" << outfile_name <<"\"." << std::endl; 
		exit(EXIT_FAILURE);
	}
	outfile << content;
	outfile.close();
}

void replace_strings(char **argv, std::string &content)
{
	size_t found = 0;;

	while (argv[2][0] != 0)
	{
		found = content.find(argv[2], found);
		if (found != std::string::npos)
		{
			content.insert(found, (std::string)argv[3]);
			found += ((std::string)argv[3]).length();
			content.erase(found, ((std::string)argv[2]).length() );
		}
		else
			break;
	}
}

std::string copy_infile(char *infile_name)
{
	std::string buffer;
	std::string content;
	std::fstream infile(infile_name);
	
	if (!infile)
	{
		std::cerr << "Could not open \"" << infile_name <<"\"." << std::endl; 
		exit(EXIT_FAILURE);
	}
	while (getline(infile, buffer))
		content += buffer + '\n';
	infile.close();
	return (content);
}

void check_arguments(int argc, char **argv)
{
	if (argc != 4)
		exit_error("Wrong number of arguments.");
	if (!argv[1][0])
		exit_error("The file name must not be null.");
}

void exit_error(std::string message)
{
	std::cerr << message << std::endl;
	exit(EXIT_FAILURE);
} 