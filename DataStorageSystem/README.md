# Dropbox-like Data Storage System

Dropbox gives a fast and reliable way to send and receive files with compression. In this project, we are going to create a dropbox-like data storage system which could result in less storage capacity and increased productivity.

## INTRODUCTION

- Dropbox-like storage in this project should accept the following functions:
- Creating a local file system
- Loading and encoding of text files
- Retrieving back and decoding of text files
- Listing of loaded files
- Deleting of text files


### Code folder

    disk.c
    disk.h
    fileSystem.c
    fileSystem.h
    fileCompress.cpp
    fileCompress.h
    HuffmanTree,hpp
    compress.c
    compress.h
    UI.c
    makefile

# Introduction of Code

To use the UI, make the project and use the following command:

makefile
```./make -k -f makefile```

Creating a new disk with its name: 
```./UI -newdisk {DiskName}```

Listing the content and usage of a disk: 
```./UI -ls {DiskName}```

Saving a file to the disk: 
```./UI -save {DiskName} {OriginalFileName} {FileNameInVFS}```

Deleting a file in the disk: 
```./UI -rm {DiskName} {FileNameInVFS}```

Loading a file from the disk: 
```./UI -load {DiskName} {FileName} {FileNameInVFS}```

Loading a file from the disk, without decoding: 
```./UI -load_NoDecode {DiskName} {FileName} {FileNameInVFS}```

Encoding a file: 
```./UI -encode {ASCIIFileName} {TrainBigramFileName}```

Decoding a file: 
```./UI -decode {ASCIIFileName} {TrainBigramFileName}```

**Would output ```Segmentation Fault``` if the user try to read from a non-existing file.
