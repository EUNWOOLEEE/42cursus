# miniRT
My first RayTracer with miniLibX

## Summary
This project is an introduction to the beautiful world of Raytracing.  
Once completed you will be able to render simple Computer-Generated-Images and you will never be afraid of implementing mathematical formulas again.

## Install
__Directory__  
- mandatory : basic features  
- bonus : basic + additional features
```sh
make         # comfile ./miniRT
make clean   # remove temporary files
make fclean  # remove all files
make re      # make fclean and make
```

## Usage
```sh
./miniRT scene.rt
```

## Scene
**Ambient lightning** : `A 0.2 255,255,255`  
- ambient lighting ratio in range [0.0,1.0]: 0.2  
- R,G,B colors in range [0-255]: 255, 255, 255  
  
**Camera** : `C -50.0,0,20 0,0,1 70`  
- x,y,z coordinates of the view point: -50.0,0,20  
- 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0  
- FOV : Horizontal field of view in degrees in range [0,180]: 70  
  
**Light** : `L -40.0,50.0,0.0 0.6 10,0,255`  
- x,y,z coordinates of the light point: -40.0,50.0,0.0  
- the light brightness ratio in range [0.0,1.0]: 0.6  
- R,G,B colors in range [0-255]: 10, 0, 255 (unused in mandatory part)

**Specular reflection** : `SR 0.2`
- (unused in mandatory part)  
- ambient lighting ratio in range [0.0, 1.0]: 0.2  

**Sphere** : `sp 0.0,0.0,20.6 12.6 10,0,255`  
- x,y,z coordinates of the sphere center: 0.0,0.0,20.6  
- the sphere diameter: 12.6  
- R,G,B colors in range [0-255]: 10, 0, 255  
  
**Plane** : `pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225`  
- x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0  
- 3d normalized normal vector. In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0  
- R,G,B colors in range [0-255]: 0,0,225  

**Cylinder** : `cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255`  
- x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6  
- 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0  
- the cylinder diameter: 14.2  
- the cylinder height: 21.42  
- R,G,B colors in range [0,255]: 10, 0, 255  

**Cone** : `co 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10.0.255`  
- (unused in mandatory part)  
- x,y,z coordinates of a point in the cone: 50.0,0.0,20.6
- 3d normalized normal vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0  
- the cone diameter: 14.2  
- the cone height: 21.42 
- R,G,B colors in range [0,255]: 10, 0, 255  

### example : mandatory
```sh
A  0.5                              255,255,255
C  0,25,3    0,-1,-0.1    80
L  0,15,0                 0.5       255,255,255

cy 2,9,0     0,0,-1       1    1    255,255,255
cy 0,9,-2    0,1,-0.5     1    1    255,255,255
sp 0,0,0                  15        0,0,255
sp 0,9,0                  1         255,255,255
pl 0,-10,0   0,1,0                  255,255,255
```

### example : bonus
```sh
C 0,3,5         0,-0.05,-0.1   80
A 0.5                                  255,255,255
L 0,4,0                        0.3     255,0,0
L 2,2,2                        0.3     0,0,255
L -2,0,2                       0.3     0,255,0
SR 1

cy 0,0,0         0,1,0         1   2   255,255,255
pl 0,-2,0        0.1,0.9,0.1           255,255,255
sp 1.2,0.5,1                   1       255,255,255
sp -0.5,2,0                    1       255,255,255
co -1.5,-0.5,0   0,1,0         1   2   255,255,255

sp 1,3,3         20                    255,255,255
```
