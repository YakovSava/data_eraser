# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <vector>
# include <stdio.h>
# include <cstdio>
# include <algorithm>
using namespace std;

void rm_file(string filepath) {
	string command = "rm -f ";
	system((command+filepath).c_str());
}

vector<string> split(const string& lines, const string& splitter) {
    vector<string> substrings;
    istringstream iss(lines);
    string substring;
    while (getline(iss, substring, splitter[0])) {
        substrings.push_back(substring);
    }
    return substrings;
}

string get_cl_answer(string command) {
	FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        cerr << "Unknow error!" << endl;
        return NULL;
    }
    
    char buffer[128];
    string result = "";
    
    while (fgets(buffer, 128, pipe) != nullptr) {
        result += buffer;
    }
    
    pclose(pipe);

    return result;
}

int startswith(string str, string start) {
	if (str.compare(0, start.size(), start)) {
		return 1;
	} else {
		return 0;
	}
}