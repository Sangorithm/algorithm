//////////////////////////////////////////////////////////////////////
// vertexBufferObject.cpp: implementation for the VBO class.
// -Kyoung Shin Park (2013 Spring)
//////////////////////////////////////////////////////////////////////
#include "moglclass.h"
#include "vertexBufferObject.h"

namespace moglclass
{
VertexBufferObject::VertexBufferObject()
{
	bDataUploaded = false;
}
// create a vertex buffer object (VBO)
void VertexBufferObject::createVBO(int a_iSize)
{
	glGenBuffers(1, &uiBuffer);
	//fprintf(stderr, "VBO# %d\n", uiBuffer);
	data.reserve(a_iSize);
	iSize = a_iSize;
}
// release VBO and free memory
void VertexBufferObject::releaseVBO()
{
	glDeleteBuffers(1, &uiBuffer);
	bDataUploaded = false;
	data.clear();
}
// maps whole buffer data to memory and	returns pointer to data.
void* VertexBufferObject::mapBufferToMemory(int iUsageHint)
{
	if(!bDataUploaded) return NULL;
	void* ptrRes = glMapBuffer(iBufferType, iUsageHint);
	return ptrRes;
}
// maps specified part of buffer to memory.
void* VertexBufferObject::mapSubBufferToMemory(int iUsageHint, UINT uiOffset, UINT uiLength)
{
	if(!bDataUploaded) return NULL;
	void* ptrRes = glMapBufferRange(iBufferType, uiOffset, uiLength, iUsageHint);
	return ptrRes;
}
// Unmaps previously mapped buffer.
void VertexBufferObject::unmapBuffer()
{
	glUnmapBuffer(iBufferType);
}
// binds this VBO.
void VertexBufferObject::bindVBO(int a_iBufferType)
{
	iBufferType = a_iBufferType;
	glBindBuffer(iBufferType, uiBuffer);
}
// sends data to GPU
void VertexBufferObject::uploadDataToGPU(int iDrawingHint)
{
	glBufferData(iBufferType, data.size(), &data[0], iDrawingHint);
	bDataUploaded = true;
	data.clear();
}
// adds data to VBO
void VertexBufferObject::addData(void* ptrData, UINT uiDataSize)
{
	data.insert(data.end(), (BYTE*)ptrData, (BYTE*)ptrData+uiDataSize);
}
// returns data pointer (only before uploading)
void* VertexBufferObject::getDataPointer()
{
	if(bDataUploaded)return NULL;
	return (void*)data[0];
}
// get VBO ID
UINT VertexBufferObject::getBuffer()
{
	return uiBuffer;
}
}

