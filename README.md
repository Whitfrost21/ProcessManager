# Process Manager

A simple command-line tool to manage external processes in C++.

## What it does

- Start and stop processes
- Send input to running processes
- Read output from processes
- List all running processes
- Built with C++17, uses Linux system calls (fork, execvp, pipe)

## Requirements

- Linux (or WSL on Windows)
- C++17 compiler (g++ 7+)
- Make

## Building

```bash
git clone <your-repo-url>
cd ProcessManager
make