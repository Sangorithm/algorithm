#pragma once
#include "allinclude.h"
#include "segment.h"
Segment2::Segment2(glm::vec4& startVertex, glm::vec4& endVertex) {
	this->startVertex = startVertex;
	this->endVertex = endVertex;
	init2();
}
void Segment2::init2() {
	vertex2.push_back(startVertex);
	vertex2.push_back(endVertex);


	glGenBuffers(1, &vao2);
	//vertexLoc = glGetAttribLocation(program, "position");
	glBindBuffer(GL_ARRAY_BUFFER, vao2);
	glBufferData(GL_ARRAY_BUFFER, 2*sizeof(glm::vec4), &vertex2[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	vertex2.clear();
	glBindVertexArray(vao2);
	glDrawArrays(GL_LINES, 0, 2);       // draw wireframe circle
	glFlush();
}
glm::vec4 Segment2::getStartVertex() { return this->startVertex; }
glm::vec4 Segment2::getEndVertex() { return this->endVertex; }
void Segment2::setStartVertex(glm::vec4& startVertex) { this->startVertex = startVertex; }
void Segment2::setEndVertex(glm::vec4& endVertex) { this->endVertex = endVertex; }


Segment3::Segment3(glm::vec4& startVertex, glm::vec4& midVertex, glm::vec4& endVertex) : Segment2(startVertex, endVertex) {
	this->midVertex = midVertex;
	init3();
}
void Segment3::init3() {
	vertex3.push_back(startVertex);
	vertex3.push_back(midVertex);
	vertex3.push_back(endVertex);
	

	glGenBuffers(1, &vao2);
	//vertexLoc = glGetAttribLocation(program, "position");
	glBindBuffer(GL_ARRAY_BUFFER, vao2);
	glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(glm::vec4), &vertex3[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	vertex3.clear();
	glBindVertexArray(vao2);
	glDrawArrays(GL_LINES, 0, 3);       // draw wireframe circle
	glFlush();
}
glm::vec4 Segment3::getMidVertex() { return this->midVertex; }
void Segment3::setMidVertex(glm::vec4& midVertex) { this->midVertex = midVertex; }


Segment4::Segment4(glm::vec4& startVertex, glm::vec4& midVertex, glm::vec4& endVertex, glm::vec4& lastVertex) : Segment3(startVertex, midVertex, endVertex) {
	this->lastVertex = lastVertex;
	init4();
}
void Segment4::init4() {
	vertex4.push_back(startVertex);
	vertex4.push_back(midVertex);
	vertex4.push_back(endVertex);
	vertex4.push_back(lastVertex);

	glGenBuffers(1, &vao2);
	//vertexLoc = glGetAttribLocation(program, "position");
	glBindBuffer(GL_ARRAY_BUFFER, vao2);
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(glm::vec4), &vertex4[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	vertex4.clear();
	glBindVertexArray(vao2);
	glDrawArrays(GL_LINES, 0, 4);       // draw wireframe circle
	glFlush();
}
glm::vec4 Segment4::getLastVertex() {
	return this->lastVertex;
}
void Segment4::setLastVertex(glm::vec4& lastVertex) {
	this->lastVertex = lastVertex;
}