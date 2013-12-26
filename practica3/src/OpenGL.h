#pragma once

#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>

using namespace System::Windows::Forms;

namespace OpenGLForm 
{
	public ref class COpenGL: public System::Windows::Forms::NativeWindow
	{
  private:
		HDC m_hDC;
		HGLRC m_hglrc;
	public:
		COpenGL(System::Windows::Forms::Form ^ parentForm) //, GLsizei iWidth, GLsizei iHeight)
		{
			CreateParams^ cp = gcnew CreateParams;

			// Set the position on the form
			cp->X = 0;
			cp->Y = 0;
			cp->Height = parentForm->ClientSize.Width;
			cp->Width = parentForm->ClientSize.Height;

			// Specify the form as the parent.
			cp->Parent = parentForm->Handle;

			// Create as a child of the specified parent and make OpenGL compliant (no clipping)
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

			// Create the actual window
			this->CreateHandle(cp);

			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			if(m_hDC)
			{
				SetPixelFormatDescriptor(m_hDC);
			}
		}

		~COpenGL()
		{
      ReleaseDC((HWND)this->Handle.ToPointer(),m_hDC);
      wglMakeCurrent(nullptr, nullptr);
      wglDeleteContext(m_hglrc);
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

      m_hglrc = wglCreateContext(m_hDC);
			if(m_hglrc == nullptr)
			{
				MessageBox::Show("wglCreateContext Failed");
				return false;
			}

			if(! wglMakeCurrent(m_hDC, m_hglrc))
			{
				MessageBox::Show("wglMakeCurrent Failed");
				return false;
			}

			return true;
		}

  public:
    GLvoid SwapOpenGLBuffers()
		{
			SwapBuffers(m_hDC) ;
		}

	};
}