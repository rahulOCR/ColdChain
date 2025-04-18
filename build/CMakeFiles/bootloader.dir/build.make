# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/techeagle/ESP_PROJECT/Projects/TempController

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/techeagle/ESP_PROJECT/Projects/TempController/build

# Utility rule file for bootloader.

# Include the progress variables for this target.
include CMakeFiles/bootloader.dir/progress.make

CMakeFiles/bootloader: CMakeFiles/bootloader-complete


CMakeFiles/bootloader-complete: bootloader-prefix/src/bootloader-stamp/bootloader-install
CMakeFiles/bootloader-complete: bootloader-prefix/src/bootloader-stamp/bootloader-mkdir
CMakeFiles/bootloader-complete: bootloader-prefix/src/bootloader-stamp/bootloader-download
CMakeFiles/bootloader-complete: bootloader-prefix/src/bootloader-stamp/bootloader-update
CMakeFiles/bootloader-complete: bootloader-prefix/src/bootloader-stamp/bootloader-patch
CMakeFiles/bootloader-complete: bootloader-prefix/src/bootloader-stamp/bootloader-configure
CMakeFiles/bootloader-complete: bootloader-prefix/src/bootloader-stamp/bootloader-build
CMakeFiles/bootloader-complete: bootloader-prefix/src/bootloader-stamp/bootloader-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/techeagle/ESP_PROJECT/Projects/TempController/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'bootloader'"
	/usr/bin/cmake -E make_directory /home/techeagle/ESP_PROJECT/Projects/TempController/build/CMakeFiles
	/usr/bin/cmake -E touch /home/techeagle/ESP_PROJECT/Projects/TempController/build/CMakeFiles/bootloader-complete
	/usr/bin/cmake -E touch /home/techeagle/ESP_PROJECT/Projects/TempController/build/bootloader-prefix/src/bootloader-stamp/bootloader-done

bootloader-prefix/src/bootloader-stamp/bootloader-install: bootloader-prefix/src/bootloader-stamp/bootloader-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/techeagle/ESP_PROJECT/Projects/TempController/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No install step for 'bootloader'"
	cd /home/techeagle/ESP_PROJECT/Projects/TempController/build/bootloader && /usr/bin/cmake -E echo_append
	cd /home/techeagle/ESP_PROJECT/Projects/TempController/build/bootloader && /usr/bin/cmake -E touch /home/techeagle/ESP_PROJECT/Projects/TempController/build/bootloader-prefix/src/bootloader-stamp/bootloader-install

bootloader-prefix/src/bootloader-stamp/bootloader-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/techeagle/ESP_PROJECT/Projects/TempController/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'bootloader'"
	/usr/bin/cmake -E make_directory /home/techeagle/ESP_PROJECT/esp-idf/components/bootloader/subproject
	/usr/bin/cmake -E make_directory /home/techeagle/ESP_PROJECT/Projects/TempController/build/bootloader
	/usr/bin/cmake -E make_directory /home/techeagle/ESP_PROJECT/Projects/TempController/build/bootloader-prefix
	/usr/bin/cmake -E make_directory /home/techeagle/ESP_PROJECT/Projects/TempController/build/bootloader-prefix/tmp
	/usr/bin/cmake -E make_directory /home/techeagle/ESP_PROJECT/Projects/TempController/build/bootloader-prefix/src/bootloader-stamp
	/usr/bin/cmake -E make_directory /home/techeagle/ESP_PROJECT/Projects/TempController/build/bootloader-prefix/src
	/usr/bin/cmake -E make_directory /home/techeagle/ESP_PROJECT/Projects/TempController/build/bootloader-prefix/src/bootloader-stamp
	/usr/bin/cmake -E touch /home/techeagle/ESP_PROJECT/Projects/TempController/build/bootloader-prefix/src/bootloader-stamp/bootloader-mkdir

bootloader-prefix/src/bootloader-stamp/bootloader-download: bootloader-prefix/src/bootloader-stamp/bootloader-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/techeagle/ESP_PROJECT/Projects/TempController/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "No download step for 'bootloader'"
	/usr/bin/cmake -E echo_append
	/usr/bin/cmake -E touch /home/techeagle/ESP_PROJECT/Projects/TempController/build/bootloader-prefix/src/bootloader-stamp/bootloader-download

