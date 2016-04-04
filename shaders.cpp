//////////////////////////////////////////////////////////////////////
// shaders.cpp: implementation for the Shader & ShaderProgram class.
// -Kyoung Shin Park (2016 Spring)
//////////////////////////////////////////////////////////////////////
#include "moglclass.h"
#include "shaders.h"
#include <glm/gtc/type_ptr.hpp>

namespace moglclass
{

Shader::Shader()
{
	loaded = false;
	source = NULL;
}

// returns a NULL-terminated string by reading the shader source
bool Shader::readShaderSource(const char* sFile)
{
	FILE* fp = fopen(sFile, "rb");
	if(!fp) return false;

	// Get all lines from a file
    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);

    fseek(fp, 0L, SEEK_SET);
    
	source = new char[size + 1];
    fread(source, 1, size, fp);
	source[size] = '\0';
    
	fclose(fp);

	return true;
}

// load and compile shader
bool Shader::loadShader(const char* sFile, int aType)
{
	if (!readShaderSource(sFile)) 
	{
		fprintf(stderr, "Failed to read %s\n", sFile);
	    return false;
	}

	uiShader = glCreateShader(aType);

	glShaderSource(uiShader, 1, (const GLchar**) &source, NULL);
	glCompileShader(uiShader);

	GLint  compiled;
	glGetShaderiv(uiShader, GL_COMPILE_STATUS, &compiled);
	if(compiled == GL_FALSE)
	{
		GLint  logSize;
	    glGetShaderiv(uiShader, GL_INFO_LOG_LENGTH, &logSize );
	    char* logMsg = new char[logSize];
	    glGetShaderInfoLog(uiShader, logSize, NULL, logMsg );
		fprintf(stderr, "Error! Shader file %s wasn't compiled! The compiler returned:\n\n%s", sFile, logMsg);
		delete [] logMsg;
		return false;
	}
	delete[] source;

	type = aType;
	loaded = true;

	return true;
}

// delete and free memory
void Shader::deleteShader()
{
	if(!loaded) return;
	loaded = false;
	glDeleteShader(uiShader);
}

////////////////////////////////////////////////////////

Program::Program()
{
	linked = false;
}

// creates a new shader program.
void Program::createProgram()
{
	uiProgram = glCreateProgram();
}

// attaches a shader (like source file) to a program, but only compiled one.
bool Program::attachShaderToProgram(Shader* shShader)
{
	if(!shShader->isLoaded()) return false;
	glAttachShader(uiProgram, shShader->getShaderID());

	return true;
}

// link program
bool Program::linkProgram()
{
	glLinkProgram(uiProgram);

	int iLinkStatus;
	glGetProgramiv(uiProgram, GL_LINK_STATUS, &iLinkStatus);
	linked = iLinkStatus == GL_TRUE;

	if ( !linked ) 
	{
		GLint  logSize;
		glGetProgramiv(uiProgram, GL_INFO_LOG_LENGTH, &logSize);
		char* logMsg = new char[logSize];
		glGetProgramInfoLog(uiProgram, logSize, NULL, logMsg );
		fprintf(stderr, "Shader program failed to link\n\n%s", logMsg);
		delete [] logMsg;
	}

	return linked;
}

// deletes program and frees memory on GPU.
void Program::deleteProgram()
{
	if(!linked) return;
	linked = false;
	glDeleteProgram(uiProgram);
}

// tells OpenGL to use this program.
void Program::useProgram()
{
	if(linked) glUseProgram(uiProgram);
}

// Returns OpenGL generated shader program ID.
UINT Program::getProgramID()
{
	return uiProgram;
}

//	These set of functions set most common uniform variables. 

// Setting floats
void Program::setUniform(string sName, float* fValues, int iCount)
{
	int iLoc = glGetUniformLocation(uiProgram, sName.c_str());
	glUniform1fv(iLoc, iCount, fValues);
}

void Program::setUniform(string sName, const float fValue)
{
	int iLoc = glGetUniformLocation(uiProgram, sName.c_str());
	glUniform1fv(iLoc, 1, &fValue);
}

// Setting vectors
void Program::setUniform(string sName, glm::vec2* vVectors, int iCount)
{
	int iLoc = glGetUniformLocation(uiProgram, sName.c_str());
	glUniform2fv(iLoc, iCount, (GLfloat*)vVectors);
}

void Program::setUniform(string sName, const glm::vec2 vVector)
{
	int iLoc = glGetUniformLocation(uiProgram, sName.c_str());
	glUniform2fv(iLoc, 1, (GLfloat*)&vVector);
}

void Program::setUniform(string sName, glm::vec3* vVectors, int iCount)
{
	int iLoc = glGetUniformLocation(uiProgram, sName.c_str());
	glUniform3fv(iLoc, iCount, (GLfloat*)vVectors);
}

void Program::setUniform(string sName, const glm::vec3 vVector)
{
	int iLoc = glGetUniformLocation(uiProgram, sName.c_str());
	glUniform3fv(iLoc, 1, (GLfloat*)&vVector);
}

void Program::setUniform(string sName, glm::vec4* vVectors, int iCount)
{
	int iLoc = glGetUniformLocation(uiProgram, sName.c_str());
	glUniform4fv(iLoc, iCount, (GLfloat*)vVectors);
}

void Program::setUniform(string sName, const glm::vec4& vVector)
{
	int iLoc = glGetUniformLocation(uiProgram, sName.c_str());
	glUniform4fv(iLoc, 1, (GLfloat*)&vVector);
}

// Setting 3x3 matrices
void Program::setUniform(string sName, glm::mat3* mMatrices, int iCount)
{
	int iLoc = glGetUniformLocation(uiProgram, sName.c_str());
	glUniformMatrix3fv(iLoc, iCount, FALSE, (GLfloat*)mMatrices);
}

void Program::setUniform(string sName, const glm::mat3 mMatrix)
{
	int iLoc = glGetUniformLocation(uiProgram, sName.c_str());
	glUniformMatrix3fv(iLoc, 1, FALSE, (GLfloat*)&mMatrix);
}

// Setting 4x4 matrices
void Program::setUniform(string sName, glm::mat4* mMatrices, int iCount)
{
	int iLoc = glGetUniformLocation(uiProgram, sName.c_str());
	glUniformMatrix4fv(iLoc, iCount, FALSE, (GLfloat*)mMatrices);
}

void Program::setUniform(string sName, const glm::mat4& mMatrix)
{
	int iLoc = glGetUniformLocation(uiProgram, sName.c_str());
	glUniformMatrix4fv(iLoc, 1, FALSE, (GLfloat*)&mMatrix);
}

// Setting integers
void Program::setUniform(string sName, int* iValues, int iCount)
{
	int iLoc = glGetUniformLocation(uiProgram, sName.c_str());
	glUniform1iv(iLoc, iCount, iValues);
}

void Program::setUniform(string sName, const int iValue)
{
	int iLoc = glGetUniformLocation(uiProgram, sName.c_str());
	glUniform1i(iLoc, iValue);
}

}