/*
Proyecto -> Visual C++ -> WinCLI
Propiedades del proyecto (Debug y release) -> Vinculador -> Entrada -> Dependencias adicionales -> openGL32.lib, glu32.lib
Añadir al proyecto el archivo WNOpenGL.h
Incluir el archivo en el winform en el que se quiera utilizar openGL, y 
añadir un atributo para la nueva clase, crearlo en la constructora, iniciar y ...

*/

#include "WFormGL.h"

using namespace WinCliOpenGL;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	Application::Run(gcnew WFormGL());
	return 0;
}