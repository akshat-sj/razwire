# razwire

the wire renderer version of my 3d graphics engine raz made with the help of SDL2.

## Getting Started

### Running the program


run the makefile with the make command

```console
make
```
now add your own .obj file to the models folder or use of the existing models. run the main.exe generated using main models/object_name.obj

```console
main models/object_name.obj
```

now give the rgb values to get the color of the lines we want

```console
r_value g_value b_value
```
this will now create a new sdl window with the object rendered

## Examples of objects we have rendered


### human head 
<img width="236" alt="man" src="https://github.com/akshat-sj/razwire/blob/main/assets/man.png">

### gun 

<img width="818" alt="gun" src="https://github.com/akshat-sj/razwire/blob/main/assets/gun.png">


## Built With

* [C++](https://isocpp.org/) - the programming language used
* [SDL2](https://www.libsdl.org/) - library used for basic graphical rendering (drawing lines, generating a window etc.)


