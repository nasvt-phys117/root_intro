# root_intro
A repo with simple root projects.

## ROOT - Installation
I am using the latest version provided in the conda-forge repository. The following steps will guide you through the installation process.

1. Download [anaconda](https://www.anaconda.com/download) for Linux and install it using `bash Anaconda3-your-version.sh` in the folder where you downloaded the installer.
2. Use the `export` or `source` command to show your computer where to find the new python installation: `export PATH="/home/your_username/anaconda3/bin:$PATH"` or `source /home/your_username/anaconda3/bin/activate`. There's probably a better way to do that which modifies your `.bashrc` using the command `conda init` but I had some issues in the past and I am scared to use that. For `conda init` to take effect, we need to restart the terminal so it can load the modified `.bashrc` file (or just source ~/.bashrc).
3. Update your conda installation: `conda update --all`
4. Install ROOT using the following set of commands:
```
conda config --set channel_priority strict
conda create -c conda-forge --name <my-root-environment-name> root
```
where you replace the `<...>` with the name of your choice.
5. Activate the new environment using
```
conda activate <my-root-environment-name>
```

## How to compile from source
To compile C++ source files that make use of root libraries we use the following:
```
g++ myprogram.C -o myprogramOUT $(root-config --glibs --libs --cflags)
```
Note: the environment we installed above comes with an appropriate version of gcc installed so we do not need to install anything else in our system.
## List of projects
Note:The root files used can be found in this [link](https://drive.proton.me/urls/ZTKCF9QSV0#3xaoTK32Ai3y).

1. **Size of root files**. This progamme determines the size of the different branches of a rootfile of a particular structure.
2. **Make class tutorial**. A small introduction to the Make Class command and its uses. We print histograms from a file using different methods.
3. **Small analysis**. Configure objects, apply cuts, make histograms.