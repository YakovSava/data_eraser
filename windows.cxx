# include <iostream>
# include <vector>
# include <windows.h>
# include <fstream>
# include <cstdio>
# include <algorithm>
using namespace std;

void rm_file(string filepath) {
	string command = "rm -f ";
	system((command+filepath).c_str());
}

vector<string> get_logical_disks() {
	DWORD bufferLength = GetLogicalDriveStrings(0, NULL);
	vector<char> buffer(bufferLength);

	GetLogicalDriveStrings(bufferLength, &buffer[0]);

	vector<string> drives;
	char* drive = &buffer[0];
	while (*drive) {
		drives.push_back(drive);
		drive += strlen(drive) + 1;
	}

	return drives;
}

int get_free_memory(string disk) {
	ULARGE_INTEGER freeSpace;
    if (GetDiskFreeSpaceExA(disk.c_str(), &freeSpace, NULL, NULL)) {
        return freeSpace.QuadPart;
    } else {
        cerr << "Unknow error!" << endl;
		return -1;
    }
}

long long get_file_size(string filepath) {
	ifstream file(filepath, ios::binary);

	if (!file) {
		cerr << "Unknow error!" << endl;
		return -1;
	}

	file.seekg(0, ios::end);
	streampos file_size = file.tellg();
	file.seekg(0, ios::beg);

	file.close();

	return static_cast<long long>(file_size);
}

int erase(string path) {
	string filename = "/erase";
	ofstream file(path+filename);
	if (!file.is_open()) {
		cerr << "Unknow error!" << endl;
		return -1;
	}
	while (true) {
		file << "1\n";
		if (get_file_size(path+filename) < (double)get_free_memory(path) * 0.7) {
			break;
		}
	}

	rm_file(path+filename);

	return 0;
}


int main(int argc, char* argv[]) {
	vector<string> drives = get_logical_disks();
	if (argc < 2) {
		cout << "Error! Not enought disk" << endl;
	} else {
		auto it = find(drives.begin(), drives.end(), (string)argv[1])
		if (it == strings.end()) {
			cout << "Disk not found!" << endl;
		} else {
			erase((string)argv[1]);
		}
	}

	return 0;
}