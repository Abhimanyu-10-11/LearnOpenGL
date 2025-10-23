#version 330 core

struct Material {
sampler2D diffuse;
sampler2D specular;
float shininess;


};

struct Light{

vec3 position;
vec3 ambient;
vec3 diffuse;
vec3 specular;

float constant;
float linear;
float quadratic;

};

/*
struct DirectionalLight{

//Directional Light
vec3 direction; 



vec3 ambient;
vec3 diffuse;
vec3 specular;

};
*/



out vec4 FragColor;
in vec2 texCoord;
in vec3 Normal;
in vec3 FragPos;
uniform Material material;
uniform Light light;
uniform vec3 viewPos;


void main()
{
    vec3 norm = normalize(Normal);  
    
        
    //directional Light
	//vec3 lightDir = normalize(-light.direction);
    //float diff = max(dot(norm, lightDir), 0.0);
	
    
    //diffuse
	vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse =   light.diffuse * diff * vec3(texture(material.diffuse,texCoord));

   //ambient
    //float ambientStrength = .1f;
    vec3 ambient =  light.ambient * vec3(texture(material.diffuse,texCoord));
    //specular
    float specularStrength = .5f;
    vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular =  light.specular * spec * vec3(texture(material.specular,texCoord));
 
      float distance =  length(light.position - FragPos);
//      if(distance > 5)
//        distance= 100;
    float attenuation = 1.0/(light.constant+ light.linear*
    distance +light.quadratic *sqrt(distance));

    diffuse*=attenuation;
    ambient *= attenuation;
    specular *= attenuation;

    FragColor =   vec4(ambient+diffuse+specular,1.0f);
    
}