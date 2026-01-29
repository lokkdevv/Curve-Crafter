# CurveCrafter

**CurveCrafter** is a terminal-based tool that visualizes mathematical functions in real-time. It plots functions like quadratics, sine waves, linear, and more directly in the console. Making it both an educational and visually satisfying experience.

---

## Features

- Real-time function plotting  
- Flicker-free double-buffered console rendering  
- Supports quadratic and linear functions  

---

## Getting Started

### Requirements

- Windows OS (currently only supports Windows console)  
- C compiler (e.g., `gcc`, `cl`, or any IDE that supports C compilation)  

> Note: Unix / Linux / macOS support may be added in future versions.

---

### Compiling

Using **GCC**:

```bash
cd ./src
gcc -o CurveCrafter main.c
```
Using **MSVC** (Visual Studio Developer Command Prompt):
```bash
cd ./src
cl /Fe:CurveCrafter.exe main.c
```
Using **MAKE**:
```bash
make
```
## Running
- After compiling, run the program from the terminal:
```bash
./bin/CurveCrafter
```
- To give it input add a string after the program name when running it, example:
```bash
./bin/CurveCrafter "2x^2+4x+7"
```

## Future Plans
- Add support for Unix/Linux/macOS terminals

- Allow multiple functions to be plotted simultaneously


## License
MIT License
