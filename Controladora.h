#pragma once
#include "Ingrediente.h"
#include "Chef.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class Controladora
{
private:
	Chef^ chef;
	List<Ingrediente^>^ ingredientes;
	Bitmap^ sprite_ingrediente;
	Random^ azar;
public:
	Controladora();
	~Controladora();

	void crear_ingrediente(int ancho_ventana);
	void dibujar(Graphics^ graphics);
};

Controladora::Controladora()
{
	chef = gcnew Chef(); //Crea un chef y guárdalo en mi caja chef
	chef->cargar_sprite_chef("sprites/Sprite-0001.png"); //Chef, carga tu dibujo desde este archivo

	ingredientes = gcnew List<Ingrediente^>(); //Crea una lista vacía para guardar ingredientes. Ahora no hay ninguno
	azar = gcnew Random(); //Consigue un dado para sacar números al azar
	sprite_ingrediente = gcnew Bitmap("sprites/Sprite-0002.png"); //Abre el dibujo de los ingredientes y guárdalo
}

Controladora::~Controladora()
{
	delete sprite_ingrediente;
}

void Controladora::crear_ingrediente(int ancho_ventana)
{
	ingredientes->Add(gcnew Ingrediente(300, 2, sprite_ingrediente));
}

void Controladora::dibujar(Graphics^ graphics)
{
	for (int i = 0; i < ingredientes->Count; i++)
	{
		ingredientes[i]->dibujar_sprite_ingrediente(graphics);
	}
}