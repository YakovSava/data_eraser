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

int get_free_memory_on_disk(string diskpath) {
    return 0;
}

int get_filesize(string filepath) {
    return 0;
}

int eraser(string diskpath) {
    return 0;
}

vector<string> get_diskpaths() {
    vector<string> to_ret;
    vector<string> diskutils_info = split(get_cl_answer("diskutil list"), "\n");
    for (const string ln : diskutils_info) {
        if (startswith(ln, "/dev/sd")) {
            vector<string> str = split(ln, " ");

            vector<string> finder = split(get_cl_answer("diskutil info "+str[0]), " ");
            for (const string line : finder) {
                if ((line.find('Protocol:') != string::npos) && (line.find('USB') != string::npos)) {
                    to_ret.push_back(str[0]);
                }
            }
        }
    }

    return to_ret;
}

int main(int argc, char* argv[]) {
    return 0;
}