#include"complexPlane.h"

ComplexPlane::ComplexPlane(int pixelSize, int pixelHeight)
{
    m_pixel_size = {pixelSize, pixelHeight};
    m_plane_center = {0,0};
    m_plane_size = {BASE_WIDTH,BASE_HEIGHT * m_aspectRatio};
    m_zoomCount = 0;
    m_state = State::CALCULATING;
    // Init VertexArray
}
        
void updateRender();
void zoomIn();
void zoomOut();
void setCenter(Vector2i mousePixel);
void setMouseLocation(Vector2i mousePixel);
void loadText(Text& Text);
size_t countIterations(Vector2f coord);
Vector2f mapPixelToCoords(Vector2i mousePixel);
void iterationToRGB(size_t count, Uint8& g, Uint8& b);