attribute vec4 vertex;
attribute vec4 color;
varying vec4 var_color;
uniform mat4 matrixModel;
uniform mat4 matrixProjection;
uniform mat4 matrixView;
void main(void)
{
    mat4 MVP = matrixProjection * matrixView * matrixModel;
    gl_Position = MVP * vertex;
    var_color = color;
}
