/**
 * Parts of this file are from the OpenGL Programming wikibook: http://en.wikibooks.org/wiki/OpenGL_Programming
 * This file is in the public domain.
 * Contributors: Sylvain Beucler
 */
#ifndef _CREATE_SHADER_H
#define _CREATE_SHADER_H

#include <iostream>
#include <GL/glew.h>

/* Prints the GL error log during shader compilation. */
void print_gl_error_log(GLuint object);


/* Create  a shader from a file.
 *
 * @filename name of the file to read
 * @type GL_VERTEX_SHADER or GL_FRAGMENT_SHADER
 */
GLuint create_shader(const std::string filename, GLenum type);


/* Create shader program from vertexShader and fragmentShader. */
GLuint create_program(GLuint vertexShader,GLuint fragmentShader);


/* Create shader program from vertexShaderfile and fragmentShaderfile. */
GLuint create_program(const std::string vertexfile, const std::string fragmentfile);


/* create fragmentShader. */
GLuint emCreateFragmentShader(std::string fileName);


/* create vertexShader. */
GLuint emCreateVertexShader(std::string fileName);

GLint get_attrib(GLuint program, const char *name);

GLint get_uniform(GLuint program, const char *name);
#endif

