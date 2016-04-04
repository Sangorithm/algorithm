#pragma once
//////////////////////////////////////////////////////////////////////
// vertexBufferObject.h: interface for the VBO class.
// -Kyoung Shin Park (2013 Spring)
//////////////////////////////////////////////////////////////////////

namespace moglclass
{

// OpenGL vertex buffer	object.
class VertexBufferObject
{
public:
	VertexBufferObject();

	void createVBO(int a_iSize = 0);
	void releaseVBO();

	void* mapBufferToMemory(int iUsageHint);
	void* mapSubBufferToMemory(int iUsageHint, UINT uiOffset, UINT uiLength);
	void unmapBuffer();

	void bindVBO(int a_iBufferType = GL_ARRAY_BUFFER);
	void uploadDataToGPU(int iUsageHint);
	
	void addData(void* ptrData, UINT uiDataSize);

	void* getDataPointer();
	UINT getBuffer();

private:
	UINT uiBuffer;
	int iSize;
	int iBufferType;
	vector<BYTE> data;

	bool bDataUploaded;
};

} // moglclass namespace