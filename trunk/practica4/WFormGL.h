#pragma once
#include "WNOpenGL.h"
#include "src\Scene.h"
#include <msclr/marshal_cppstd.h>
#include "src\textures\PixmapY.h"

#define MOVE_FACTOR 0.01
#define ZOOM_FACTOR 0.05

using namespace Microsoft::VisualBasic;

namespace WinCliOpenGL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Summary for WFormGL
	/// </summary>
	public ref class WFormGL : public System::Windows::Forms::Form
	{
	public:
		WFormGL(void)
		{
      nwOpenGL = gcnew NWOpenGL(this, this->ClientSize.Width, this->ClientSize.Height); 
     //ReSizeGL(this->ClientSize.Width, this->ClientSize.Height);
			InitGL();
      scene = new Scene();
	  RatioViewPort= (float)ClientSize.Width/(float)ClientSize.Height;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			// Viewport
			nwOpenGL->ResizeGL(this->ClientSize.Width,this->ClientSize.Height);
			glViewport(0, 0, this->ClientSize.Width, this->ClientSize.Height);
			
				// Model transformation
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();

				// Scene Visible Area
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				gluOrtho2D(scene->xL, scene->xR, scene->yB, scene->yT);

		}
  // metodos public definidos en el cpp
    GLvoid InitGL();
    GLvoid GLScene();
    GLvoid ReSizeGL(GLsizei width, GLsizei height);	
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~WFormGL()
		{
      delete scene;
      scene = nullptr;
      delete nwOpenGL;
			nwOpenGL = nullptr;

			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
    NWOpenGL ^ nwOpenGL;
    Scene * scene;
	GLfloat RatioViewPort;

  private: System::Windows::Forms::MenuStrip^  menuStrip1;


  private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::ToolStripMenuItem^  escenasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  escena1ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  accionesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  activarTimerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  moverUnPasoEnterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  escena2ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  depuraciónF1ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  escena3ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  colaToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  contornosToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  activarBoundingBoxToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  escena4ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  renderToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  generarUnÁrbolToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  gLSceneToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pixmapToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  guardarEnPixmapToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cargarPixmapToolStripMenuItem;







	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  tB_Xrot;
	private: System::Windows::Forms::TextBox^  tB_Yrot;
	private: System::Windows::Forms::TextBox^  tB_degreesRot;
	private: System::Windows::Forms::ToolStripMenuItem^  abrirDesdeFicheroToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  operacionesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mediaPonderadaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  diferenciaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  máscarasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  suavizado1ToolStripMenuItem;

private: System::Windows::Forms::TabControl^  tabControl1;
private: System::Windows::Forms::TabPage^  tabPage1;
private: System::Windows::Forms::TabPage^  tabPage2;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::Button^  b_weightedMean;
private: System::Windows::Forms::TextBox^  tB_factor_wm;
private: System::Windows::Forms::Label^  label4;

private: System::Windows::Forms::TabPage^  tabPage3;
private: System::Windows::Forms::Button^  b_gauss;

private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::TextBox^  tB_gauss_m;
private: System::Windows::Forms::TextBox^  tB_gauss_d;
private: System::Windows::Forms::ToolStripMenuItem^  opcionesToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  menuExtraToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  mostrarP3ToolStripMenuItem;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::TextBox^  tB_limit_x;
private: System::Windows::Forms::TextBox^  tB_limit_y;
private: System::Windows::Forms::CheckBox^  chk_limits;



	private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->opcionesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuExtraToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mostrarP3ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->accionesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->activarTimerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->moverUnPasoEnterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->activarBoundingBoxToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->escenasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->escena1ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->escena2ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->escena3ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->escena4ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->depuraciónF1ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contornosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->renderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->generarUnÁrbolToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gLSceneToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pixmapToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->abrirDesdeFicheroToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->operacionesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mediaPonderadaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->diferenciaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->máscarasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->suavizado1ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->guardarEnPixmapToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cargarPixmapToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tB_Xrot = (gcnew System::Windows::Forms::TextBox());
			this->tB_Yrot = (gcnew System::Windows::Forms::TextBox());
			this->tB_degreesRot = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->b_weightedMean = (gcnew System::Windows::Forms::Button());
			this->tB_factor_wm = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->b_gauss = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tB_gauss_m = (gcnew System::Windows::Forms::TextBox());
			this->tB_gauss_d = (gcnew System::Windows::Forms::TextBox());
			this->chk_limits = (gcnew System::Windows::Forms::CheckBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tB_limit_x = (gcnew System::Windows::Forms::TextBox());
			this->tB_limit_y = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->opcionesToolStripMenuItem, 
				this->accionesToolStripMenuItem, this->escenasToolStripMenuItem, this->depuraciónF1ToolStripMenuItem, this->renderToolStripMenuItem, 
				this->pixmapToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 1, 0, 1);
			this->menuStrip1->Size = System::Drawing::Size(1008, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// opcionesToolStripMenuItem
			// 
			this->opcionesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->menuExtraToolStripMenuItem, 
				this->mostrarP3ToolStripMenuItem});
			this->opcionesToolStripMenuItem->Name = L"opcionesToolStripMenuItem";
			this->opcionesToolStripMenuItem->Size = System::Drawing::Size(69, 22);
			this->opcionesToolStripMenuItem->Text = L"Opciones";
			// 
			// menuExtraToolStripMenuItem
			// 
			this->menuExtraToolStripMenuItem->CheckOnClick = true;
			this->menuExtraToolStripMenuItem->Name = L"menuExtraToolStripMenuItem";
			this->menuExtraToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->menuExtraToolStripMenuItem->Text = L"Menu extra";
			this->menuExtraToolStripMenuItem->Click += gcnew System::EventHandler(this, &WFormGL::menuExtraToolStripMenuItem_Click);
			// 
			// mostrarP3ToolStripMenuItem
			// 
			this->mostrarP3ToolStripMenuItem->CheckOnClick = true;
			this->mostrarP3ToolStripMenuItem->Name = L"mostrarP3ToolStripMenuItem";
			this->mostrarP3ToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->mostrarP3ToolStripMenuItem->Text = L"Mostrar P3";
			this->mostrarP3ToolStripMenuItem->Click += gcnew System::EventHandler(this, &WFormGL::mostrarP3ToolStripMenuItem_Click);
			// 
			// accionesToolStripMenuItem
			// 
			this->accionesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->activarTimerToolStripMenuItem, 
				this->moverUnPasoEnterToolStripMenuItem, this->activarBoundingBoxToolStripMenuItem});
			this->accionesToolStripMenuItem->Enabled = false;
			this->accionesToolStripMenuItem->Name = L"accionesToolStripMenuItem";
			this->accionesToolStripMenuItem->Size = System::Drawing::Size(67, 22);
			this->accionesToolStripMenuItem->Text = L"Acciones";
			// 
			// activarTimerToolStripMenuItem
			// 
			this->activarTimerToolStripMenuItem->CheckOnClick = true;
			this->activarTimerToolStripMenuItem->Name = L"activarTimerToolStripMenuItem";
			this->activarTimerToolStripMenuItem->Size = System::Drawing::Size(191, 22);
			this->activarTimerToolStripMenuItem->Text = L"Activar Timer";
			this->activarTimerToolStripMenuItem->Click += gcnew System::EventHandler(this, &WFormGL::activarTimerToolStripMenuItem_Click);
			// 
			// moverUnPasoEnterToolStripMenuItem
			// 
			this->moverUnPasoEnterToolStripMenuItem->Name = L"moverUnPasoEnterToolStripMenuItem";
			this->moverUnPasoEnterToolStripMenuItem->Size = System::Drawing::Size(191, 22);
			this->moverUnPasoEnterToolStripMenuItem->Text = L"Mover un paso (Enter)";
			this->moverUnPasoEnterToolStripMenuItem->Click += gcnew System::EventHandler(this, &WFormGL::moverUnPasoEnterToolStripMenuItem_Click);
			// 
			// activarBoundingBoxToolStripMenuItem
			// 
			this->activarBoundingBoxToolStripMenuItem->CheckOnClick = true;
			this->activarBoundingBoxToolStripMenuItem->Name = L"activarBoundingBoxToolStripMenuItem";
			this->activarBoundingBoxToolStripMenuItem->Size = System::Drawing::Size(191, 22);
			this->activarBoundingBoxToolStripMenuItem->Text = L"Activar bounding box";
			this->activarBoundingBoxToolStripMenuItem->Click += gcnew System::EventHandler(this, &WFormGL::activarBoundingBoxToolStripMenuItem_Click);
			// 
			// escenasToolStripMenuItem
			// 
			this->escenasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->escena1ToolStripMenuItem, 
				this->escena2ToolStripMenuItem, this->escena3ToolStripMenuItem, this->escena4ToolStripMenuItem});
			this->escenasToolStripMenuItem->Enabled = false;
			this->escenasToolStripMenuItem->Name = L"escenasToolStripMenuItem";
			this->escenasToolStripMenuItem->Size = System::Drawing::Size(60, 22);
			this->escenasToolStripMenuItem->Text = L"Escenas";
			// 
			// escena1ToolStripMenuItem
			// 
			this->escena1ToolStripMenuItem->Name = L"escena1ToolStripMenuItem";
			this->escena1ToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->escena1ToolStripMenuItem->Text = L"Escena 1";
			this->escena1ToolStripMenuItem->Click += gcnew System::EventHandler(this, &WFormGL::escena1ToolStripMenuItem_Click);
			// 
			// escena2ToolStripMenuItem
			// 
			this->escena2ToolStripMenuItem->Name = L"escena2ToolStripMenuItem";
			this->escena2ToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->escena2ToolStripMenuItem->Text = L"Escena 2";
			this->escena2ToolStripMenuItem->Click += gcnew System::EventHandler(this, &WFormGL::escena2ToolStripMenuItem_Click);
			// 
			// escena3ToolStripMenuItem
			// 
			this->escena3ToolStripMenuItem->Name = L"escena3ToolStripMenuItem";
			this->escena3ToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->escena3ToolStripMenuItem->Text = L"Escena 3";
			this->escena3ToolStripMenuItem->Click += gcnew System::EventHandler(this, &WFormGL::escena3ToolStripMenuItem_Click);
			// 
			// escena4ToolStripMenuItem
			// 
			this->escena4ToolStripMenuItem->Name = L"escena4ToolStripMenuItem";
			this->escena4ToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->escena4ToolStripMenuItem->Text = L"Escena 4";
			this->escena4ToolStripMenuItem->Click += gcnew System::EventHandler(this, &WFormGL::escena4ToolStripMenuItem_Click);
			// 
			// depuraciónF1ToolStripMenuItem
			// 
			this->depuraciónF1ToolStripMenuItem->CheckOnClick = true;
			this->depuraciónF1ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->colaToolStripMenuItem, 
				this->contornosToolStripMenuItem});
			this->depuraciónF1ToolStripMenuItem->Enabled = false;
			this->depuraciónF1ToolStripMenuItem->Name = L"depuraciónF1ToolStripMenuItem";
			this->depuraciónF1ToolStripMenuItem->Size = System::Drawing::Size(80, 22);
			this->depuraciónF1ToolStripMenuItem->Text = L"Depuración";
			// 
			// colaToolStripMenuItem
			// 
			this->colaToolStripMenuItem->CheckOnClick = true;
			this->colaToolStripMenuItem->Name = L"colaToolStripMenuItem";
			this->colaToolStripMenuItem->Size = System::Drawing::Size(130, 22);
			this->colaToolStripMenuItem->Text = L"Cola";
			this->colaToolStripMenuItem->Click += gcnew System::EventHandler(this, &WFormGL::colaToolStripMenuItem_Click);
			// 
			// contornosToolStripMenuItem
			// 
			this->contornosToolStripMenuItem->CheckOnClick = true;
			this->contornosToolStripMenuItem->Name = L"contornosToolStripMenuItem";
			this->contornosToolStripMenuItem->Size = System::Drawing::Size(130, 22);
			this->contornosToolStripMenuItem->Text = L"Contornos";
			this->contornosToolStripMenuItem->Click += gcnew System::EventHandler(this, &WFormGL::contornosToolStripMenuItem_Click);
			// 
			// renderToolStripMenuItem
			// 
			this->renderToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->generarUnÁrbolToolStripMenuItem, 
				this->gLSceneToolStripMenuItem});
			this->renderToolStripMenuItem->Name = L"renderToolStripMenuItem";
			this->renderToolStripMenuItem->Size = System::Drawing::Size(56, 22);
			this->renderToolStripMenuItem->Text = L"Render";
			// 
			// generarUnÁrbolToolStripMenuItem
			// 
			this->generarUnÁrbolToolStripMenuItem->Name = L"generarUnÁrbolToolStripMenuItem";
			this->generarUnÁrbolToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->generarUnÁrbolToolStripMenuItem->Text = L"Generar un árbol";
			this->generarUnÁrbolToolStripMenuItem->Click += gcnew System::EventHandler(this, &WFormGL::generarUnÁrbolToolStripMenuItem_Click);
			// 
			// gLSceneToolStripMenuItem
			// 
			this->gLSceneToolStripMenuItem->Name = L"gLSceneToolStripMenuItem";
			this->gLSceneToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->gLSceneToolStripMenuItem->Text = L"GLScene()";
			this->gLSceneToolStripMenuItem->Click += gcnew System::EventHandler(this, &WFormGL::gLSceneToolStripMenuItem_Click);
			// 
			// pixmapToolStripMenuItem
			// 
			this->pixmapToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->abrirDesdeFicheroToolStripMenuItem, 
				this->operacionesToolStripMenuItem, this->guardarEnPixmapToolStripMenuItem, this->cargarPixmapToolStripMenuItem});
			this->pixmapToolStripMenuItem->Name = L"pixmapToolStripMenuItem";
			this->pixmapToolStripMenuItem->Size = System::Drawing::Size(58, 22);
			this->pixmapToolStripMenuItem->Text = L"Pixmap";
			// 
			// abrirDesdeFicheroToolStripMenuItem
			// 
			this->abrirDesdeFicheroToolStripMenuItem->Name = L"abrirDesdeFicheroToolStripMenuItem";
			this->abrirDesdeFicheroToolStripMenuItem->Size = System::Drawing::Size(183, 22);
			this->abrirDesdeFicheroToolStripMenuItem->Text = L"Abrir desde fichero...";
			this->abrirDesdeFicheroToolStripMenuItem->Click += gcnew System::EventHandler(this, &WFormGL::abrirDesdeFicheroToolStripMenuItem_Click);
			// 
			// operacionesToolStripMenuItem
			// 
			this->operacionesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->mediaPonderadaToolStripMenuItem, 
				this->diferenciaToolStripMenuItem, this->máscarasToolStripMenuItem});
			this->operacionesToolStripMenuItem->Name = L"operacionesToolStripMenuItem";
			this->operacionesToolStripMenuItem->Size = System::Drawing::Size(183, 22);
			this->operacionesToolStripMenuItem->Text = L"Operaciones";
			// 
			// mediaPonderadaToolStripMenuItem
			// 
			this->mediaPonderadaToolStripMenuItem->Name = L"mediaPonderadaToolStripMenuItem";
			this->mediaPonderadaToolStripMenuItem->Size = System::Drawing::Size(165, 22);
			this->mediaPonderadaToolStripMenuItem->Text = L"Media Aritmética";
			this->mediaPonderadaToolStripMenuItem->Click += gcnew System::EventHandler(this, &WFormGL::mediaPonderadaToolStripMenuItem_Click);
			// 
			// diferenciaToolStripMenuItem
			// 
			this->diferenciaToolStripMenuItem->Name = L"diferenciaToolStripMenuItem";
			this->diferenciaToolStripMenuItem->Size = System::Drawing::Size(165, 22);
			this->diferenciaToolStripMenuItem->Text = L"Diferencia";
			this->diferenciaToolStripMenuItem->Click += gcnew System::EventHandler(this, &WFormGL::diferenciaToolStripMenuItem_Click);
			// 
			// máscarasToolStripMenuItem
			// 
			this->máscarasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->suavizado1ToolStripMenuItem});
			this->máscarasToolStripMenuItem->Name = L"máscarasToolStripMenuItem";
			this->máscarasToolStripMenuItem->Size = System::Drawing::Size(165, 22);
			this->máscarasToolStripMenuItem->Text = L"Máscaras";
			// 
			// suavizado1ToolStripMenuItem
			// 
			this->suavizado1ToolStripMenuItem->Name = L"suavizado1ToolStripMenuItem";
			this->suavizado1ToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->suavizado1ToolStripMenuItem->Text = L"Suavizado 1";
			// 
			// guardarEnPixmapToolStripMenuItem
			// 
			this->guardarEnPixmapToolStripMenuItem->Name = L"guardarEnPixmapToolStripMenuItem";
			this->guardarEnPixmapToolStripMenuItem->Size = System::Drawing::Size(183, 22);
			this->guardarEnPixmapToolStripMenuItem->Text = L"Guardar";
			this->guardarEnPixmapToolStripMenuItem->Click += gcnew System::EventHandler(this, &WFormGL::guardarEnPixmapToolStripMenuItem_Click);
			// 
			// cargarPixmapToolStripMenuItem
			// 
			this->cargarPixmapToolStripMenuItem->Name = L"cargarPixmapToolStripMenuItem";
			this->cargarPixmapToolStripMenuItem->Size = System::Drawing::Size(183, 22);
			this->cargarPixmapToolStripMenuItem->Text = L"Cargar";
			this->cargarPixmapToolStripMenuItem->Click += gcnew System::EventHandler(this, &WFormGL::cargarPixmapToolStripMenuItem_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 20;
			this->timer1->Tick += gcnew System::EventHandler(this, &WFormGL::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(16, 136);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(44, 45);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Rota";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &WFormGL::button1_Click);
			// 
			// tB_Xrot
			// 
			this->tB_Xrot->Location = System::Drawing::Point(16, 32);
			this->tB_Xrot->Name = L"tB_Xrot";
			this->tB_Xrot->Size = System::Drawing::Size(100, 20);
			this->tB_Xrot->TabIndex = 5;
			this->tB_Xrot->Text = L"100";
			// 
			// tB_Yrot
			// 
			this->tB_Yrot->Location = System::Drawing::Point(16, 71);
			this->tB_Yrot->Name = L"tB_Yrot";
			this->tB_Yrot->Size = System::Drawing::Size(100, 20);
			this->tB_Yrot->TabIndex = 6;
			this->tB_Yrot->Text = L"100";
			// 
			// tB_degreesRot
			// 
			this->tB_degreesRot->Location = System::Drawing::Point(16, 110);
			this->tB_degreesRot->Name = L"tB_degreesRot";
			this->tB_degreesRot->Size = System::Drawing::Size(100, 20);
			this->tB_degreesRot->TabIndex = 7;
			this->tB_degreesRot->Text = L"70";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->DefaultExt = L"bmp";
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(0, 27);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(169, 243);
			this->tabControl1->TabIndex = 8;
			this->tabControl1->Visible = false;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->tB_degreesRot);
			this->tabPage1->Controls->Add(this->tB_Xrot);
			this->tabPage1->Controls->Add(this->tB_Yrot);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(161, 201);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Rotación";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 94);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Grados";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Eje Vertical";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Eje Horizontal";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->b_weightedMean);
			this->tabPage2->Controls->Add(this->tB_factor_wm);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(161, 201);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"M.Ponderada";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// b_weightedMean
			// 
			this->b_weightedMean->Location = System::Drawing::Point(10, 51);
			this->b_weightedMean->Name = L"b_weightedMean";
			this->b_weightedMean->Size = System::Drawing::Size(100, 23);
			this->b_weightedMean->TabIndex = 2;
			this->b_weightedMean->Text = L"Aplicar a pixmap";
			this->b_weightedMean->UseVisualStyleBackColor = true;
			this->b_weightedMean->Click += gcnew System::EventHandler(this, &WFormGL::b_weightedMean_Click);
			// 
			// tB_factor_wm
			// 
			this->tB_factor_wm->Location = System::Drawing::Point(10, 24);
			this->tB_factor_wm->Name = L"tB_factor_wm";
			this->tB_factor_wm->Size = System::Drawing::Size(100, 20);
			this->tB_factor_wm->TabIndex = 1;
			this->tB_factor_wm->Text = L"0,7";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(7, 7);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Factor";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label7);
			this->tabPage3->Controls->Add(this->label8);
			this->tabPage3->Controls->Add(this->tB_limit_x);
			this->tabPage3->Controls->Add(this->tB_limit_y);
			this->tabPage3->Controls->Add(this->chk_limits);
			this->tabPage3->Controls->Add(this->b_gauss);
			this->tabPage3->Controls->Add(this->label5);
			this->tabPage3->Controls->Add(this->label6);
			this->tabPage3->Controls->Add(this->tB_gauss_m);
			this->tabPage3->Controls->Add(this->tB_gauss_d);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(161, 217);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Gauss";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// b_gauss
			// 
			this->b_gauss->Location = System::Drawing::Point(11, 85);
			this->b_gauss->Name = L"b_gauss";
			this->b_gauss->Size = System::Drawing::Size(100, 23);
			this->b_gauss->TabIndex = 14;
			this->b_gauss->Text = L"Genera y Aplica";
			this->b_gauss->UseVisualStyleBackColor = true;
			this->b_gauss->Click += gcnew System::EventHandler(this, &WFormGL::b_gauss_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(8, 42);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(63, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Factor delta";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(8, 3);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(48, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Factor m";
			// 
			// tB_gauss_m
			// 
			this->tB_gauss_m->Location = System::Drawing::Point(11, 19);
			this->tB_gauss_m->Name = L"tB_gauss_m";
			this->tB_gauss_m->Size = System::Drawing::Size(100, 20);
			this->tB_gauss_m->TabIndex = 10;
			this->tB_gauss_m->Text = L"2";
			// 
			// tB_gauss_d
			// 
			this->tB_gauss_d->Location = System::Drawing::Point(11, 58);
			this->tB_gauss_d->Name = L"tB_gauss_d";
			this->tB_gauss_d->Size = System::Drawing::Size(100, 20);
			this->tB_gauss_d->TabIndex = 11;
			this->tB_gauss_d->Text = L"1,5";
			// 
			// chk_limits
			// 
			this->chk_limits->AutoSize = true;
			this->chk_limits->Location = System::Drawing::Point(11, 115);
			this->chk_limits->Name = L"chk_limits";
			this->chk_limits->Size = System::Drawing::Size(58, 17);
			this->chk_limits->TabIndex = 15;
			this->chk_limits->Text = L"Limites";
			this->chk_limits->UseVisualStyleBackColor = true;
			this->chk_limits->CheckedChanged += gcnew System::EventHandler(this, &WFormGL::chk_limits_CheckedChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(8, 172);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(44, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"Limite Y";
			this->label7->Visible = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(8, 133);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(44, 13);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Limite X";
			this->label8->Visible = false;
			// 
			// tB_limit_x
			// 
			this->tB_limit_x->Location = System::Drawing::Point(11, 149);
			this->tB_limit_x->Name = L"tB_limit_x";
			this->tB_limit_x->Size = System::Drawing::Size(100, 20);
			this->tB_limit_x->TabIndex = 16;
			this->tB_limit_x->Visible = false;
			// 
			// tB_limit_y
			// 
			this->tB_limit_y->Location = System::Drawing::Point(11, 188);
			this->tB_limit_y->Name = L"tB_limit_y";
			this->tB_limit_y->Size = System::Drawing::Size(100, 20);
			this->tB_limit_y->TabIndex = 17;
			this->tB_limit_y->Visible = false;
			// 
			// WFormGL
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 681);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1024, 720);
			this->Name = L"WFormGL";
			this->Text = L"IGr - Practica 2";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &WFormGL::WFormGL_FormClosing_1);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &WFormGL::WFormGL_Paint);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &WFormGL::WFormGL_KeyPress);
			this->Resize += gcnew System::EventHandler(this, &WFormGL::WFormGL_Resize);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void salirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
             Close();
           }
