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
	FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        cerr << "Unknow error!" << endl;
        return -1;
    }
    
    char buffer[128];
    string result = "";
    
    while (fgets(buffer, 128, pipe) != nullptr) {
        result += buffer;
    }
    
    pclose(pipe);

    return result;
}

vector<vector<string>> maping(vector<string> lines_splitted) {
	vector<vector<string>> lines_double_splitted;
	for (string line : lines_splitted) {
		lines_double_splitted.push_back(split(line, " "));
	}
	
	return lines_double_splitted;
}

vector<string> get_mount_point() {
	return NULL;
}

int main(int argc, char* argv[]) {
	return 0;
}