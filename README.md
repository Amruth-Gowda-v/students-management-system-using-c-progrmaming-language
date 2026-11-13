# Student Management System in C

A console-based student record management program written in C. It stores student details in an in-memory array and provides menu options for managing records.

## Features visible in the source

- Add a student record
- Display stored student records
- Search by roll number
- Update a student record
- Delete a student record
- Save records to a text file
- Load records from a text file

Student records include a name, age, roll number, percentage, and grade.

## Requirements

- A C compiler such as GCC
- A terminal or command prompt

## Compile

```bash
gcc sms.c -o student_management
```

## Run

On Linux or macOS:

```bash
./student_management
```

On Windows:

```powershell
student_management.exe
```

## Data storage

The program uses a local text file named `datafile.txt` for saving and loading records. Run the program from a directory where it can create and access this file.

## Notes

This is a learning project using structures, arrays, functions, pointers, console input/output, and basic file handling. Review input validation and file-format handling before using it with important records.
