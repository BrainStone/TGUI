![Logo](logo.png)

# Text-GUI-Library - A C++17 alternative for ncurses

Are you sick and tired of the old ncurses interface?<br />
Do you just want to build an CLI application that has a decently usable GUI?<br />
Are you dreaming of a modern OO-interface that is easy to use?

**Worry no more!**<br />
This library provides just that!

## Table of Content

* [Features](#features)
* [Installing](#installing)
* [Documentation](#documentation)
* [Copyright and License](#copyright-and-license)
  + [Copyright](#copyright)
  + [License](#license)

## Features

Here are the features:
- Built for modern C++17
- Simple OO-API
- Expandable with custom classes and elements
- Minimal console output. (Only changed parts of the console will get printed)
- Customizable

## Installing

To install simply run the following commands:<br />
*Note for Windows: Replace `./gradlew` with `gradlew.bat`*

    git clone https://github.com/BrainStone/TGUI
    cd TGUI
    ./gradlew build
    # Actuall installation still WIP!

The compiled binaries will be located in the subdirectories of `build/libs`.

Of course make sure you have a C++11 compiler *(See
[the gradle doc](https://docs.gradle.org/3.4.1/userguide/native_software.html#native-binaries:tool-chain-support)
to see which compilers are supported on your system)*, Java (required for gradle) and `git` installed.

## Documentation

The full documentation can be found at https://doc.brainstonemod.com/TGUI/.<br />
You can also download the documentation in [HTML](https://doc.brainstonemod.com/TGUI/downloads/TGUI-doc.zip) (zipped) or
[PDF](https://doc.brainstonemod.com/TGUI/downloads/TGUI-doc.pdf) format.

You can also generate the documentation locally. However [`doxygen`](http://www.stack.nl/~dimitri/doxygen/) needs to be
installed. [`graphviz`](http://www.graphviz.org/), [`make`](https://www.gnu.org/software/make/) and
[`latex`](https://www.latex-project.org/) is not required but recommended. To generate the documentation locally run this
command:

    ./gradlew doc

You will then find a `TGUI-doc.zip` file and if you have `latex` installed a `TGUI-doc.pdf` file in the `build/doc`
directory.

## Copyright and License

### Copyright
Copyright 2017 [Yannick Schinko](https://github.com/BrainStone). All rights reserved

### License
TGUI is licensed under the [GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0.html)
