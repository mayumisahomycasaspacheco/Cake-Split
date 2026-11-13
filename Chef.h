#pragma once
using namespace System;
using namespace System::Drawing;

enum class Direccion {Ninguna, Izquierda, Derecha}; //Idle, izquierda, derecha

ref class Chef
{
private:
	int x, y;
	int dx;
	int ancho, alto;
	Bitmap^ sprite_chef;
	Direccion direccion;
	int velocidad;
public:
	Chef();
	~Chef();

	void cargar_sprite_chef(String^ ruta_sprite_chef);
	void dibujar_sprite_chef(Graphics^ graphics);
	void cambiar_direccion(Direccion cambiar_direccion);
	void mover(int ancho_ventana);
};

Chef::Chef()
{
	x = 100;
	y = 100;
	dx = 0;
	direccion = Direccion::Ninguna; //Empieza en idle
	velocidad = 5; //Se mueve con una velocidad de 5
}

Chef::~Chef()
{
	delete sprite_chef;
}

void Chef::cargar_sprite_chef(String^ ruta_sprite_chef)
{
	sprite_chef = gcnew Bitmap(ruta_sprite_chef);
	ancho = sprite_chef->Width / 3; //Numero de columnas
	alto = sprite_chef->Height / 4; //Numero de filas
}

void Chef::dibujar_sprite_chef(Graphics^ graphics)
{
	Rectangle origen = Rectangle(0, 0, ancho, alto);
	Rectangle destino = Rectangle(x, y, ancho, alto);
	graphics->DrawImage(sprite_chef, destino, origen, GraphicsUnit::Pixel);
}

void Chef::cambiar_direccion(Direccion cambiar_direccion)
{
	direccion = cambiar_direccion; //Guarda hacia donde va el chef

	if (direccion == Direccion::Izquierda)
	{
		dx = -velocidad;
	}

	else if (direccion == Direccion::Derecha)
	{
		dx = velocidad;
	}

	else
	{
		dx = 0;
	}
}

void Chef::mover(int ancho_ventana)
{
	x = x + dx;                               // Da un paso. Ej: x = 100 y dx = 5, ahora x = 105

	if (x < 0)                                // ¿Se pasó de la pared izquierda?
	{
		x = 0;                                // Lo pego a la pared izquierda
	}

	if (x + ancho > ancho_ventana)            // ¿Se pasó de la pared derecha? (x + ancho es su lado derecho)
	{
		x = ancho_ventana - ancho;            // Lo pego a la pared derecha
	}
}