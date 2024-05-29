#include "ResourceManager.h"

#include <sstream>
#include <fstream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

std::map<std::string, Shader> ResourceManager::Shaders;
std::map<std::string, Texture2D> ResourceManager::Textures;

Shader ResourceManager::LoadShader(const char* vShaderFile, const char* fShaderFile, std::string name)
{
    Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile);
    return Shaders[name];
}

Shader ResourceManager::GetShader(std::string name)
{
    auto it = Shaders.find(name);
    if (it == Shaders.end())
    {
        std::cerr << "WARNING::ResourceManager::CANNOT FIND SHADER: " << name << std::endl;
    }
    return Shaders[name];
}

Texture2D ResourceManager::LoadTexture(const char* file, bool alpha, std::string name)
{
    Textures[name] = loadTextureFromFile(file, alpha);
    return Textures[name];
}

Texture2D ResourceManager::GetTexture(std::string name)
{
 auto it = Textures.find(name);
 if (it == Textures.end())
{
    std::cerr << "WARNING::ResourceManager::CANNOT FIND TEXTURE: " << name << std::endl;
}
    return Textures[name];
}

void ResourceManager::Clear()
{
    for (auto iter : Shaders) glDeleteProgram(iter.second.id);
    for (auto iter : Textures) glDeleteTextures(1, &iter.second.ID);
}

Shader ResourceManager::loadShaderFromFile(const char* vShaderFile, const char* fShaderFile)
{
    Shader shader(vShaderFile, fShaderFile);
    shader.Bind();
    return shader;
}

Texture2D ResourceManager::loadTextureFromFile(const char* file, bool alpha)
{
    Texture2D texture;
    if (alpha)
    {
        texture.Internal_Format = GL_RGBA;
        texture.Image_Format = GL_RGBA;
    }
    int width, height, nrChannels;
    unsigned char* data = stbi_load(file, &width, &height, &nrChannels, 0);
    texture.Generate(width, height, data);
    
    stbi_image_free(data);
    return texture;
}