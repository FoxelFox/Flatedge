#ifndef TEXTURE_H
#define TEXTURE_H

#include <QOpenGLFunctions>


enum PixelFormat { RG, RGB, RGBA };
enum BitDepth { Default, Depth8, Depth16, Depth32 };

class Texture : public QOpenGLFunctions
{
public:
    Texture(int width, int height);
    ~Texture(void);

    void CreateOnGPU();
    void UploadPixel(char* pixels);
    void Resize(unsigned int width, unsigned int height);
    void bind(unsigned int point);
    void release();

    unsigned int GetWidth();
    unsigned int GetHeight();
    unsigned int GetHandle();

    void SetPixelFormat(PixelFormat format, BitDepth depth);
    void SetInternalPixelFormat(PixelFormat format, BitDepth depth);

private:
    unsigned int width;
    unsigned int height;
    unsigned int handle;

    int bindingPoint;
    int internalPixelFormat;
    int pixelFormat;


    void setupTextureParameter();
};

#endif // TEXTURE_H
