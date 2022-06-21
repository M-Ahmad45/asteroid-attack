# asteroid-attack
Asteroid Attack is inspired by the 1979 classic *Asteroids*
It is still in development, or to be more precise in the drawing board phase.

## How to build
I am making it on Ubuntu and support for Windows will probably take some time.
To build the the game first open up the terminal and install the SDL2 libraries.

`sudo apt install libsdl2-dev`
`sudo apt install libsdl2-image-dev`
`sudo apt install libsdl2-mixer-dev`
`sudo apt install libsdl2-ttf-dev`

Now that you have the necessary libraries installed, go ahead and clone the repo.
You need to have *gcc* and *make* installed before build.
Once cloned, go into the folder where you clonned it then run
`make all`
If everything went properly you can now simply do
```
cd bin
./main
```
