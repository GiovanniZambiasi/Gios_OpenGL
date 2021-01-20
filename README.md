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
- [ ] Gizmos
  - [ ] Gizmos shader
  - [ ] Gizmos drawer
- [ ] Component inspectors
- [ ] Camera rotation
- [ ] Camera translate GUI
- [ ] Save material as file
- [ ] Separate modules so that:
  - They're all accessible to the dev via static interface classes (like ``Renderer::Draw`` or ``Input::GetDevice``)
  - Their implementation is actually concrete, but hidden (like ``OpenGLRenderer`` or ``GLFWInput``)
  - The static interface classes are initialized by the application with a specialized concrete implementation (``Input::Initialize(new GLFWInput())``)
- [ ] Simple collision component
- [ ] View Culling

## Fixes
- [ ] Fix projection when res changed in runtime 
- [ ] Add libs for 64bit OpenGL