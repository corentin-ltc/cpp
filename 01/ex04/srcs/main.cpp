#include "utils.hpp"

int main(int argc, char **argv)
{
	std::string content;

	check_arguments(argc, argv);
	content = copy_infile(argv[1]);
	replace_strings(argv, content);
	copy_in_outfile(argv, content);
	return (EXIT_SUCCESS);
}