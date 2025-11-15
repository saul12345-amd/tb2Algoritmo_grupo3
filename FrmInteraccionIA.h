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
		}

	protected:
		~FrmInteraccionIA()
		{
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
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
			// FrmInteraccionIA
			// 
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1172, 753);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->btnOmitirDialogo);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->lblInteraccion);
			this->Controls->Add(this->pictureBox2);
			this->Name = L"FrmInteraccionIA";
			this->Text = L"FrmInteraccionIA";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmInteraccionIA::FrmInteraccionIA_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void FrmInteraccionIA_Load(System::Object^ sender, System::EventArgs^ e) {

		// Inicializar lista
		dialogos = gcnew List<String^>();

		// Intentar obtener 3 diálogos del servicio
		for (int i = 0; i < 3; i++) {
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
		timerEfectoTexto->Interval = 50; // 50ms entre cada letra (ajusta según prefieras)
		timerEfectoTexto->Tick += gcnew EventHandler(this, &FrmInteraccionIA::MostrarSiguienteLetra);

		// Crear Timer para cambio automático de diálogo
		timerDialogos = gcnew System::Windows::Forms::Timer();
		timerDialogos->Interval = 1000; // Se activa cuando termina de mostrar el texto
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
			MostrarDialogoConEfecto(dialogos[indiceDialogo]);
		}
		else {
			// Ya terminaron todos los diálogos
			// Puedes cerrar el form o hacer otra acción
			// this->Close();
		}
	}

	private: System::Void btnOmitirDialogo_Click(System::Object^ sender, System::EventArgs^ e) {
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
	}
};
}