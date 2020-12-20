#version 330 core
out vec4 FragColor;
  
in vec4 vertexColor; // Vertex Shader로 부터 받은 입력 변수(똑같은 이름, 똑같은 타입)

void main()
{
    FragColor = vertexColor;
} 