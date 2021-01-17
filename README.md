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
- [ ] Input system
  - [X] Device interface
  - [X] Key interface
  - [X] Device factory
  - [X] ``GetDevice<T>``
  - [ ] ``Device.GetKey<T>``
  - [ ] Input Actions. Configured externally in file (JSON)
    - [ ] Button Actions (onDown, onUp, etc..)
    - [ ] Axis Actions (value, previous value)
  - [ ] Input Actions to be mapped to device name and element name (changed to int in runtime?)
  - [ ] Fast mapping of device name to device ref
- [ ] Gizmos
  - [ ] Gizmos shader
  - [ ] Gizmos drawer
- [ ] Component inspectors
- [ ] Camera rotation
- [ ] Camera translate GUI
- [ ] Save material as file
- [ ] Random utility

## Fixes
- [ ] Fix projection when res changed in runtime 
- [ ] Add libs for 64bit OpenGL