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
git clone https://github.com/Rashidk-907/ProcessManager.git
cd ProcessManager
make
```

## Usage

```bash
./Pshell
```

## Example
```
# Start a process
pshell > run ls
[ls] started (PID: 1234)

# List running processes
pshell > list
  ls  →  Running (PID: 1234)

# Send input and read output
pshell > run cat /bin/cat
[cat] started (PID: 1235)
pshell > send cat hello world
pshell > output cat
hello world

# Stop a process
pshell > stop cat
[cat] stopped

# Exit
pshell > exit
exit
```
