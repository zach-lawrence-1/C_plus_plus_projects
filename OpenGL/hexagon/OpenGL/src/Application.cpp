#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>

static std::string ParseShader(const std::string& filePath)
{
    std::ifstream stream(filePath);
    std::stringstream data;
    std::string datastr = "";

    while (!stream.eof())
    {
        getline(stream, datastr);
        data << datastr << "\n";
    }
    stream.close();
    return data.str();
}

static unsigned int CompileShader(const std::string& source, unsigned int type)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    /*  error handling  */
    int result;
    //checks if opengl shader compiled correctly and stores true or false in result
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    if (result == GL_FALSE)
    {
        int length;
        //because compilation failed, we need to first store the length of the error log message and later use that for writing
        //message so we can see what went wrong
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = new char[length];

        //writes log data from previous get command to message char
        glGetShaderInfoLog(id, length, &length, message);
        //in the type == part, it is saying if type is equal to some opengl constant then print vertex, otherwise print
        //fragment. You could also just use simple if branch or even switch case statements depending on situation
        std::cout << "failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader" << std::endl;
        std::cout << message << std::endl;

        delete message;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

//returns a number for the shader similar to numbering buffers as we did in below code
static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(vertexShader, GL_VERTEX_SHADER);
    unsigned int fs = CompileShader(fragmentShader, GL_FRAGMENT_SHADER);

    //attach shaders we made to the glprogram
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);
	glDeleteShader(vs);
	glDeleteShader(fs);
    return program;
}

int main(void)
{
    unsigned int width = 500;
    unsigned int height = 500;
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    //sets version of opengl to 3.3 with core enabled
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, "Hexagon", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        std::cout << "error, something went wrong with glew";
    }

    std::cout << glGetString(GL_VERSION);

    float positions[] = {
         0.0f,  0.0f,  // 0
         0.5f,  0.0f,  // 1
         0.5f,  0.5f,  // 2
         0.0f,  0.5f,  // 3
        -0.5f,  0.0f,  // 4
        -0.5f, -0.5f,  // 5
         0.0f, -0.5f,  // 6
         0.0f, -1.0f,  // 7
         0.5f, -0.5f,  // 8
         0.5f, -1.0f,  // 9
         1.0f, -0.5f,  // 10
         1.0f, 0.0f    // 11
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0,
        3, 0, 4,
        4, 0, 5,
        0, 5, 6,
        0, 1, 6,
        5, 6, 7,
        6, 1, 8,
        6, 8, 7,
        8, 7, 9,
        9, 8, 10,
        8, 10, 1,
        1, 11, 10,
        1, 2, 11
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);

    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 12 * 2 * sizeof(float), positions, GL_STATIC_DRAW);

    //generates 1 vertex array, need to make one when using core opengl
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    //index buffer object
    unsigned int ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * 14 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    std::string vertexShader = ParseShader("res/shaders/BasicVertex.shader");
    std::string fragmentShader = ParseShader("res/shaders/BasicFragment.shader");

    unsigned int shader = CreateShader(vertexShader, fragmentShader);
    glUseProgram(shader);

    //finds location of Uniform in shader code
    unsigned int location = glGetUniformLocation(shader, "u_Color");
    glUniform4f(location, 0.4f, .7f, .7f, 1.0f);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, 42, GL_UNSIGNED_INT, nullptr);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(shader);

    glfwTerminate();
    return 0;
}