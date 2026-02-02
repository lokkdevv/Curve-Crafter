# CurveCrafter

**CurveCrafter** is a terminal-based tool that visualizes mathematical functions. It’s split into 2 parts, a very basic cli game-engine and a very basic math parser, so the project can be taken appart to take and use any tool you want.

---

## Features

- Real-time function plotting  
- Flicker-free double-buffered console rendering  
- Has a tiny CLI game-engine included

---

## Getting Started

### Requirements
- Windows SDK (Only till unix support is added)

- Windows OS (currently only supports Windows console)  
- C compiler (e.g., `gcc`, `cl`, or any IDE that supports C compilation)  

> Note: Unix / Linux / macOS support may be added in future versions.

---

### Compiling
Using **MAKE** on windows:
```bash
make win
```
Using **MAKE** on unix:
```bash
make unix
```
## Running
- After compiling, run the program from the terminal:
```bash
./bin/CurveCrafter
```
- To give it input add a string after the program name when running it, example:
```bash
./bin/CurveCrafter "2*x*x+4*x+7"
```

## Future Plans
- Add support for Unix/Linux/macOS terminals

- Allow multiple functions to be plotted simultaneously


## License
MIT License
