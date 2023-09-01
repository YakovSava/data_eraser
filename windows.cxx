#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
using namespace std;

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

int erase(string path) {
	string filename = "/erase";
	ofstream file(path+filename);
	if (!file.is_open()) {
		cerr << "Unknow error!" << endl;
		return -1;
	}
	while (true) {
		file << "1\n";
	}

	return 0;
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

// int main(int argc, char* argv[]) {
// 	vector<string> disks = get_logical_disks();
// 	if (argc < 1) {
// 		cout << "Error! Empty disk" << endl;
// 	} else if {
// 		string disk = argv[0];
// 		bool disk_in = false;
// 		for (string& drive : drives) {
// 			if (disk == drive) {
// 				disk_in = true;
// 				break;
// 			}
// 		}
// 	}
// 	if (!disk_in) {
// 		cout << "Disk not found!" << endl;
// 	} else {
		
// 	}
// }

int main() {
	erase("F:");

	return 0;
}