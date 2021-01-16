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
- [ ] Input system
  - [X] Device interface
  - [X] Key interface
  - [X] Device factory
  - [X] ``GetDevice<T>``
  - [ ] ``Device.GetKey<T>``
  - [ ] Input Actions. Configured externally in file
  - [ ] Input Actions to be mapped to device key name
  - [ ] Fast mapping of device name to device ref
- [ ] Gizmos
  - [ ] Gizmos shader
  - [ ] Gizmos drawer
- [ ] Shader manager for shader reuse
- [ ] Component inspectors
- [ ] Camera rotation
- [ ] Camera translate GUI

## Fixes
- [ ] Fix projection when res changed in runtime 
- [ ] Add libs for 64bit OpenGL