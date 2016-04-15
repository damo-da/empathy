/**
 * Parts of this file are from the OpenGL Programming wikibook: http://en.wikibooks.org/wiki/OpenGL_Programming
 * This file is in the public domain.
 * Contributors: Sylvain Beucler
 */
#include "shader_utils.h"


#include "../Utils/file_utils.h"

/**
 * Display compilation errors from the OpenGL shader compiler
 */
void print_gl_error_log(GLuint object)
{
  GLint log_length = 0;
  if (glIsShader(object))
    glGetShaderiv(object, GL_INFO_LOG_LENGTH, &log_length);
  else if (glIsProgram(object))
    glGetProgramiv(object, GL_INFO_LOG_LENGTH, &log_length);
  else {
    fprintf(stderr, "printlog: Not a shader or a program\n");
    return;
  }

  char* log = (char*)malloc(log_length);

  if (glIsShader(object))
    glGetShaderInfoLog(object, log_length, NULL, log);
  else if (glIsProgram(object))
    glGetProgramInfoLog(object, log_length, NULL, log);

  fprintf(stderr, "%s", log);
  free(log);
}

/**
 * Compile the shader from file 'filename', with error handling
 */
GLuint create_shader(const std::string fileName, GLenum type)
{
	const GLchar* shaderCode = file_read(fileName.c_str());

	//create shader
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &shaderCode, NULL);
	glCompileShader(shader);

	//check if shader compiled successfully
	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
        print_gl_error_log(shader);

		return 0;
	}

	return shader;
}

GLuint emCreateFragmentShader(std::string fileName) {
    return create_shader(fileName,GL_FRAGMENT_SHADER);
}
GLuint emCreateVertexShader(std::string fileName) {
    return create_shader(fileName,GL_VERTEX_SHADER);
}



GLuint create_program(const std::string vertexfile, const std::string fragmentfile) {
    GLuint vertexShader=emCreateVertexShader(vertexfile);
    GLuint fragmentShader=emCreateFragmentShader(fragmentfile);
    return create_program(vertexShader,fragmentShader);
}


GLuint create_program(GLuint vertexShader,GLuint fragmentShader){
    //create shader program
    GLuint shaderProgram = glCreateProgram();

    //link shader and program
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glUseProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    GLint success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(! success){
        print_gl_error_log(shaderProgram);
        return 0;
    }

    return shaderProgram;
}


GLint get_attrib(GLuint program, const char *name) {
    GLint attribute = glGetAttribLocation(program, name);
    if(attribute == -1)
        fprintf(stderr, "Could not bind attribute %s\n", name);
    return attribute;
}



GLint get_uniform(GLuint program, const char *name) {
    GLint uniform = glGetUniformLocation(program, name);
    if(uniform == -1)
        fprintf(stderr, "Could not bind uniform %s\n", name);
    return uniform;
}