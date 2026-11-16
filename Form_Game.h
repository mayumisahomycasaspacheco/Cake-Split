#pragma once
#include "Chef.h"
#include "Controladora.h"

namespace CakeSplit {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Form_Game
	/// </summary>
	public ref class Form_Game : public System::Windows::Forms::Form
	{
	public:
		Form_Game(void)
		{
			InitializeComponent();

			this->DoubleBuffered = true;

			juego = gcnew Controladora();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Form_Game()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:
	private: System::Windows::Forms::Timer^ timer1;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

	private: System::Windows::Forms::Timer^ timer2;
		   Controladora^ juego;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>

		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->SuspendLayout();
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Interval = 30;
			   this->timer1->Tick += gcnew System::EventHandler(this, &Form_Game::timer1_Tick);
			   // 
			   // timer2
			   // 
			   this->timer2->Enabled = true;
			   this->timer2->Interval = 1000;
			   this->timer2->Tick += gcnew System::EventHandler(this, &Form_Game::timer2_Tick);
			   // 
			   // Form_Game
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(782, 553);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->KeyPreview = true;
			   this->MaximizeBox = false;
			   this->Name = L"Form_Game";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Cake Split";
			   this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form_Game::Form_Game_Paint);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form_Game::Form_Game_KeyDown);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form_Game::Form_Game_KeyUp);
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		juego->mover(this->ClientSize.Width);
		juego->atrapar_ingredientes();

		if (juego->gano())
		{
			timer1->Stop();
			timer2->Stop();
			MessageBox::Show("¡Armaste el pastel!");
			this->Close();
			return;
		}

		juego->eliminar_fuera_de_la_pantalla(this->ClientSize.Height);

		this->Invalidate();
	}
	private: System::Void Form_Game_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		if (e->KeyCode == Keys::Left) //Izquierda
		{
			juego->cambiar_direccion_chef(Direccion::Izquierda);
		}

		if (e->KeyCode == Keys::Right)
		{
			juego->cambiar_direccion_chef(Direccion::Derecha);
		}
	}
	private: System::Void Form_Game_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		if (e->KeyCode == Keys::Left)
		{
			juego->cambiar_direccion_chef(Direccion::Ninguna);
		}

		if (e->KeyCode == Keys::Right)
		{
			juego->cambiar_direccion_chef(Direccion::Ninguna);
		}
	}
	private: System::Void Form_Game_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		e->Graphics->Clear(Color::White);
		juego->dibujar(e->Graphics);
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		juego->crear_ingrediente(this->ClientSize.Width);
	}
	};
}