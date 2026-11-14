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
};

Controladora::Controladora()
{

}

Controladora::~Controladora()
{

}