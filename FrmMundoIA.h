#pragma once
#include "MundoIAService.h"
#include "FrmInteraccionIA.h"
namespace tb2Algoritmo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmMundoIA
	/// </summary>
	public ref class FrmMundoIA : public System::Windows::Forms::Form
	{
	public:
		FrmMundoIA(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			//int nroVidas = rand()% 3;
			service = new MundoIAService(pnlMundo->Width, pnlMundo->Height, 3);

			char rutaFondo[] = "fondo1.png";
			service->cargarFondo(rutaFondo);

			char rutaMadre[] = "madre.png";
			service->cargarSpriteMadre(rutaMadre, 4, 4);

			char rutaPersonaje[] = "protagonista.png";
			service->cargarSpriteProtagonista(rutaPersonaje, 4, 4);

			//TODO: HAMP(recomienda) en caso desee generar recursos aleatoriamente
			// service->generarRecursos(5); // Generar 5 monedas aleatoriamente

			// Generar recursos en posiciones fijas
			service->generarRecursos();
			service->generarObstaculos();
			// Mostrar monedas y vidas iniciales cargadas
			lblMonedas->Text = "Recursos: " + service->getRecursosRecolectados();
			lblVidas->Text = "Vidas: " + service->getVidas();

			teclaPresionada = Direccion::Ninguno;
			contadorMensaje = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmMundoIA()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlMundo;
	private: System::Windows::Forms::Label^ lblMensaje;
	private: System::Windows::Forms::Label^ lblMonedas;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Button^ btnResetear;
	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

	private:
		MundoIAService* service;
	private: System::Windows::Forms::Timer^ timer1;
		   Direccion teclaPresionada;
		   int contadorMensaje;


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->pnlMundo = (gcnew System::Windows::Forms::Panel());
			   this->btnResetear = (gcnew System::Windows::Forms::Button());
			   this->lblVidas = (gcnew System::Windows::Forms::Label());
			   this->lblMonedas = (gcnew System::Windows::Forms::Label());
			   this->lblMensaje = (gcnew System::Windows::Forms::Label());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->pnlMundo->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // pnlMundo
			   // 
			   this->pnlMundo->Controls->Add(this->btnResetear);
			   this->pnlMundo->Controls->Add(this->lblVidas);
			   this->pnlMundo->Controls->Add(this->lblMonedas);
			   this->pnlMundo->Controls->Add(this->lblMensaje);
			   this->pnlMundo->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pnlMundo->Location = System::Drawing::Point(0, 0);
			   this->pnlMundo->Name = L"pnlMundo";
			   this->pnlMundo->Size = System::Drawing::Size(1924, 1170);
			   this->pnlMundo->TabIndex = 0;
			   this->pnlMundo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMundoIA::pnlMundo_Paint);
			   // 
			   // btnResetear
			   // 
			   this->btnResetear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				   static_cast<System::Int32>(static_cast<System::Byte>(69)));
			   this->btnResetear->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			   this->btnResetear->ForeColor = System::Drawing::Color::White;
			   this->btnResetear->Location = System::Drawing::Point(1665, 567);
			   this->btnResetear->Name = L"btnResetear";
			   this->btnResetear->Size = System::Drawing::Size(225, 63);
			   this->btnResetear->TabIndex = 2;
			   this->btnResetear->Text = L"Resetear Progreso";
			   this->btnResetear->UseVisualStyleBackColor = false;
			   this->btnResetear->Click += gcnew System::EventHandler(this, &FrmMundoIA::btnResetear_Click);
			   // 
			   // lblVidas
			   // 
			   this->lblVidas->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(220)),
				   static_cast<System::Int32>(static_cast<System::Byte>(53)), static_cast<System::Int32>(static_cast<System::Byte>(69)));
			   this->lblVidas->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Bold));
			   this->lblVidas->ForeColor = System::Drawing::Color::White;
			   this->lblVidas->Location = System::Drawing::Point(1670, 808);
			   this->lblVidas->Name = L"lblVidas";
			   this->lblVidas->Padding = System::Windows::Forms::Padding(16, 12, 16, 12);
			   this->lblVidas->Size = System::Drawing::Size(231, 65);
			   this->lblVidas->TabIndex = 2;
			   this->lblVidas->Text = L"Vidas: 3";
			   // 
			   // lblMonedas
			   // 
			   this->lblMonedas->AutoSize = true;
			   this->lblMonedas->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(215)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->lblMonedas->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Bold));
			   this->lblMonedas->ForeColor = System::Drawing::Color::White;
			   this->lblMonedas->Location = System::Drawing::Point(1643, 682);
			   this->lblMonedas->Name = L"lblMonedas";
			   this->lblMonedas->Padding = System::Windows::Forms::Padding(16, 12, 16, 12);
			   this->lblMonedas->Size = System::Drawing::Size(279, 70);
			   this->lblMonedas->TabIndex = 1;
			   this->lblMonedas->Text = L"Recursos: 0";
			   // 
			   // lblMensaje
			   // 
			   this->lblMensaje->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->lblMensaje->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			   this->lblMensaje->ForeColor = System::Drawing::Color::Yellow;
			   this->lblMensaje->Location = System::Drawing::Point(3, 911);
			   this->lblMensaje->Name = L"lblMensaje";
			   this->lblMensaje->Padding = System::Windows::Forms::Padding(12);
			   this->lblMensaje->Size = System::Drawing::Size(2008, 263);
			   this->lblMensaje->TabIndex = 0;
			   this->lblMensaje->Visible = false;
			   // 
			   // timer1
			   // 
			   this->timer1->Tick += gcnew System::EventHandler(this, &FrmMundoIA::timer1_Tick);
			   // 
			   // FrmMundoIA
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1924, 1170);
			   this->Controls->Add(this->pnlMundo);
			   this->KeyPreview = true;
			   this->Name = L"FrmMundoIA";
			   this->Text = L"FrmMundoIA";
			   this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			   this->Load += gcnew System::EventHandler(this, &FrmMundoIA::FrmMundoIA_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMundoIA::FrmMundoIA_KeyDown);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMundoIA::FrmMundoIA_KeyUp);
			   this->pnlMundo->ResumeLayout(false);
			   this->pnlMundo->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void FrmMundoIA_Load(System::Object^ sender, System::EventArgs^ e) {
		FrmInteraccionIA^ frmInteraccion = gcnew FrmInteraccionIA();
		frmInteraccion->ShowDialog();
		timer1->Start();
	}


	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		// Solo verificar colision si no hay un dialogo visible
		if (!lblMensaje->Visible) {
			bool hayColision = service->verificarColisionProtagonistaRecurso();
			if (hayColision) {
				// Iniciar un dialogo aleatorio
				service->iniciarDialogoAleatorio();
				lblMensaje->Visible = true;
			}
		}
		if (!lblMensaje->Visible) {
			bool hayColisionMadre = service->verificarColisionProtagonistaMadre();
			if (hayColisionMadre) {
				// Iniciar un dialogo aleatorio
				service->iniciarDialogoAleatorio();
				lblMensaje->Visible = true;
			}
		}
		if (!lblMensaje->Visible) {
			bool hayColisionObstaculo = service->verificarColisionProtagonistaObstaculo();
			if (hayColisionObstaculo) {
				// Iniciar un dialogo aleatorio
				service->iniciarDialogoAleatorio();
				lblMensaje->Visible = true;
			}
		}

		// Actualizar y mostrar el dialogo letra por letra
		if (service->dialogoEnProgreso()) {
			service->actualizarDialogo();
			string textoActual = service->obtenerTextoDialogoActual();
			lblMensaje->Text = gcnew String(textoActual.c_str());
		}
		else if (lblMensaje->Visible && !service->dialogoEnProgreso()) {
			// Si el dialogo termino, esperar un tiempo antes de ocultarlo
			contadorMensaje++;
			/*TODO HAMP (Explica)


			  A 30 FPS:
			  - 90 caracteres ÷ 3 letras/frame = 30 frames
			  - 30 frames ÷ 30 FPS = 1 segundo ← Aquí está el paso que falta

			  A 60 FPS:
			  - 90 caracteres ÷ 3 letras/frame = 30 frames
			  - 30 frames ÷ 60 FPS = 0.5 segundos ← Aquí también falta


			  Tiempo = Caracteres / (Letras_por_frame × FPS)

			  Ejemplo:
			  - A 30 FPS: 90 / (3 × 30) = 90/90 = 1 segundo
			  - A 60 FPS: 90 / (3 × 60) = 90/180 = 0.5 segundos

			  - Frame 1: Muestra "Hol"
			  - Frame 2: Muestra "Hola m"
			  - Frame 3: Muestra "Hola mundo"
			  - Y así sucesivamente...

			  Si tu juego corre a 60 FPS (frames por segundo), estarías mostrando 180 letras por segundo (60 frames × 3 letras), lo que da un efecto de escritura rápida y fluida.
			*/
			if (contadorMensaje >= 60) { // Mostrar 60 frames (aprox. 0.5 segundo) despues de terminar
				lblMensaje->Visible = false;
				contadorMensaje = 0;
			}
		}
		service->moverObstaculos();
		service->moverMadre();
		service->moverProtagonista(teclaPresionada);
		service->moverRecursos();

		// Actualizar contador de monedas y vidas
		lblMonedas->Text = "Recursos: " + service->getRecursosRecolectados();
		lblVidas->Text = "Vidas: " + service->getVidas();

		Graphics^ canvas = pnlMundo->CreateGraphics();

		BufferedGraphicsContext^ espacio_buffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio_buffer->Allocate(canvas, pnlMundo->ClientRectangle);

		service->dibujarTodo(buffer->Graphics);
		buffer->Render(canvas);

		delete buffer;
		delete canvas;
	}

	private: System::Void FrmMundoIA_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Up:
		case Keys::W:
			teclaPresionada = Direccion::Arriba;
			break;
		case Keys::Down:
		case Keys::S:
			teclaPresionada = Direccion::Abajo;
			break;
		case Keys::Left:
		case Keys::A:
			teclaPresionada = Direccion::Izquierda;
			break;
		case Keys::Right:
		case Keys::D:
			teclaPresionada = Direccion::Derecha;
			break;
		}
	}

	private: System::Void FrmMundoIA_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		teclaPresionada = Direccion::Ninguno;
	}

	private: System::Void btnResetear_Click(System::Object^ sender, System::EventArgs^ e) {
		// Confirmar antes de resetear
		System::Windows::Forms::DialogResult resultado = MessageBox::Show(
			"¿Estas seguro que desea resetear el progreso?\n\nSe perderan todas las monedas recolectadas y las vidas.",
			"Confirmar Reset",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Warning
		);

		if (resultado == System::Windows::Forms::DialogResult::Yes) {
			// Resetear progreso (tanto en archivo como en memoria)
			service->resetRecursosRecolectados();

			// Actualizar labels inmediatamente
			lblMonedas->Text = "Recursos: 0";
			lblVidas->Text = "Vidas: 3";

			// Mostrar mensaje de confirmación
			MessageBox::Show(
				"Progreso reseteado exitosamente.",
				"Reset Completo",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);
		}
	}
	private: System::Void pnlMundo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	};
}
