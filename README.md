<p align="center">
  <h1 align="center">C++ CLI File Manager </h1>
</p>
<p align="center">
  A colorful and intuitive C++ command-line tool to manage files and folders effortlessly.
</p>

<div align="center">
  <img src="https://img.shields.io/badge/code-C++-blue.svg" />
  <img src="https://img.shields.io/badge/status-active-brightgreen.svg" />
  <img src="https://img.shields.io/github/languages/count/Mareczech321/CPP_CLI_File_Manager.svg" />
  <img src="https://img.shields.io/github/last-commit/Mareczech321/CPP_CLI_File_Manager.svg" />
</div>

---

## Table of Contents

- [Overview](#overview)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

---

## Overview

**File Manager CLI** is a lightweight, beginner-friendly C++ application designed to help users manage files and directories through a simple terminal interface. With ANSI color support and \`std::filesystem\`, it offers a modern and interactive CLI experience.

---

## Getting Started

### Prerequisites

- C++17 or later
- A terminal that supports ANSI escape codes (Windows 10+, macOS, Linux)
- A C++ compiler like \`g++\` or MSVC

### Installation

1. Clone the repository:

~~~bash
git clone https://github.com/Mareczech321/FileManagerCLI.git
cd FileManagerCLI
~~~

2. Compile the project:

~~~bash
g++ main.cpp -o filemanager -std=c++17
~~~

3. Run the tool:

~~~bash
./filemanager
~~~

> On Windows:
~~~bash
filemanager.exe
~~~

---

## Usage

The application supports the following actions:

- **List files**: View all files in a given folder  
- **Create file**: Generate a new empty file  
- **Delete file**: Remove a file after confirmation  
- **Rename file**: Change the name of an existing file  
- **Help**: View usage instructions  
- **Exit**: Close the application  

---

## Features

- ✅ Colorful CLI with ANSI escape codes  
- ✅ Input validation and error handling  
- ✅ Safe file operations using \`std::filesystem\`  
- ✅ Portable and easy to compile  
- ✅ Default path fallback if no folder is specified  
- ✅ Works on Windows, macOS, and Linux  

---

## Project Structure

~~~plaintext
/
├── main.cpp        ← core logic of the file manager
├── colors.cpp      ← ANSI color utility function
├── colors.h        ← (optional) header for color declarations
├── README.md       ← this file
~~~

---

## Future Work

This project currently serves as a robust command-line backend for file management. 

A natural next step would be to develop a graphical user interface (GUI) that interacts with this backend, providing a more user-friendly experience. The modular design of the codebase allows for easy integration with various GUI frameworks such as Qt, wxWidgets, or even web-based frontends using Electron or similar technologies.

This separation of concerns enables developers to extend functionality without modifying the core logic, fostering maintainability and scalability.

---

## Contributing

1. Fork this repository  
2. Create a new branch: \`feature/your-feature\`  
3. Commit your changes  
4. Open a Pull Request  

---

## License

This project is open source and available under the [MIT License](LICENSE).

---

## Contact

For ideas, bugs, or contributions:

- GitHub: [@Mareczech321](https://github.com/Mareczech321)  
- Or open an issue in the repo
EOF
