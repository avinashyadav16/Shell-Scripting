# Shell Scripting Guide

## Overview

This guide provides a series of commands and steps used for basic shell scripting operations. It includes creating directories, managing files, and using common UNIX commands. Follow these instructions to replicate the setup and understand the actions performed.

## Commands Used

### Directory and File Management

1. **Creating a Directory**

   ```bash
   mkdir testingDir
   ```

   Creates a directory named `testingDir` within the `commands` directory.

2. **Listing Files and Directories**

   ```bash
   ls
   ```

   Lists the files and subdirectories in the current directory.

3. **Viewing Detailed File Information**

   ```bash
   ls -l
   ```

   Lists files with detailed information, including permissions, owner, size, and modification date.

4. **Copying Files**

   ```bash
   cp file1.sh copiedFile1.sh
   ```

   Copies the contents of `file1.sh` to `copiedFile1.sh`.

5. **Touch Command**

   ```bash
   touch file1.sh
   touch copiedFile1.sh
   ```

   Creates empty files `file1.sh` and `copiedFile1.sh` if they do not already exist.

6. **Removing Files**

   ```bash
   rm newfile.sh
   ```

   Removes the file `newfile.sh`.

7. **Removing Directories**
   ```bash
   rmdir testDirectory
   ```
   Removes the directory `testDirectory`, which must be empty.

### Editing Files

1. **Using `nano` to Edit Files**

   ```bash
   nano file1.sh
   ```

   Opens `file1.sh` in the `nano` text editor for editing. Save changes with `Ctrl+O` and exit with `Ctrl+X`.

2. **Appending Text with `echo`**

   ```bash
   echo '#This is second method by which I am appending the content to the file by using echo method.' >> file1.sh
   ```

   Appends text to `file1.sh` using the `echo` command.

3. **Appending Multiple Lines with `cat`**
   ```bash
   cat << 'EOF' >> file1.sh
   '# Here I am adding the text using cat command for multiple lines.'
   EOF
   ```
   Appends multiple lines of text to `file1.sh` using a here document.

### Viewing File Contents

1. **Displaying File Contents**
   ```bash
   cat file1.sh
   ```
   Displays the contents of `file1.sh`.

## File Contents

- **`file1.sh`**: Contains comments and text added using `nano`, `echo`, and `cat` commands.
- **`copiedFile1.sh`**: Initially copied from `file1.sh`, should contain the same content as `file1.sh`.

## Notes

- Ensure that you are in the correct directory when executing commands.
- Use `ls -F` to distinguish between files and directories (directories will have a trailing slash `/`).
- Commands are case-sensitive in UNIX; ensure correct usage.

## Troubleshooting

If you encounter issues such as commands not found or file operations failing, verify that the paths and filenames are correct and that you have the necessary permissions.

## Conclusion

This guide demonstrates basic file and directory operations using shell scripting. For more advanced shell scripting techniques, consider exploring additional commands and scripting practices.
