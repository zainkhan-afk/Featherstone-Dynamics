        ��  ��                  �  (   G L S L   ���       0 	        #version 150

uniform mat4	ciModelViewProjection;
uniform mat3	ciNormalMatrix;

in vec4		ciPosition;
in vec2		ciTexCoord0;
in vec3		ciNormal;
in vec4		ciColor;

out highp vec2	TexCoord;
out lowp vec4	Color;
out highp vec3	Normal;

void main(void)
{
	gl_Position = ciModelViewProjection * ciPosition;
	Color = ciColor;
	TexCoord = ciTexCoord0;
	Normal = ciNormalMatrix * ciNormal;
}
   (   G L S L   ���       0 	        #version 150

uniform sampler2D uTex0;

in vec4		Color;
in vec3		Normal;
in vec2		TexCoord;

out vec4 	oColor;

void main(void)
{
	vec3 normal = normalize(-Normal);
	float diffuse = max(dot(normal, vec3(0, 0, -1)), 0);
	oColor = Color *diffuse;
}   