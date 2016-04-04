#pragma once
#include"allinclude.h"

class Segment2 {
public:
	glm::vec4 startVertex;
	glm::vec4 endVertex;
	GLuint vao2;
	
	std::vector<glm::vec4> vertex2;
	Segment2(glm::vec4& startVertex, glm::vec4& endVertex);
	void init2();
	glm::vec4 getStartVertex();
	glm::vec4 getEndVertex();
	void setStartVertex(glm::vec4& startVertex);
	void setEndVertex(glm::vec4& endVertex);
	Segment2 drawing(GLuint);
};
class Segment3 :public Segment2 {
public:
	glm::vec4 midVertex;
	//GLuint vao3;
	std::vector<glm::vec4> vertex3;
	Segment3(glm::vec4& startVertex, glm::vec4& midVertex, glm::vec4& endVertex);
	void init3();
	glm::vec4 getMidVertex();
	void setMidVertex(glm::vec4& midVertex);
};
class Segment4 :public Segment3 {
public:
	glm::vec4 lastVertex;
	//GLuint vao4;
	//public :
	std::vector<glm::vec4> vertex4;
	
	Segment4(glm::vec4& startVertex, glm::vec4& midVertex, glm::vec4& endVertex, glm::vec4& lastVertex);
	void init4();
	glm::vec4 getLastVertex();
	void setLastVertex(glm::vec4& lastVertex);
};