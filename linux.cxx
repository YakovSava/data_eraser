# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <vector>

void rm_file(string filepath) {
	string command = "rm -f ";
	system((command+filepath).c_str());
}

vector<string> split(string lines, string splitter) {
	vector<string> substrings;
	istringstream iss(lines);
	string substring;
	while (getline(iss, substring, splitter)) {
		substrings.push_back(substring);
	}

	return substrings;
}

string get_cl_answer(string command) {
	return "";
}

vector<string> get_mount_point() {
	return NULL;
}

int main(int argc, char* argv[]) {
	return 0;
}