#include <iostream>
#include <vector>
#include <windows.h>
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

