#pragma once
#include "WNOpenGL.h"
#include "src\Scene.h"

#define MOVE_FACTOR 0.01
#define ZOOM_FACTOR 0.05

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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->accionesToolStripMenuItem, 
				this->escenasToolStripMenuItem, this->depuraciónF1ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 1, 0, 1);
			this->menuStrip1->Size = System::Drawing::Size(795, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// accionesToolStripMenuItem
			// 
			this->accionesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->activarTimerToolStripMenuItem, 
				this->moverUnPasoEnterToolStripMenuItem, this->activarBoundingBoxToolStripMenuItem});
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
			// timer1
			// 
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &WFormGL::timer1_Tick);
			// 
			// WFormGL
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(795, 488);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"WFormGL";
			this->Text = L"IGr - Practica 2";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &WFormGL::WFormGL_FormClosing_1);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &WFormGL::WFormGL_Paint);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &WFormGL::WFormGL_KeyPress);
			this->Resize += gcnew System::EventHandler(this, &WFormGL::WFormGL_Resize);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
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
};
}