private: System::Void moverToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
              this->timer1->Enabled = ! this->timer1->Enabled;
           }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
            this->timer1->Enabled = ! this->timer1->Enabled;
            scene->step();
			GLScene();
            this->timer1->Enabled = ! this->timer1->Enabled;
         }
private: System::Void WFormGL_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
            GLScene();
         }
private: System::Void WFormGL_Resize(System::Object^  sender, System::EventArgs^  e) {
            ReSizeGL(this->ClientSize.Width, this->ClientSize.Height);
            GLScene();
         }
private: System::Void WFormGL_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

			bool need_redisplay = true;

			switch (e->KeyChar) {
				case '\r' : scene->step();break;
				case 'a' : scene->move(0,-MOVE_FACTOR); break;
				case 'd' : scene->move(0,+MOVE_FACTOR); break;  
				case 's' : scene->move(1,-MOVE_FACTOR); break;
				case 'w' : scene->move(1,+MOVE_FACTOR); break;

				case '+': scene->zoom(1+ZOOM_FACTOR); break;
				case '-': scene->zoom(1-ZOOM_FACTOR); break;
									
				default : need_redisplay = false; break;
			}

			if (need_redisplay){
				// Scene Visible Area
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				gluOrtho2D(scene->xL, scene->xR, scene->yB, scene->yT);

				GLScene();
			}
		 }
