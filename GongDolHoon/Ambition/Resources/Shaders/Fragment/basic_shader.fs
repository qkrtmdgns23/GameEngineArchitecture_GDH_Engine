#version 330 core
out vec4 FragColor;
  
in vec4 vertexColor; // Vertex Shader�� ���� ���� �Է� ����(�Ȱ��� �̸�, �Ȱ��� Ÿ��)

void main()
{
    FragColor = vertexColor;
} 