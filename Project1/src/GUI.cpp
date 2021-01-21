#include <string>
#include "GUI.h"

#include "Input.h"
#include "Scene.h"
#include "time.h"
#include "Window.h"
#include "InputSystem/IInputDevice.h"
#include "InputSystem/IInputElement.h"
#include "InputSystem/InputAction.h"
#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw_gl3.h"
#include "vendor/imgui/imgui_internal.h"

Gio::GUI::GUI(Scene& game, Window& window, Input& input,Renderer& renderer)
    : _window(window)
    , _game(game)
    , _input(input)
    , _renderer(renderer)
{
    _windowSize = _window.GetSize();
    
    ImGui::CreateContext();
    ImGui_ImplGlfwGL3_Init(window.GetGLFWWindow(), true);
    ImGui::StyleColorsDark();
}

Gio::GUI::~GUI()
{
    ImGui_ImplGlfwGL3_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
}

void Gio::GUI::Clear()
{
    ImGui_ImplGlfwGL3_NewFrame();
}

void DrawEntity(Gio::ECS::Entity* entity)
{
    ImGui::Text(entity->GetName().c_str());
    ImGui::SameLine();
    if(ImGui::Button("Delete"))
    {
        entity->Delete();
    }
}

void DrawEntities(Gio::Scene& game)
{
    std::vector<Gio::ECS::Entity*>& entities =  game.GetEntities();

    if(ImGui::Begin("Entities"))
    {
        ImGui::Text(("Count: " + std::to_string(entities.size())).c_str());
    
        if(ImGui::BeginChild("entities"))
        {
            ImGui::Indent(1);
    
            for (int i = entities.size() - 1; i >=0 ; i--)
            {
                ImGui::PushID(i);
                Gio::ECS::Entity* entity = entities[i];
                DrawEntity(entity);
                ImGui::PopID();
            }
        }
        
        ImGui::EndChild();
    }
    
    ImGui::End();
}

void Gio::GUI::Draw()
{
    DrawSettingsWindow();
    
    if(_shouldShowDebugInfo)
        DrawDebugInfo();
    
    if(_shouldShowEntities)
        DrawEntities(_game);

    if(_shouldShowInputDevices)
        DrawInputDevices();

    if(_shouldShowInputActions)
        DrawInputActions();
    
    if(_shouldShowInputAxes)
        DrawInputAxes();
    
    /*
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    
    // 1. Show a simple window.
    // Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets automatically appears in a window called "Debug".
    {
        static float f = 0.0f;
        static int counter = 0;
        ImGui::Text("Hello, world!");                           // Display some text (you can use a format string too)
        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f    
        ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

        ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our windows open/close state
        ImGui::Checkbox("Another Window", &show_another_window);

        if (ImGui::Button("Button"))                            // Buttons return true when clicked (NB: most widgets return true when edited/activated)
            counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    }*/
    
    ImGui::Render();
    ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
}

void DrawCamera()
{
    Gio::Transform& camTransform = Gio::Camera::instance->GetTransform();
    auto position = camTransform.GetPosition();

    ImGui::Text("Camera Position:");
    ImGui::Text(position.to_string().c_str());

    camTransform.SetPosition(position);
}

void Gio::GUI::DrawSettingsWindow()
{
    if(ImGui::Begin("Settings"))
    {
        ImGui::Checkbox("Debug Info", &_shouldShowDebugInfo);
        ImGui::Checkbox("Entities", &_shouldShowEntities);
        ImGui::Checkbox("Input Devices", &_shouldShowInputDevices);
        ImGui::Checkbox("Input Actions", &_shouldShowInputActions);
        ImGui::Checkbox("Input Axes", &_shouldShowInputAxes);

        ImGui::Separator();

        DrawCamera();
    
        ImGui::Separator();
    
        ImGui::Text("Video:");
        ImGui::Indent(10);

        int* _size = new int();

        (*_size) = _windowSize.width;
    
        ImGui::InputInt("Width", _size);

        _windowSize.width = *_size;

        (*_size) = _windowSize.height;
    
        ImGui::InputInt("Height", _size);

        _windowSize.height = *_size;

        delete _size;
    
        if(ImGui::Button("Apply"))
        {
            _window.SetSize(_windowSize);
        }

        ImGui::Separator();

        ImGui::InputText("Log", _log, 24);
    
        if(ImGui::Button("Test Log"))
        {
            Debug::Log(_log);
        }
    }
    
    ImGui::End();
}

void DrawInputElement(unsigned int index, Gio::InputSystem::IInputElement* element)
{
    float value = element->GetValue();
        
    ImVec4 color = value == 0.0f
                       ? ImVec4(1.0f, 1.0f, 1.0f, 1.0f)
                       : value > 0
                            ? ImVec4(.0f, .7f, .0f, 1.0f)
                            : ImVec4(.7f, .0f, .0f, 1.0f);

    std::string log = "[" + std::to_string(index) + "] " + element->GetName() + " (" + std::to_string(value) + ")";

    ImGui::TextColored(color, log.c_str());
}

