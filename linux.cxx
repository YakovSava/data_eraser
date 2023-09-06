# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <vector>
# include <stdio.h>
# include <sys/statvfs.h>
# include <cstdio>
# include <algorithm>
using namespace std;

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

int startswith(string str, string start) {
	if (string.compare(0, start.size(), start)) {
		return 1;
	} else {
		return 0;
	}
}

vector<vector<string>> maping(vector<string> lines_splitted) {
	vector<vector<string>> lines_double_splitted;
	for (string line : lines_splitted) {
		lines_double_splitted.push_back(split(line, " "));
	}
	
	return lines_double_splitted;
}

vector<string> get_mount_point() {
	vector<string> mnt_points;

	string findmnt_answer = get_cl_answer("findmnt");
	vector<string> lines = split(findmnt_answer);
	// vector<vector<string>> splitted_lines;
	
	for (vector<string> info : lines) {
		if (startswith(info[1], "/dev/sd")) {
			for (string udevadm_info : split(get_cl_answer(((string)"udevadm info --query=all --name="))+info[1], "\n")) {
				if (startswith(udevadm_info, "E: DEVPATH") && (udevadm_info.find("usb") != string::npos)) {
					mnt_points.push_back(info[0]);
				}
			}
		}
	}
	
	return mnt_points;
}

unsigned long long get_free_memory_on_disk(string mnt_point) {
	struct statvfs buffer;
    int result = statvfs(mnt_point.c_str(), &buffer);

    if (result == 0) {
        unsigned long long freeSpace = buffer.f_bavail * buffer.f_frsize;
        return freeSpace;
    } else {
        cerr << "Unknow error!" << endl;
        return -1;
    }
}

unsigned long long get_file_size(string filepath) {
	ifstream file(filepath, ios::binary);

	if (!file) {
		cerr << "Unknow error!" << endl;
		return -1;
	}

	file.seekg(0, ios::end);
	streampos file_size = file.tellg();
	file.seekg(0, ios::beg);

	file.close();

	return static_cast<unsigned long long>(file_size);
}

int erase(string mnt_point) {
	return 0;
}

int main(int argc, char* argv[]) {
	vector<string> mnt_list = get_mount_point();
	if (argc < 2) {
		cout << "Error! Not enought disk" << endl;
	} else {
		auto it = find(mnt_list.begin(), mnt_list.end(), (string)argv[1])
		if (it == mnt_list.end()) {
			cout << "Disk not found!" << endl;
		} else {
			erase((string)argv[1]);
		}
	}
	
	return 0;
}