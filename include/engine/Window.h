//
// Created by andre on 2025-11-30.
//

#ifndef GAMEREVAMP_WINDOW_H
#define GAMEREVAMP_WINDOW_H

#include <string>
struct GLFWwindow;

class Window {
public:
    //constructor to create window
    Window(int w, int h, const std::string &title);

    //destructor to clean up window
    ~Window();

    //check if window should close
    bool shouldClose() const;

    //swap buffers
    void swapBuffers() const;

    //poll events ie keyboard mouse events
    void pollEvents() const;

    void processInput() const;

    //getters
    int getWidth() const;

    int getHeight() const;

    GLFWwindow *getGlfwWindow() const;

    // Set callback for framebuffer resize
    static void framebufferSizeCallBack(GLFWwindow *window, int width, int height);

private:
    int width, height;
    std::string title;
    GLFWwindow *window;
};


#endif //GAMEREVAMP_WINDOW_H
