# Shell Scripting Guide

<!-- ![repo views](https://repoviews.netlify.app/.netlify/functions/repoViews?repo=https://github.com/avinashyadav16/Shell-Scripting) -->

## Introduction

Shell scripting is a powerful tool that allows you to automate tasks and manage your system efficiently. This guide provides a comprehensive overview of basic shell commands, directory and file management, file editing, and troubleshooting tips. Whether you are a beginner or need a refresher, this guide will help you understand and execute common shell scripting tasks.

---

## Table of Contents

1. [Linux For Beginners](./Linux%20for%20Beginners.md) (\* still working on it)
2. [Most Common Unix Commands](./Most_Common_Unix_Commands.md)
3. [001 Directory and File Management](./001_Directory_And_File_Management.md)
4. [002 Editing Files and Viewing](./002_Editing_Files_And_Viewing.md)
5. [PRACTICE](./PRACTICE/)
   - [001 PRACTICE](./PRACTICE/001%20PRACTICE/To-Do-File.md)
   - [002 PRACTICE](./PRACTICE/002%20PRACTICE/To-Do-File.mds)

## Table of Contents in this File

1. [Introduction](#introduction)
2. [Understanding the Shell](#understanding-the-shell)
   - What is a Shell?
   - Types of Shells
   - Determining Your Default Shell
3. [Basic Shell Commands](#basic-shell-commands)
   - Command Structure
   - Case Sensitivity
   - Running Commands
   - Common Commands Overview
4. [Directory and File Management](#directory-and-file-management)
   - Navigating Directories
   - Creating and Deleting Directories
   - Managing Files (Creating, Copying, Moving, Deleting)
   - Viewing File Contents
   - Managing Permissions
5. [Editing Files](#editing-files)
   - Using `vi` Editor
   - Using `nano` Editor
6. [Troubleshooting](#troubleshooting)
   - Common Errors and Solutions
   - Permissions Issues
   - Command Not Found
7. [Conclusion](#conclusion)
8. [Additional Resources](#additional-resources)

---

## Introduction

Shell scripting is an essential skill for system administrators, developers, and power users. It allows for task automation, system management, and enhances efficiency by combining commands into scripts. This guide covers the foundational aspects of shell scripting, including the execution of basic commands, managing files and directories, and editing files directly from the command line.

---

## Understanding the Shell

### What is a Shell?

The shell is a command-line interpreter that provides a user interface for accessing the operating system's services. It processes commands entered by the user and executes them, allowing for interaction with the system.

### Types of Shells

There are several types of shells available, such as:

- **sh (Bourne Shell)**
- **bash (Bourne Again Shell)**: The most common and widely used shell.
- **zsh (Z Shell)**: Known for its advanced features and user-friendly configuration.
- **ksh (Korn Shell)**: A powerful scripting shell with advanced scripting capabilities.
- **csh (C Shell)**: Known for its syntax resembling the C programming language.

### Determining Your Default Shell

To determine your default shell, type the following command in your terminal:

```bash
echo $SHELL
```

### Changing Your Default Shell

To change your default shell, run the following command:

```bash
/usr/local/bin/chsh
```

Follow the prompts to change your shell. Note that this is a custom script and not the standard `chsh` you might find on Linux machines. Allow 24 hours for the default shell to take effect.

## Basic Shell Commands

### Command Structure

- Commands are typed at a prompt, typically represented by a percent sign (`%`) or dollar sign (`$`). Sometimes, it includes the name of the machine followed by the percent or dollar sign.

### Case Sensitivity

- Commands are case-sensitive and are usually in lowercase. For example, `ls` and `LS` are completely different commands.
- Commands are typically in lowercase. Ensure that you are typing them correctly to avoid errors.

### Running Commands

- To execute a command, press Enter at the end of the command line. If the command is accepted, the prompt and cursor will appear on the next line awaiting your next command. If the command is rejected, an error message such as `Command not found` will appear.

- To cancel a command before pressing Enter, press `CTRL + C`.

### Common Commands Overview

`ls`: Lists the contents of a directory.
`cd`: Changes the current directory.
`mkdir`: Creates a new directory.
`rm`: Removes files or directories.
`cp`: Copies files or directories.
`mv`: Moves or renames files or directories.
`echo`: Displays a line of text.

## Directory and File Management

### Navigating Directories

- `cd <directory>` - Use the `cd` command to `change directories`.
- `pwd` - Use `pwd` to print the `current working directory`.
- `cd ..` - Moves up one directory level.
- `ls` - Use `ls` to `list the contents of a directory`.

### Creating and Managing Files

- `touch <file>` - Use `touch` to `create a new file`.
- `rm <file>` - Use `rm` to `delete a file`.
- `cp <source> <destination>` - Use `cp` to `copy a file`.
- `mv <source> <destination>` - Use `mv` to `move or rename a file`.

### Viewing File Contents

- `cat <file>` - Displays the `contents of a file`.
- `less <file>` - Views the `file content page by page`.
- `head <file>` - Displays the `first few lines of a file`.
- `tail <file>` - Displays the `last few lines of a file`.

### Managing Permissions

- `chmod <permissions> <file>` - Changes the file's permissions.
- `chown <user>:<group> <file>` - Changes the file's owner and group.

### Editing Files

- Use `nano`, `vi`, or `vim` to edit text files directly from the terminal.
- Ensure that you are in the correct directory when executing commands to avoid unintended operations.

1. Using vi Editor

   - `vi <filename.exetension>` - Opens a file in vi editor.
   - Press `i` for going into insert mode and editing text.
   - Press `ESC` for the exiting out of the insert mode.
   - Press `:w` for saving the edited file.
   - Press `:q` for quitting out of vi editor.
   - We can perform the above saving and quitting of the task in a single command as `:wq`
   - Change the mode of the file making it as executable(if it is not already) as `chmod +x <filename.extention>`
   - Run the file as `./<filename.extention>`

2. Using nano Editor

   - `nano <filename.exetension>` - Opens a file in nano editor.
   - Press `CTRL + O` to the edited file
   - Press `CTRL + X` to exit out of the nano editor.

## Troubleshooting

**Common Errors and Solutions**
`Command Not Found`: Ensure the command is installed and in your PATH.
`Permission Denied`: Check file permissions or use sudo for elevated privileges.
`File Not Found`: Verify the file path and name.

**Permissions Issues**

- Use chmod and chown to correct file permissions and ownership.
- Ensure that you have the necessary permissions to perform the operations.

## Conclusion

This guide provides a fundamental understanding of shell scripting, covering basic commands, directory and file management, and troubleshooting. By following these instructions, you can efficiently manage and edit files using shell scripting techniques.

For more advanced operations and additional commands, refer to the UNIX manual pages or other shell scripting resources.

## Additional Resources

- **[UNIX Manual Pages](https://man7.org/linux/man-pages)**: Access detailed command documentation using the `man` command.
- **[Bash Scripting Guide](https://tldp.org/LDP/Bash-Beginners-Guide/html/index.html)**
- **[Zsh Documentation](https://zsh.sourceforge.io/Doc/Release/zsh.html)**
- **Online Shell Scripting Tutorials**: Explore further learning with online courses and tutorials.
- **Community Forums**: Join discussions and seek help from the shell scripting community.
