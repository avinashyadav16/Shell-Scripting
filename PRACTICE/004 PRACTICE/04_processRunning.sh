#!/bin/bash

# 4. Write a shell script to display the processes running on the system
# for every 30 seconds, but only for 3 times.

# Loop that runs 3 times
for i in {1..3}; do
    # 'ps' command displays the list of running processes on the system
    ps

    # Sleep for 30 seconds before running the next iteration
    sleep 30

done
