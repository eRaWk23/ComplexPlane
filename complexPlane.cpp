#include"complexPlane.h"

ComplexPlane::ComplexPlane(int pixelSize, int pixelHeight)
{
    m_pixel_size = {pixelSize, pixelHeight};
    m_aspectRatio = static_cast<float>(pixelHeight)/pixelSize;
    m_plane_center = {0,0};
    m_plane_size = {BASE_WIDTH,BASE_HEIGHT * m_aspectRatio};
    m_zoomCount = 0;
    m_state = State::CALCULATING;
    // TODO - Init VertexArray
    m_vArray.setPrimitiveType(sf::Points);
    m_vArray.resize(pixelSize * pixelHeight);
}
        
void ComplexPlane::updateRender()
{
    if(m_state == State::CALCULATING)
    {
        for (int i = 0; i < m_pixel_size.y; i++)
        {
            for (int j = 0; j < m_pixel_size.x; j++)
            {
                m_vArray[j + i *m_pixel_size.x].position = sf::Vector2f(j, i);
                sf::Vector2f coord = mapPixelToCoords(sf::Vector2i(j,i));
                size_t iterations = countIterations(coord);
                Uint8 r,g,b;
                iterationToRGB(iterations, r, g, b);
            }
        }
    }
}
void zoomIn();
void zoomOut();
void setCenter(Vector2i mousePixel);
void setMouseLocation(Vector2i mousePixel);
void loadText(Text& Text);
size_t countIterations(Vector2f coord);
Vector2f mapPixelToCoords(Vector2i mousePixel);
void iterationToRGB(size_t count, Uint8& g, Uint8& b);
