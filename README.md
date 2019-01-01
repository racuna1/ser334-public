# Introduction
This repository contains public files for use in SER334 (Operating Systems & Networks) taught by Lecturer Ruben Acuña at Arizona State University. This repository stores practice exams and sample problems used in the course.

The content associated with the most recent offering of the course can be downloaded from the "release" tab. Note that if you are currently taking the course, the files provided to you on course website, or on the master branch, will be more up to date than last official release.

## Units
This course is divided into sections of material called units. Each of these units focuses on a topic in operating systems. A typical course offering includes 12 units of material (named: Unit 1, ..., Unit 12).

Note that the specific units covered may vary between semesters. All existing units are made available on this repository regardless of whether they are used in the current offering. See the table below. Units which are marked with "_opt_" in the internal ID are optional in the current offering of the course.

Each unit has an internal ID (e.g., unit1, opt_module_spp3), a title, and a reference source. The internal ID is used as a unique identifier for a unit in the file name. (This ID may or may not match the specific unit number used in a course offering.) The title is the name used for the unit of content. The reference indicates the primary book or website source for the content.

| Internal ID      | Title                       | Reference                                |
|------------------|-----------------------------|------------------------------------------|
| unit1            | C Programming I             | N/A                                      |
| unit2            | C Programming II            | N/A                                      |
| unit3            | Operating-System Structures | OSC: Chapter 2 (Operating-System Structures) |
| unit4            | Processes                   | OSC: Chapter 3 (Processes)               |
| unit6            | Threads                     | OSC: Chapter 4 (Threads)                 |
| unit7            | Process Synchronization I   | OSC: Chapter 5 (Process Synchronization) |
| unit8            | Process Synchronization II  | OSC: Chapter 5 (Process Synchronization) |
| unit9            | CPU Scheduling              | OSC: Chapter 6 (CPU Scheduling)          |
| unit10           | Main Memory                 | OSC: Chapter 8 (Main Memory)             |
| unit11           | Virtual Memory              | OSC: Chapter 9 (Virtual Memory)          |
| unit12           | Mass-Storage Structure      | OSC: Chapter 10 (Mass-Storage), TSC: Chapter 2 (TCP Sockets) |
| opt_module_osc7  | Deadlocks                   | OSC: Chapter 7 (Deadlocks)               |
| opt_module_spp3  | Parallel Programming        | SPP: Chapter 3 (Patterns)                |

Abbreviations:
* OSC: Operating System Concepts by Silberschatz, Galvin, and Gagne.
* SSP: Structured Parallel Programming by McCool, Robison, and Reinders. [available online from ASU Library]
* TSC: TCP/IP Sockets in C by Donahoo, and Calvert. [available online from ASU Library]

## Practice Exams
(These files are optional and intended for advanced students. During courses, these practice exams are provided as prints and/or PDFs.)

This repository contains sample exams for SER334. Each practice exam contains problems which match the units on exams that will be conducted. These practice exams are half length, meaning they contain approximate half the number of questions of a real exam. Problems are similar in scope and difficulty to what appears on real exams but will not be "the same questions with different numbers". The questions should be to gauge how well you perform on the type of questions that may appear, and on the topics that the exam(s) will cover.

These practice exams are provided without answers. You are encouraged to speak with the instructor or teaching assistants about the questions when enrolled in the class.

## Sample Problems
(These files are optional and intended for advanced students. During courses, these problems are provided as prints and/or PDFs.)

 This repository contains the sample problem sets used in SER334, which is taught using a problem-centric approach. These problem sets cover many different topics in Operating Systems (Units 3 to 12), as well as C programming (Units 1 to 2). Answers are provided for all questions. They are intended to enable a more active approach to learning, where students may attempt the problems and then check their answers, rather than seeing material passively. 

 As preparation to full (graded) exercise sets, students should attempt these sample problems and self-assess their answers based on the provided solutions. Each problem set indicates specific questions which are required. These questions touch on critical concepts and will appear on exercises/homework/exams. Although some problems are not required, that does NOT mean you are not required to be able to solve them. If you are taking the course, you should have the ability to work every problem given.

These questions are publicly available for several reasons:
1) To enable students to report issues with the prompts or answers.
2) To enable the continuous improvement of sample problems throughout the semester.
3) To enable students and support staff access to material before it is used in class.

Many of the questions are aligned with the material in Operating-System Concepts by Silberschatz, Galvin, and Gagne. Students taking a similar course at another university may find these worked problems useful.

### Dependencies
* [LyX](https://www.lyx.org/) 2.3.x or greater must be installed.
* (optional) [yEd](https://www.yworks.com/products/yed) 3.17 or greater must be installed.

The sample questions are provided in LyX. LyX is a WYSIWYG editor which wraps Latex, a programming language typically used to typeset mathematical texts.

Most of the diagrams are provided in graphml format. Since LyX does not natively support graphml files, we convert them to PNG. We suggest using yEd to view and edit the graphml files, and then exporting them to PNG before building the complete PDF with LyX. Since the images are already provided as PNGs, yEd is only needed for those wanting to edit diagrams.

### Viewing
In order to view the problems, you will need to install LyX on your system, and compile the LyX file(s) to a PDF.

Every LyX file contains two LyX branches: "blank", and "soln". By default, the "blank" branch is selected. This will cause Lyx to build the output PDF with blank spaces for you to fill in your answers. Deactivating the blank branch and activating the soln one will produce a PDF with the answers.

### Building
A build script (build.py) is also provided. Running this file will automatically produce PDFs for the practice exams and sample problems (both blank and solution) in the build subdirectory. Note that LyX must be available in the system PATH.

### Reporting Issues
If you find an error in a question answer, please use the issue tracker to report it.

Issues should be named with the following pattern: "Unit [N]: Sample Problems: Q[#] [problem]", where N is the unit number, # is the question number, and [problem] is the general issue category (e.g., correction, clarification, etc.) Use the issue text field to describe the specific problem.

Note that issues are not the place to ask for additional explanation of an answer, instead you should contact the instructional staff for your course. Answers are intended to be concise and similar to what would be given as a written answer in class. 

### Contributing
Users of this material are welcome to fork the repository and make upstream pull requests. See the issue tracker for available work. Please note that making a pull request will be taken as permission to use your contribution under our license.

If you are interested in making a more substantial contribution, such as writing original problems, you should apply for a SER334 UGTA position.

### Authors
* Ruben Acuna
* Tanner Lisonbee
* Natallia Karaliova
* Alireza Bahremand
* Jonathan Bush
* Marcinina Alvaran