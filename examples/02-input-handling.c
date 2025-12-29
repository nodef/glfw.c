// This example demonstrates handling keyboard and mouse input using GLFW.
#define GLFW_IMPLEMENTATION
#include <GLFW/glfw3.h>
#include <stdio.h>

// Key callback function
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        printf("Key pressed: %d\n", key);
    } else if (action == GLFW_RELEASE) {
        printf("Key released: %d\n", key);
    }
}

// Mouse button callback function
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (action == GLFW_PRESS) {
        printf("Mouse button pressed: %d\n", button);
    } else if (action == GLFW_RELEASE) {
        printf("Mouse button released: %d\n", button);
    }
}

// Cursor position callback function
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    printf("Cursor position: (%.2f, %.2f)\n", xpos, ypos);
}

int main(void) {
    // Initialize the library
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(640, 480, "Input Handling", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Set input callbacks
    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Render here (clear the screen)
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Clean up and exit
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