private: System::Void escena1ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) { scene->initScene(1); GLScene();
		 if (this->timer1->Enabled){
				 this->timer1->Enabled = false;
				 this->activarTimerToolStripMenuItem->Checked = false;
				 this->moverUnPasoEnterToolStripMenuItem->Enabled = true;
			 }
		 }
private: System::Void escena2ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) { scene->initScene(2); GLScene();
		 if (this->timer1->Enabled){
				 this->timer1->Enabled = false;
				 this->activarTimerToolStripMenuItem->Checked = false;
				 this->moverUnPasoEnterToolStripMenuItem->Enabled = true;
			 }
		 }
private: System::Void escena3ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) { scene->initScene(3); GLScene();
		 if (this->timer1->Enabled){
				 this->timer1->Enabled = false;
				 this->activarTimerToolStripMenuItem->Checked = false;
				 this->moverUnPasoEnterToolStripMenuItem->Enabled = true;
			 }
		 }


private: System::Void activarTimerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			this->timer1->Enabled = ! this->timer1->Enabled;
            scene->step();
			GLScene();
			if (this->timer1->Enabled)
				this->moverUnPasoEnterToolStripMenuItem->Enabled = false;
			else
				this->moverUnPasoEnterToolStripMenuItem->Enabled = true;
            //this->timer1->Enabled = ! this->timer1->Enabled;
		 }
