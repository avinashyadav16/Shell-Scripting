# Overview

This document provides a detailed guide on various file operations and editing techniques in UNIX-like systems. It covers the creation, modification, and viewing of shell script files using different commands. Each section includes specific commands, descriptions, and expected outputs to help understand file manipulation in a UNIX environment.

The guide demonstrates:

- Editing files using `nano`, `vi editor` and `echo`.
- Overwriting and appending content using `cat`.
- Viewing file contents to verify changes.
- Practical tips on distinguishing between files and directories.

<br><br>

# Table of Contents

1. [File Names and Descriptions](#1-file-names-and-descriptions)
2. [Commands and Outputs](#2-commands-and-outputs)
   - [Editing Files](#21-editing-files)
     - [Editing with `nano` Command](#211-editing-with-nano-command)
     - [Editing with `vi` Command](#212-editing-with-vi-command)
     - [Overwriting with `echo` Command](#213-overwriting-with-echo-command)
     - [Appending Text with `echo` Command](#214-appending-text-with-echo-command)
     - [Overwriting with `cat` Command](#215-overwriting-with-cat-command)
     - [Appending Multiple Lines with `cat` Command](#216-appending-multiple-lines-with-cat-command)
   - [Viewing File Contents](#22-viewing-file-contents)
     - [Displaying File Contents](#221-displaying-file-contents)
3. [Notes](#3-notes)

<br><br>

# 1. File Names and Descriptions

- **`command.sh`**: The original shell script file containing various UNIX commands for demonstration and practice.
- **`copiedCommand.sh`**: A copy of `command.sh`, used to illustrate file copying operations.
- **`newFile.sh`**: A shell script file created and edited using various methods to demonstrate file editing commands.
- **`copiedNewFile.sh`**: A copy of `newFile.sh`, used to show file copying operations and verify file duplication.

<br><br>

# 2. Commands and Outputs

## 2.1 Editing Files

### 2.1.1 Editing with `nano` Command

```bash
    nano newFile.sh
```

**Description**: Opens `newFile.sh` in the nano text editor. nano is a simple, user-friendly text editor that allows for interactive editing of files.
To `Save` Changes: Press `Ctrl+O`, then press `ENTER`.
To `Exit`: Press `Ctrl+X`.

**Output**: The terminal will display the nano text editor interface, where you can make changes to the file. There is no immediate output until you save and exit the editor.

<br><br><br>

### 2.1.2 Editing with `vi` Command

```bash
    vi newFile.sh
```

**Description**: Opens `newFile.sh` in the vi text editor. vi is a powerful text editor with modes for both command-line operations and text editing.
`Insert Mode`: Press `i` to enter Insert mode, which allows you to type and edit the content.
`Command Mode`: Press `Esc` to return to Command mode. In this mode, you can navigate, delete, copy, and paste text.
Basic Commands:
To `Save Changes and Exit`: Type `:wq` and press `ENTER`.
To `Exit Without Saving`: Type `:q!` and press `ENTER`.

**Output**: The terminal will display the vi text editor interface. No immediate output is shown until you save and exit the editor.

<br><br><br>

### 2.1.3 Overwriting with `echo` Command

```bash
    echo '#!/bin/bash' > newFile.sh
    echo '# This is the new content of the file.' >> newFile.sh
```

**Description**:The echo command with the `>` operator is used to create or overwrite the contents of `newFile.sh` with the provided text.
The first command writes `#!/bin/bash` to the file, which is a shebang line indicating the file is a shell script.
The second command appends `# This is the new content of the file.` to the file.

**Output**: No immediate output. The file `newFile.sh` will contain only the text:

```bash
    #!/bin/bash
    # This is the new content of the file.
```

<br><br><br>

### 2.1.4 Appending Text with `echo` Command

```bash
    echo '# This is second method to append contents to the file.' >> newFile.sh
```

**Description**: Appends text to `newFile.sh` using the `echo` command. Appends the text `# This is the second method to append contents to the file.` to the end of `newFile.sh` using the `>>` operator.

**Output**: No immediate output. The text is added to `newFile.sh`, resulting in:

```bash
    #!/bin/bash
    # This is the new content of the file.
    # This is the second method to append contents to the file.
```

<br><br><br>

### 2.1.5 Overwriting with cat Command

```bash
    cat << 'EOF' > newFile.sh
    # Here we are adding text using cat command for multiple lines.
    # This is the second line using the cat command under multiple lines.
    EOF
```

**Description**: Using the `cat` command here (`<< 'EOF' ... EOF`) to replace the entire content of `newFile.sh` with multiple lines of text.
The `>` operator ensures that the file is overwritten with the new content.

**Output**: No immediate output. File Content: `newFile.sh` will contain:

```bash
    # Here we are adding text using the cat command for multiple lines.
    # This is the second line using the cat command under multiple lines.
```

<br><br><br>

### 2.1.6 Appending Multiple Lines with `cat` Command

```bash
    cat << 'EOF' >> newFile.sh
    '# Here we are adding text using cat command for multiple lines.
    # This is second line using the cat command under multiple lines.'
    EOF
```

**Description**: Appends multiple lines of text to `newFile.sh` using a cat command. The `>>` operator is used to add the text to the end of the file without overwriting existing content.

**Output**: No immediate output. Multiple lines are added to `newFile.sh`. File Content: `newFile.sh` will now include:

```bash
    # Here we are adding text using the cat command for multiple lines.
    # This is the second line using the cat command under multiple lines.
```

<br><br><br>

### 2.2 Viewing File Contents

### 2.2.1 Displaying File Contents

```bash
    cat newFile.sh
```

**Description**: Displays the current contents of `newFile.sh` in the terminal.

**Output**:

```bash
    #!/bin/bash
    # Here we are adding text using the cat command for multiple lines.
    # This is the second line using the cat command under multiple lines.
```

<br><br><br>

## 3. Notes

**File and Directory Listing**: Use `ls -F` to list files and directories in a directory. Directories will have a trailing slash (`/`), which helps distinguish them from regular files.

This version includes a summary at the beginning, a clear table of contents, and detailed explanations for each command, making it easy to follow and understand.
