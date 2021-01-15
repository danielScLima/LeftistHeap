Leftist Heap
====================
Building with AppVeyor: [![Build status](https://ci.appveyor.com/api/projects/status/g3qynqmihjnhjwxt?svg=true)](https://ci.appveyor.com/project/DanielSLima/leftistheap)

Building with Travis: [![Build Status](https://www.travis-ci.com/danielScLima/LeftistHeap.svg?branch=master)](https://www.travis-ci.com/danielScLima/LeftistHeap)

This repository has a project with the implementation of a Leftist Heap.

It is written in C++.

The code of the Leftist Heap is independent of platform.

Is has two possible main files:

* [Codes](#markdown-header)
	* [A main that triggers unit test;](#markdown-header-emphasis)

	* [A Qt project to manage the Leftist Heap (With Gui).](#markdown-header-strikethrough)
	
The library used to make the Unit Test is the Catch v2.12.3. The code is already in this repository.

The Qt project generates images of the Leftist Heap, using the lib Graphviz.
Install this lib in your computer for you to be able to create such images.

The code was written containing the Doxygen documentation.

- - -

You have several options to build the project: 
====================

* [Build tools](#markdown-header)
	* [Makefile (using the file named MakefileGeneral);](#markdown-header-emphasis)
	* [CMake.](#markdown-header-emphasis)
	* [Qt Project (With QMake).](#markdown-header-emphasis)

The project has no leaks (Fully tested with Valgrind).

All the unit tests are ok.

- - -

The functionalities available are: 
====================

* [Functionalities](#markdown-header)
	* [Insert;](#markdown-header-emphasis)
	* [Search;](#markdown-header-emphasis)	
	* [Remove min;](#markdown-header-emphasis)
	* [Merge of two heaps;](#markdown-header-emphasis)
	* [Traverse types:](#markdown-header-emphasis)
		* [Pre-order;](#markdown-header-emphasis)
		* [in-order;](#markdown-header-emphasis)
		* [Pos-order;](#markdown-header-emphasis)
		* [In-level.](#markdown-header-emphasis)
	
- - -

Sample images (type of view 1): 
====================

![Alt text](images/sample11.png)

![Alt text](images/sample21.png)

- - -

Sample images (type of view 2): 
====================

![Alt text](images/sample12.png)

![Alt text](images/sample22.png)


Qt gui project: 
====================
The qt gui application gui is shown below:

![Alt text](images/guisample1.png)

![Alt text](images/guisample2.png)

![Alt text](images/guisample3.png)



Insertion steps (type of view 1): 
====================

## Initial:

![Alt text](images/insertion/0a.png)

## Inserting 50:

![Alt text](images/insertion/1a.png)

## Inserting 22:

![Alt text](images/insertion/2a.png)

## Inserting 30:

![Alt text](images/insertion/3a.png)

## Inserting 10:

![Alt text](images/insertion/4a.png)

## Inserting 40:

![Alt text](images/insertion/5a.png)

## Inserting 60:

![Alt text](images/insertion/6a.png)

## Inserting 70:

![Alt text](images/insertion/7a.png)

## Inserting 80:

![Alt text](images/insertion/8a.png)

## Inserting 90:

![Alt text](images/insertion/9a.png)

## Inserting 100:

![Alt text](images/insertion/10a.png)

## Inserting 110:

![Alt text](images/insertion/11a.png)



Insertion steps (type of view 2): 
====================

## Initial:

![Alt text](images/insertion/0b.png)

## Inserting 50:

![Alt text](images/insertion/1b.png)

## Inserting 22:

![Alt text](images/insertion/2b.png)

## Inserting 30:

![Alt text](images/insertion/3b.png)

## Inserting 10:

![Alt text](images/insertion/4b.png)

## Inserting 40:

![Alt text](images/insertion/5b.png)

## Inserting 60:

![Alt text](images/insertion/6b.png)

## Inserting 70:

![Alt text](images/insertion/7b.png)

## Inserting 80:

![Alt text](images/insertion/8b.png)

## Inserting 90:

![Alt text](images/insertion/9b.png)

## Inserting 100:

![Alt text](images/insertion/10b.png)

## Inserting 110:

![Alt text](images/insertion/11b.png)



Remove min samples (type of view 1): 
====================

## Initial:

![Alt text](images/removemin/0a.png)

## Removing:

![Alt text](images/removemin/1a.png)

## Removing:

![Alt text](images/removemin/2a.png)

## Removing:

![Alt text](images/removemin/3a.png)

## Removing:

![Alt text](images/removemin/4a.png)

## Removing:

![Alt text](images/removemin/5a.png)



Remove min samples (type of view 2): 
====================

## Initial:

![Alt text](images/removemin/0b.png)

## Removing:

![Alt text](images/removemin/1b.png)

## Removing:

![Alt text](images/removemin/2b.png)

## Removing:

![Alt text](images/removemin/3b.png)

## Removing:

![Alt text](images/removemin/4b.png)

## Removing:

![Alt text](images/removemin/5b.png)
