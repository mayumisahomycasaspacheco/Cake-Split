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
	int fila, columna;
	int escala;
	int contador;
public:
	Chef();
	~Chef();

	void cargar_sprite_chef(String^ ruta_sprite_chef);
	void dibujar_sprite_chef(Graphics^ graphics);
	void cambiar_direccion(Direccion cambiar_direccion);
	void mover(int ancho_ventana);

	Rectangle area_captura();
};

Chef::Chef()
{
	x = 200;
	y = 300;
	dx = 0;
	direccion = Direccion::Ninguna; //Empieza en idle
	velocidad = 4; //Se mueve con una velocidad de 3
	fila = 0;
	columna = 0;
	escala = 3;
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
	Rectangle origen = Rectangle(columna * ancho, fila * alto, ancho, alto);
	Rectangle destino = Rectangle(x, y, ancho * escala, alto * escala);

	graphics->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::NearestNeighbor;
	graphics->PixelOffsetMode = System::Drawing::Drawing2D::PixelOffsetMode::Half;

	graphics->DrawImage(sprite_chef, destino, origen, GraphicsUnit::Pixel);
}

void Chef::cambiar_direccion(Direccion cambiar_direccion)
{
	direccion = cambiar_direccion; //Guarda hacia donde va el chef

	if (direccion == Direccion::Izquierda)
	{
		dx = -velocidad;
		fila = 1;
	}

	else if (direccion == Direccion::Derecha)
	{
		dx = velocidad;
		fila = 2;
	}

	else
	{
		dx = 0;
		fila = 0;
	}
}

void Chef::mover(int ancho_ventana)
{
	x = x + dx;                               // Da un paso. Ej: x = 100 y dx = 5, ahora x = 105

	if (x < 0)                                // ¿Se pasó de la pared izquierda?
	{
		x = 0;                                // Lo pego a la pared izquierda
	}

	if (x + ancho * escala > ancho_ventana)            // ¿Se pasó de la pared derecha? (x + ancho * escala es su lado derecho)
	{
		x = ancho_ventana - ancho * escala;            // Lo pego a la pared derecha
	}

	if (dx != 0) //Solo se anima si esta caminando
	{
		contador = contador + 1;

		if (contador >= 5)
		{
			contador = 0;
			columna = columna + 1;

			if (columna > 2)
			{
				columna = 0;
			}
		}
	}

	else
	{
		contador = 0;
		columna = 0;
	}
}

Rectangle Chef::area_captura()
{
	return Rectangle(x, y, ancho * , alto * );
}