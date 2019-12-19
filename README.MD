# Welcome to libtp

Hi! This is a library written in **C/C++** specifically for **The Legend of Zelda: Twilight Princess**
This project contains all the mandatory tools to create a custom REL for TP but is primarily designed to grant easy access to symbols without unreadable, manual RAM access.

## Structure
	include/
		gc/
			// GC Specific headers (dolphin OS)
		tp/
			// TP Specific headers
			eu.lst // Lists that resolve
			jp.lst // symbols to their
			us.lst // respective RAM address
		...
		// General purpose function headers
	source/
		// General purpose function source files
	tools/
		elf2rel // Compiled elf2rel for UNIX/Linux systems
		elf2rel.exe // Windows version
		gcipack.py // Script to generate a valid GCI
	


## Coding guidelines
The code should be [**clang-formatted**](https://clang.llvm.org/docs/ClangFormat.html) and contain [**c-style** doxygen](https://www.cs.cmu.edu/~410/doc/doxygen.html) comments for documentation.

You can find clang [here](https://releases.llvm.org/download.html) (I use 3.7.0) install it and when asked whether you want clang to be in your `path` select **Yes** and you should have access to the command `clang-format`
