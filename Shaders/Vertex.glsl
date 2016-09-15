attribute vec4 vertex;
attribute vec4 color;
varying vec3 var_color;
uniform mat4 matrix;
void main(void)
{
    gl_Position = matrix * vertex;
    var_color = color;
}
