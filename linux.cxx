# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <vector>

void rm_file(string filepath) {
	string command = "rm -f ";
	system((command+filepath).c_str());
}