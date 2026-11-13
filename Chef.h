#pragma once
using namespace System;
using namespace System::Drawing;

ref class Chef
{
private:
	int x, y;
	int dx;
	int ancho, alto;
	Bitmap^ sprite_chef;
public:
	Chef();
	~Chef();

	void cargar_sprite_chef(String^ ruta_sprite_chef);
	void dibujar_sprite_chef(Graphics^ graphics);
};

Chef::Chef()
{
	x = 100;
	y = 100;
	dx = 0;
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