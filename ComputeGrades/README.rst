**************
Compute Grades
**************

.. contents::
    :local:
    :depth: 1
    :backlinks: none

========
Synopsis
========
Parses input file grades and makes necessary calculations to determine the overall grade. The number of assignments (by category) and percentage weightings are already initialized and can be changed as needed. The output will be generated upon running the program. 

===============
Getting Started
===============
Make sure you have an input file following this format (separate numerical values with spaces)::

	First: 
	Last: 
	Attendances: <0 or 1>
	Labs: 
	Projects: 
	Midterm: 
	Final:

=====================
Compiling and Running
=====================
Linux::

	g++ -std=c++11 computegrades.cpp -o cg
	./cg


Windows (e.g. PowerShell)::

	cl /Ehsc /c computegrades.cpp 
	link /out:cg.exe computegrades.obj
	./cg.exe
