# rechecker
Simple C++ regex checker

For those, who really tired to fix regexes in C++.

Build: just clone repository and make.

Example

```
$> rechecker --regex "([0-9A-Za-z_-])(\\.([0-9A-Za-z_-]))?" main.cpp README.md Makefile
"main.cpp" match "([0-9A-Za-z_-]+)(\.([0-9A-Za-z_-]+))?"
	main.cpp
	main
	.cpp
	cpp
"README.md" match "([0-9A-Za-z_-]+)(\.([0-9A-Za-z_-]+))?"
	README.md
	README
	.md
	md
"Makefile" match "([0-9A-Za-z_-]+)(\.([0-9A-Za-z_-]+))?"
	Makefile
	Makefile
	
	

```
