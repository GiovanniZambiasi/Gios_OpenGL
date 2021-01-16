#include <string>
#include "GUI.h"
#include "Game.h"
#include "time.h"
#include "Window.h"
#include "Input/IInputDevice.h"
#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw_gl3.h"
#include "vendor/imgui/imgui_internal.h"

Gio::GUI::GUI(Game& game, Window& window, Input::Input& input)
    : _window(window)
    , _game(game)
    , _input(input)
{   
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

void DrawDebugInfo()
{
    ImGui::Begin("Debug Info:");
    
    std::string string ="Time: " + std::to_string(Gio::Time::GetTimeSinceStartSeconds());
    ImGui::Text(string.c_str());
    
    string ="DeltaTime: " + std::to_string(Gio::Time::GetDeltaTimeSeconds());
    ImGui::Text(string.c_str());

    string ="FPS: " + std::to_string(Gio::Time::GetFPSApprox());
    ImGui::Text(string.c_str());

    ImGui::End();
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

void DrawEntities(Gio::Game& game)
{
    ImGui::Begin("Entities");

    std::vector<Gio::ECS::Entity*>& entities =  game.GetEntities();
    
    ImGui::Indent(1);
    
    for (int i = entities.size() - 1; i >=0 ; i--)
    {
        Gio::ECS::Entity* entity = entities[i];
        DrawEntity(entity);
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

    if(_shouldShowInput)
        DrawInputDevices();
    
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

void Gio::GUI::DrawSettingsWindow()
{
    ImGui::Begin("Settings");
    ImGui::Checkbox("Debug Info", &_shouldShowDebugInfo);
    ImGui::Checkbox("Entities", &_shouldShowEntities);
    ImGui::Checkbox("Input Devices", &_shouldShowInput);

    ImGui::Separator();
    
    ImGui::Text("Video:");
    ImGui::Indent(10);
    
    ImGui::InputInt("Width", &_windowWidth);
    
    ImGui::InputInt("Height", &_windowHeight);

    if(ImGui::Button("Apply"))
    {
        _window.SetSize(_windowWidth, _windowHeight);
    }
    
    ImGui::End();
}

void DrawInputDevice(int iteration, Gio::Input::IInputDevice* device, std::vector<Gio::Input::IInputElement*> elements, ImVec2 size)
{
    std::string index = std::to_string(iteration);
    
    ImGui::Text(("[" + index + "] " +  device->GetName()).c_str());

    ImGui::BeginChild(index.c_str(), size);
    
    ImGui::Indent(10);
    
    device->GetElements(elements);
    
    for (int j = 0; j < elements.size(); j++)
    {
        auto element = elements[j];

        ImVec4 color = element->IsPressed()
            ? (element->WasPressedThisFrame() ? ImVec4(.0f, .0f, .7f, 1.0f) : ImVec4(.0f, .7f, .0f, 1.0f))
            : (element->WasReleasedThisFrame() ? ImVec4(1.0f, 0.0f, 0.0f, 1.0f) : ImVec4(1.0f, 1.0f, 1.0f, 1.0f));

        std::string log = "[" + std::to_string(j) + "] " + element->GetName();

        ImGui::TextColored(color, log.c_str());
    }

    ImGui::EndChild();
}

void Gio::GUI::DrawInputDevices()
{
    ImGui::Begin("Input Devices:");

    _devices.clear();
    _input.GetDevices(_devices);

    int devicesPerPage = Gio::Math::Clamp(_devices.size(), 1, 2);
    
    auto currentWindowSize = ImGui::GetCurrentWindow()->Size;
    
    float windowHeightPerDevice = currentWindowSize.y / devicesPerPage;

    ImVec2 deviceDisplaySize = ImVec2(currentWindowSize.x - 25, windowHeightPerDevice);
    
    for(int i = 0; i < _devices.size(); i++)
    {
        Input::IInputDevice* device = _devices[i];

        _inputElements.clear();

        if(i != 0)
            ImGui::Separator();
        
        DrawInputDevice(i, device, _inputElements, deviceDisplaySize);
    }

    ImGui::End();
}
