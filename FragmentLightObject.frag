#version 330 core
out vec4 FragColor;
in vec2 texCoord;
in vec3 Normal;
in vec3 FragPos;
uniform sampler2D texture1;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;
void main()
{
    vec3 norm = normalize(Normal);  
	vec3 lightDir = normalize(lightPos - FragPos);

    float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse =  diff * lightColor;

    float ambientStrength = .1f;
    vec3 ambient = ambientStrength * lightColor;

    float specularStrength = .5f;
    vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0f);
	vec3 specular = specularStrength * spec * lightColor;
 
    FragColor = texture(texture1,texCoord) * vec4(ambient+diffuse+specular,1.0f);
    
}