#include "empathy.hpp"

GLuint emCreateFragmentShader() {
	cout<<"created emCreateFragmentShader"<<endl;

	//read the shaders
	// 1. Retrieve the vertex/fragment source code from filePath
	std::string fragmentCode = "#version 330 core\n"
	                           "out vec4 color;\n"
	                           "uniform vec4 vertexColor;\n"

	                           "void main()\n"
	                           "{\n"
	                           "  color = vertexColor;\n"
	                           "}";


	const GLchar* fShaderCode = fragmentCode.c_str();


	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
	glCompileShader(fragmentShader);

	
	GLint success;
	GLchar infoLog[512];	
	//check if shader compiled successfully
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" <<
		          infoLog << std::endl;

		return 2;
	}

	return fragmentShader;
}

GLuint emCreateVertexShader() {
	cout<<"created emCreateVertexShader"<<endl;
	std::string vertexCode = "#version 330 core\n"
	                         "layout (location = 0) in vec2 position;\n"
	                         "void main()\n"
	                         "{\n"
	                         "  gl_Position = vec4(position.x, position.y, 0.0, 1.0);\n"
	                         "}";

	const GLchar* vShaderCode = vertexCode.c_str();

	//create vertexShader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderCode, NULL);
	glCompileShader(vertexShader);

	//check if shader compiled successfully
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);

		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" <<
		          infoLog << std::endl;

		return 1;
	}

	return vertexShader;
}

GLuint emCreateShaderProgram(GLuint fragmentShader , GLuint vertexShader) {
	cout<<"created emCreateShaderProgram"<<endl;

	//create shader program
	GLuint shaderProgram = glCreateProgram();

	//link shader and program
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glUseProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return shaderProgram;
}