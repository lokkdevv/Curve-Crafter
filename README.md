# Curve Crafter

        _________                              _________                _____  __                 
        \_   ___ \ __ ____________  __ ____    \_   ___ \____________ _/ ____\/  |_  ___________  
        /    \  \/|  |  \_  __ \  \/ // __ \   /    \  \/\_  __ \__  \\   __\\   __\/ __ \_  __ \ 
        \     \___|  |  /|  | \/\   /\  ___/   \     \____|  | \// __ \|  |   |  | \  ___/|  | \/ 
         \______  /____/ |__|    \_/  \___  >   \______  /|__|  (____  /__|   |__|  \___  >__|    
            \/                        \/          \/            \/                 \/             


**Curve Crafter** is a terminal based C project combining:

- A math function grapher
- A mini CLI game engine

Each part can be used independently, making it easy to repurpose for other projects or experiments.

---

## Features

- Graphing calculator capabilities via command line input
- Flicker free, double-buffered console rendering
- Mini CLI game engine for simple terminal games

---

## Requirements
- Windows OS / Unix OS
- Windows SDK  `// If using windows OS`
- C compiler (`gcc`, `cl`, etc)

## Compiling
**Graphing Calculator**
- Windows:
```bash
make win 
```

- linux:
```bash
make linux
```
**CLI pong game**
- Windows:
```bash
make win_pong
```

- linux:
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
- Multiple functions plotted simultaneously
- More optimization

_Contributions are welcome!_ Open an issue or submit a pull request if you want to help.


## License
- MIT License
