#pragma once
#include "FrmMundoIA.h"
#include "FrmInstrucciones.h"
#include "FrmCreditos.h"
namespace tb2Algoritmo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FrmMenu : public System::Windows::Forms::Form
	{
	public:
		FrmMenu(void)
		{
			InitializeComponent();
		}

	protected:
		~FrmMenu()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btnCreditos;
	private: System::Windows::Forms::Button^ btnSalir;
	private: System::Windows::Forms::Button^ btnInstrucciones;
	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Button^ btnJugar;
	private: AxWMPLib::AxWindowsMediaPlayer^ axWindowsMediaPlayer1;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmMenu::typeid));
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->btnJugar = (gcnew System::Windows::Forms::Button());
			this->axWindowsMediaPlayer1 = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnCreditos
			// 
			this->btnCreditos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnCreditos->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCreditos.Image")));
			this->btnCreditos->Location = System::Drawing::Point(699, 447);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(194, 46);
			this->btnCreditos->TabIndex = 0;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &FrmMenu::btnCreditos_Click_1);
			// 
			// btnSalir
			// 
			this->btnSalir->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnSalir->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSalir.Image")));
			this->btnSalir->Location = System::Drawing::Point(699, 565);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(194, 48);
			this->btnSalir->TabIndex = 1;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FrmMenu::btnSalir_Click_1);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnInstrucciones->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnInstrucciones.Image")));
			this->btnInstrucciones->Location = System::Drawing::Point(699, 499);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(194, 49);
			this->btnInstrucciones->TabIndex = 2;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &FrmMenu::btnInstrucciones_Click_1);
			// 
			// lblTitulo
			// 
			this->lblTitulo->BackColor = System::Drawing::Color::Blue;
			this->lblTitulo->ForeColor = System::Drawing::Color::White;
			this->lblTitulo->Location = System::Drawing::Point(162, 165);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(582, 63);
			this->lblTitulo->TabIndex = 3;
			this->lblTitulo->Text = L"IA VS PENSAMIENTO CRITICO";
			// 
			// btnJugar
			// 
			this->btnJugar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnJugar.Image")));
			this->btnJugar->Location = System::Drawing::Point(699, 370);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(194, 71);
			this->btnJugar->TabIndex = 4;
			this->btnJugar->Click += gcnew System::EventHandler(this, &FrmMenu::btnJugar_Click);
			// 
			// axWindowsMediaPlayer1
			// 
			this->axWindowsMediaPlayer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->axWindowsMediaPlayer1->Enabled = true;
			this->axWindowsMediaPlayer1->Location = System::Drawing::Point(0, 0);
			this->axWindowsMediaPlayer1->Name = L"axWindowsMediaPlayer1";
			this->axWindowsMediaPlayer1->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"axWindowsMediaPlayer1.OcxState")));
			this->axWindowsMediaPlayer1->Size = System::Drawing::Size(1054, 779);
			this->axWindowsMediaPlayer1->TabIndex = 11;
			// 
			// FrmMenu
			// 
			this->ClientSize = System::Drawing::Size(1054, 779);
			this->Controls->Add(this->btnCreditos);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->btnJugar);
			this->Controls->Add(this->axWindowsMediaPlayer1);
			this->Name = L"FrmMenu";
			this->Load += gcnew System::EventHandler(this, &FrmMenu::FrmMenu_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->EndInit();
			this->ResumeLayout(false);

		}

#pragma endregion

	private: System::Void FrmMenu_Load(System::Object^ sender, System::EventArgs^ e) {

		// Ruta del video (debe estar en bin/Debug o Release)
		String^ rutaVideo = Application::StartupPath + "\\FondoMenu.mp4";

		axWindowsMediaPlayer1->URL = rutaVideo;

		// Ocultar controles
		axWindowsMediaPlayer1->uiMode = "none";

		// Loop infinito
		axWindowsMediaPlayer1->settings->setMode("loop", true);

		// Reproducir
		axWindowsMediaPlayer1->Ctlcontrols->play();
	}

	private: System::Void btnJugar_Click(System::Object^ sender, System::EventArgs^ e) {
		FrmMundoIA^ frmMundoIA = gcnew FrmMundoIA();
		frmMundoIA->Show();
	}
	private: 
		Void btnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
			// Código para mostrar instrucciones
			FrmInstrucciones^ frmInstrucciones = gcnew FrmInstrucciones();
			frmInstrucciones->Show();
		}
		Void btnCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
			// Código para mostrar créditos
			FrmCreditos^ frmCreditos = gcnew FrmCreditos();
			frmCreditos->Show();
		}
		Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
			Application::Exit();
		}
	private: System::Void btnCreditos_Click_1(System::Object^ sender, System::EventArgs^ e) {
		FrmCreditos^ frmCreditos = gcnew FrmCreditos();
		frmCreditos->Show();
	}
private: System::Void btnInstrucciones_Click_1(System::Object^ sender, System::EventArgs^ e) {
	FrmInstrucciones^ frmInstrucciones = gcnew FrmInstrucciones();
	frmInstrucciones->Show();
}
private: System::Void btnSalir_Click_1(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
};
}
