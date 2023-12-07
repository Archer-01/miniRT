# miniRT

miniRT is a simple ray tracer written in C that can render complex scenes with various shapes and lighting effects.

## Features

- Render scenes with planes, spheres, cylinders, and cones.
- Handle all possible intersections between objects correctly.
- Resize object properties such as diameter for spheres and width/height for cylinders.
- Apply translation and rotation transformations to objects, lights, and cameras.
- Light management with spot brightness, hard shadows, and ambiance lighting.
- Ambient, diffuse, and specular lighting using the Phong reflection model.
- Display images in a window with the ability to close cleanly using ESC or the red cross.
- Color disruption with a checkerboard pattern.
- Colored and multi-spot lights.
- Textures for added visual detail.

## Usage

The program takes a scene description file with the .rt extension as the first argument.

```bash
make FAST=1 && ./miniRT scene.rt
```

## Scene Description File

The scene description file (.rt) defines the elements of the scene using the following syntax:

### Ambient Lighting
```
A intensity red,green,blue
```
### Camera
```
C PositionX,PositionY,PositionZ OriginX,OriginY,OriginZ fieldOfView
```
### Light
```
L x,y,z brightness r,g,b
```
### Sphere
```
sp x,y,z d r,g,b shininess,diffuse,specular [ch:r,g,b|tx:/path/to/texture/file.png]
```
### Plane
```
pl x,y,z ox,oy,oz r,g,b shininess,diffuse,specular [ch:r,g,b|tx:/path/to/texture/file.png]
```
### Cylinder
```
cy x,y,z ox,oy,oz d h r,g,b shininess,diffuse,specular [ch:r,g,b|tx:/path/to/texture/file.png]
```
### Cone
#### Cone with two sides
```
cn x,y,z ox,oy,oz d h r,g,b shininess,diffuse,specular [ch:r,g,b|tx:/path/to/texture/file.png]
```
#### Cone with one side
```
cnh x,y,z ox,oy,oz d h r,g,b shininess,diffuse,specular [ch:r,g,b|tx:/path/to/texture/file.png]
```
### Comments
Use `#` for single line comments.
```
# This is a valid comment
A 1 255,255,255 # but this is invalid
```
## Example scene
```
# Ambient
A 1 184,232,252

# Camera
C 0,0,-5 0,0,1 50

# Lights
L -10,10,-10 0.7 255,255,255

# Planes
pl 0,-1,0 0,1,0 255,255,255 200,1,0

# Cones
cnh 0,-1,0 0,1,0 1 1.5 255,255,255 200,1,0 tx:textures/waffle.png

# Spheres
sp 0,0.6,0 1 255,255,255 200,1,0 tx:textures/strawberry.png
```
