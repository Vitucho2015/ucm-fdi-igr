//#pragma once

#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>

using namespace System::Windows::Forms;

public ref class NWOpenGL: public System::Windows::Forms::NativeWindow
{
  public:
    //static const GLsizei WIDTH = 1400;
    //static const GLsizei HEIGHT = 800;
  private:
		HDC nw_hDC;
		HGLRC nw_hglrc;
	public:
		NWOpenGL(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight)
		{
			CreateParams^ cp = gcnew CreateParams;

			// Set the position on the form
			cp->X = 0;
			cp->Y = 0;
			cp->Height = iHeight; //HEIGHT;  // iHeight  // para no tener que cambiar el tamaño de la ventana nativa
			cp->Width = iWidth;   //WIDTH;    // iWidth  

			// Specify the form as the parent.
			cp->Parent = parentForm->Handle;

			// Create as a child of the specified parent and make OpenGL compliant (no clipping)
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

			// Create the actual window
			this->CreateHandle(cp);

			nw_hDC = GetDC((HWND)this->Handle.ToPointer());

			if(nw_hDC)	SetPixelFormatDescriptor(nw_hDC);
		}

		~NWOpenGL()
		{
      ReleaseDC((HWND)this->Handle.ToPointer(),nw_hDC);
      wglMakeCurrent(nullptr, nullptr);
      wglDeleteContext(nw_hglrc);
      DestroyHandle();
		}

  protected:
		bool SetPixelFormatDescriptor(HDC hdc)
		{
			  PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
				{
					sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
					1,											// Version Number
					PFD_DRAW_TO_WINDOW |						// Format Must Support Window
					PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
					PFD_DOUBLEBUFFER,							// Must Support Double Buffering
					PFD_TYPE_RGBA,								// Request An RGBA Format
					32,										// 32-bit Color Depth
					0, 0, 0, 0, 0, 0,							// Color Bits Ignored
					0,											// No Alpha Buffer
					0,											// Shift Bit Ignored
					0,											// No Accumulation Buffer
					0, 0, 0, 0,									// Accumulation Bits Ignored
					32,											// 32-bit Z-Buffer (Depth Buffer)  
					0,											// No Stencil Buffer
					0,											// No Auxiliary Buffer
					PFD_MAIN_PLANE,								// Main Drawing Layer
					0,											// Reserved
					0, 0, 0										// Layer Masks Ignored
				};
			
			// get the device context's best, available pixel format match 
      GLint  iPixelFormat = ChoosePixelFormat(hdc, &pfd); 
			if(iPixelFormat  == 0)
			{
				MessageBox::Show("ChoosePixelFormat Failed");
				return false;
			}
			 
			// make that match the device context's current pixel format 
			if(! SetPixelFormat(hdc, iPixelFormat, &pfd))
			{
				MessageBox::Show("SetPixelFormat Failed");
				return false;
			}

      nw_hglrc = wglCreateContext(nw_hDC);
			if(nw_hglrc == nullptr)
			{
				MessageBox::Show("wglCreateContext Failed");
				return false;
			}

			if(! wglMakeCurrent(nw_hDC, nw_hglrc))
			{
				MessageBox::Show("wglMakeCurrent Failed");
				return false;
			}

			return true;
		}

  public:
		GLvoid SwapBuffersGL()
    {
      SwapBuffers(nw_hDC);
    }

    GLvoid ResizeGL(GLsizei iWidth, GLsizei iHeight)  
    {
      //cambiar tamaño de la ventana nativa 
      SetWindowPos((HWND)this->Handle.ToPointer(), HWND_BOTTOM, 0, 0,iWidth,iHeight,SWP_NOMOVE); 
    }
    /*
    GLvoid ViewportGL(GLint ix, GLint iy, GLsizei iWidth, GLsizei iHeight)  // Añadir parámetros
    {
      //glViewport(ix, HEIGHT-iHeight+iy,iWidth,iHeight); // nuevo ajuste ¿+iy???
    }*/
};
