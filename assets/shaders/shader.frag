#version 460 core
out vec4 FragColor;
in vec2 TexCoord;

uniform vec3 objectColor;
uniform bool useTexture;
uniform sampler2D texture1;

void main() {
    if (useTexture){
        vec4 texColor = texture(texture1, TexCoord);
        vec3 finalColor = mix(objectColor, texColor.rgb, texColor.a);
        FragColor=vec4(finalColor, 1.0);
    } else {
        FragColor = vec4(objectColor, 1.0);
    }
}
