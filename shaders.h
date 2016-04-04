#pragma once
//////////////////////////////////////////////////////////////////////
// shaders.h: interface for the Shader & ShaderProgram class.
// -Kyoung Shin Park (2013 Spring)
//////////////////////////////////////////////////////////////////////

namespace moglclass
{

// OpenGL shader
class Shader
{
public:
	Shader();
	bool readShaderSource(const char* file);
	bool loadShader(const char* file, int type);
	void deleteShader();
	bool isLoaded() { return loaded; }				// if shader was loaded and compiled.
	unsigned int getShaderID() { return uiShader; }	// returns ID of a generated shader.

private:
	GLuint uiShader; // shader ID
	GLenum type; // GL_VERTEX_SHADER, GL_FRAGMENT_SHADER...
	GLchar* source; // shader source
	bool loaded; // Whether shader was loaded and compiled
};

// OpenGL shader program
class Program
{
public:
	void createProgram();
	void deleteProgram();
	bool attachShaderToProgram(Shader* shShader);
	bool linkProgram();
	void useProgram();
	unsigned int getProgramID();

	// Setting vectors
	void setUniform(std::string sName, glm::vec2* vVectors, int iCount = 1);
	void setUniform(std::string sName, const glm::vec2 vVector);
	void setUniform(std::string sName, glm::vec3* vVectors, int iCount = 1);
	void setUniform(std::string sName, const glm::vec3 vVector);
	void setUniform(std::string sName, glm::vec4* vVectors, int iCount = 1);
	void setUniform(std::string sName, const glm::vec4& vVector);

	// Setting floats
	void setUniform(std::string sName, float* fValues, int iCount = 1);
	void setUniform(std::string sName, const float fValue);

	// Setting 3x3 matrices
	void setUniform(std::string sName, glm::mat3* mMatrices, int iCount = 1);
	void setUniform(std::string sName, const glm::mat3 mMatrix);

	// Setting 4x4 matrices
	void setUniform(std::string sName, glm::mat4* mMatrices, int iCount = 1);
	void setUniform(std::string sName, const glm::mat4& mMatrix);

	// Setting integers
	void setUniform(std::string sName, int* iValues, int iCount = 1);
	void setUniform(std::string sName, const int iValue);

	Program();

private:
	GLuint uiProgram; // program ID
	bool linked; // Whether program was linked and is ready to use
};

}