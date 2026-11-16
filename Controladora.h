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
	void mover(int ancho_ventana);
	void cambiar_direccion_chef(Direccion direccion);
	void eliminar_fuera_de_la_pantalla(int alto_ventana);

	void atrapar_ingredientes();
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
	int x = azar->Next(0, ancho_ventana - sprite_ingrediente->Width * 3);
	int tipo = azar->Next(0, 4);

	ingredientes->Add(gcnew Ingrediente(x, tipo, sprite_ingrediente));
}

void Controladora::dibujar(Graphics^ graphics)
{
	chef->dibujar_sprite_chef(graphics);
	
	for (int i = 0; i < ingredientes->Count; i++)
	{
		ingredientes[i]->dibujar_sprite_ingrediente(graphics);
	}
}

void Controladora::cambiar_direccion_chef(Direccion direccion)
{
	chef->cambiar_direccion(direccion);
}

void Controladora::mover(int ancho_ventana)
{
	chef->mover(ancho_ventana);
	
	for (int i = 0; i < ingredientes->Count; i++)
	{
		ingredientes[i]->mover();
	}
}

void Controladora::eliminar_fuera_de_la_pantalla(int alto_ventana)
{
	for (int i = ingredientes->Count - 1; i >= 0; i--)
	{
		if (ingredientes[i]->salio_de_pantalla(alto_ventana))
		{
			ingredientes->RemoveAt(i);
		}
	}
}