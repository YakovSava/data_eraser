# What is it?
This is a program for relatively fast rewriting of blocks for flash drives or other drives. If you don't want no one to find your deleted data, use this program! What can I offer?
- Minimalistic console interface
- Cross-platform (P.S. see below)
- Adaptability to different drives (whether **mmcblk**, **ssd**/**hdd**/**usb** or **cd**)

## Cross-platform
For Linux (ELF) use the "lineraser" file, for Windows use "wineraser.exe"
<blockquote> Unfortunately, I can't check how it will work with systems on the ARM platform, as well as on systems with x86_32, I'm also not sure about Linux systems running on aout </blockquote>
<blockquote> Also it unfortunately doesn't work on Mac (OS X) since I don't have the right equipment for this =( </blockquote>

## How to use it?
Everything is very simple. Here's how to use it on different systems:
```
***erase /path/to/mount/point
```
Where *** should be replaced with *lin* or *win*, depending on the system you are using. Here are the commands for these two systems
- Windows
`winerase E:`
- Linux
`linerase /dev/sdb`
<blockquote> The program will find the mount point itself </blockquote>