bootloader-prefix/src/bootloader-stamp/bootloader-update: bootloader-prefix/src/bootloader-stamp/bootloader-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/techeagle/ESP_PROJECT/Projects/TempController/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No update step for 'bootloader'"
	/usr/bin/cmake -E echo_append
	/usr/bin/cmake -E touch /home/techeagle/ESP_PROJECT/Projects/TempController/build/bootloader-prefix/src/bootloader-stamp/bootloader-update

bootloader-prefix/src/bootloader-stamp/bootloader-patch: bootloader-prefix/src/bootloader-stamp/bootloader-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/techeagle/ESP_PROJECT/Projects/TempController/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "No patch step for 'bootloader'"
	/usr/bin/cmake -E echo_append
	/usr/bin/cmake -E touch /home/techeagle/ESP_PROJECT/Projects/TempController/build/bootloader-prefix/src/bootloader-stamp/bootloader-patch

bootloader-prefix/src/bootloader-stamp/bootloader-configure: bootloader-prefix/tmp/bootloader-cfgcmd.txt
bootloader-prefix/src/bootloader-stamp/bootloader-configure: bootloader-prefix/src/bootloader-stamp/bootloader-update
bootloader-prefix/src/bootloader-stamp/bootloader-configure: bootloader-prefix/src/bootloader-stamp/bootloader-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/techeagle/ESP_PROJECT/Projects/TempController/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Performing configure step for 'bootloader'"
	cd /home/techeagle/ESP_PROJECT/Projects/TempController/build/bootloader && /usr/bin/cmake -DSDKCONFIG=/home/techeagle/ESP_PROJECT/Projects/TempController/sdkconfig -DIDF_PATH=/home/techeagle/ESP_PROJECT/esp-idf -DIDF_TARGET=esp32 -DPYTHON_DEPS_CHECKED=1 -DPYTHON=/home/techeagle/.espressif/python_env/idf5.3_py3.8_env/bin/python -DEXTRA_COMPONENT_DIRS=/home/techeagle/ESP_PROJECT/esp-idf/components/bootloader -DPROJECT_SOURCE_DIR=/home/techeagle/ESP_PROJECT/Projects/TempController -DIGNORE_EXTRA_COMPONENT= "-GUnix Makefiles" /home/techeagle/ESP_PROJECT/esp-idf/components/bootloader/subproject
	cd /home/techeagle/ESP_PROJECT/Projects/TempController/build/bootloader && /usr/bin/cmake -E touch /home/techeagle/ESP_PROJECT/Projects/TempController/build/bootloader-prefix/src/bootloader-stamp/bootloader-configure

bootloader-prefix/src/bootloader-stamp/bootloader-build: bootloader-prefix/src/bootloader-stamp/bootloader-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/techeagle/ESP_PROJECT/Projects/TempController/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Performing build step for 'bootloader'"
	cd /home/techeagle/ESP_PROJECT/Projects/TempController/build/bootloader && $(MAKE)

bootloader: CMakeFiles/bootloader
bootloader: CMakeFiles/bootloader-complete
bootloader: bootloader-prefix/src/bootloader-stamp/bootloader-install
bootloader: bootloader-prefix/src/bootloader-stamp/bootloader-mkdir
bootloader: bootloader-prefix/src/bootloader-stamp/bootloader-download
bootloader: bootloader-prefix/src/bootloader-stamp/bootloader-update
bootloader: bootloader-prefix/src/bootloader-stamp/bootloader-patch
bootloader: bootloader-prefix/src/bootloader-stamp/bootloader-configure
bootloader: bootloader-prefix/src/bootloader-stamp/bootloader-build
bootloader: CMakeFiles/bootloader.dir/build.make

.PHONY : bootloader

# Rule to build all files generated by this target.
CMakeFiles/bootloader.dir/build: bootloader

.PHONY : CMakeFiles/bootloader.dir/build

CMakeFiles/bootloader.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bootloader.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bootloader.dir/clean

CMakeFiles/bootloader.dir/depend:
	cd /home/techeagle/ESP_PROJECT/Projects/TempController/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/techeagle/ESP_PROJECT/Projects/TempController /home/techeagle/ESP_PROJECT/Projects/TempController /home/techeagle/ESP_PROJECT/Projects/TempController/build /home/techeagle/ESP_PROJECT/Projects/TempController/build /home/techeagle/ESP_PROJECT/Projects/TempController/build/CMakeFiles/bootloader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bootloader.dir/depend

