/**
 * Parts of this file are from the OpenGL Programming wikibook: http://en.wikibooks.org/wiki/OpenGL_Programming
 * This file is in the public domain.
 * Contributors: Sylvain Beucler
 */
#ifndef _CREATE_SHADER_H
#define _CREATE_SHADER_H

#include <iostream>
#include <GL/glew.h>
void print_gl_error_log(GLuint object);

GLuint create_shader(const std::string filename, GLenum type);

GLuint create_program(GLuint vertexShader,GLuint fragmentShader);
GLuint create_program(const std::string vertexfile, const std::string fragmentfile);

GLuint emCreateFragmentShader(std::string fileName);
GLuint emCreateVertexShader(std::string fileName);
#endif
