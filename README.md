# Curve Crafter

        _________                              _________                _____  __                 
        \_   ___ \ __ ____________  __ ____    \_   ___ \____________ _/ ____\/  |_  ___________  
        /    \  \/|  |  \_  __ \  \/ // __ \   /    \  \/\_  __ \__  \\   __\\   __\/ __ \_  __ \ 
        \     \___|  |  /|  | \/\   /\  ___/   \     \____|  | \// __ \|  |   |  | \  ___/|  | \/ 
         \______  /____/ |__|    \_/  \___  >   \______  /|__|  (____  /__|   |__|  \___  >__|    
            \/                        \/          \/            \/                 \/             


**CurveCrafter** is a terminal-based C project combining:

- A mini CLI game engine
- A math function parser & real-time plotting tool

Each part can be used independently, making it easy to repurpose for other projects or experiments.

---

## Features

- Real-time function plotting of mathematical expressions
- Flicker-free, double-buffered console rendering
- Mini CLI game engine for simple terminal games
- Graphing calculator capabilities via command-line input

---

## Requirements
- Windows OS (Unix/macOS support coming soon)
- Windows SDK
- C compiler (`gcc`, `cl`, or any IDE that supports C compilation)

## Compiling
**Graphing Calculator**
- Windows:
```bash
make win 
```

- linux: (not supported yet):
```bash
make linux
```
**CLI pong game**
- Windows:
```bash
make win_pong
```

- linux: (not supported yet):
```bash
make linux_pong
```
## Running
After compiling, run from the terminal and pass a mathematical expression as an argument:
```bash
./bin/CurveCrafter "2*x*x+4*x+7"
```
To run the pong game you can either open it as any regular exe or open it via terminal:
```bash
./bin/Pong
```

## Future Plans
- Cross-platform terminal support (Unix/Linux/macOS)
- Multiple functions plotted simultaneously
- Expand the CLI game engine with reusable modules

_Contributions are welcome!_ Open an issue or submit a pull request if you want to help.


## License
- MIT License