void DrawInputDevice(int iteration, Gio::InputSystem::IInputDevice* device, std::vector<Gio::InputSystem::IInputElement*> elements, ImVec2 size)
{
    std::string index = std::to_string(iteration);
    
    ImGui::Text(("[" + index + "] " +  device->GetName()).c_str());

    if(ImGui::BeginChild(index.c_str(), size))
    {
        ImGui::Indent(10);
    
        device->GetElements(elements);
    
        for (auto j = 0; j < elements.size(); j++)
        {
            auto element = elements[j];

            DrawInputElement(j, element);
        }
    }
    
    ImGui::EndChild();
}

void Gio::GUI::DrawInputDevices()
{
    if(ImGui::Begin("Input Devices:"))
    {
        _devices.clear();
    
        Input::GetDeviceManager()->GetDevices(_devices);

        int devicesPerPage = Gio::Math::Clamp(_devices.size(), 1, 2);
    
        auto currentWindowSize = ImGui::GetCurrentWindow()->Size;
    
        float windowHeightPerDevice = currentWindowSize.y / devicesPerPage;

        ImVec2 deviceDisplaySize = ImVec2(currentWindowSize.x - 25, windowHeightPerDevice);
    
        for(int i = 0; i < _devices.size(); i++)
        {
            InputSystem::IInputDevice* device = _devices[i];

            _inputElements.clear();

            if(i != 0)
                ImGui::Separator();
        
            DrawInputDevice(i, device, _inputElements, deviceDisplaySize);
        }
    }
    ImGui::End();
}

void DrawInputAction(Gio::InputSystem::InputAction& action)
{
    ImVec4 color = action.IsPressed()
            ? ImVec4(.0f, .7f, .0f, 1.0f)
            : ImVec4(1.0f, 1.0f, 1.0f, 1.0f);

    ImGui::TextColored(color, action.GetName().c_str());

    ImGui::Indent(20);
    std::vector<Gio::InputSystem::IInputElement*> inputElements;
    action.GetElements(inputElements);

    for (auto i = 0; i < inputElements.size(); i++)
    {
        auto element = inputElements[i];
        DrawInputElement(i, element);
    }

    ImGui::Unindent();
}

void Gio::GUI::DrawInputActions()
{
    if(ImGui::Begin("Input Actions:"))
    {
        std::vector<InputSystem::InputAction*> actions;

        Input::GetActionManager()->GetActions(actions);

        for(auto i = 0; i < actions.size(); i++)
        {
            auto action = actions[i];
            if(i != 0)
                ImGui::Separator();

            DrawInputAction(*action);
        }
    }
    
    ImGui::End();
}

void DrawInputAxis(Gio::InputSystem::InputAxis& axis)
{
    float value = axis.GetValue();

    ImVec4 color = value == 0.0f
                       ? ImVec4(1.0f, 1.0f, 1.0f, 1.0f)
                       : value > 0
                            ? ImVec4(.0f, .7f, .0f, 1.0f)
                            : ImVec4(.7f, .0f, .0f, 1.0f);
                            
    std::string entry = axis.GetName() + " (" + std::to_string(value) + ")";
    
    ImGui::TextColored(color, entry.c_str());

    ImGui::Indent(20);
    
    ImGui::Text("+");
    
    ImGui::Indent(10);
    
    std::vector<Gio::InputSystem::IInputElement*> inputElements;
    axis.GetPositiveContributors(inputElements);

    for (auto i = 0; i < inputElements.size(); i++)
    {
        auto element = inputElements[i];
        DrawInputElement(i, element);
    }

    ImGui::Unindent(10);
    
    ImGui::Text("-");
    
    ImGui::Indent(10);

    inputElements.clear();
    axis.GetNegativeContributors(inputElements);

    for (auto i = 0; i < inputElements.size(); i++)
    {
        auto element = inputElements[i];
        DrawInputElement(i, element);
    }
    
    ImGui::Unindent(10);
    
    ImGui::Unindent();
}

void Gio::GUI::DrawInputAxes()
{
    if(ImGui::Begin("Input Axes:"))
    {
        std::vector<InputSystem::InputAxis*> axes;

        Input::GetActionManager()->GetAxes(axes);

        for(int i = 0; i < axes.size(); i++)
        {
            auto axis = axes[i];
        
            if(i != 0)
                ImGui::Separator();

            DrawInputAxis(*axis);
        }
    }
    
    ImGui::End();
}

void Gio::GUI::DrawDebugInfo()
{
    if(ImGui::Begin("Debug Info:"))
    {
        ImGui::Text(("Time: " + std::to_string(Gio::Time::GetTimeSinceStartSeconds())).c_str());
    
        ImGui::Text(("DeltaTime: " + std::to_string(Gio::Time::GetDeltaTimeSeconds())).c_str());

        ImGui::Text(("FPS: " + std::to_string(Gio::Time::GetFPSApprox())).c_str());

        ImGui::Text(("Draw calls: " + std::to_string(_renderer.GetDrawCalls())).c_str());
    
        ImGui::Text(("Triangles: " + std::to_string(_renderer.GetTriangleCount())).c_str());
    }
    
    ImGui::End();
}