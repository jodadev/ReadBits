# Update Log

    The log displays from latest to old. 

## Patch v1.0.2

### Fixes
- When converting directly in console(option 2), anything after a space is ignored. Needed to use getline() since we have spaces and then use ignore() to ensure no skipping inputs.  
- Minor re-wording of strings.
- Minor refactors to Program.cpp, binary_encoding.cpp, file_manager.cpp, log.cpp, input.cpp

### Updates
- Added option to add spaces in between binaries in both the console and file converting (option 1 and 2).
- Removed asking "Terminate program?" after each task is complete.
- Added print() method to log.cpp with an option to remove line break (adds by default)
- Updated Readme .txt file to .md file as well Update_log .txt to .md

## Patch v1.0.1

### Fixes
- Input::get_boolean_input() print was not utilizing the msg argument. 
- Call to Input::get_boolean_input() from program on line 29 passed the wrong string data.
- Small corrections with logic. 

### Updates
- Added menu and selections.
- Now you can convert data within the program without getting it from file.
- Added ability to save the binary code to file or just have it displayed.
