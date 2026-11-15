#pragma once
using namespace System;
using namespace System::Drawing;

ref class Ingrediente
{
private:
	int x, y;
	int ancho, alto;
	Bitmap^ sprite_ingrediente;
	int dy;
	int tipo;
public:
	Ingrediente(int x, int tipo, Bitmap^ sprite_ingrediente);
	~Ingrediente();

	void dibujar_sprite_ingrediente(Graphics^ graphics);
	void mover();
	bool salio_de_pantalla(int alto_ventana);
};

Ingrediente::Ingrediente(int x, int tipo, Bitmap^ sprite_ingrediente)
{
	this->x = x;
	this->tipo = tipo;
	this->sprite_ingrediente = sprite_ingrediente;
	y = -alto;
	ancho = sprite_ingrediente->Width / 1;
	alto = sprite_ingrediente->Height / 4;
	dy = 3;
}

Ingrediente::~Ingrediente()
{
	//Destructor vacio
}

void Ingrediente::dibujar_sprite_ingrediente(Graphics^ graphics)
{
	Rectangle origen = Rectangle(0, tipo * alto, ancho, alto);
	Rectangle destino = Rectangle(x, y, ancho, alto);
	graphics->DrawImage(sprite_ingrediente, destino, origen, GraphicsUnit::Pixel);
}

void Ingrediente::mover()
{
	y = y + dy;
}

bool Ingrediente::salio_de_pantalla(int alto_ventana)
{
	return y > alto_ventana;
}