private: System::Void moverUnPasoEnterToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 scene->step();
			 GLScene();
		 }

private: System::Void WFormGL_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 if (MessageBox::Show("¿Quieres cerrar el programa?", "IGr",
								  MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes){
				Application::Exit();
			 } else {
				 e->Cancel = true;
			 }
		 }


private: System::Void activarBoundingBoxToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 scene->activeBB(this->activarBoundingBoxToolStripMenuItem->Checked);
			 GLScene();
			 if (this->timer1->Enabled){
				 this->timer1->Enabled = false;
				 this->activarTimerToolStripMenuItem->Checked = false;
				 this->moverUnPasoEnterToolStripMenuItem->Enabled = true;
			 }
		 }

private: System::Void WFormGL_FormClosing_1(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 if (MessageBox::Show("¿Quieres cerrar el programa?", "IGr",
								  MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes){
				Application::Exit();
			 } else {
				 e->Cancel = true;
			 }

		 }
private: System::Void colaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {GLScene();}
private: System::Void contornosToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {GLScene();}
private: System::Void escena4ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) { scene->initScene(4); GLScene();
		 if (this->timer1->Enabled){
				 this->timer1->Enabled = false;
				 this->activarTimerToolStripMenuItem->Checked = false;
				 this->moverUnPasoEnterToolStripMenuItem->Enabled = true;
			 }		 
		 }
