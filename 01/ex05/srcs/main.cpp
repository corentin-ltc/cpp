#include "Harl.hpp"

int main(void)
{
	Harl harlos;

	harlos.complain("debug");
	harlos.complain("info");
	harlos.complain("warning");
	harlos.complain("error");
	harlos.complain("random");
	harlos.complain("");
}