# fractol_pub
The public version of my fractol project for 42.
Most of the history is missing because the norminette require to put your name in the header, meaning i would need to rebase the entire history and change all the headers. I might do it if I find a way to automate this, but for now only the source code is available.

# Dependecies
- make
- c compiler
- [minlibx's dependencies](https://github.com/42Paris/minilibx-linux/tree/7dc53a411a7d4ae286c60c6229bd1e395b0efb82) (linux version included as submodule)
  - xorg
  - xext-dev
  - libbsd-dev
- My libft (included as submodule)

# Compilation
Get the source code, go to the folder and do `make`

# Usage
`./fractol <fractal_name> [<parameters>]`  
example :
- `./fractol mandelbrot`
- `./fractol julia -0.8 0.1`

## parameters
Currently only julia fractals accept and require 2 parameters, which are the real part and imaginary part of the `c` constant.

# Controls
- WASD/Arrow keys : move the view around  
- Left click : Center the view around the potition that was clicked
- Right click : Change the `c` constant to the corresponding point on the complex plane.
  - Will switch a fractal to it's julia counterpart if the current fractal is not a julia fractal already
- F3 : Toggle smooth rendering algorithm (slower) (not all fractals have one implemented) (still experimental, contains bugs)
- F5 : switch color palette
- F6 : increase palette offset
- F7 : go to next fractal
- F8 : vertical flip
- F9 : horizontal flip
- p/m increase/decrease the power of 2 used in calculation for julia/mandelbrot (starts at 2)
- o/l increase the decrease the level of metandelbrot/metajulia (starts at 1)
- i/k increase/decrease the power used in calculation for julia/mandelbrot by `0.01` (starts at 2)

## Debugging features
- F1 : Toggle "Turning number view" (slower)
- F2 : Show chunks boundaries
- F4 : Show rendered chunks boundaries (refresh to update properly)