private: System::Void gLSceneToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 GLScene();
		 }
private: System::Void guardarEnPixmapToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 nwOpenGL->SwapBuffersGL();
			 delete scene->pixmap;
			 scene->pixmap = new PixmapRGB(720,1024);
			 scene->pixmap->save(0,0);
			 nwOpenGL->SwapBuffersGL();
			 scene->pixmap->saveBMP();
		 }
private: System::Void cargarPixmapToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 GLScene();
		 }
private: System::Void generarUnÁrbolToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			Tree* tree = new Tree();
			tree->initTree(new Square(new PV2D(250,50), 20, 0));
			for (int i=0;i<14;i++) tree->generateNewLevel();
			
			glClear(GL_COLOR_BUFFER_BIT);
			tree->render();
			nwOpenGL->SwapBuffersGL();

			delete tree;
		 }
private: System::Void rotarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			
		 }

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 float degrees = Convert::ToDouble(tB_degreesRot->Text);
			 int xPos = Convert::ToInt32(tB_Xrot->Text);
			 int yPos = Convert::ToInt32(tB_Yrot->Text);
			 scene->pixmap->rotate(degrees*2*3.141592/360, xPos, yPos);
			 GLScene();
		 }
private: System::Void abrirDesdeFicheroToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			openFileDialog1->ShowDialog();
			string filename = msclr::interop::marshal_as< std::string >(openFileDialog1->FileName);
			delete scene->pixmap;
			scene->pixmap = new PixmapRGB(filename.c_str());
			GLScene();
		 }
