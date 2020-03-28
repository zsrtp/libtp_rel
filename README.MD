# Welcome to libtp

Hi! This is a library written in **C/C++** specifically for **The Legend of Zelda: Twilight Princess**
This project contains all the mandatory tools to create a custom REL for TP but is primarily designed to grant easy access to symbols without unreadable, manual RAM access.

# Contributors

Credits for implementing Custom RELs go to [Piston Miner](https://github.com/PistonMiner)

Main contributors are
* [AECX](//github.com/AECX)
* [Zephiles](//github.com/Zephiles)

## Filesystem Structure
	assets/
		// Additional data and code
		eu.lst	// Lists that resolve
		jp.lst	// symbols to their
		us.lst	// respective RAM address
	bin/
		elf2rel		// Compiled elf2rel for UNIX/Linux systems
		elf2rel.exe	// Windows version
		gcipack.py	// Script to generate a valid GCI
	include/
		// Header files
		gc/
			// GC Specific headers (dolphin OS)
		tp/
			// TP Specific headers
	source/
		// General purpose function source files
	.clang-format	// rules for clang-format
	format.sh	// Runs the formatter for all files


## Coding guidelines
Please refer to [this](https://dev.tpspeed.run/guidelines) document
