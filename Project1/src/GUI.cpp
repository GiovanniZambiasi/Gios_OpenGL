#include "GUI.h"

#include <string>



#include "Math.h"
#include "time.h"
#include "Window.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"

void Gio::GUI::Initialize(Window& window)
{
    ImGui::CreateContext();
    ImGui_ImplGlfwGL3_Init(window.GetGLFWWindow(), true);
    ImGui::StyleColorsDark();
}

void Gio::GUI::Clear()
{
    ImGui_ImplGlfwGL3_NewFrame();
}

void DrawDebugInfo()
{
    ImGui::Begin("Debug Info:");
    
    ImGui::Text("Debug:");
    //ImGui::SameLine();
    
    std::string string ="Time: " + std::to_string(Gio::Time::GetTimeSinceStartSeconds());
    ImGui::Text(string.c_str());
    
    string ="DeltaTime: " + std::to_string(Gio::Time::GetDeltaTimeSeconds());
    ImGui::Text(string.c_str());

    string ="FPS: " + std::to_string(Gio::Time::GetFPSApprox());
    ImGui::Text(string.c_str());

    ImGui::End();
}

void DrawSettingsWindow(bool& showDebugInfo)
{
    ImGui::Begin("Settings");
    ImGui::Checkbox("Show Debug Info", &showDebugInfo);
    ImGui::End();
}

void Gio::GUI::Draw()
{
    DrawSettingsWindow(_shouldShowDebugInfo);
    
    if(_shouldShowDebugInfo)
        DrawDebugInfo();
    
        
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

void Gio::GUI::Shutdown()
{
    ImGui_ImplGlfwGL3_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
}
