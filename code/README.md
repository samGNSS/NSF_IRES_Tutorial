## Building
To build the code, assuming you've cloned the repo and are using Linux, open a terminal and move to this location. The directory will look
like: 'your paths'/NSF_IRES_Tutorial/code/

Once here run the following commands:
```
mkdir build && cd build #make a build directory and move into it
cmake .. #run cmake using the cmake lists up one directory
make #run make
sudo make install #install
sudo ldconfig
```

## Potential Problems
If after installing, you can't run the blocks in the GNURADIO companion try adding pythons site-packages to your python path.
This can be done in python as follows:
```
import sys;sys.path.append(/--your site-packages location---/)
```

The location of your site-packages my vary, on Ubuntu 16.04 mine is: /usr/local/lib/python2.7/site-packages
