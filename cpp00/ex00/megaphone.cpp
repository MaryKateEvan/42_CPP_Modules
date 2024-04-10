#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}

	int j;
	char tmp;
	for (int i = 1; argv[i]; i++) {
		j = 0;
		while (argv[i][j]) {
			tmp = std::toupper((int)argv[i][j++]);
			std::cout << tmp;
		}
	}
	std::cout << std::endl;
	return 0;
}