private: System::Void diferenciaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			openFileDialog1->ShowDialog();
			string filename = msclr::interop::marshal_as< std::string >(openFileDialog1->FileName);
			delete scene->pixmap2;
			scene->pixmap2 = new PixmapRGB(filename.c_str());

			unsigned char* m1 = scene->pixmap->toY();
			unsigned char* m2 = scene->pixmap2->toY();

			PixmapY* pY_1 = new PixmapY(scene->pixmap->getRows(), scene->pixmap->getCols());
			PixmapY* pY_2 = new PixmapY(scene->pixmap2->getRows(), scene->pixmap2->getCols());

			pY_1->setMatrix(m1);
			pY_2->setMatrix(m2);

			PixmapY* pY_res = pY_1->difference(pY_2);

			unsigned char* mRes = pY_res->toRGB();
			scene->pixmap->setMatrix(mRes);

			GLScene();
		 }
private: System::Void mediaPonderadaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			openFileDialog1->ShowDialog();
			string filename = msclr::interop::marshal_as< std::string >(openFileDialog1->FileName);
			delete scene->pixmap2;
			scene->pixmap2 = new PixmapRGB(filename.c_str());
			scene->pixmap = scene->pixmap->arithmeticMean(scene->pixmap2);
			GLScene();
		 }
private: System::Void suavizadoGaussianoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 float* mask = scene->gaussianMask(2,1.5);
			 //scene->pixmap->applyMask9(mask);
			 scene->pixmap->applyMaskm(mask, 2);
			 GLScene();
		 }
