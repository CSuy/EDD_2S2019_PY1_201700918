#ifndef DATO_H
#define DATO_H
#include <string>

class Dato
{
    public:
        std::string Color;
        int posX, posY;
        Dato(int posX, int posY, std::string color);
        virtual ~Dato();

    protected:

    private:
};

#endif // DATO_H
