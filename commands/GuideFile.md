# Shell Scripting Guide

## Overview

This guide provides a series of commands and steps used for basic shell scripting operations. It includes creating directories, managing files, and using common UNIX commands. It also includes descriptions of each command and their associated outputs. Follow these instructions to replicate the setup and understand the actions performed.

## File Names and Descriptions

- **`command.sh`**: Original shell script file containing various UNIX commands.
- **`copiedCommand.sh`**: A copy of `command.sh`, used for demonstrating file copy operations.
- **`newFile.sh`**: A script file created and edited using various methods to demonstrate file editing commands.
- **`copiedNewFile.sh`**: A copy of `newFile.sh`, created to show file copying operations.

## Commands and Outputs

### Directory and File Management

1. **Creating a Directory: mkdir Command**

   ```bash
   mkdir testDir
   ```

   **Description**: Creates a directory named `testDir` inside the current directory.

   **Output**: No output. The directory `testDir` is created.

2. **Listing Files and Directories: ls Command**

   ```bash
   ls
   ```

   **Description**: Lists files and directories in the current directory.

   **Output**:

   ```
   'Basic unix-commands.pdf'   GuideFile.md   commands.sh   copiedFile.sh   testDir
   ```

3. **Viewing Detailed File Information: ls -l Command**

   ```bash
   ls -l
   ```

   **Description**: Lists files with detailed information including permissions, owner, size, and modification date.

   **Output**:

   ```
   total 92
   -rwxrwxrwx 1 avinashyadav16 avinashyadav16 74295 Aug  9 09:56 'Basic unix-commands.pdf'
   -rwxrwxrwx 1 avinashyadav16 avinashyadav16  6468 Aug 13 00:43  GuideFile.md
   -rwxrwxrwx 1 avinashyadav16 avinashyadav16  3461 Aug 12 23:16  commands.sh
   -rwxrwxrwx 1 avinashyadav16 avinashyadav16  3461 Aug 12 23:33  copiedFile.sh
   drwxrwxrwx 1 avinashyadav16 avinashyadav16   512 Aug 13 00:43  testDir
   ```

4. **Copying Files: cp Command**

   ```bash
   cp newFile.sh copiedNewFile.sh
   ```

   **Description**: Copies the contents of `newFile.sh` to `copiedNewFile.sh`.

   **Output**: No output. The file `copiedNewFile.sh` is created as a copy of `newFile.sh`.

5. **Creating New Files: touch Command**

   ```bash
   touch newFile.sh
   touch copiedNewFile.sh
   ```

   **Description**: Creates empty files `newFile.sh` and `copiedNewFile.sh` if they do not already exist.

   **Output**: No output. The files are created.

6. **Removing Files: rm Command**

   ```bash
   rm newfile.sh
   ```

   **Description**: Removes the file `newfile.sh`.

   **Output**: No output. The file `newfile.sh` is deleted.

7. **Removing Directories: rmdir Command**

   ```bash
   rmdir testDirectory
   ```

   **Description**: Removes the directory `testDirectory`, which must be empty.

   **Output**: No output. The directory `testDirectory` is deleted.

### Editing Files

1.  **Editing with `nano` Command**

    ```bash
    nano newFile.sh
    ```

    **Description**: Opens `newFile.sh` in the `nano` text editor for editing. Save changes by pressing `Ctrl+O`, then press ENTER and finally exit with `Ctrl+X`.

    **Output**: Opens the `nano` editor. No immediate output until you save and exit.

2.  **Overwriting with `echo` Command**

    ```bash
        echo '#!/bin/bash' > newFile.sh
        echo '# This is the new content of the file.' >> newFile.sh
    ```

    **Description**: Overwrites the contents of `newFile.sh` with the text provided. The `>` operator will replace the entire file content with the new text.

    **Output**: No immediate output. The file `newFile.sh` will contain only the text `# This is the new content of the file.`.

3.  **Appending Text with `echo` Command**

    ```bash
    echo '# This is second method to append contents to the file.' >> newFile.sh
    ```

    **Description**: Appends text to `newFile.sh` using the `echo` command.

    **Output**: No immediate output. The text is added to `newFile.sh`.

4.  **Overwriting with cat Command**

    ```bash
        cat << 'EOF' >> newFile.sh
        # Here we are adding text using cat command for multiple lines.
        # This is the second line using the cat command under multiple lines.
        EOF
    ```

    **Description**: Overwrites the contents of `newFile.sh` with the text provided in the here document. The `>` operator will replace the entire file content.

    **Output**: No immediate output. The file `newFile.sh` will contain the text `# This is the new content added using the cat command.`.

5.  **Appending Multiple Lines with `cat` Command**

    ```bash
    cat << 'EOF' >> newFile.sh
    '# Here we are adding text using cat command for multiple lines.
    # This is second line using the cat command under multiple lines.'
    EOF
    ```

    **Description**: Appends multiple lines of text to `newFile.sh` using a here document.

    **Output**: No immediate output. Multiple lines are added to `newFile.sh`.

### Viewing File Contents

1. **Displaying File Contents**

   ```bash
   cat newFile.sh
   ```

   **Description**: Displays the contents of `newFile.sh`.

   **Output**:

   ```
   #!/bin/bash

    # This is the first line that I wrote in this file using nano command in the cmd.
    # This is second method to append content to the file using echo method.
   '# Here we are adding text using cat command for multiple lines.'
   '# This is second line using the cat command under multiple lines.'
   ```

## Notes

- Ensure that you are in the correct directory when executing commands.
- Use `ls -F` to distinguish between files and directories (directories will have a trailing slash `/`).
- Commands are case-sensitive in UNIX; ensure correct usage.

## Troubleshooting

If you encounter issues such as commands not found or file operations failing, verify that the paths and filenames are correct and that you have the necessary permissions.

## Conclusion

This guide demonstrates basic shell commands for file and directory management, file editing, and viewing file contents. By following these steps, you can efficiently manage and edit files using shell scripting techniques.

For more advanced operations and additional commands, refer to the UNIX manual pages or other shell scripting resources.
