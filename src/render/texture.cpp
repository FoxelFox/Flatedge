#include "texture.h"

Texture::Texture(int width, int height)
{
    this->width = width;
    this->height = height;

    internalPixelFormat = GL_RGB8;
    pixelFormat = GL_RGB;

    initializeOpenGLFunctions();
}


Texture::~Texture(void)
{
}

void Texture::CreateOnGPU(){
    glGenTextures(1, &handle);
    glBindTexture(GL_TEXTURE_2D, handle);

    glTexImage2D(GL_TEXTURE_2D, 0, internalPixelFormat, width, height, 0, pixelFormat, GL_FLOAT, 0);
    setupTextureParameter();
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::setupTextureParameter(){
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

void Texture::UploadPixel(char* pixels){
    glBindTexture(GL_TEXTURE_2D, handle);
    glTexImage2D(GL_TEXTURE_2D, 0, internalPixelFormat, width, height, 0, pixelFormat, GL_UNSIGNED_BYTE, pixels);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Resize(unsigned int width, unsigned int height){
    this->width = width;
    this->height = height;

    glBindTexture(GL_TEXTURE_2D, handle);
    glTexImage2D(GL_TEXTURE_2D, 0, internalPixelFormat, width, height, 0, pixelFormat, GL_UNSIGNED_BYTE, 0);
}

void Texture::bind(unsigned int point){
    bindingPoint = point;
    glActiveTexture(GL_TEXTURE0 + point);
    glBindTexture(GL_TEXTURE_2D, handle);
    glUniform1i(point,point); // TODO: Is that needed after GLSL 430 core ?
}

void Texture::release(){
    glActiveTexture(bindingPoint);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::destroy() {
    release();
    glDeleteTextures(1, &handle);
}

unsigned int Texture::GetWidth(){ return width; }
unsigned int Texture::GetHeight(){ return height; }
unsigned int Texture::GetHandle(){ return handle; }

unsigned int convertToGL(PixelFormat format, BitDepth depth){
    switch (format) {
        case RG: {
            switch (depth) {
                case Depth8: return GL_RG8; // normalized
                case Depth16: return GL_RG16F;
                case Depth32: return GL_RG32F;
                default: return GL_RG;
            }
        }
        case RGB: {
            switch (depth) {
                case Depth8: return GL_RGB8; // normalized
                case Depth16: return GL_RGB16F;
                case Depth32: return GL_RGB32F;
                default: return GL_RGB;
            }
        }
        case RGBA: {
            switch (depth) {
                case Depth8: return GL_RGBA8; // normalized
                case Depth16: return GL_RGBA16F;
                case Depth32: return GL_RGBA32F;
                default: return GL_RGBA;
            }
        }
    }
    return GL_RGB;
}

void Texture::SetPixelFormat(PixelFormat format, BitDepth depth){ pixelFormat = convertToGL(format, depth);}
void Texture::SetInternalPixelFormat(PixelFormat format, BitDepth depth){ internalPixelFormat = convertToGL(format, depth);}
