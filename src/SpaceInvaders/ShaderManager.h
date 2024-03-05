#pragma once
#include "ShaderProgram.h"
#include "Texture.h"
#include <map>
#include <string>

class ShaderManager
{
public:
    // loads (and generates) a shader program from file loading vertex, fragment (and geometry) shader's source code. If gShaderFile is not nullptr, it also loads a geometry shader
    static ShaderProgram LoadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, std::string name);
    
    // retrieves a stored sader
    static ShaderProgram& GetShader(const std::string& name);

    // properly de-allocates all loaded resources
    static void Clear();

private:
    static std::map<std::string, ShaderProgram> Shaders;

    // loads and generates a shader from file
    static ShaderProgram loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile = nullptr);
    
    // loads a single texture from file
    static Texture loadTextureFromFile(const char* file, bool alpha);
};
