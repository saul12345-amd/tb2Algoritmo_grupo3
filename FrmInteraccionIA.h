#pragma once
#include "DialogoInteraccionService.h"

namespace tb2Algoritmo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FrmInteraccionIA : public System::Windows::Forms::Form
	{
	public:
		FrmInteraccionIA(void)
		{
			InitializeComponent();
			gestorDialogosInteraccion = new DialogoInteraccionService();
			groupBox1->Visible = false;
			groupBox1->BringToFront();  // Asegurar que esté al frente
		}

	protected:
		~FrmInteraccionIA()
		{
			if (timerEfectoTexto != nullptr) {
				timerEfectoTexto->Stop();
				delete timerEfectoTexto;
			}

			if (timerDialogos != nullptr) {
				timerDialogos->Stop();
				delete timerDialogos;
			}

			if (components)
				delete components;

			delete gestorDialogosInteraccion;
		}

	private:
		DialogoInteraccionService* gestorDialogosInteraccion;

		// Timers
		System::Windows::Forms::Timer^ timerDialogos;      // Para cambiar de diálogo
		System::Windows::Forms::Timer^ timerEfectoTexto;   // Para efecto letra por letra

		System::Windows::Forms::Button^ btnOmitir;
		List<String^>^ dialogos;
		int indiceDialogo = 0;

		// Variables para efecto de texto
		String^ textoCompleto;
		int caracterActual = 0;
		bool mostrandoTexto = false;

	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ lblInteraccion;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnOmitirDialogo;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btnOpcionC;
	private: System::Windows::Forms::Button^ btnOpcionB;
	private: System::Windows::Forms::Button^ btnOpcionA;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmInteraccionIA::typeid));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->lblInteraccion = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnOmitirDialogo = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnOpcionC = (gcnew System::Windows::Forms::Button());
			this->btnOpcionB = (gcnew System::Windows::Forms::Button());
			this->btnOpcionA = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(-14, -15);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(1257, 851);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// lblInteraccion
			// 
			this->lblInteraccion->BackColor = System::Drawing::Color::DimGray;
			this->lblInteraccion->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblInteraccion->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			this->lblInteraccion->ForeColor = System::Drawing::Color::White;
			this->lblInteraccion->Location = System::Drawing::Point(131, 540);
			this->lblInteraccion->Name = L"lblInteraccion";
			this->lblInteraccion->Size = System::Drawing::Size(854, 146);
			this->lblInteraccion->TabIndex = 1;
			this->lblInteraccion->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::UpArrow;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(284, 213);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(149, 295);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &FrmInteraccionIA::pictureBox1_Click);
			// 
			// btnOmitirDialogo
			// 
			this->btnOmitirDialogo->BackColor = System::Drawing::Color::Gainsboro;
			this->btnOmitirDialogo->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnOmitirDialogo->Location = System::Drawing::Point(872, 491);
			this->btnOmitirDialogo->Name = L"btnOmitirDialogo";
			this->btnOmitirDialogo->Size = System::Drawing::Size(134, 34);
			this->btnOmitirDialogo->TabIndex = 4;
			this->btnOmitirDialogo->Text = L"omitir";
			this->btnOmitirDialogo->UseVisualStyleBackColor = false;
			this->btnOmitirDialogo->Click += gcnew System::EventHandler(this, &FrmInteraccionIA::btnOmitirDialogo_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Gray;
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox3->Cursor = System::Windows::Forms::Cursors::UpArrow;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(131, 574);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(59, 88);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox3->TabIndex = 5;
			this->pictureBox3->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->btnOpcionC);
			this->groupBox1->Controls->Add(this->btnOpcionB);
			this->groupBox1->Controls->Add(this->btnOpcionA);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Enabled = false;
			this->groupBox1->Location = System::Drawing::Point(535, 64);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(450, 400);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Enter += gcnew System::EventHandler(this, &FrmInteraccionIA::groupBox1_Enter);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::White;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 10.5F));
			this->label2->Location = System::Drawing::Point(40, 65);
			this->label2->Name = L"label2";
			this->label2->Padding = System::Windows::Forms::Padding(10);
			this->label2->Size = System::Drawing::Size(370, 90);
			this->label2->TabIndex = 4;
			this->label2->Text = L"¿Qué aspecto del pensamiento humano continúa siendo más difícil de reemplazar por"
				L" la Inteligencia Artificial\?";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// btnOpcionC
			// 
			this->btnOpcionC->BackColor = System::Drawing::Color::LightSteelBlue;
			this->btnOpcionC->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnOpcionC->Font = (gcnew System::Drawing::Font(L"Arial", 9.5F));
			this->btnOpcionC->Location = System::Drawing::Point(40, 310);
			this->btnOpcionC->Name = L"btnOpcionC";
			this->btnOpcionC->Size = System::Drawing::Size(370, 60);
			this->btnOpcionC->TabIndex = 3;
			this->btnOpcionC->Text = L"c) La velocidad para procesar grandes cantidades de información simultáneamente.";
			this->btnOpcionC->UseVisualStyleBackColor = false;
			this->btnOpcionC->Click += gcnew System::EventHandler(this, &FrmInteraccionIA::btnOpcion_Click);
			// 
			// btnOpcionB
			// 
			this->btnOpcionB->BackColor = System::Drawing::Color::LightSteelBlue;
			this->btnOpcionB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnOpcionB->Font = (gcnew System::Drawing::Font(L"Arial", 9.5F));
			this->btnOpcionB->Location = System::Drawing::Point(40, 240);
			this->btnOpcionB->Name = L"btnOpcionB";
			this->btnOpcionB->Size = System::Drawing::Size(370, 60);
			this->btnOpcionB->TabIndex = 2;
			this->btnOpcionB->Text = L"b) La habilidad de interpretar emociones, contexto social y valores éticos en sit"
				L"uaciones ambiguas.";
			this->btnOpcionB->UseVisualStyleBackColor = false;
			this->btnOpcionB->Click += gcnew System::EventHandler(this, &FrmInteraccionIA::btnOpcion_Click);
			// 
			// btnOpcionA
			// 
			this->btnOpcionA->BackColor = System::Drawing::Color::LightSteelBlue;
			this->btnOpcionA->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnOpcionA->Font = (gcnew System::Drawing::Font(L"Arial", 9.5F));
			this->btnOpcionA->Location = System::Drawing::Point(40, 170);
			this->btnOpcionA->Name = L"btnOpcionA";
			this->btnOpcionA->Size = System::Drawing::Size(370, 60);
			this->btnOpcionA->TabIndex = 1;
			this->btnOpcionA->Text = L"a) La capacidad de seguir patrones lógicos y resolver problemas matemáticos rápid"
				L"amente.";
			this->btnOpcionA->UseVisualStyleBackColor = false;
			this->btnOpcionA->Click += gcnew System::EventHandler(this, &FrmInteraccionIA::btnOpcion_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(120, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(259, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Pregunta de reflexión";
			// 
			// FrmInteraccionIA
			// 
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1172, 753);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->btnOmitirDialogo);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->lblInteraccion);
			this->Controls->Add(this->pictureBox2);
			this->Name = L"FrmInteraccionIA";
			this->Text = L"Interacción con IA";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmInteraccionIA::FrmInteraccionIA_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void FrmInteraccionIA_Load(System::Object^ sender, System::EventArgs^ e) {

		// Inicializar lista
		dialogos = gcnew List<String^>();

		// Intentar obtener 4 diálogos del servicio
		for (int i = 0; i < 4; i++) {
			try {
				std::string tmp = gestorDialogosInteraccion->obtenerDialogoInteraccion(i, "MundoIA");
				if (tmp.size() > 0) {
					String^ s = gcnew String(tmp.c_str());
					dialogos->Add(s);
				}
				else {
					dialogos->Add("[Diálogo vacío]");
				}
			}
			catch (...) {
				dialogos->Add("[Error al cargar diálogo]");
			}
		}

		if (dialogos->Count == 0) {
			lblInteraccion->Text = "No hay diálogos disponibles.";
			return;
		}

		// Crear Timer para efecto de texto letra por letra
		timerEfectoTexto = gcnew System::Windows::Forms::Timer();
		timerEfectoTexto->Interval = 50; // 50ms entre cada letra
		timerEfectoTexto->Tick += gcnew EventHandler(this, &FrmInteraccionIA::MostrarSiguienteLetra);

		// Crear Timer para cambio automático de diálogo
		timerDialogos = gcnew System::Windows::Forms::Timer();
		timerDialogos->Interval = 1000;
		timerDialogos->Tick += gcnew EventHandler(this, &FrmInteraccionIA::MostrarSiguienteDialogo);

		// Mostrar primer diálogo
		indiceDialogo = 0;
		MostrarDialogoConEfecto(dialogos[indiceDialogo]);
	}

		   // Inicia el efecto de texto letra por letra
	private: void MostrarDialogoConEfecto(String^ texto)
	{
		textoCompleto = texto;
		caracterActual = 0;
		lblInteraccion->Text = "";
		mostrandoTexto = true;

		// Detener timer de cambio de diálogo mientras se muestra el texto
		if (timerDialogos != nullptr && timerDialogos->Enabled) {
			timerDialogos->Stop();
		}

		// Iniciar timer de efecto de texto
		if (timerEfectoTexto != nullptr) {
			timerEfectoTexto->Start();
		}
	}

		   // Mostrar siguiente letra
	private: void MostrarSiguienteLetra(System::Object^ sender, System::EventArgs^ e)
	{
		if (caracterActual < textoCompleto->Length) {
			lblInteraccion->Text += textoCompleto[caracterActual];
			caracterActual++;
		}
		else {
			// Terminó de mostrar el texto
			timerEfectoTexto->Stop();
			mostrandoTexto = false;

			// Iniciar timer para cambiar al siguiente diálogo después de 3 segundos
			if (indiceDialogo < dialogos->Count - 1) {
				timerDialogos->Interval = 3000; // 3 segundos de pausa
				timerDialogos->Start();
			}
		}
	}

		   // Cambiar al siguiente diálogo
	private: void MostrarSiguienteDialogo(System::Object^ sender, System::EventArgs^ e)
	{
		timerDialogos->Stop();

		if (indiceDialogo < dialogos->Count - 1) {
			indiceDialogo++;

			// Verificar si es el 4to diálogo (índice 3)
			if (indiceDialogo == 3) {
				// Pausar y mostrar el GroupBox
				groupBox1->Visible = true;
				groupBox1->BringToFront();  // Traer al frente de todos los controles
				this->Refresh();  // Forzar actualización visual
				MostrarDialogoConEfecto(dialogos[indiceDialogo]);
				return;
			}

			MostrarDialogoConEfecto(dialogos[indiceDialogo]);
		}
		else {
			this->Close();
		}
	}

		   // Manejar clic en botones de opciones
	private: System::Void btnOpcion_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ botonSeleccionado = safe_cast<Button^>(sender);

		// Identificar qué botón fue presionado
		String^ respuesta = "";
		String^ mensaje = "";

		if (botonSeleccionado == btnOpcionA) {
			respuesta = "Opción A";
			mensaje = "Has seleccionado la opción A.\n\nLa IA es excelente en patrones lógicos, pero esta no es la respuesta correcta.";
		}
		else if (botonSeleccionado == btnOpcionB) {
			respuesta = "Opción B - ¡Correcto!";
			mensaje = "¡Correcto! La opción B es la respuesta adecuada.\n\nLa interpretación de emociones, el contexto social y los valores éticos en situaciones ambiguas continúan siendo uno de los mayores desafíos para la IA.";
		}
		else if (botonSeleccionado == btnOpcionC) {
			respuesta = "Opción C";
			mensaje = "Has seleccionado la opción C.\n\nDe hecho, procesar grandes cantidades de información es una fortaleza de la IA, no una debilidad.";
		}

		// Deshabilitar los botones después de seleccionar
		btnOpcionA->Enabled = false;
		btnOpcionB->Enabled = false;
		btnOpcionC->Enabled = false;

		// Resaltar la opción seleccionada
		botonSeleccionado->BackColor = System::Drawing::Color::LightGreen;
		if (botonSeleccionado == btnOpcionB) {
			botonSeleccionado->BackColor = System::Drawing::Color::LightGreen;
		}
		else {
			botonSeleccionado->BackColor = System::Drawing::Color::LightCoral;
		}

		// Mostrar feedback
		MessageBox::Show(mensaje, respuesta, MessageBoxButtons::OK,
			botonSeleccionado == btnOpcionB ? MessageBoxIcon::Information : MessageBoxIcon::Warning);

		// Ocultar el groupBox después de un momento
		System::Threading::Thread::Sleep(500);
		groupBox1->Visible = false;

		// Cerrar el formulario
		System::Threading::Thread::Sleep(500);
		this->Close();
	}

		   // Botón omitir diálogo
	private: System::Void btnOmitirDialogo_Click(System::Object^ sender, System::EventArgs^ e) {

		// Si el GroupBox está visible, no permitir omitir sin responder
		if (groupBox1->Visible) {
			MessageBox::Show("Por favor responde la pregunta antes de continuar.",
				"Atención", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Si está mostrando texto letra por letra, completar inmediatamente
		if (mostrandoTexto && timerEfectoTexto != nullptr && timerEfectoTexto->Enabled) {
			timerEfectoTexto->Stop();
			lblInteraccion->Text = textoCompleto; // Mostrar texto completo
			mostrandoTexto = false;

			// Pasar al siguiente diálogo inmediatamente
			if (indiceDialogo < dialogos->Count - 1) {
				indiceDialogo++;
				MostrarDialogoConEfecto(dialogos[indiceDialogo]);
			}
			else {
				// Ya no hay más diálogos
				this->Close();
			}
		}
		else {
			// Si no está mostrando texto, pasar al siguiente diálogo directamente
			if (indiceDialogo < dialogos->Count - 1) {
				indiceDialogo++;
				MostrarDialogoConEfecto(dialogos[indiceDialogo]);
			}
			else {
				// Ya no hay más diálogos, cerrar
				this->Close();
			}
		}
	}

	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Puedes agregar funcionalidad aquí si necesitas
	}

	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
		// Evento del GroupBox
	}
	};
}