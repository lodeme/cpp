#!/bin/bash

# Paths to the log files
LOG1="19920104_091532.log"
LOG2="new.log"

# Temporary files to store the logs with ignored parts
TMP_LOG1="tmp_log1.txt"
TMP_LOG2="tmp_log2.txt"

# Use sed to remove everything until the first space and store the results in temporary files
sed 's/^[^ ]* //' "$LOG1" > "$TMP_LOG1"
sed 's/^[^ ]* //' "$LOG2" > "$TMP_LOG2"

# Compare the files with the ignored parts
diff "$TMP_LOG1" "$TMP_LOG2"

# Clean up temporary files
#rm "$TMP_LOG1" "$TMP_LOG2"

