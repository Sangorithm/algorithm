/* minimal program to open & clear a window */
#include"allinclude.h"
#include"segment.h"
#define LINE_WIDTH  5

#define STEP 32
using namespace moglclass;

#define NUMSHADERS 2
Shader shShaders[NUMSHADERS];
Program spMain;
std::map<GLuint, string> tMap;
std::list<GLuint> gluintList;
std::list<GLuint>::iterator itr;
std::map<GLuint, UINT> mapOfUINT;
std::vector<glm::vec4> circleVertices;
GLuint vao;
GLuint vbo;

void setData();
void init();
void display();
void setting(string, UINT);
void keyboard(unsigned char, int, int);
void cleanup();
void setAllData(GLuint *, VertexBufferObject*, string, int);
void initSharedShadersDrawing(GLuint *, VertexBufferObject *);
void kwonInit();
void giInit();
void hoInit();
void addVertexBufferObject(VertexBufferObject *, double, double, double, double);
void SetCircleData(float, int);

void kwon();
void gi();
void ho();

int vertexNo;
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(512, 512);
	glutCreateWindow("Your First OpenGL");
	glewInit();
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	cleanup();
	return 0;
}
void kwonInit() {
	GLuint GLKwon;
	VertexBufferObject VBOKwon;

	addVertexBufferObject(&VBOKwon, -0.9, 0.8, 0.0, 1.0);// 점r
	addVertexBufferObject(&VBOKwon, 1.0, 0.0, 0.0, 1.0);//색

	addVertexBufferObject(&VBOKwon, -0.7, 0.8, 0.0, 1.0);//점r
	addVertexBufferObject(&VBOKwon, 0.0, 1.0, 0.0, 1.0);//색

	addVertexBufferObject(&VBOKwon, -0.7, 0.8, 0.0, 1.0);//점r
	addVertexBufferObject(&VBOKwon, 0.0, 0.0, 1.0, 1.0);//색

	addVertexBufferObject(&VBOKwon, -0.7, 0.6, 0.0, 1.0);//점r
	addVertexBufferObject(&VBOKwon, 1.0, 0.0, 0.0, 1.0);//색

	addVertexBufferObject(&VBOKwon, -0.93, 0.58, 0.0, 1.0);//점ㅡ
	addVertexBufferObject(&VBOKwon, 0.0, 1.0, 0.0, 1.0);//색

	addVertexBufferObject(&VBOKwon, -0.65, 0.58, 0.0, 1.0);//점ㅡ
	addVertexBufferObject(&VBOKwon, 0.0, 0.0, 1.0, 1.0);//색

	addVertexBufferObject(&VBOKwon, -0.83, 0.58, 0.0, 1.0);//점ㅜ
	addVertexBufferObject(&VBOKwon, 1.0, 0.0, 0.0, 1.0);//색

	addVertexBufferObject(&VBOKwon, -0.83, 0.48, 0.0, 1.0);//점ㅜ
	addVertexBufferObject(&VBOKwon, 0.0, 1.0, 0.0, 1.0);//색

	addVertexBufferObject(&VBOKwon, -0.83, 0.53, 0.0, 1.0);//점j
	addVertexBufferObject(&VBOKwon, 0.0, 0.0, 1.0, 1.0);//색

	addVertexBufferObject(&VBOKwon, -0.62, 0.53, 0.0, 1.0);//점j
	addVertexBufferObject(&VBOKwon, 1.0, 0.0, 0.0, 1.0);//색

	addVertexBufferObject(&VBOKwon, -0.62, 0.8, 0.0, 1.0);//점l
	addVertexBufferObject(&VBOKwon, 0.0, 1.0, 0.0, 1.0);//색

	addVertexBufferObject(&VBOKwon, -0.62, 0.45, 0.0, 1.0);//점l
	addVertexBufferObject(&VBOKwon, 0.0, 0.0, 1.0, 1.0);//색

	addVertexBufferObject(&VBOKwon, -0.89, 0.52, 0.0, 1.0);//점s
	addVertexBufferObject(&VBOKwon, 0.0, 0.0, 1.0, 1.0);//색

	addVertexBufferObject(&VBOKwon, -0.89, 0.42, 0.0, 1.0);//점s
	addVertexBufferObject(&VBOKwon, 0.0, 0.0, 1.0, 1.0);//색

	addVertexBufferObject(&VBOKwon, -0.9, 0.42, 0.0, 1.0);//점
	addVertexBufferObject(&VBOKwon, 0.0, 0.0, 1.0, 1.0);//색

	addVertexBufferObject(&VBOKwon, -0.62, 0.42, 0.0, 1.0);//점s
	addVertexBufferObject(&VBOKwon, 0.0, 0.0, 1.0, 1.0);//색
														//printf("%d", vertexNo1);
	setAllData(&GLKwon, &VBOKwon, "lines", 32);

}
void giInit() {

	GLuint GLGi;
	VertexBufferObject VBOGi;
	addVertexBufferObject(&VBOGi, -0.55, 0.8, 0.0, 1.0);// 점r
	addVertexBufferObject(&VBOGi, 0.0, 0.0, 1.0, 1.0);//색

	addVertexBufferObject(&VBOGi, -0.3, 0.8, 0.0, 1.0);//색r
	addVertexBufferObject(&VBOGi, 1.0, 0.0, 0.0, 1.0);//색

	addVertexBufferObject(&VBOGi, -0.3, 0.8, 0.0, 1.0);//색
	addVertexBufferObject(&VBOGi, 0.0, 0.0, 1.0, 1.0);//색

	addVertexBufferObject(&VBOGi, -0.41, 0.42, 0.0, 1.0);//색r
	addVertexBufferObject(&VBOGi, 0.0, 1.0, 0.0, 1.0);//색

	addVertexBufferObject(&VBOGi, -0.22, 0.8, 0.0, 1.0);// 점l
	addVertexBufferObject(&VBOGi, 0.0, 0.0, 1.0, 1.0);//색

	addVertexBufferObject(&VBOGi, -0.22, 0.42, 0.0, 1.0);//l
	addVertexBufferObject(&VBOGi, 1.0, 0.0, 0.0, 1.0);//색



	setAllData(&GLGi, &VBOGi, "lines", vertexNo);


}
void hoInit() {
	GLuint GLHo;
	VertexBufferObject VBOHo;
	addVertexBufferObject(&VBOHo, 0, 0.85, 0.0, 1.0);//점 ㅎ
	addVertexBufferObject(&VBOHo, 1.0, 0.0, 0.0, 1.0);//색

	addVertexBufferObject(&VBOHo, 0, 0.75, 0.0, 1.0);//점ㅎ
	addVertexBufferObject(&VBOHo, 1.0, 0.0, 0.0, 1.0);//색

	addVertexBufferObject(&VBOHo, -0.15, 0.75, 0.0, 1.0);//점ㅡ
	addVertexBufferObject(&VBOHo, 0.0, 1.0, 0.0, 1.0);//색

	addVertexBufferObject(&VBOHo, 0.15, 0.75, 0.0, 1.0);//점ㅡ
	addVertexBufferObject(&VBOHo, 0.0, 0.0, 1.0, 1.0);//색


	SetCircleData(0.1f, 32);

	///////////////


	addVertexBufferObject(&VBOHo, 0.0, 0.52, 0.0, 1.0);//점
	addVertexBufferObject(&VBOHo, 0.0, 0.0, 1.0, 1.0);//색 ㅗ의 ㅣ

	addVertexBufferObject(&VBOHo, 0.0, 0.42, 0.0, 1.0);//점
	addVertexBufferObject(&VBOHo, 0.0, 0.0, 1.0, 1.0);//색 ㅗ 의 ㅣ


	addVertexBufferObject(&VBOHo, -0.13, 0.42, 0.0, 1.0);//점
	addVertexBufferObject(&VBOHo, 0.0, 0.0, 1.0, 1.0);//색 ㅗ 의 ㅡ

	addVertexBufferObject(&VBOHo, 0.17, 0.42, 0.0, 1.0);//점
	addVertexBufferObject(&VBOHo, 0.0, 0.0, 1.0, 1.0);//색 ㅗ 의 ㅡ

	setAllData(&GLHo, &VBOHo, "lines", vertexNo);
}
void SetCircleData(float radius, int step)
{
	// circle position
	float theta = (float)(2 * M_PI / step);
	for (int i = 0; i<step; i++)
	{
		float x = radius * cos(theta * i);
		float y = radius * sin(theta * i);
		circleVertices.push_back(glm::vec4(x, y + 0.63, 0.0f, 1.0f));
	}
	printf("circle::numVertices =%d\n", (int)circleVertices.size());

	// VAO

	// VBO
	glGenBuffers(1, &vbo);
	//vertexLoc = glGetAttribLocation(program, "position");
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, step*sizeof(glm::vec4), &circleVertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	circleVertices.clear();
}


