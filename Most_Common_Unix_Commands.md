# Most Basic Linux Commands:

`linux` `LinuxCommands` `SysAdmin` `DeveloperTips` `LinuxTips` `DevOps` `CodingLife` `CommandLine` `LinuxTutorial` `bash` `devops`

| **Command**   | **Description**                                                                                               | **Example Command**               |
| ------------- | ------------------------------------------------------------------------------------------------------------- | --------------------------------- |
| 📂 `pwd`      | Print working directory.                                                                                      | `pwd`                             |
| 📋 `ls`       | List directory contents.                                                                                      | `ls`                              |
| 📋 `ls -l`    | List directory contents in long format, showing details like permissions, owner, size, and modification date. | `ls -l`                           |
| 📋 `ls -lt`   | List directory contents in long format, sorted by modification time, most recent first.                       | `ls -lt`                          |
| 📋 `ls -f`    | List directory contents without sorting, displaying files and directories as they appear in the directory.    | `ls -f`                           |
| 📋 `ls -F`    | List directory contents without sorting, displaying files and directories followed with '/'.                  | `ls -f`                           |
| 📋 `ls -R`    | List directory contents recursively, including all subdirectories.                                            | `ls -R`                           |
| 📁 `cd`       | Change directory.                                                                                             | `cd /Sports/Cricket/`             |
| 📄 `touch`    | Create a file without any content.                                                                            | `touch newfile.txt`               |
| 🐱 `cat`      | Concatenate and display file content.                                                                         | `cat filename.txt`                |
| 📁📂 `cp`     | Copy files or directories.                                                                                    | `cp file1.txt /backup/`           |
| 🔄 `mv`       | Move or rename files or directories.                                                                          | `mv oldname.txt newname.txt`      |
| 🗑️ `rm`       | Remove files or directories.                                                                                  | `rm unwantedfile.txt`             |
| 📁 `mkdir`    | Create a new directory.                                                                                       | `mkdir new_directory`             |
| 📁🗑️ `rmdir`  | Remove an empty directory.                                                                                    | `rmdir empty_directory`           |
| 📢 `echo`     | Display a line of text or a variable value.                                                                   | `echo "Hello, World!"`            |
| ✏️ `nano`     | A simple text editor.                                                                                         | `nano filename.txt`               |
| ✒️ `vi`       | A powerful text editor.                                                                                       | `vi filename.txt`                 |
| 🔐 `chmod`    | Change file or directory permissions.                                                                         | `chmod a+x script.sh`             |
| 👤 `chown`    | Change file or directory owner and group.                                                                     | `chown user:user file.txt`        |
| 🔍 `find`     | Search for files in a directory hierarchy.                                                                    | `find /mnt/c/Users -name "*.txt"` |
| 🔎 `grep`     | Search text using patterns.                                                                                   | `grep "search_term" file.txt`     |
| 📖 `man`      | Display the manual for a command.                                                                             | `man ls`                          |
| 🔄 `ps`       | Display information about running processes.                                                                  | `ps aux`                          |
| 📊 `top`      | Display and update sorted information about processes.                                                        | `top`                             |
| 📊 `htop`     | Interactive process viewer for Unix systems. Provides real-time CPU, memory usage, and process details.       | `htop`                            |
| ⚰️ `kill`     | Terminate processes by PID.                                                                                   | `kill 1234`                       |
| 💾 `df`       | Report file system disk space usage.                                                                          | `df -h`                           |
| 📏 `du`       | Estimate file space usage. Shows the disk space used by files and directories.                                | `du`                              |
| 📏 `du -h`    | Estimate file space usage in human-readable format (e.g., KB, MB, GB).                                        | `du -h`                           |
| 📏 `du -d 1`  | Limit the depth of directories shown in the output.                                                           | `du -d 1 /path/to/directory`      |
| 📏 `du -k`    | Display disk usage in kilobytes.                                                                              | `du -k`                           |
| 📏 `du -m`    | Display disk usage in megabytes.                                                                              | `du -m`                           |
| 📏 `du -g`    | Display disk usage in gigabytes.                                                                              | `du -g`                           |
| 📏 `du`       | Estimate file space usage.                                                                                    | `du -sh *`                        |
| 📏 `du -sh`   | Summarize the disk usage of a directory in human-readable format.                                             | `du -sh /path/to/directory`       |
| 🧠 `free`     | Display memory usage.                                                                                         | `free -m`                         |
| ℹ️ `uname`    | Print system information.                                                                                     | `uname -a`                        |
| ⏳ `uptime`   | Tell how long the system has been running.                                                                    | `uptime`                          |
| 👤 `whoami`   | Display the current user.                                                                                     | `whoami`                          |
| 📦 `zip`      | Package and compress (archive) files.                                                                         | `zip archive.zip file.txt`        |
| 📂 `unzip`    | Extract compressed files.                                                                                     | `unzip archive.zip`               |
| 🌐 `wget`     | Retrieve files from the web.                                                                                  | `wget http://example.com/file`    |
| 🏠 `hostname` | Show or set the system's host name.                                                                           | `hostname`                        |
| 🌐 `netstat`  | Print network connections, routing tables, and interface statistics.                                          | `netstat -tuln`                   |
| 🌐 `ifconfig` | Configure a network interface.                                                                                | `ifconfig`                        |
| 🌐 `ip`       | Show/manipulate routing, devices, policy routing, and tunnels.                                                | `ip addr show`                    |
| 📂 `mount`    | Mount a file system.                                                                                          | `mount /dev/sda1 /mnt`            |
| 📂 `umount`   | Unmount a file system.                                                                                        | `umount /mnt`                     |
| 🔍 `locate`   | Find files by name using a pre-built index.                                                                   | `locate filename`                 |
| 🔄 `updatedb` | Update the database used by locate.                                                                           | `updatedb`                        |
| 📜 `history`  | Display the command history.                                                                                  | `history`                         |
| 📜 `less`     | View file content one screen at a time.                                                                       | `less filename.txt`               |
| 📜 `more`     | View file content one screen at a time.                                                                       | `more filename.txt`               |
