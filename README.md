# Gios_OpenGL
Gio's OpenGL is an API I'm working on as an OpenGL and c++ study
<br><br>
NOTES: Currently setup for 32 bit (x86), so use that configuration in the IDE
## To-dos
- [X] Debug window
- [X] Logger
- [X] ECS
- [X] Rendering pipeline
- [X] Time and deltaTime
- [X] Vector structs and maths
- [X] Create wrapper for Mesh
- [X] Create wrapper for Material
- [X] Shader manager for shader reuse
- [X] Random utility
- [X] Make scenes dynamic so that the dev can run the application with a custom scene class
- [X] Input system
  - [X] Device interface
  - [X] Key interface
  - [X] Device factory
  - [X] ``GetDevice<T>``
  - [X] ``Device.GetKey<T>``
  - [X] Input Actions. Configured externally in file (JSON)
    - [X] Button Actions (onDown, onUp, etc..)
    - [X] Axis Actions (value, previous value)
  - [X] Input Actions to be mapped to device name and element name
  - [ ] Implement Joystick
- [X] Spawning of entities in realtime
- [X] Camera translate GUI
- [ ] Gizmos
  - [ ] Gizmos shader
  - [ ] Gizmos drawer
- [ ] Component inspectors
- [ ] Camera rotation
- [ ] Save material as file
- [ ] Simple collision component
- [ ] View Culling
- [ ] Batch Rendering
- [ ] Add fullscreen support
- [ ] 3D?
- [ ] **UNIT TESTING**

## Fixes
- [X] Fix projection when res changed in runtime 
- [ ] Add libs for 64bit OpenGL
- [ ] Fix scaling so 1x1 represents more screen space

## Refactors
- [X] Input system to be broken down into device manager and action manager
- [ ] Window to be abstracted and contain a reference to an interface (``IWindowBackend`` or so) of a concrete implementation (GLFW)
- [ ] Renderer to have an extra layer of abstraction to allow for other rendering apis
- [ ] Separate App funcionality (Window, WindowSize, Application, etc..) from the api core (Transform, Vector, Math, etc..)
  - [ ] Move "ECS" into core namespace