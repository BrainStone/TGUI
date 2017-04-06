![Logo](logo.png)

# Text-GUI-Library - A C++11 alternative for ncurses

Are you sick and tired of the old ncurses interface?<br />
Do you just want to build an CLI application that has a decently usable GUI?<br />
Are you dreaming of a modern OO-interface that is easy to use?

**Worry no more!**<br />
This library provides just that!

## Features

Here are the features:
- Built for modern C++11
- Simple OO-API
- Expandable with custom classes and elements
- Minimal console output. (Only changed parts of the console will get printed)
- Customizable

## Installing

To install simply run the following commands

    git clone https://github.com/BrainStone/TGUI
    cd TGUI
    make
    sudo make install

Of course make sure you have `sudo`, `g++`, `make` and `git` installed.

## Documentation

The full documentation can be found at https://doc.brainstonemod.com/TGUI/.<br />
You can also download the documentation in [HTML](https://doc.brainstonemod.com/TGUI/downloads/TGUI-doc.zip) (zipped) or
[PDF](https://doc.brainstonemod.com/TGUI/downloads/TGUI-doc.pdf) format.

You can also generate the documentation locally. However [`doxygen`](http://www.stack.nl/~dimitri/doxygen/) needs to be
installed. [`graphviz`](http://www.graphviz.org/) and [`latex`](https://www.latex-project.org/) is not required but
recommended. To generate the documentation locally run this command:

    make doc
    
You will then find a `TGUI-doc.zip` file and if you have `latex` installed a `TGUI-doc.pdf` file in the base directory.

## Legal Stuff

### Copyright
Copyright 2017 Yannick Schinko. All rights reserved

### License
TGUI is licensed under the GNU General Public License v3.0
