# TailF Implementation in C++

A lightweight implementation of the Linux `tail -f` command in C++. The program continuously monitors a file and prints newly appended lines in real time.

## Features

- Monitor file changes continuously
- Print newly appended lines
- Efficient file offset tracking
- Reads the last lines before entering monitoring mode
- Cross-platform C++ implementation

## Tech Stack

- C++17
- File Streams (`fstream`)
- Multithreading
- Chrono Library

## How It Works

1. Opens the target file.
2. Moves the file pointer to the end.
3. Reads the last few lines.
4. Continuously checks whether the file size has increased.
5. If new content is detected, reads and prints only the appended lines.

## Project Structure

```
.
├── main.cpp
├── sample.txt
└── README.md
```

## Build

```bash
g++ main.cpp -o tailf -std=c++17
```

## Run

```bash
./tailf
```

Append text to `sample.txt` from another terminal:

```bash
echo "New log entry" >> sample.txt
```

The application will immediately display the new line.

## Future Improvements

- Use Linux `inotify` instead of polling
- Support command-line arguments
- Configurable polling interval
- Handle log rotation
- Support configurable number of initial lines

## Concepts Used

- File I/O
- Stream Positioning
- Polling
- Multithreading
- Chrono Library
- Linux Utilities
