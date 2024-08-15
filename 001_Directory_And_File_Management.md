# Shell Scripting Guide

This guide provides a comprehensive overview of basic shell scripting commands and operations for managing files and directories in UNIX-like systems. The commands are demonstrated with explanations, making it easy to understand and replicate.

## Table of Contents

1. [File Names and Descriptions](#1-file-names-and-descriptions)
2. [Directory and File Management Commands](#2-directory-and-file-management-commands-and-outputs)
   - [Creating a Directory: `mkdir`](#21-creating-a-directory-mkdir)
   - [Listing Files and Directories: `ls`](#22-listing-files-and-directories-ls)
   - [Viewing Detailed File Information: `ls -l`](#23-viewing-detailed-file-information-ls--l)
   - [Changing Directory: `cd`](#24-changing-directory-cd)
   - [Copying Files: `cp`](#25-copying-files-cp)
   - [Moving or Renaming Files: `mv`](#26-moving-or-renaming-files-mv)
   - [Creating New Files: `touch`](#27-creating-new-files-touch)
   - [Removing Files: `rm`](#28-removing-files-rm)
   - [Removing Directories: `rmdir`](#29-removing-directories-rmdir)

## 1. File Names and Descriptions

- **`command.sh`**: Original shell script file to work upon.
- **`copiedCommand.sh`**: A copy of `command.sh`, used for demonstrating file copy operations.

## 2. Directory and File Management Commands and Outputs:

### 2.1 Creating a Directory: `mkdir`

```bash
   mkdir testDir
```

**Description**: Creates a directory named `testDir` inside the current directory.

**Output**: No output. The directory `testDir` is created.
<br><br><br>

### 2.2 Listing Files and Directories: `ls`

```bash
   ls
```

**Description**: Lists files and directories in the current directory.

**Output**: Gives the list of all the files and directory present in the currect directory.
<br><br><br>

### 2.3 Viewing Detailed File Information: `ls -l`

```bash
   ls -l
```

**Description**: Lists files with detailed information including permissions, owner, size, and modification date.

**Output**:

```bash
   total 75
   -rwxrwxrwx 1 avinashyadav16 avinashyadav16  6468 Aug 15 00:43  GuideFile.md
```

<br><br><br>

### 2.4 Changing Directory: `cd`

```bash
cd testDir
```

**Description**: Changes the current directory to testDir.

**Output**: No output. The working directory is now testDir.

<br><br><br>

### 2.5 Copying Files: `cp`

```bash
cp newFile.sh copiedNewFile.sh
```

**Description**: Copies the contents of `newFile.sh` to `copiedNewFile.sh`.

**Output**: No output. The file `copiedNewFile.sh` is created as a copy of `newFile.sh`.
<br><br><br>

### 2.6 Moving or Renaming Files: `mv`

```bash
mv copiedNewFile.sh renamedFile.sh
```

**Description**: Moves or renames copiedNewFile.sh to renamedFile.sh.

**Output**: No output. The file copiedNewFile.sh is now renamed to renamedFile.sh.
<br><br><br>

### 2.7 Creating New Files: `touch`

```bash
touch newFile.sh
touch copiedNewFile.sh
```

**Description**: Creates empty files `newFile.sh` and `copiedNewFile.sh` if they do not already exist.

**Output**: No output. The files are created.
<br><br><br>

### 2.8 Removing Files: `rm`

```bash
rm newfile.sh
```

**Description**: Removes the file `newfile.sh`.

**Output**: No output. The file `newfile.sh` is deleted.
<br><br><br>

### 2.9 Removing Directories: `rmdir`

```bash
rmdir testDir
```

**Description**: Removes the directory `testDir`, which must be empty.

**Output**: No output. The directory `testDir` is deleted.
<br><br><br>

## Ensure all the commands are executed with caution, as some operations like rm and rmdir are irreversible.
