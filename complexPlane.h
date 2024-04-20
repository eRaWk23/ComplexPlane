#ifndef COMPLEXPLANE_H
#define COMPLEXPLANE_H

#include<iostream>
#include<vector>

const unsigned int MAX_ITER = 64;
const float BASE_WIDTH = 4.0;
const float BASE_HEIGHT = 4.0;
const float BASE_ZOOM = 0.5;

class ComplexPlane : public sf::Drawable
{
    public:
        ComplexPlane(int pixelSize, int pixelHeight);
        void draw(RenderTarger& target, RenderStates states) const
        {
            target.draw(m_vArray);
        }
        void updateRender();
        void zoomIn();
        void zoomOut();
        void setCenter(Vector2i mousePixel);
        void setMouseLocation(Vector2i mousePixel);
        void loadText(Text& Text);
    private:
        size_t countIterations(Vector2f coord);
        Vector2f mapPixelToCoords(Vector2i mousePixel);
        void iterationToRGB(size_t count, Uint8& g, Uint8& b);

};     

#endif 