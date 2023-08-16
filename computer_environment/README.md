# Getting started

You will need to install several programs. This folder contains programs and batch scripts to setup the correct computing environment. These tools are setup for Windows. Equivalent tools exist for Mac or Linux, but you'll have to install your own. 



## install git

If you are just getting started, copy `install_git.bat` to your local machine from https://github.com/usafa-astro-331/astro-331-2023-fall/tree/main/computer_environment

Verify file contents using a text editor. You should do this before running any script. This script runs two commands using Windows' built-in command `winget` to install `git` and `tortoisegit`.  Complete setup of both programs. 

- **git**: version control software

- **TortoiseGit**: windows integration for git



## clone the course repository

Copy the path to the course repository: https://github.com/usafa-astro-331/astro-331-2023-fall/

Go to My Documents. Do not create a new course folder yet. 

Right click -> Git clone

Paste the course URL and click OK. 



## install tools

Go to the `computer_environment` directory. 

- Verify the contents of `install_tools.bat` (right click -> edit)
  - This batch script uses Windows’ built-in `winget` command line package management tool to install several programs you will use in the course. 
    - **Arduino IDE**
    - **arduino-cli** a scriptable command line tool for managing arduino boards and libraries
    - **marktext**: a markdown editor/viewer that you will use to view lab instructions
    - **teraterm**: a serial terminal you will use to power your ground station
    -  **notepad++**: a useful text editor

- After you’ve verified, double-click `install_tools.bat` to run it 



## update arduino

Verify and run `update_arduino.bat` which updates the Arduino IDE/environment using the `arduino-cli` tool

- updates Arduino environment

- installs drivers for newer SAMD-based Arduino boards such as Arduino MKR Zero



## update the course

This step is not necessary if you just cloned the course repository. 

**This step should be performed before every lab to ensure you're using updated material.** 

- Right click the course folder (or any location within the course folder). 
- Git Sync -> Pull




# before each lab

- Pull latest changes from course repository
  - Right click the course folder (or any location within the course folder). 
  - Git Sync -> Pull
- Update Arduino environment using `install_libraries.bat` found in that lab's folder

