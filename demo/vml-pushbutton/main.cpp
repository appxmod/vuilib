#include "../../include/core/widget/vwidget.h"
#include "../../include/vml/vmlwidget.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	Core::VApplication VMLDemo;
	VML::VMLMainWindow MainWindow(1000, 400, &VMLDemo);

	auto Result = MainWindow.LoadVML(L"./mainui.xml", VML::VMLParserParseMode::FromFile);

	return VMLDemo.Exec();
}