void addVertexBufferObject(VertexBufferObject * vbo, double f1, double f2, double f3, double f4) {
	(*vbo).addData(&glm::vec4(f1, f2, f3, f4), sizeof(glm::vec4));
	++vertexNo;
}
void setAllData(GLuint *vao, VertexBufferObject *vbo, string type, int no) {
	initSharedShadersDrawing(vao, vbo);
	tMap[(*vao)] = type;
	mapOfUINT[(*vao)] = no;
	gluintList.push_front((*vao));
}

void setData()
{
	kwon();
	gi();
	ho();
	//Segment2 nn();
	

	/*kwonInit();
	giInit();
	hoInit();*/
}
void gi() {
	//-0.22, 0.8, 0.0, 1.0
	Segment3 r(glm::vec4(-0.55, 0.8, 0.0, 1.0), glm::vec4(-0.3, 0.8, 0.0, 1.0), glm::vec4(-0.41, 0.42, 0.0, 1.0));
	Segment2 nm(glm::vec4(-0.22, 0.8, 0.0, 1.0), glm::vec4(-0.22, 0.42, 0.0, 1.0));
}
void ho() {
	//  0.0, 0.52, 0.0, 1.0
	Segment2 gg(glm::vec4(0, 0.85, 0.0, 1.0), glm::vec4(0, 0.75, 0.0, 1.0));
	Segment2 gm(glm::vec4(-0.15, 0.75, 0.0, 1.0), glm::vec4(0.15, 0.75, 0.0, 1.0));
	SetCircleData(0.1f, 32);
	Segment2 hh(glm::vec4(0.0, 0.52, 0.0, 1.0), glm::vec4(0.0, 0.42, 0.0, 1.0));
	Segment2 hm(glm::vec4(-0.13, 0.42, 0.0, 1.0), glm::vec4(0.17, 0.42, 0.0, 1.0));

}
void kwon() {
	Segment3 r(glm::vec4(-0.9f, 0.8f, 0.0f, 1.0f), glm::vec4(-0.7f, 0.8f, 0.0f, 1.0f), glm::vec4(-0.7f, 0.6f, 0.0f, 1.0f));
	//r.init3();
	Segment2 nm(glm::vec4(-0.93f, 0.58f, 0.0f, 1.0f), glm::vec4(-0.65f, 0.58f, 0.0f, 1.0f));
	//nm.init2();
	Segment2 nn(glm::vec4(-0.83f, 0.58f, 0.0f, 1.0f), glm::vec4(-0.83f, 0.48f, 0.0f, 1.0f));
	//nn.init2();
	Segment2 jj(glm::vec4(-0.83f, 0.53f, 0.0f, 1.0f), glm::vec4(-0.62f, 0.53f, 0.0f, 1.0f));
	//jj.init2();
	Segment2 jl(glm::vec4(-0.62f, 0.8f, 0.0f, 1.0f), glm::vec4(-0.62f, 0.53f, 0.0f, 1.0f));
	Segment3 s(glm::vec4(-0.89f, 0.52f, 0.0f, 1.0f), glm::vec4(-0.89f, 0.42f, 0.0f, 1.0f), glm::vec4(-0.62f, 0.42f, 0.0f, 1.0f));
}
void init(void)
{
	// Load shaders and use the resulting shader program
	spMain.createProgram();
	shShaders[0].loadShader("simple2.vs", GL_VERTEX_SHADER);
	shShaders[1].loadShader("simple2.fs", GL_FRAGMENT_SHADER);
	spMain.attachShaderToProgram(&shShaders[0]);
	spMain.attachShaderToProgram(&shShaders[1]);
	spMain.linkProgram();
	spMain.useProgram();

	setData();

	glClearColor(1.0, 1.0, 1.0, 1.0); // white background
}
void display(void)
{
	int i = 0;
	glClearColor(1.0, 1.0, 1.0, 1.0); // white background
	glClear(GL_COLOR_BUFFER_BIT); // clear the window
	itr = gluintList.begin();
	for (map<GLuint, string>::iterator mm = tMap.begin(); mm != tMap.end(); mm++) {
		glBindVertexArray(*itr);
		setting(mm->second, mapOfUINT[mm->first]);
		++itr;
	}
	glBindVertexArray(vao);
	glDrawArrays(GL_LINE_LOOP, 0, STEP);       // draw wireframe circle
	glFlush();
}
void setting(string str, UINT bufferSize) {
	glLineWidth(LINE_WIDTH);
	if (str == "strip")
		glDrawArrays(GL_TRIANGLES, 0, bufferSize);
	else if (str == "loop")
		glDrawArrays(GL_LINE_LOOP, 0, bufferSize);
	else if (str == "lines")
		glDrawArrays(GL_LINES, 0, bufferSize);

}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(EXIT_SUCCESS);
		break;
	}
}
void cleanup()
{
	spMain.deleteProgram();
}
void initSharedShadersDrawing(GLuint * vao, VertexBufferObject * vbo) {
	(*vbo).createVBO();
	(*vbo).bindVBO();
	(*vbo).uploadDataToGPU(GL_STATIC_DRAW);
	// 1 triangle - VAO
	glGenVertexArrays(1, vao);
	glBindVertexArray((*vao));

	int iDataStride = 2 * sizeof(glm::vec4); // vertex & color
	int iDataOffset = 0;
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, iDataStride, (void*)iDataOffset);
	iDataOffset += sizeof(glm::vec4);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, iDataStride, (void*)iDataOffset);
	glBindVertexArray(0);
}