private: System::Void b_weightedMean_Click(System::Object^  sender, System::EventArgs^  e) {
			openFileDialog1->ShowDialog();
			string filename = msclr::interop::marshal_as< std::string >(openFileDialog1->FileName);
			delete scene->pixmap2;
			scene->pixmap2 = new PixmapRGB(filename.c_str());
			float factor = Convert::ToDouble(tB_factor_wm->Text);
			scene->pixmap = scene->pixmap->weightedMean(factor ,scene->pixmap2);
			GLScene();
		 }

private: System::Void b_gauss_Click(System::Object^  sender, System::EventArgs^  e) {
			 int m = Convert::ToInt32(tB_gauss_m->Text);
			 float delta = Convert::ToDouble(tB_gauss_d->Text);
			 float* mask = scene->gaussianMask(m, delta);
			 
			 if (!chk_limits->Checked){
				scene->pixmap->applyMaskm(mask,m);
			 } else {
				 int xPos = Convert::ToInt32(tB_limit_x->Text);
				 int yPos = Convert::ToInt32(tB_limit_y->Text);
				 scene->pixmap->applyMaskm(mask, m, xPos, yPos);
			 }
			 GLScene();
		 }
private: System::Void menuExtraToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 tabControl1->Visible = menuExtraToolStripMenuItem->Checked;
			 GLScene();
		 }
private: System::Void mostrarP3ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 scene->showP3(mostrarP3ToolStripMenuItem->Checked);
			 accionesToolStripMenuItem->Enabled = mostrarP3ToolStripMenuItem->Checked;
			 escenasToolStripMenuItem->Enabled = mostrarP3ToolStripMenuItem->Checked;
			 depuraciónF1ToolStripMenuItem->Enabled = mostrarP3ToolStripMenuItem->Checked;
			 GLScene();
		 }
private: System::Void chk_limits_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 label7->Visible = chk_limits->Checked;
			 label8->Visible = chk_limits->Checked;
			 tB_limit_x->Visible = chk_limits->Checked;
			 tB_limit_y->Visible = chk_limits->Checked;
		 }
};
};