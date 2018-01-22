#version 330

#ifdef VERTEX_SHADER

layout(location= 0) in vec3 position;
uniform mat4 mvpMatrix;

void main( )
{
    gl_Position= mvpMatrix * vec4(position, 1);
}
#endif


#ifdef FRAGMENT_SHADER

uniform vec4 color;

out vec4 fragment_color;

void main( )
{
    vec4 color2 = vec4(0);
//    if(gl_FrontFacing == false) // if(!gl_FrontFacing) bug sur mac ?!
//    {
//        ivec2 pixel= ivec2(gl_FragCoord.xy / 4) % ivec2(2, 2);
//        if((pixel.x ^ pixel.y) == 0)
//            color2 = vec4(0.8, 0.4, 0, 1);
//    }

    fragment_color = color + color2;
}
#endif